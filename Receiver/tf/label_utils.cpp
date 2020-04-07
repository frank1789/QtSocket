#include "label_utils.hpp"

#include <QRegularExpression>
#include <regex>

#include "logger.h"

std::tuple<int, std::string> LabelSplitter::CocoLabel(const QString &str) {
  QString id{""};
  QString label{""};
  QString accessor{""};
  QRegularExpression re;
  re.setPattern(
      "(?<id>[0-9]\\d*)\\s*(?<label>[A-z]\\w*)?\\s+(?<accessor>[A-z]\\w+)");
  QRegularExpressionMatch match = re.match(str);
  if (match.hasMatch()) {
    id = match.captured("id");
    label = match.captured("label");
    accessor = match.captured("accessor");
    if (!accessor.isEmpty() && accessor != "") {
      label = label + " " + accessor;
    }
  }
  label = label.trimmed();
  return std::make_tuple(id.toUInt(), label.toStdString());
}

std::tuple<int, std::string> LabelSplitter::ImagenetLabel(const QString &str) {
  QString id;
  QString label;
  QString accessor;
  QString accessor2;
  QRegularExpression re;
  re.setPattern(
      "(?<id>[0-9]\\d*)\\s*(?<label>[A-z]\\w*)?\\s+(?<accessor>[A-z]\\w*)?\\s+("
      "?<accessor2>[A-z]\\w*)");
  QRegularExpressionMatch match = re.match(str);
  if (match.hasMatch()) {
    id = match.captured("id");
    label = match.captured("label");
    accessor = match.captured("accessor");
    accessor2 = match.captured("accessor2");
    if (!accessor.isEmpty()) {
      label += " " + accessor;
    }
    if (!accessor2.isEmpty()) {
      label += " " + accessor2;
    }
  }
  label = label.trimmed();
  return std::make_tuple(id.toUInt(), label.toStdString());
}

std::tuple<int, std::string> LabelSplitter::GenericLabel(const QString &str) {
  QString id;
  QString label;
  QRegularExpression re("(?P<id>\\d+)\\W(?P<label>(.*))");
  QRegularExpressionMatch match = re.match(str);
  if (match.hasMatch()) {
    id = match.captured("id");
    label = match.captured("label");
    label = label.trimmed();
  }
  return std::make_tuple(id.toUInt(), label.toStdString());
}