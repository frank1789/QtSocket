#ifndef UTIL_LABEL_IMAGE_HPP
#define UTIL_LABEL_IMAGE_HPP

#include <fstream>
#include <string>
#include <tuple>
#include <unordered_map>

class QString;

using callback_split = std::tuple<int, std::string> (*)(const QString&);

class LabelSplitter {
 public:
  static std::tuple<int, std::string> coco_label_split(const QString& str);
  static std::tuple<int, std::string> imagenet_label_split(const QString& str);
  static std::tuple<int, std::string> tensorflow_label_map(const QString& str);
};

std::unordered_map<int, std::string> read_label_file(
    const std::string& file_path, callback_split split);

class LabelObjectDetection {
 public:
  LabelObjectDetection();

  std::unordered_map<int, std::string> getLabels();
};

#endif  // UTIL_LABEL_IMAGE_HPP
