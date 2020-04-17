#include <memory>

#include "gtest/gtest.h"
#include "labels.hpp"
#include "test_label_function.hpp"

TEST(Labels, IndexNumberCoco) {
  const std::string label_path = {
      "../build_debug/test/resources/coco_labels.txt"};
  auto label_ = std::make_unique<LabelDetection>(label_path);
  label_->read();
  auto num_lab = label_->getLabels().size();
  EXPECT_EQ(num_lab, 80);
}

TEST(Labels, CocoBigObject) {
  const std::string label_path = {
      "../build_debug/test/resources/coco_labels.txt"};
  auto label_ = std::make_unique<LabelDetection>(label_path);
  label_->read();
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 1), 1);
  EXPECT_EQ(getLabel(label_->getLabels(), 1), "person");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 2), 2);
  EXPECT_EQ(getLabel(label_->getLabels(), 2), "bicycle");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 3), 3);
  EXPECT_EQ(getLabel(label_->getLabels(), 3), "car");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 4), 4);
  EXPECT_EQ(getLabel(label_->getLabels(), 4), "motorcycle");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 5), 5);
  EXPECT_EQ(getLabel(label_->getLabels(), 5), "airplane");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 6), 6);
  EXPECT_EQ(getLabel(label_->getLabels(), 6), "bus");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 7), 7);
  EXPECT_EQ(getLabel(label_->getLabels(), 7), "train");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 8), 8);
  EXPECT_EQ(getLabel(label_->getLabels(), 8), "truck");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 9), 9);
  EXPECT_EQ(getLabel(label_->getLabels(), 9), "boat");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 10), 10);
  EXPECT_EQ(getLabel(label_->getLabels(), 10), "traffic light");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 11), 11);
  EXPECT_EQ(getLabel(label_->getLabels(), 11), "fire hydrant");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 13), 13);
  EXPECT_EQ(getLabel(label_->getLabels(), 13), "stop sign");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 14), 14);
  EXPECT_EQ(getLabel(label_->getLabels(), 14), "parking meter");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 15), 15);
  EXPECT_EQ(getLabel(label_->getLabels(), 15), "bench");
}

TEST(Labels, CocoAnimals) {
  const std::string label_path = {
      "../build_debug/test/resources/coco_labels.txt"};
  auto label_ = std::make_unique<LabelDetection>(label_path);
  label_->read();
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 16), 16);
  EXPECT_EQ(getLabel(label_->getLabels(), 16), "bird");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 17), 17);
  EXPECT_EQ(getLabel(label_->getLabels(), 17), "cat");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 18), 18);
  EXPECT_EQ(getLabel(label_->getLabels(), 18), "dog");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 19), 19);
  EXPECT_EQ(getLabel(label_->getLabels(), 19), "horse");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 20), 20);
  EXPECT_EQ(getLabel(label_->getLabels(), 20), "sheep");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 21), 21);
  EXPECT_EQ(getLabel(label_->getLabels(), 21), "cow");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 22), 22);
  EXPECT_EQ(getLabel(label_->getLabels(), 22), "elephant");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 23), 23);
  EXPECT_EQ(getLabel(label_->getLabels(), 23), "bear");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 24), 24);
  EXPECT_EQ(getLabel(label_->getLabels(), 24), "zebra");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 25), 25);
  EXPECT_EQ(getLabel(label_->getLabels(), 25), "giraffe");
}

