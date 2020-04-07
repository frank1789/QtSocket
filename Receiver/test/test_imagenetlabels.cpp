#include <memory>
#include <string>

#include "gtest/gtest.h"
#include "labels.hpp"

class ImagenetLabels : public ::testing::Test {
 protected:
  const std::string label_path = {
      "../build_debug/test/resources/imagenet_labels.txt"};
  std::unique_ptr<LabelDetection> label_{nullptr};

  void SetUp() {
    label_ = std::make_unique<LabelDetection>(label_path);
    label_->read();
  }

  void TearDown() {
    // code here will be called just after the TEST_F completes
    // ok to through exceptions from here if need be
  }

  const std::string getLabel(std::unordered_map<int, std::string> label,
                             int i) {
    std::unordered_map<int, std::string>::iterator it = label.find(i);
    return it->second;
  }

  const int getIndexLabel(std::unordered_map<int, std::string> label, int i) {
    std::unordered_map<int, std::string>::iterator it = label.find(i);
    return it->first;
  }
};