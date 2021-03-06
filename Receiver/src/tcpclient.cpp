#include "tcpclient.hpp"

#include <QComboBox>
#include <QDebug>
#include <QDialogButtonBox>
#include <QGridLayout>
#include <QGroupBox>
#include <QImage>
#include <QLabel>
#include <QLineEdit>
#include <QMessageBox>
#include <QNetworkConfiguration>
#include <QPushButton>
#include <QSettings>
#include <QString>
#include <QTextEdit>

#include "instrumentor.h"
#include "logger.h"
#include "commonconnection.hpp"

TcpClient::TcpClient(QWidget *parent) : QWidget(parent) {
#if LOGGER_UI
  LOG(LevelAlert::I, "ctor Client initialize parameters.")
  LOG(LevelAlert::I, "dis/connect buttons are set disable.")
  LOG(LevelAlert::I, "Opening network session.")
#endif
  // initialize button and assemble ui
  connectButton = new QPushButton("Connect");
  disconnectButton = new QPushButton("Disconnect");
  connectButton->setEnabled(false);
  disconnectButton->setEnabled(false);
  auto *grid = new QGridLayout;
  grid->addWidget(createInformationGroup(), 0, 0, 1, 3);
  grid->addWidget(connectButton, 1, 1);
  grid->addWidget(disconnectButton, 1, 2);
  grid->addWidget(createLogGroup(), 2, 0, 1, 3);
  setLayout(grid);
  // connect functions
  m_stream = new StreamerThread(this);
  connect(m_stream->socket, &QTcpSocket::connected,
          [=]() { this->connectedToServer(); });
  // connect buttons
  connect(disconnectButton, &QPushButton::clicked,
          [=]() { this->onDisconnectClicked(); });
  connect(connectButton, &QPushButton::clicked, [=]() {
    this->onConnectClicked();
    m_stream->slotReconnect();
  });
  // connect ui
  connect(hostCombo, &QComboBox::editTextChanged, this,
          &TcpClient::enableConnectButton);
  connect(m_port_linedit, &QLineEdit::textChanged, this,
          &TcpClient::enableConnectButton);
  connect(m_stream, &StreamerThread::newImageAvailabe, this,
          &TcpClient::imageAvailabe);

  // network manager
  QNetworkConfigurationManager manager;
  if (manager.capabilities() &
      QNetworkConfigurationManager::NetworkSessionRequired) {
    // Get saved network configuration
    QSettings settings(QSettings::UserScope, QLatin1String("QtProject"));
    settings.beginGroup(QLatin1String("QtNetwork"));
    const QString id =
        settings.value(QLatin1String("DefaultNetworkConfiguration")).toString();
    settings.endGroup();
    // If the saved network configuration is not currently discovered use the
    // system default
    QNetworkConfiguration config = manager.configurationFromIdentifier(id);
    if ((config.state() & QNetworkConfiguration::Discovered) !=
        QNetworkConfiguration::Discovered) {
      config = manager.defaultConfiguration();
    }
    networkSession = new QNetworkSession(config, this);
    connect(networkSession, &QNetworkSession::opened, this,
            &TcpClient::sessionOpened);
    connectButton->setEnabled(false);
    m_log_text->append(tr("* Opening network session."));
    networkSession->open();
  }
}

//////////////////////////////////////////////////////////////////////////////
//// Slot function
//////////////////////////////////////////////////////////////////////////////

void TcpClient::imageAvailabe(QByteArray baImage) {
  PROFILE_FUNCTION();
  QPixmap pixImage;
  QImage image;

  if (!pixImage.loadFromData(baImage, "JPG")) return;
  image = pixImage.toImage();
  if (image.pixel(image.width() - 1, image.height() - 1) == 4286611584 &&
      image.pixel(image.width() / 2, image.height() - 1) == 4286611584 &&
      image.pixel(0, image.height() - 1) == 4286611584)
    return;

  emit updatePixmap(pixImage);
}

void TcpClient::connectedToServer() {
  PROFILE_FUNCTION();
#if LOGGER_UI
  LOG(LevelAlert::I, "update connection status: try connect to server.")
  LOG(LevelAlert::I, "update ui.")
#endif
  m_log_text->append(tr("* Connected to server."));
  updateGui(QAbstractSocket::ConnectedState);
}

void TcpClient::onDisconnectClicked() {
#if LOGGER_UI
  LOG(LevelAlert::I, "disconnect button pressed, emit signal.")
  LOG(LevelAlert::D, "set connect button true, set disconnect button false.")
#endif
  m_stream->slotQuit();
  m_log_text->append(tr("* Disconnect."));
  connectButton->setEnabled(true);
  disconnectButton->setEnabled(false);
}

void TcpClient::sessionOpened() {
  // Save the used configuration
  QNetworkConfiguration config = networkSession->configuration();
  QString id;
  if (config.type() == QNetworkConfiguration::UserChoice)
    id = networkSession
             ->sessionProperty(QLatin1String("UserChoiceConfiguration"))
             .toString();
  else
    id = config.identifier();

  QSettings settings(QSettings::UserScope, QLatin1String("QtProject"));
  settings.beginGroup(QLatin1String("QtNetwork"));
  settings.setValue(QLatin1String("DefaultNetworkConfiguration"), id);
  settings.endGroup();
  connectButton->setEnabled(true);
}

