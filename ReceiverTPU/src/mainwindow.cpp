#include "mainwindow.hpp"

#include <QColor>
#include <QComboBox>
#include <QGridLayout>
#include <QGroupBox>
#include <QHBoxLayout>
#include <QImage>
#include <QPushButton>
#include <QRadioButton>
#include <QString>
#include <QVBoxLayout>

#include "../log/logger.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

  // init central widget
  QWidget *widget = new QWidget;
  setCentralWidget(widget);

  // init complete group
  auto m_group_all = new QGridLayout;

  // allocate image
  m_image = new QImage(640, 480, QImage::Format_RGB888);
  for (int i = 0; i < 640; i++) {
    for (int j = 0; j < 480; j++) {
      m_image->setPixel(i, j, qRgb(0, 0, 0));
    }
  }

  m_label = new MyLabel(this);

  // set minimum size
  m_label->setMinimumSize(640, 480);

  // load image
  m_label->setPixmap(QPixmap::fromImage(*m_image));

  client = new TcpClient();
  m_group_all->addWidget(m_label, 0, 0);
  m_group_all->addWidget(client, 0, 1);
  widget->setLayout(m_group_all);

  connect(client, &TcpClient::updatePixmap, [=](QPixmap img) {
    m_label->updatePixmap(img);
    emit updateImage(img);
  });
}

MainWindow::~MainWindow() {
  delete ui;
  delete client;
}

QGridLayout *MainWindow::create_label_preview() {
#if LOGGER_UI
  LOG(INFO, "make preview label ui.")
#endif
  // create horizontal layout
  auto m_group_label = new QGridLayout;
  return m_group_label;
}
