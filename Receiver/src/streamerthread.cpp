#include "streamerthread.hpp"

#include <unistd.h>
#include <QMutexLocker>
#include "commonconnection.hpp"
#include "../log/instrumentor.h"

StreamerThread::StreamerThread(QObject *parent)
    : m_address(QHostAddress::LocalHost), m_port(TCP_PORT) {
  m_quit = false;
}

void StreamerThread::run() {
  PROFILE_FUNCTION();
  socket = new QTcpSocket;
  socket->connectToHost(m_address, m_port);
  socket->write(new char[4]{1, 2, 3, 4});
  QMutexLocker locker(&mutex);
  QByteArray buffer;
  while (!m_quit) {
    if (socket->waitForReadyRead(3000)) {
      buffer.append(socket->readAll());
      msleep(350);
      emit newImageAvailabe(buffer);
      buffer.clear();
    }
  }
  socket = nullptr;
}

void StreamerThread::setAddressHost(const QString &str_address) {
  m_address = QHostAddress(str_address);
}

void StreamerThread::setAddressHost(const QHostAddress &address) {
  m_address = address;
}

void StreamerThread::setPortHost(const quint16 &port) { m_port = port; }

void StreamerThread::slotQuit() { m_quit = true; }

void StreamerThread::slotReconnect() { m_quit = false; }

StreamerThread::~StreamerThread() {
  if (socket) {
    if (socket->state() == QTcpSocket::ConnectedState) {
      socket->disconnect();
      socket->disconnectFromHost();
    }
    socket->deleteLater();
    socket = nullptr;
  }
}
