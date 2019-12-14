#ifndef TCPSERVER_HPP
#define TCPSERVER_HPP

#include <QWidget>

QT_BEGIN_NAMESPACE
class QTcpServer;
class QTcpSocket;
class QUdpSocket;
class QLabel;
class QPushButton;
class QTextEdit;
class QGroupBox;
class QGridLayout;
QT_END_NAMESPACE

class TcpServer : public QWidget {
  Q_OBJECT

 public:
  explicit TcpServer(QWidget *parent = nullptr);
  ~TcpServer();

 private slots:
  /**
   * @brief
   *
   */
  void newConnection();

  /**
   * @brief
   *
   */
  void removeConnection();

  /**
   * @brief
   *
   */
  void readyRead();

  /**
   * @brief
   *
   */
  void onDisconnectClientsClicked();

 private:
  void newMessage(QTcpSocket *sender, const QString &message);
  QString findIpAddress();
  // function interface
  QGroupBox *createLogGroup();
  QGridLayout *createInformationGroup();

 private:
  QTcpServer *m_server{nullptr};
  QVector<QTcpSocket *> m_clients;
  QHash<QTcpSocket *, QByteArray> m_receivedData;

  // interface elements
  QPushButton *disconnectButton{nullptr};
  QLabel *connection_label{nullptr};
  QLabel *port_label{nullptr};
  QLabel *m_connection_address{nullptr};
  QLabel *m_port_number{nullptr};
  QTextEdit *m_log_text{nullptr};
};

#endif  // TCPSERVER_HPP
