#ifndef TCPCLIENT_HPP
#define TCPCLIENT_HPP

#include <QWidget>
#include <QtNetwork>

#include "streamerthread.hpp"

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

/**
 * @brief TcpClient class that expand QWidget and permit manage the connection
 * status on UI.
 *
 */
class TcpClient : public QWidget {
  Q_OBJECT

 public:
 /**
  * @brief Construct a new Tcp Client object.
  * 
  * @param parent QWidget object, default = nullptr.
  */
  explicit TcpClient(QWidget *parent = nullptr);

 public slots:

 signals:
  void updateImage(QImage);
  void updateImage(QPixmap);

 private slots:
  void imageAvailabe(QByteArray baImage);

  /**
   * @brief connectToServer slot.
   *
   * Update connection status when click button and connect to remote sender.
   */
  void connectedToServer();

  /**
   * @brief onDisconnectClicked slot.
   *
   * Update connection status when click button and disconnect to remote sender.
   */
  void onDisconnectClicked();

  /**
   * @brief sessionOpened slot.
   *
   * Update connection status retrun message to user.
   */
  void sessionOpened();

  /**
   * @brief display erro from socket.
   *
   * @param socketError
   */
  void displayError(QAbstractSocket::SocketError socketError);

  /**
   * @brief enable button when port is filled.
   *
   */
  void enableConnectButton();

  /**
   * @brief onConnectClicked slot
   *
   * Update message when clicked button.
   */
  void onConnectClicked();

 private:
  /**
   * @brief Create a Information Group object.
   *
   * @return QGridLayout* layout.
   */
  QGroupBox *createInformationGroup();

  /**
   * @brief Create a Log Group object.
   *
   * @return QGroupBox* widget.
   */
  QGroupBox *createLogGroup();

  /**
   * @brief update the UI.
   *
   * @param state socket status.
   */
  void updateGui(QAbstractSocket::SocketState state);

  // ui variables
  QLineEdit *m_port_linedit{nullptr};
  QLineEdit *m_user_linedit{nullptr};
  QTextEdit *m_log_text{nullptr};

  QComboBox *hostCombo{nullptr};
  QPushButton *connectButton{nullptr};
  QPushButton *disconnectButton{nullptr};

  // network variables
  StreamerThread *m_stream{nullptr};
  QNetworkSession *networkSession{nullptr};
};

#endif  // TCPCLIENT_HPP
