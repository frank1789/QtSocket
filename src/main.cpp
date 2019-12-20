#include "mainwindow.hpp"
#include "tcpclient.hpp"
#include "tcpserver.hpp"

#include <QApplication>
#include <QObject>
#include <QPointer>

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  QPointer<TcpServer> server = new TcpServer();
  QPointer<TcpClient> client = new TcpClient();
  server->show();
  client->show();
  return a.exec();
}
