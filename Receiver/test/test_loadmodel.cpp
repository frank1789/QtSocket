#include <fstream>
#include <iostream>
#include <string>

#include "gtest/gtest.h"

inline bool exists_file(const std::string& name) {
  std::ifstream f(name.c_str());
  return f.good();
}

TEST(LoadFiles, LoadModel) {
  std::string model{"/Users/francesco/Documents/Project/tcpsocket/Receiver/build_debug/test/resources/detect.tflite"};
  EXPECT_TRUE(exists_file(model));
}

TEST(LoadFiles, LoadLabels) {
  std::string label{"/Users/francesco/Documents/Project/tcpsocket/Receiver/build_debug/test/resources/coco_labels.txt"};
  EXPECT_TRUE(exists_file(label));
}