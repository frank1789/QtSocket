#include "labels.hpp"

#include <QFile>
#include <QRegularExpression>
#include <QString>
#include <QTextStream>
#include <regex>

#include "logger.h"

LabelDetection::LabelDetection(const QString &path) : m_filename(path) {
  if (path.endsWith(".txt")) {
    m_process_line = LabelSplitter::coco_label_split;
  } else if (path.endsWith(".pbtxt")) {
    m_process_line = LabelSplitter::tensorflow_label_map;
  } else {
    LOG(ERROR, "unsupported label map %s", path.toStdString().c_str())
  }
}

LabelDetection::LabelDetection(const QString &path)
    : m_filename(QString::fromStdString(path)) {
  if (path.endsWith(".txt")) {
    m_process_line = LabelSplitter::coco_label_split;
  } else if (path.endsWith(".pbtxt")) {
    m_process_line = LabelSplitter::tensorflow_label_map;
  } else {
    LOG(ERROR, "unsupported label map %s", path.toStdString().c_str())
  }
}

std::unordered_map<int, std::string> LabelDetection::getLabels() {
  return m_labels;
}

void LabelDetection::read() {
  QFile file(m_filename);
  if (!file.open(QIODevice::ReadOnly)) {
    LOG(ERROR, "file not exist %s", m_filename.toStdString().c_str())
    return;
  }

  QTextStream in(&file);
  while (!in.atEnd()) {
    QString line = in.readLine();
    auto [label_id, label_name] = m_process_line(line);
    m_labels[label_id] = label_name;
  }
}
