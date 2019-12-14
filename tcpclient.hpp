#ifndef TCPCLIENT_HPP
#define TCPCLIENT_HPP

#include <QWidget>
#include <QtNetwork>

QT_BEGIN_NAMESPACE
class QComboBox;
class QLabel;
class QTextEdit;
class QLineEdit;
class QPushButton;
class QTcpSocket;
class QNetworkSession;
class QGroupBox;
class QImage;
QT_END_NAMESPACE

class TcpClient : public QWidget {
  Q_OBJECT

 public:
  explicit TcpClient(QWidget *parent = nullptr);

 signals:
  void updateImage(QImage image);

 private slots:
  /**
   * @brief
   *
   */
  void sendTestMessageStream();

  /**
   * @brief
   *
   */
  void connectedToServer();

  /**
   * @brief
   *
   */
  void onDisconnectClicked();

  /**
   * @brief
   *
   */
  void sessionOpened();

  /**
   * @brief
   *
   * @param socketError
   */
  void displayError(QAbstractSocket::SocketError socketError);

  /**
   * @brief
   *
   */
  void enableConnectButton();

  /**
   * @brief
   *
   */
  void readFortune();

  /**
   * @brief
   *
   */
  void readyRead();

  /**
   * @brief
   *
   */
  void onConnectClicked();

  /**
   * @brief
   *
   */
  void disconnectByServer();

 private:
  /**
   * @brief Create a Information Group object
   *
   * @return QGroupBox*
   */
  QGroupBox *createInformationGroup();

  /**
   * @brief Create a Log Group object
   *
   * @return QGroupBox*
   */
  QGroupBox *createLogGroup();

  /**
   * @brief
   *
   * @param state
   */
  void updateGui(QAbstractSocket::SocketState state);

  // ui variables
  QLineEdit *m_port_linedit{nullptr};
  QLineEdit *m_user_linedit{nullptr};
  QTextEdit *m_log_text{nullptr};

  QComboBox *hostCombo{nullptr};
  QPushButton *connectButton{nullptr};
  QPushButton *disconnectButton{nullptr};

  QString currentFortune;

  // network variables
  QTcpSocket *m_tcp_socket{nullptr};
  QDataStream m_data;
  QNetworkSession *networkSession{nullptr};

  // data exchanged
  QByteArray receive_data;

#if TEST_IMAGE
 private slots:
  void sendImageMessage();
#endif
};

#endif  // TCPCLIENT_HPP
