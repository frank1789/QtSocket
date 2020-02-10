#ifndef TCPCLIENT_HPP
#define TCPCLIENT_HPP

#include <QWidget>

QT_BEGIN_NAMESPACE
class QComboBox;
class QLabel;
class QPushButton;
class QGroupBox;
class QGridLayout;
QT_END_NAMESPACE

class TcpClient : public QWidget {
  Q_OBJECT

  QGroupBox *createLogGroup();

 public:
  explicit TcpClient(QWidget *parent = nullptr);
  /**
   * @brief Create a Information Group object
   *
   * @return QGridLayout* layout.
   */
  QGridLayout *createInformationGroup();

  /**
   * @brief search which address and port the client should connect to.
   *
   * In then displays the port QTcpServer picked in a label, so that user knows
   * which port the client should connect to.
   *
   * @return QString the address which port the client should connect to.
   */
  QString findIpAddress();

 public slots:
  void onClientDisonnect();
  void onClientConnect();

 private:
  unsigned int m_device_count;
  // interface elements
  QLabel *connection_label{nullptr};
  QLabel *port_label{nullptr};
  QLabel *m_connection_address{nullptr};
  QLabel *m_port_number{nullptr};
  QLabel *m_device_label{nullptr};
};

#endif  // TCPCLIENT_HPP
