#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <QPainter>

#include "mylabel.hpp"
#include "tcpclient.hpp"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}

class QComboBox;
class QGroupBox;
class QGridLayout;
class QHBoxLayout;
class QVBoxLayout;
class QImage;
class QPushButton;
class QRadioButton;
class QString;
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

 signals:
  void update_rgb_image(QImage);

 private:
  /**
   * @brief Create a label preview object.
   *
   * function that builds the layout of the UI.
   *
   * @return QGridLayout* [out] layout.
   */
  QGridLayout *create_label_preview();

  Ui::MainWindow *ui;

  // image placeholder
  QImage *m_image{nullptr};

  // label's placeholder
  MyLabel *m_label{nullptr};

  // socket client layout
  TcpClient *client{nullptr};
};
#endif  // MAINWINDOW_HPP
