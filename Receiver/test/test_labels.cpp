#include <memory>
#include <string>

#include "gtest/gtest.h"
#include "labels.hpp"

class CocoLabels : public ::testing::Test {
 protected:
  const std::string label_path = {
      "../build_debug/test/resources/coco_labels.txt"};
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

TEST_F(CocoLabels, allclass) {
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 0), 0);
  EXPECT_EQ(getLabel(label_->getLabels(), 0), "person");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 1), 1);
  EXPECT_EQ(getLabel(label_->getLabels(), 1), "bicycle");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 2), 2);
  EXPECT_EQ(getLabel(label_->getLabels(), 2), "car");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 3), 3);
  EXPECT_EQ(getLabel(label_->getLabels(), 3), "motorcycle");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 4), 4);
  EXPECT_EQ(getLabel(label_->getLabels(), 4), "airplane");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 5), 5);
  EXPECT_EQ(getLabel(label_->getLabels(), 5), "bus");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 6), 6);
  EXPECT_EQ(getLabel(label_->getLabels(), 6), "train");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 7), 7);
  EXPECT_EQ(getLabel(label_->getLabels(), 7), "truck");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 8), 8);
  EXPECT_EQ(getLabel(label_->getLabels(), 8), "boat");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 9), 9);
  EXPECT_EQ(getLabel(label_->getLabels(), 9), "traffic light");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 10), 10);
  EXPECT_EQ(getLabel(label_->getLabels(), 10), "fire hydrant");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 12), 12);
  EXPECT_EQ(getLabel(label_->getLabels(), 12), "stop sign");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 13), 13);
  EXPECT_EQ(getLabel(label_->getLabels(), 13), "parking meter");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 14), 14);
  EXPECT_EQ(getLabel(label_->getLabels(), 14), "bench");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 15), 15);
  EXPECT_EQ(getLabel(label_->getLabels(), 15), "bird");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 16), 16);
  EXPECT_EQ(getLabel(label_->getLabels(), 16), "cat");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 17), 17);
  EXPECT_EQ(getLabel(label_->getLabels(), 17), "dog");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 18), 18);
  EXPECT_EQ(getLabel(label_->getLabels(), 18), "horse");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 19), 19);
  EXPECT_EQ(getLabel(label_->getLabels(), 19), "sheep");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 20), 20);
  EXPECT_EQ(getLabel(label_->getLabels(), 20), "cow");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 21), 21);
  EXPECT_EQ(getLabel(label_->getLabels(), 21), "elephant");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 22), 22);
  EXPECT_EQ(getLabel(label_->getLabels(), 22), "bear");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 23), 23);
  EXPECT_EQ(getLabel(label_->getLabels(), 23), "zebra");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 24), 24);
  EXPECT_EQ(getLabel(label_->getLabels(), 24), "giraffe");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 26), 26);
  EXPECT_EQ(getLabel(label_->getLabels(), 26), "backpack");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 27), 27);
  EXPECT_EQ(getLabel(label_->getLabels(), 27), "umbrella");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 30), 30);
  EXPECT_EQ(getLabel(label_->getLabels(), 30), "handbag");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 31), 31);
  EXPECT_EQ(getLabel(label_->getLabels(), 31), "tie");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 32), 32);
  EXPECT_EQ(getLabel(label_->getLabels(), 32), "suitcase");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 33), 33);
  EXPECT_EQ(getLabel(label_->getLabels(), 33), "frisbee");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 34), 34);
  EXPECT_EQ(getLabel(label_->getLabels(), 34), "skis");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 35), 35);
  EXPECT_EQ(getLabel(label_->getLabels(), 35), "snowboard");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 36), 36);
  EXPECT_EQ(getLabel(label_->getLabels(), 36), "sports ball");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 37), 37);
  EXPECT_EQ(getLabel(label_->getLabels(), 37), "kite");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 38), 38);
  EXPECT_EQ(getLabel(label_->getLabels(), 38), "baseball bat");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 39), 39);
  EXPECT_EQ(getLabel(label_->getLabels(), 39), "baseball glove");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 40), 40);
  EXPECT_EQ(getLabel(label_->getLabels(), 40), "skateboard");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 41), 41);
  EXPECT_EQ(getLabel(label_->getLabels(), 41), "surfboard");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 42), 42);
  EXPECT_EQ(getLabel(label_->getLabels(), 42), "tennis racket");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 43), 43);
  EXPECT_EQ(getLabel(label_->getLabels(), 43), "bottle");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 45), 45);
  EXPECT_EQ(getLabel(label_->getLabels(), 45), "wine glass");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 46), 46);
  EXPECT_EQ(getLabel(label_->getLabels(), 46), "cup");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 47), 47);
  EXPECT_EQ(getLabel(label_->getLabels(), 47), "fork");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 48), 48);
  EXPECT_EQ(getLabel(label_->getLabels(), 48), "knife");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 49), 49);
  EXPECT_EQ(getLabel(label_->getLabels(), 49), "spoon");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 50), 50);
  EXPECT_EQ(getLabel(label_->getLabels(), 50), "bowl");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 51), 51);
  EXPECT_EQ(getLabel(label_->getLabels(), 51), "banana");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 52), 52);
  EXPECT_EQ(getLabel(label_->getLabels(), 52), "apple");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 53), 53);
  EXPECT_EQ(getLabel(label_->getLabels(), 53), "sandwich");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 54), 54);
  EXPECT_EQ(getLabel(label_->getLabels(), 54), "orange");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 55), 55);
  EXPECT_EQ(getLabel(label_->getLabels(), 55), "broccoli");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 56), 56);
  EXPECT_EQ(getLabel(label_->getLabels(), 56), "carrot");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 57), 57);
  EXPECT_EQ(getLabel(label_->getLabels(), 57), "hot dog");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 58), 58);
  EXPECT_EQ(getLabel(label_->getLabels(), 58), "pizza");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 59), 59);
  EXPECT_EQ(getLabel(label_->getLabels(), 59), "donut");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 60), 60);
  EXPECT_EQ(getLabel(label_->getLabels(), 60), "cake");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 61), 61);
  EXPECT_EQ(getLabel(label_->getLabels(), 61), "chair");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 62), 62);
  EXPECT_EQ(getLabel(label_->getLabels(), 62), "couch");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 63), 63);
  EXPECT_EQ(getLabel(label_->getLabels(), 63), "potted plant");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 64), 64);
  EXPECT_EQ(getLabel(label_->getLabels(), 64), "bed");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 66), 66);
  EXPECT_EQ(getLabel(label_->getLabels(), 66), "dining table");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 69), 69);
  EXPECT_EQ(getLabel(label_->getLabels(), 69), "toilet");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 71), 71);
  EXPECT_EQ(getLabel(label_->getLabels(), 71), "tv");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 72), 72);
  EXPECT_EQ(getLabel(label_->getLabels(), 72), "laptop");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 73), 73);
  EXPECT_EQ(getLabel(label_->getLabels(), 73), "mouse");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 74), 74);
  EXPECT_EQ(getLabel(label_->getLabels(), 74), "remote");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 75), 75);
  EXPECT_EQ(getLabel(label_->getLabels(), 75), "keyboard");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 76), 76);
  EXPECT_EQ(getLabel(label_->getLabels(), 76), "cell phone");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 77), 77);
  EXPECT_EQ(getLabel(label_->getLabels(), 77), "microwave");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 78), 78);
  EXPECT_EQ(getLabel(label_->getLabels(), 78), "oven");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 79), 79);
  EXPECT_EQ(getLabel(label_->getLabels(), 79), "toaster");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 80), 80);
  EXPECT_EQ(getLabel(label_->getLabels(), 80), "sink");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 81), 81);
  EXPECT_EQ(getLabel(label_->getLabels(), 81), "refrigerator");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 83), 83);
  EXPECT_EQ(getLabel(label_->getLabels(), 83), "book");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 84), 84);
  EXPECT_EQ(getLabel(label_->getLabels(), 84), "clock");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 85), 85);
  EXPECT_EQ(getLabel(label_->getLabels(), 85), "vase");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 86), 86);
  EXPECT_EQ(getLabel(label_->getLabels(), 86), "scissors");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 87), 87);
  EXPECT_EQ(getLabel(label_->getLabels(), 87), "teddy bear");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 88), 88);
  EXPECT_EQ(getLabel(label_->getLabels(), 88), "hair drier");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 89), 89);
  EXPECT_EQ(getLabel(label_->getLabels(), 89), "toothbrush");
}
