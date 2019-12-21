#include "commonconnection.hpp"

#include <QDebug>
#include <QDir>
#include <QString>
#include <QTime>

#include "../log/logger.h"

MessageType identifies_message_type(const QString &header, const qint32 &size) {
#if LOGGER_SERVER || LOGGER_CLIENT
  LOG(DEBUG,
      "incoming message control through header identification:\n"
      "\t* message containing text if the header corresponds to the code UTF-8 "
      "'\\u001D' or the ASCII code %d\n"
      "\t* message containing images if the header corresponds to the code "
      "UTF-8 '\\u001E' or the ASCII code %d",
      GROUP_SEPARATOR_ASCII_CODE, RECORD_SEPARATOR_ASCII_CODE)
  qDebug() << "\tincoming message header: " << header << "\tsize: " << size
           << "\n";
#endif

  if (header == QString(GROUP_SEPARATOR_ASCII_CODE)) {
    return MessageType::Text;
  }

  else if (header == QString(RECORD_SEPARATOR_ASCII_CODE)) {
    return MessageType::Image;
  }
  return MessageType::Unknow;
}

#if TEST_IMAGE

QImage randomImage() {
  qsrand(QTime(0, 0, 0).secsTo(QTime::currentTime()));

  QDir dir("/Users/francesco/Desktop/landingzone/CiterX");
  dir.setFilter(QDir::Files);
  QFileInfoList entries = dir.entryInfoList();

  if (entries.size() == 0) {
    qDebug("No images to show!");
    return QImage();
  }
  qDebug() << entries.at(qrand() % entries.size()).absoluteFilePath();
  return QImage(entries.at(qrand() % entries.size()).absoluteFilePath());
}

#endif
