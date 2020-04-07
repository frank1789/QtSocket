#ifndef LABEL_UTILS_HPP
#define LABEL_UTILS_HPP

#include <QFile>
#include <QObject>
#include <QString>
#include <QTextStream>
#include <fstream>
#include <functional>
#include <string>
#include <tuple>
#include <unordered_map>

#include "logger.h"

using callback_split = std::tuple<int, std::string> (*)(const QString &);

class LabelSplitter {
 public:
  static std::tuple<int, std::string> CocoLabel(const QString &str);
  static std::tuple<int, std::string> ImagenetLabel(const QString &str);
  static std::tuple<int, std::string> TensorflowLabel(const QString &str);
  static std::tuple<int, std::string> GenericLabel(const QString &str);
};

std::unordered_map<int, std::string> read_label_file(
    const std::string &file_path, callback_split split);

#endif  // LABEL_UTILS_HPP
