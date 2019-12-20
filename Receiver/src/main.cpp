#include "mainwindow.hpp"
#include "tcpclient.hpp"

#include <QApplication>
#include <QObject>
#include <QPointer>

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  MainWindow w;
  w.show();
  return a.exec();
}
