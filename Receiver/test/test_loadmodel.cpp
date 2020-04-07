#include <fstream>
#include <iostream>
#include <string>

#include "gtest/gtest.h"
#include "labels.hpp"

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

std::string write_dummy_file(const std::string &param) {
  const std::string filename{"../build_debug/test/resources/"};
  const std::string input{"Hello world!"};
  std::ofstream out(filename + param);
  for (auto i = 0; i < 10; ++i) {
    out << input;
    out << "\n";
  }
  out.close();
  return filename;
}

TEST(LoadFiles, ErrorFiles) {
  const std::string label_path = write_dummy_file("false.rtf");
  std::unique_ptr<LabelDetection> label_{nullptr};
  label_ = std::make_unique<LabelDetection>(label_path);
  ASSERT_DEATH(label_->read();, ".*");
}

TEST(LoadFiles, EmptyFiles) {
  const std::string label_path = write_dummy_file("empty.txt");
  std::unique_ptr<LabelDetection> label_{nullptr};
  label_ = std::make_unique<LabelDetection>(label_path);
  EXPECT_DEATH(label_->read();, ".*");
}
