#include "tcpserver.hpp"

#include <QDataStream>
#include <QDebug>
#include <QGridLayout>
#include <QGroupBox>
#include <QLabel>
#include <QPlainTextEdit>
#include <QPushButton>
#include <QTcpServer>
#include <QTcpSocket>
#include <QtNetwork>

#include "commonconnection.hpp"
#include "log/logger.h"

TcpServer::TcpServer(QWidget *parent) : QWidget(parent), m_server(new QTcpServer(this)) {
  this->setWindowTitle("Server");
  // assemble ui
  QGridLayout *grid = new QGridLayout;
  grid->addLayout(createInformationGroup(), 0, 0);
  grid->addWidget(createLogGroup(), 1, 0);
  setLayout(grid);
  if (!m_server->listen(QHostAddress::Any, TCP_PORT)) {
#if LOGGER_SERVER
    LOG(ERROR, "Failure while tcp starting server:")
    qDebug() << m_server->errorString();
#endif
    const auto error_message = QString("Failure while starting server: %1").arg(m_server->errorString());
    m_log_text->append(error_message);
    return;
  }

  // update ui
  m_connection_address->setText(findIpAddress());
  m_port_number->setText(QString::number(m_server->serverPort()));

  // connect signal
  connect(m_server, &QTcpServer::newConnection, [=]() { this->newConnection(); });
  connect(disconnectButton, &QPushButton::clicked, [=]() { this->onDisconnectClientsClicked(); });
}

TcpServer::~TcpServer() {}

void TcpServer::newConnection() {
  while (m_server->hasPendingConnections()) {
    QTcpSocket *socket = m_server->nextPendingConnection();
    m_clients << socket;
    disconnectButton->setEnabled(true);
    // connect signals
    connect(socket, &QTcpSocket::disconnected, this, &TcpServer::removeConnection);
    connect(socket, &QTcpSocket::readyRead, this, &TcpServer::readyRead);
    m_log_text->append(
        QString("* New connection: %1, port %2").arg(socket->peerAddress().toString()).arg(socket->peerPort()));
#if LOGGER_SERVER
    LOG(INFO, "enter new connection.")
    qDebug() << "\t"
             << QString("* New connection: %1, port %2").arg(socket->peerAddress().toString()).arg(socket->peerPort());
#endif
  }
}

void TcpServer::removeConnection() {
  QTcpSocket *socket = qobject_cast<QTcpSocket *>(sender());
  if (!socket) {
    return;
  }
  m_log_text->append(
      tr("* Connection removed: %1, port %2").arg(socket->peerAddress().toString()).arg(socket->peerPort()));
  m_clients.removeOne(socket);
  m_receivedData.remove(socket);
  socket->deleteLater();
  disconnectButton->setEnabled(!m_clients.isEmpty());
}

void TcpServer::readyRead() {
  QTcpSocket *socket = qobject_cast<QTcpSocket *>(sender());
  if (!socket) {
#if LOGGER_SERVER
    LOG(ERROR, "socket not readable, return")
#endif
    return;
  }
  // init input server to resend message
  QDataStream in;
  in.setVersion(QDataStream::Qt_5_0);
  for (auto *socket_devices : m_clients) {
    in.setDevice(socket_devices);
    // fill message from QDataStream
    in.startTransaction();
    QString header{""};
    qint32 size{0};
    in >> header >> size;
#if LOGGER_SERVER
    LOG(DEBUG,
        "incoming message control through header identification:\n"
        "\t* message containing text if the header corresponds to the code UTF-8 '\\u001D' or the ASCII code %d\n"
        "\t* message containing images if the header corresponds to the code UTF-8 '\\u001E' or the ASCII code %d",
        GROUP_SEPARATOR_ASII_CODE, RECORD_SEPARATOR_ASII_CODE)
    qDebug() << "\tincoming message header: " << header << "\tsize: " << size << "\n";
#endif

    if (header == QString(GROUP_SEPARATOR_ASII_CODE)) {
      QString message;
      in >> message;
#if LOGGER_SERVER
      LOG(DEBUG, "check message is not empty: %s", (!message.isEmpty()) ? "true" : "false")
      LOG(DEBUG, "server read message in redyRead()\n\tmessage received:")
      qDebug() << "\t" << message << "\n";
#endif
      newMessage(socket, message);
    } else if (header == QString(RECORD_SEPARATOR_ASII_CODE)) {
#if LOGGER_SERVER
      LOG(DEBUG, "image incoming")
#endif
      QImage image;
      in >> image;
      newMessageImage(socket, image);
    }
    if (!in.commitTransaction()) {
      return;
    }
  }
}

