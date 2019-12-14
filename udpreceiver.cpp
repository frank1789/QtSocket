#include "udpreceiver.hpp"

#include <QBuffer>
#include <QByteArray>
#include <QDataStream>
#include <QImage>
#include <QImageWriter>
#include <QUdpSocket>

#include "commonconnection.hpp"

UdpReceiver::UdpReceiver(QObject *parent)
    : QObject(parent), m_socket(new QUdpSocket(this)) {
  m_socket->bind(UDP_PORT);
  connect(m_socket, &QUdpSocket::readyRead, [=]() { this->dataPending(); });
}

void UdpReceiver::dataPending() {
  while (m_socket->hasPendingDatagrams()) {
    QByteArray buffer(m_socket->pendingDatagramSize(), 0);
    m_socket->readDatagram(buffer.data(), buffer.size());

    QDataStream stream(buffer);
    stream.setVersion(QDataStream::Qt_5_0);
    QImage image;
    stream >> image;
    // image.loadFromData(data.data());
    if (!image.isNull()) {
      qDebug() << "Image file was received ";
      emit updateImage(image);
      // qDebug() << "size = " << temp.size();
    } else {
      qDebug() << "Pic is NULL";
      // qDebug() << "size = " << temp.size();
    }
  }
}
