#include <fstream>
#include <iostream>
#include <string>

#include "gtest/gtest.h"

inline bool exists_file(const std::string& name) {
  std::ifstream f(name.c_str());
  return f.good();
}

TEST(LoadFiles, LoadModel) {
  std::string model{"../build_debug/test/resources/detect.tflite"};
  EXPECT_TRUE(exists_file(model));
}

TEST(LoadFiles, LoadModelMobileNet) {
  std::string model{
      "../build_debug/test/resources/mobilenet_v1_1.0_224.tflite"};
  EXPECT_TRUE(exists_file(model));
}

TEST(LoadFiles, LoadCocoLabels) {
  std::string label{"../build_debug/test/resources/coco_labels.txt"};
  EXPECT_TRUE(exists_file(label));
}

TEST(LoadFiles, LoadLabels) {
  std::string label{"../build_debug/test/resources/labels.txt"};
  EXPECT_TRUE(exists_file(label));
}
