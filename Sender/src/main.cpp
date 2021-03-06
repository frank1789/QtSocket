#include "mainwindow.hpp"
#include "tcpclient.hpp"

#include <QApplication>
#include <QPointer>

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  QPointer<TcpClient> client = new TcpClient();
  client->show();
  return a.exec();
}
