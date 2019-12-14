#ifndef UDPSENDER_HPP
#define UDPSENDER_HPP

#include <QHostAddress>
#include <QObject>
#include <QString>

QT_BEGIN_NAMESPACE
class QUdpSocket;
class QImage;
QT_END_NAMESPACE

class UdpSender : public QObject {
  Q_OBJECT

 public:
  explicit UdpSender(QObject *parent = nullptr);
  void update_address(QString address);

 public slots:
  void sendImage(QImage image);

 private:
  QUdpSocket *m_socket{nullptr};
  QHostAddress m_address;
};

#endif  // UDPSENDER_HPP
