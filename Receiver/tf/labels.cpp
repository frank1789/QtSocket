#include "labels.hpp"

#include <QFile>
#include <QRegularExpression>
#include <QString>
#include <QTextStream>
#include <regex>

#include "label_utils.hpp"
#include "logger.h"

LabelDetection::LabelDetection(const QString &path) : m_filename(path) {
  IdentifyTypeFile();
}

LabelDetection::LabelDetection(const std::string &path)
    : m_filename(QString::fromStdString(path)) {
      IdentifyTypeFile();
    }

void LabelDetection::IdentifyTypeFile() {
  if (m_filename.endsWith(".txt") && m_filename.contains("imagenet")) {
    m_process_line = LabelSplitter::ImagenetLabel;
  }

  else if (m_filename.endsWith(".txt") && m_filename.contains("coco")) {
    m_process_line = LabelSplitter::CocoLabel;
  }
  
  else if (m_filename.endsWith(".txt") && !m_filename.contains("imagenet") && !m_filename.contains("coco")) {
    m_process_line = LabelSplitter::GenericLabel;
  }

  else if (m_filename.endsWith(".pbtxt")) {
    m_process_line = LabelSplitter::TensorflowLabel;
  } else {
    LOG(FATAL, "file unsupported")
    std::abort();
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
