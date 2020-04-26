#include "mylabel.hpp"

#include "instrumentor.h"

MyLabel::MyLabel(QWidget *parent) : QLabel(parent) {}

void MyLabel::setImage(QImage image) {
  PROFILE_FUNCTION();
  QPixmap pixmap = QPixmap::fromImage(image);
  setPixmap(
      pixmap.scaled(this->width(), this->height(), Qt::KeepAspectRatio));
}

void MyLabel::updatePixmap(QPixmap image) {
  PROFILE_FUNCTION();
  setPixmap(
      image.scaled(this->width(), this->height(), Qt::KeepAspectRatio));
}
