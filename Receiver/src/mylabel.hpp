#ifndef MY_LABEL_HPP
#define MY_LABEL_HPP

#include <QLabel>
#include <QWidget>
#include <QtCore>

/**
 * @brief Class MyLabel extend QLabel to give it an extra slot, setImage because we
 * can't pass a QPixmap from our thread so we have to pass a QImage and turn the
 * QImage into a QPixmap before display in QLabel.
 */
class MyLabel : public QLabel {
  Q_OBJECT

 public:
  /**
   * @brief Construct a new My Label object.
   *
   * @param parent QWidget object.
   */
  MyLabel(QWidget *parent = nullptr);

  /**
   * @brief Destroy the My Label object.
   */
  ~MyLabel() = default;

 public slots:
  /**
   * @brief SetImage slot
   *
   * This method updates the image in the QLabel, then
   * scale the image to the size required by the QLabel.
   *
   * @param image QImage object.
   */
  void setImage(QImage image);

  /**
   * @brief SetImage slot
   *
   * This method updates the image in the QLabel, then
   * scale the image to the size required by the QLabel.
   *
   * @param image QPixmap object.
   */
  void setImage(QPixmap image);
};

#endif  // MY_LABEL_HPP