void TcpServer::onDisconnectClientsClicked() {
  foreach (QTcpSocket *socket, m_clients) { socket->close(); }
  disconnectButton->setEnabled(false);
#if LOGGER_SERVER
  LOG(DEBUG, "disconnect all socket")
#endif
}

void TcpServer::newMessage(QTcpSocket *sender, const QString &message) {
#if LOGGER_SERVER
  LOG(DEBUG, "new message ready to be sent")
  qDebug() << "\t" << message << "\n";
#endif
  m_log_text->append(QString("Sending message: %1").arg(message));
  // init out buffer message
  QByteArray message_ba;
  QDataStream out(&message_ba, QIODevice::WriteOnly);
  out.setVersion(QDataStream::Qt_5_0);
  out << QString(GROUP_SEPARATOR_ASII_CODE) << static_cast<quint32>(message_ba.size()) << message;
  for (QTcpSocket *socket : m_clients) {
    if (socket->state() == QAbstractSocket::ConnectedState) {
      socket->write(message_ba);
    }
  }
  Q_UNUSED(sender)
}

void TcpServer::newMessageImage(QTcpSocket *sender, const QImage &image) {
#if LOGGER_SERVER
  LOG(DEBUG, "new image ready to be sent")
#endif
  const QString default_msg{"Sending image"};
  m_log_text->append(default_msg);
  // init out buffer message
  QByteArray message_ba;
  QDataStream out(&message_ba, QIODevice::WriteOnly);
  out.setVersion(QDataStream::Qt_5_0);
  out << QString(RECORD_SEPARATOR_ASII_CODE) << static_cast<quint32>(image.sizeInBytes()) << image;
  for (QTcpSocket *socket : m_clients)
    if (socket->state() == QAbstractSocket::ConnectedState) {
      socket->write(message_ba);
    }
  Q_UNUSED(sender)
}

//////////////////////////////////////////////////////////////////////////////
//// Layout function
//////////////////////////////////////////////////////////////////////////////

QGroupBox *TcpServer::createLogGroup() {
#if LOGGER_UI
  LOG(INFO, "build logging group ui")
#endif

  // defining layout group
  QGroupBox *groupBox = new QGroupBox(tr("Log"));

  // init element ui
  m_log_text = new QTextEdit;

  // setup grid layout
  QGridLayout *gridLayout = new QGridLayout;
  gridLayout->addWidget(m_log_text, 0, 0);
  groupBox->setLayout(gridLayout);
  return groupBox;
}

QGridLayout *TcpServer::createInformationGroup() {
#if LOGGER_UI
  LOG(INFO, "build information ui")
#endif

  // define group layout
  auto grid_layout = new QGridLayout;

  // init elements
  disconnectButton = new QPushButton("Disconnect");
  disconnectButton->setEnabled(false);
  connection_label = new QLabel("Connection:");
  port_label = new QLabel("Port:");
  m_log_text = new QTextEdit;
  m_connection_address = new QLabel;
  m_port_number = new QLabel;

  // assemble element
  grid_layout->addWidget(connection_label, 0, 0);
  grid_layout->addWidget(m_connection_address, 0, 1);
  grid_layout->addWidget(port_label, 0, 2);
  grid_layout->addWidget(m_port_number, 0, 3);
  grid_layout->addWidget(disconnectButton, 0, 4);

  // return layout
  return grid_layout;
}

QString TcpServer::findIpAddress() {
  QString ipAddress;
  QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();
  // use the first non-localhost IPv4 address
  for (const auto &address : ipAddressesList) {
    if (address != QHostAddress::LocalHost && address.toIPv4Address()) {
      ipAddress = address.toString();
      break;
    }
  }
  // if we did not find one, use IPv4 localhost
  if (ipAddress.isEmpty()) ipAddress = QHostAddress(QHostAddress::LocalHost).toString();
#if LOGGER_SERVER
  LOG(DEBUG, "server is running on IP")
  qDebug() << "\t" << ipAddress << " port " << m_server->serverPort();
#endif
  return ipAddress;
}
