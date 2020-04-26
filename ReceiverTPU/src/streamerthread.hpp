#ifndef STREAMERTHREAD_HPP
#define STREAMERTHREAD_HPP

#include <QHostAddress>
#include <QMutex>
#include <QObject>
#include <QTcpSocket>
#include <QThread>

/**
 * @brief This class expands the QThread by providing methods for receiving
 * frames from a TCP socket.
 */
class StreamerThread : public QThread {
  Q_OBJECT

 public:
  /**
   * @brief Construct a new Streamer Thread object.
   *
   * @param parent QWidget object.
   */
  StreamerThread(QObject *parent = nullptr);

  /**
   * @brief Destroy the Streamer Thread object.
   *
   */
  ~StreamerThread() override;

  /**
   * @brief run function that executes the main process as long as a certain
   * condition is true.
   *
   * This method makes a connection with the TCP socket, blocks the acquired
   * resource using smart mutex and reads the buffer by emitting the
   * newImageAvailable signal. Finally empty the buffer.
   */
  void run() override;

  /**
   * @brief Set the Address Host object.
   *
   * @param str_address take a string type with the address of sender.
   */
  void setAddressHost(const QString &str_address);

  /**
   * @brief Set the Address Host object.
   *
   * @param address take a string type with the address of sender.
   */
  void setAddressHost(const QHostAddress &address);

  /**
   * @brief Set the Port Host object.
   *
   * @param port take a port number of sender.
   */
  void setPortHost(const quint16 &port);

  /**
   * @brief Set the Address Port Host object.
   *
   * @tparam A
   * @tparam P
   * @param address take a string type with the address of sender.
   * @param port take a port number of sender.
   */
  template <typename A, typename P>
  void setAddressPortHost(const A &address, const P &port) {
    m_address = static_cast<QHostAddress>(address);
    m_port = static_cast<quint16>(port);
  }

  // data member
  QTcpSocket *socket{nullptr};

 signals:
  /**
   * @brief newImageAvailable signal emit when a new image is received.
   *
   * @param baimage QByteArray containing the serialized image.
   */
  void newImageAvailabe(QByteArray baImage);

 public slots:
  /**
   * @brief quit slot
   *
   * method executed when the application is closed.
   */
  void slotQuit();

  /**
   * @brief quit slot
   *
   *  method executed when try to reconnect to the socket.
   */
  void slotReconnect();

 private:
  bool m_quit;
  quint16 m_port;
  QHostAddress m_address;
  QByteArray m_baImage;
  QMutex mutex;
};

#endif  // STREAMERTHREAD_HPP
