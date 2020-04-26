#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <QPainter>

#include "mylabel.hpp"
#include "tcpclient.hpp"
#include "object_detection.hpp"

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
class QRectF;
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  /**
   * @brief Construct a new Main Window object.
   * 
   * @param parent QWidget default value parent.
   */
  MainWindow(QWidget *parent = nullptr);

  /**
   * @brief Destroy the Main Window object.
   * 
   */
  ~MainWindow();

 public slots:
  void boxDetection(BoxDetection result);

 signals:
  // void updateImage(QImage);
  void updateImage(QPixmap);
  void updateBoxDetection(BoxDetection);

 private:
  /**
   * @brief Create a label preview object.
   *
   * function that builds the layout of the UI.
   *
   * @return QGridLayout* layout.
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
