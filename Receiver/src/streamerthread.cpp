#include "streamerthread.hpp"

#include <unistd.h>

StreamerThread::StreamerThread(QObject *parent) : socket(new QTcpSocket()) {
  m_quit = false;
}

void StreamerThread::run() {
  //  socket->connectToHost("192.168.1.11", 5555);
  //  socket->write(new char[4]{1, 2, 3, 4});
  QByteArray buffer;
  while (m_quit == false) {
    if (socket->waitForReadyRead(3000)) {
      buffer.append(socket->readAll());
      emit newImageAvailabe(buffer);
      msleep(100);
      buffer.clear();
    }
  }
}

void StreamerThread::slotQuit() { m_quit = true; }