void TcpClient::displayError(QAbstractSocket::SocketError socketError) {
  switch (socketError) {
    case QAbstractSocket::RemoteHostClosedError:
      break;
    case QAbstractSocket::HostNotFoundError:
      QMessageBox::information(this, tr("Client"),
                               tr("The host was not found. Please check the "
                                  "host name and port settings."));
      break;
    case QAbstractSocket::ConnectionRefusedError:
      QMessageBox::information(this, tr("Client"),
                               tr("The connection was refused by the peer. "
                                  "Make sure the fortune server is running, "
                                  "and check that the host name and port "
                                  "settings are correct."));
      break;
    default:
      QMessageBox::information(this, tr("Client"),
                               tr("The following error occurred: %1.")
                                   .arg(m_stream->socket->errorString()));
  }
  //  m_stream->socket->abort();
  //  updateGui(QAbstractSocket::UnconnectedState);
}

void TcpClient::enableConnectButton() {
  connectButton->setEnabled((!networkSession || networkSession->isOpen()) &&
                            !hostCombo->currentText().isEmpty() &&
                            !m_port_linedit->text().isEmpty());
}

void TcpClient::onConnectClicked() {
  // check user name is not empty
  if (m_user_linedit->text().isEmpty()) {
    LOG(LevelAlert::E, "must define user name.")
    QMessageBox::information(this, tr("Client"), tr("Define an user name"));
    return;
  }

  if (m_user_linedit->text().isEmpty()) {
    LOG(LevelAlert::E, "must define port.")
    QMessageBox::information(this, tr("Client"), tr("Define port 52693."));
    return;
  }
  // try to connect
  m_log_text->append(tr("* Connecting..."));
  m_stream->setAddressPortHost(hostCombo->currentText(),
                               m_port_linedit->text().toInt());
  auto result = QString("* Connected %1:%2.")
                    .arg(hostCombo->currentText())
                    .arg(m_port_linedit->text().toInt());
  m_log_text->append(result);
  m_stream->start();
  connectButton->setEnabled(false);
  disconnectButton->setEnabled(true);
  LOG(LevelAlert::D, "try connect, connection status: ", result.toUtf8().data())
}

//////////////////////////////////////////////////////////////////////////////
//// Layout function
//////////////////////////////////////////////////////////////////////////////

QGroupBox *TcpClient::createInformationGroup() {
  LOG(LevelAlert::I, "build information group ui")
  // defining layout group
  QGroupBox *groupBox = new QGroupBox(tr("Server Configuration"));
  // init element ui
  QLabel *address_label = new QLabel("Address:");
  QLabel *port_label = new QLabel("Port:");
  QLabel *user_label = new QLabel("User:");
  hostCombo = new QComboBox;
  hostCombo->setEditable(true);
  m_port_linedit = new QLineEdit;
  m_user_linedit = new QLineEdit;

  // find out name of this machine
  QString name = QHostInfo::localHostName();
  m_user_linedit->setText(name);
  if (!name.isEmpty()) {
    hostCombo->addItem(name);
    QString domain = QHostInfo::localDomainName();
    if (!domain.isEmpty()) hostCombo->addItem(name + QChar('.') + domain);
  }
  if (name != QLatin1String("localhost"))
    hostCombo->addItem(QString("localhost"));

  // find out IP addresses of this machine
  QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();
  // add non-localhost addresses
  for (const auto &address : ipAddressesList) {
    if (!address.isLoopback()) {
      hostCombo->addItem(address.toString());
    }
  }
  // validate input port must be 1 <= x <= 65535
  m_port_linedit->setValidator(new QIntValidator(1, 65535, this));

  // setup grid layout
  auto *gridLayout = new QGridLayout;
  gridLayout->addWidget(address_label, 0, 0);
  gridLayout->addWidget(hostCombo, 0, 1);
  gridLayout->addWidget(port_label, 1, 0);
  gridLayout->addWidget(m_port_linedit, 1, 1);
  gridLayout->addWidget(user_label, 2, 0);
  gridLayout->addWidget(m_user_linedit, 2, 1);
  groupBox->setLayout(gridLayout);
  return groupBox;
}

QGroupBox *TcpClient::createLogGroup() {
#if LOGGER_UI
  LOG(LevelAlert::I, "build logging group ui")
#endif

  // defining layout group
  QGroupBox *groupBox = new QGroupBox(tr("Log"));

  // init element ui
  m_log_text = new QTextEdit;

  // setup grid layout
  auto *gridLayout = new QGridLayout;
  gridLayout->addWidget(m_log_text, 0, 0);
  groupBox->setLayout(gridLayout);
  return groupBox;
}

void TcpClient::updateGui(QAbstractSocket::SocketState state) {
  const bool connected = (state == QAbstractSocket::ConnectedState);
  const bool unconnected = (state == QAbstractSocket::UnconnectedState);
#if LOGGER_UI
  LOG(LevelAlert::D, "connection state: ", connected ? "true" : "false")
  LOG(LevelAlert::D, "un-connection state: ", unconnected ? "true" : "false")
#endif
  // update ui
  connectButton->setEnabled(unconnected);
  hostCombo->setEnabled(unconnected);
  m_port_linedit->setEnabled(unconnected);
  m_user_linedit->setEnabled(unconnected);
  disconnectButton->setEnabled(!unconnected);
  m_log_text->setEnabled(connected);
}
