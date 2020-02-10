#ifndef STREAMERTHREAD_HPP
#define STREAMERTHREAD_HPP

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
  QByteArray m_baImage;
  bool m_quit;
  QMutex mutex;
};

#endif  // STREAMERTHREAD_HPP
