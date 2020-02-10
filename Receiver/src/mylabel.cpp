#include "mylabel.hpp"

MyLabel::MyLabel(QWidget *parent) : QLabel(parent) {}
MyLabel::~MyLabel() {}

// when the system calls setImage, we'll set the label's pixmap
void MyLabel::setImage(QImage image) {
  QPixmap pixmap = QPixmap::fromImage(image);
  int w = this->width();
  int h = this->height();
  setPixmap(pixmap.scaled(w, h, Qt::KeepAspectRatio));
}

void MyLabel::updatePixmap(QPixmap image) {
  int w = this->width();
  int h = this->height();
  setPixmap(image.scaled(w, h, Qt::KeepAspectRatio));
}
