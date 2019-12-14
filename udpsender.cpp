#include "udpsender.hpp"

#include <QBuffer>
#include <QByteArray>
#include <QDataStream>
#include <QImage>
#include <QImageWriter>
#include <QUdpSocket>

#include "commonconnection.hpp"

UdpSender::UdpSender(QObject *parent)
    : QObject(parent), m_socket(new QUdpSocket(this)) {
  m_address = QHostAddress::Broadcast;
}

void UdpSender::update_address(QString address) {
  m_address = QHostAddress(address);
}

void UdpSender::sendImage(QImage image) {
  QBuffer buffer;
  QImageWriter writer(&buffer, "JPG");
  writer.write(image);
  QByteArray data;
  QDataStream stream(&data, QIODevice::WriteOnly);
  stream.setVersion(QDataStream::Qt_5_0);
  stream << (qint32)buffer.data().size();
  data.append(buffer.data());
  m_socket->writeDatagram(data, m_address, UDP_PORT);
}
