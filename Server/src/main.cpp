#include <QApplication>
#include <QPointer>

#include "tcpserver.hpp"


int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  QPointer<TcpServer> server = new TcpServer();
  server->show();
  return a.exec();
}
