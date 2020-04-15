#ifndef COMMONCONNECTION_HPP
#define COMMONCONNECTION_HPP

#include <QByteArray>
#include <QImage>
#include <QString>
#include <QTcpSocket>
#include <QUdpSocket>

#include "../log/logger.h"

constexpr int TCP_PORT{52693};
constexpr int TERMINATION_ASCII_CODE{23};
constexpr int RECORD_SEPARATOR_ASCII_CODE{30};
constexpr int GROUP_SEPARATOR_ASCII_CODE{29};

/**
 * @brief The MessageType is a strongly typed enum class representing the type
 * of message.
 * @enum mapper::MessageType
 */
enum class MessageType : quint8 {
  Text,   /**< is coded as quint8 of value 0 */
  Image,  /**< is coded as quint8 of value 1 */
  Unknow, /**< is coded as quint8 of value 2 */
};

/**
 * @brief identifies_message_type allows to identify the message from the
 * header.
 *
 * The function allows to identify the message from the header. Once the
 * QDatastream is obtained from the socket and the transition is started, the
 * header and dimensions, which represent the input parameters, are extracted.
 * Then the checking of incoming messages by identifying the header:
 * - message containing text if the header corresponds to the UTF-8 code
 * '\u001D' or to the ASCII code 29.
 * - message containing images if the header corresponds to the UTF-8 code
 * '\u001E' or to the ASCII code 30.
 *
 * @param[in] header string containing the message header.
 * @param[in] size message size expressed in bytes.
 * @return a message type as indicated by ::::MessageType.
 */
MessageType identifies_message_type(const QString &header, const qint32 &size);

/**
 * @brief send_message_text send the message.
 *
 * The function checks that the message is valid otherwise it returns.
 * If the message to be sent is valid, the buffer and the object containing the
 * stream are constructed. the message is composed of the header, then the size,
 * the text of the message.
 *
 * @param socket[in] socket required to send the buffer.
 * @param message[in] string containing the text message.
 */
template <typename T>
void send_message_text(T *socket, const QString &message) {
  // check image is not empty
  if (message.isNull()) {
#if LOGGER_CLIENT || LOGGER_SERVER
    LOG(ERROR, "image is not valid: %s", message.isNull() ? "true" : "false")
#endif
    return;
  }
  // prepare datastream
  QByteArray ba_message;
  QDataStream out(&ba_message, QIODevice::ReadWrite);
  out.setVersion(QDataStream::Qt_4_0);
  // serialize information
  out << QString(GROUP_SEPARATOR_ASCII_CODE)
      << static_cast<quint32>(ba_message.size()) << message;
  socket->write(ba_message);
#if LOGGER_CLIENT || LOGGER_SERVER
  LOG(TRACE, "sending text")
  qDebug() << "\theader: " << QString(GROUP_SEPARATOR_ASCII_CODE)
           << "\tsize: " << static_cast<quint32>(ba_message.size());
  qDebug() << "\t" << message << "\n";
#endif
}

/**
 * @brief send_message_image send the message.
 *
 * The function checks that the message is valid otherwise it returns.
 * If the message to be sent is valid, the buffer and the object containing the
 * stream are constructed. the message is composed of the header, then the size,
 * the image.
 *
 * @param socket[in] socket required to send the buffer.
 * @param image[in] containing the picture.
 */
template <typename T>
void send_message_image(T *socket, const QImage &image) {
  // check image is not null
  if (image.isNull()) {
#if LOGGER_CLIENT || LOGGER_SERVER
    LOG(ERROR, "image is not valid: %s", image.isNull() ? "true" : "false")
#endif
    return;
  }
  // prepare datastream
  QByteArray ba_message;
  QDataStream out(&ba_message, QIODevice::ReadWrite);
  out.setVersion(QDataStream::Qt_4_0);
  // serialize information
  out << QString(RECORD_SEPARATOR_ASCII_CODE)
      << static_cast<quint32>(ba_message.size()) << image;
  socket->write(ba_message);
#if LOGGER_CLIENT || LOGGER_SERVER
  LOG(DEBUG, "sending image:")
  qDebug() << "\theader: " << QString(RECORD_SEPARATOR_ASCII_CODE)
           << "\tsize:" << static_cast<quint32>(ba_message.size()) << "\n";
#endif
}

#if TEST_IMAGE
extern QImage randomImage();
#endif

#endif  // COMMONCONNECTION_HPP
