#ifndef UDPRECEIVER_HPP
#define UDPRECEIVER_HPP

#include <QHostAddress>
#include <QObject>
#include <QString>

QT_BEGIN_NAMESPACE
class QUdpSocket;
class QImage;
QT_END_NAMESPACE

class UdpReceiver : public QObject {
  Q_OBJECT

 public:
  UdpReceiver(QObject *parent = nullptr);

 signals:
  void updateImage(QImage image);

 private slots:
  void dataPending();

 private:
  QUdpSocket *m_socket{nullptr};
};

#endif  // UDPRECEIVER_HPP