TEST(Labels, CocoObjectAtHome) {
  const std::string label_path = {
      "../build_debug/test/resources/coco_labels.txt"};
  auto label_ = std::make_unique<LabelDetection>(label_path);
  label_->read();
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 27), 27);
  EXPECT_EQ(getLabel(label_->getLabels(), 27), "backpack");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 28), 28);
  EXPECT_EQ(getLabel(label_->getLabels(), 28), "umbrella");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 31), 31);
  EXPECT_EQ(getLabel(label_->getLabels(), 31), "handbag");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 32), 32);
  EXPECT_EQ(getLabel(label_->getLabels(), 32), "tie");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 33), 33);
  EXPECT_EQ(getLabel(label_->getLabels(), 33), "suitcase");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 34), 34);
  EXPECT_EQ(getLabel(label_->getLabels(), 34), "frisbee");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 35), 35);
  EXPECT_EQ(getLabel(label_->getLabels(), 35), "skis");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 36), 36);
  EXPECT_EQ(getLabel(label_->getLabels(), 36), "snowboard");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 37), 37);
  EXPECT_EQ(getLabel(label_->getLabels(), 37), "sports ball");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 38), 38);
  EXPECT_EQ(getLabel(label_->getLabels(), 38), "kite");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 39), 39);
  EXPECT_EQ(getLabel(label_->getLabels(), 39), "baseball bat");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 40), 40);
  EXPECT_EQ(getLabel(label_->getLabels(), 40), "baseball glove");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 41), 41);
  EXPECT_EQ(getLabel(label_->getLabels(), 41), "skateboard");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 42), 42);
  EXPECT_EQ(getLabel(label_->getLabels(), 42), "surfboard");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 43), 43);
  EXPECT_EQ(getLabel(label_->getLabels(), 43), "tennis racket");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 44), 44);
  EXPECT_EQ(getLabel(label_->getLabels(), 44), "bottle");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 46), 46);
  EXPECT_EQ(getLabel(label_->getLabels(), 46), "wine glass");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 47), 47);
  EXPECT_EQ(getLabel(label_->getLabels(), 47), "cup");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 48), 48);
  EXPECT_EQ(getLabel(label_->getLabels(), 48), "fork");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 49), 49);
  EXPECT_EQ(getLabel(label_->getLabels(), 49), "knife");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 50), 50);
  EXPECT_EQ(getLabel(label_->getLabels(), 50), "spoon");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 51), 51);
  EXPECT_EQ(getLabel(label_->getLabels(), 51), "bowl");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 52), 52);
  EXPECT_EQ(getLabel(label_->getLabels(), 52), "banana");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 53), 53);
  EXPECT_EQ(getLabel(label_->getLabels(), 53), "apple");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 54), 54);
  EXPECT_EQ(getLabel(label_->getLabels(), 54), "sandwich");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 55), 55);
  EXPECT_EQ(getLabel(label_->getLabels(), 55), "orange");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 56), 56);
  EXPECT_EQ(getLabel(label_->getLabels(), 56), "broccoli");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 57), 57);
  EXPECT_EQ(getLabel(label_->getLabels(), 57), "carrot");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 58), 58);
  EXPECT_EQ(getLabel(label_->getLabels(), 58), "hot dog");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 59), 59);
  EXPECT_EQ(getLabel(label_->getLabels(), 59), "pizza");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 60), 60);
  EXPECT_EQ(getLabel(label_->getLabels(), 60), "donut");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 61), 61);
  EXPECT_EQ(getLabel(label_->getLabels(), 61), "cake");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 62), 62);
  EXPECT_EQ(getLabel(label_->getLabels(), 62), "chair");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 63), 63);
  EXPECT_EQ(getLabel(label_->getLabels(), 63), "couch");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 64), 64);
  EXPECT_EQ(getLabel(label_->getLabels(), 64), "potted plant");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 65), 65);
  EXPECT_EQ(getLabel(label_->getLabels(), 65), "bed");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 67), 67);
  EXPECT_EQ(getLabel(label_->getLabels(), 67), "dining table");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 70), 70);
  EXPECT_EQ(getLabel(label_->getLabels(), 70), "toilet");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 72), 72);
  EXPECT_EQ(getLabel(label_->getLabels(), 72), "tv");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 73), 73);
  EXPECT_EQ(getLabel(label_->getLabels(), 73), "laptop");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 74), 74);
  EXPECT_EQ(getLabel(label_->getLabels(), 74), "mouse");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 75), 75);
  EXPECT_EQ(getLabel(label_->getLabels(), 75), "remote");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 76), 76);
  EXPECT_EQ(getLabel(label_->getLabels(), 76), "keyboard");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 77), 77);
  EXPECT_EQ(getLabel(label_->getLabels(), 77), "cell phone");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 78), 78);
  EXPECT_EQ(getLabel(label_->getLabels(), 78), "microwave");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 79), 79);
  EXPECT_EQ(getLabel(label_->getLabels(), 79), "oven");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 80), 80);
  EXPECT_EQ(getLabel(label_->getLabels(), 80), "toaster");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 81), 81);
  EXPECT_EQ(getLabel(label_->getLabels(), 81), "sink");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 82), 82);
  EXPECT_EQ(getLabel(label_->getLabels(), 82), "refrigerator");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 84), 84);
  EXPECT_EQ(getLabel(label_->getLabels(), 84), "book");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 85), 85);
  EXPECT_EQ(getLabel(label_->getLabels(), 85), "clock");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 86), 86);
  EXPECT_EQ(getLabel(label_->getLabels(), 86), "vase");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 87), 87);
  EXPECT_EQ(getLabel(label_->getLabels(), 87), "scissors");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 88), 88);
  EXPECT_EQ(getLabel(label_->getLabels(), 88), "teddy bear");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 89), 89);
  EXPECT_EQ(getLabel(label_->getLabels(), 89), "hair drier");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 90), 90);
  EXPECT_EQ(getLabel(label_->getLabels(), 90), "toothbrush");
}
