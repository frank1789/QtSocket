#include <memory>
#include <string>

#include "gtest/gtest.h"
#include "labels.hpp"

class LabelsTensorFlow : public ::testing::Test {
 protected:
  const std::string label_path = {"../build_debug/test/resources/label_map.pbtxt"};
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

TEST_F(LabelsTensorFlow, Circle) {
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 1), 1);
  EXPECT_EQ(getLabel(label_->getLabels(), 1), "Circle Red-orange-Circular");
}

TEST_F(LabelsTensorFlow, Circle2) {
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 2), 2);
  EXPECT_EQ(getLabel(label_->getLabels(), 0), "Green Square-green-Square");
}

TEST_F(LabelsTensorFlow, Square) {
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 3), 3);
  EXPECT_EQ(getLabel(label_->getLabels(), 3), "Circle Other-other-Circular");
}