#ifndef STREAMERTHREAD_HPP
#define STREAMERTHREAD_HPP

#include <QHostAddress>
#include <QMutex>
#include <QObject>
#include <QTcpSocket>
#include <QThread>

class StreamerThread : public QThread {
  Q_OBJECT

 public:
  StreamerThread(QObject *parent = nullptr);
  ~StreamerThread() override;
  void run() override;
  QTcpSocket *socket{nullptr};

  void setAddressHost(const QString &str_address);
  void setAddressHost(const QHostAddress &address);
  void setPortHost(const quint16 &port);
  template <typename A, typename P>
  void setAddressPortHost(const A &address, const P &port) {
    m_address = static_cast<QHostAddress>(address);
    m_port = static_cast<quint16>(port);
  }

 signals:
  /**
   * @brief newImageAvailable called when a new image is received.
   * @param baimage QByteArray containing the serialized image.
   */
  void newImageAvailabe(QByteArray baImage);

 public slots:
  /**
   * @brief quit Signal emitted when the application is closed.
   */
  void slotQuit();

 private:
  QHostAddress m_address;
  quint16 m_port;
  bool m_quit;
  QByteArray m_baImage;
  QMutex mutex;
};

#endif  // STREAMERTHREAD_HPP
