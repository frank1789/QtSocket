#ifndef LABEL_UTILS_HPP
#define LABEL_UTILS_HPP

#include <QString>
#include <string>
#include <tuple>

#include "logger.h"

using callback_split = std::tuple<int, std::string> (*)(const QString &);

/**
 * @brief Class LabelSplitter collect static methods which allow to interpret
 * some files containing the labels used for the training of the neural model.
 *
 */
class LabelSplitter {
 public:
  /**
   * @brief reads a text file containing labels in COCO format and returns a
   * tuple containing index and label.
   *
   * @example coco_labels.txt
   * 0  person
   * 1  bicycle
   * 2  car
   * 3  motorcycle
   * 4  airplane
   * 5  bus
   * 6  train
   * 7  truck
   * 8  boat
   * 9  traffic light
   * 10  fire hydrant
   * ...
   *
   * @param str path to the file.
   * @return std::tuple<int, std::string> containing index and label.
   */
  static std::tuple<int, std::string> CocoLabel(const QString &str);

  /**
   * @brief reads a text file containing labels in Imagenet format and returns a
   * tuple containing index and label.
   *
   * @example imagenet_labels.txt
   * 0  background
   * 1  tench, Tinca tinca
   * 2  goldfish, Carassius auratus
   * 3  great white shark, white shark, man-eater, man-eating shark,
   * Carcharodon carcharias
   * 4  tiger shark, Galeocerdo cuvieri
   * 5  hammerhead, hammerhead shark
   * 6  electric ray, crampfish, numbfish, torpedo
   * 7  stingray
   * 8  cock
   * 9  hen
   * 10  ostrich, Struthio camelus
   * ...
   *
   * @param str path to the file.
   * @return std::tuple<int, std::string> containing index and label.
   */
  static std::tuple<int, std::string> ImagenetLabel(const QString &str);

  /**
   * @brief reads a text file containing labels in format and returns a tuple
   * containing index and label.
   *
   * @example labels.txt
   * 0:background
   * 1:tench, Tinca tinca
   * 2:goldfish, Carassius auratus
   * 3:great white shark, white shark, man-eater, man-eating shark, Carcharodon
   * carcharias
   * 4:tiger shark, Galeocerdo cuvieri
   * 5:hammerhead, hammerhead shark
   * 6:electric ray, crampfish, numbfish, torpedo
   * 7:stingray
   * 8:cock
   * 9:hen
   * 10:ostrich, Struthio camelus
   *
   * @param str path to the file.
   * @return std::tuple<int, std::string> containing index and label.
   */
  static std::tuple<int, std::string> GenericLabel(const QString &str);
};

#endif  // LABEL_UTILS_HPP
