#include <string>
#include <memory>
#include <QCoreApplication>

#include "gtest/gtest.h"
#include "labels.hpp"

class Label : public ::testing::Test {
 protected:
  const std::string label_path = {"../build_debug/test/resources/coco_labels.txt"};
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

TEST_F(Label, person) {
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 0), 0);
  EXPECT_EQ(getLabel(label_->getLabels(), 0), "person");
}

TEST_F(Label, bicycle) {
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 1), 1);
  EXPECT_EQ(getLabel(label_->getLabels(), 1), "bicycle");
}

TEST_F(Label, car) {
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 2), 2);
  EXPECT_EQ(getLabel(label_->getLabels(), 2), "car");
}

TEST_F(Label, motorcycle) {
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 3), 3);
  EXPECT_EQ(getLabel(label_->getLabels(), 3), "motorcycle");
}

TEST_F(Label, airplane) {
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 4), 4);
  EXPECT_EQ(getLabel(label_->getLabels(), 4), "airplane");
}

TEST_F(Label, bus) {
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 5), 5);
  EXPECT_EQ(getLabel(label_->getLabels(), 5), "bus");
}

TEST_F(Label, train) {
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 6), 6);
  EXPECT_EQ(getLabel(label_->getLabels(), 6), "train");
}

TEST_F(Label, truck) {
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 7), 7);
  EXPECT_EQ(getLabel(label_->getLabels(), 7), "truck");
}

TEST_F(Label, boat) {
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 8), 8);
  EXPECT_EQ(getLabel(label_->getLabels(), 8), "boat");
}

TEST_F(Label, traffic_light) {
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 9), 9);
  EXPECT_EQ(getLabel(label_->getLabels(), 9), "traffic light");
}

TEST_F(Label, fire_hydrant) {
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 10), 10);
  EXPECT_EQ(getLabel(label_->getLabels(), 10), "fire hydrant");
}

TEST_F(Label, stop_sign) {
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 12), 12);
  EXPECT_EQ(getLabel(label_->getLabels(), 12), "stop sign");
}

TEST_F(Label, parking_meter) {
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 13), 13);
  EXPECT_EQ(getLabel(label_->getLabels(), 13), "parking meter");
}

TEST_F(Label, bench) {
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 14), 14);
  EXPECT_EQ(getLabel(label_->getLabels(), 14), "bench");
}

TEST_F(Label, bird) {
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 15), 15);
  EXPECT_EQ(getLabel(label_->getLabels(), 15), "bird");
}

TEST_F(Label, cat) {
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 16), 16);
  EXPECT_EQ(getLabel(label_->getLabels(), 16), "cat");
}

TEST_F(Label, dog) {
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 17), 17);
  EXPECT_EQ(getLabel(label_->getLabels(), 17), "dog");
}

TEST_F(Label, horse) {
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 18), 18);
  EXPECT_EQ(getLabel(label_->getLabels(), 18), "horse");
}

TEST_F(Label, sheep) {
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 19), 19);
  EXPECT_EQ(getLabel(label_->getLabels(), 19), "sheep");
}

TEST_F(Label, cow) {
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 20), 20);
  EXPECT_EQ(getLabel(label_->getLabels(), 20), "cow");
}

TEST_F(Label, elephant) {
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 21), 21);
  EXPECT_EQ(getLabel(label_->getLabels(), 21), "elephant");
}

TEST_F(Label, bear) {
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 22), 22);
  EXPECT_EQ(getLabel(label_->getLabels(), 22), "bear");
}

TEST_F(Label, zebra) {
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 23), 23);
  EXPECT_EQ(getLabel(label_->getLabels(), 23), "zebra");
}

TEST_F(Label, giraffe) {
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 24), 24);
  EXPECT_EQ(getLabel(label_->getLabels(), 24), "giraffe");
}

TEST_F(Label, backpack) {
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 26), 26);
  EXPECT_EQ(getLabel(label_->getLabels(), 26), "backpack");
}

TEST_F(Label, umbrella) {
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 27), 27);
  EXPECT_EQ(getLabel(label_->getLabels(), 27), "umbrella");
}

TEST_F(Label, handbag) {
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 30), 30);
  EXPECT_EQ(getLabel(label_->getLabels(), 30), "handbag");
}

TEST_F(Label, tie) {
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 31), 31);
  EXPECT_EQ(getLabel(label_->getLabels(), 31), "tie");
}

TEST_F(Label, suitcase) {
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 32), 32);
  EXPECT_EQ(getLabel(label_->getLabels(), 32), "suitcase");
}

TEST_F(Label, frisbee) {
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 33), 33);
  EXPECT_EQ(getLabel(label_->getLabels(), 33), "frisbee");
}

TEST_F(Label, skis) {
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 34), 34);
  EXPECT_EQ(getLabel(label_->getLabels(), 34), "skis");
}

TEST_F(Label, snowboard) {
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 35), 35);
  EXPECT_EQ(getLabel(label_->getLabels(), 35), "snowboard");
}

TEST_F(Label, sports_ball) {
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 36), 36);
  EXPECT_EQ(getLabel(label_->getLabels(), 36), "sports ball");
}

TEST_F(Label, kite) {
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 37), 37);
  EXPECT_EQ(getLabel(label_->getLabels(), 37), "kite");
}

TEST_F(Label, baseball_bat) {
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 38), 38);
  EXPECT_EQ(getLabel(label_->getLabels(), 38), "baseball bat");
}

TEST_F(Label, baseball_glove) {
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 39), 39);
  EXPECT_EQ(getLabel(label_->getLabels(), 39), "baseball glove");
}

TEST_F(Label, skateboard) {
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 40), 40);
  EXPECT_EQ(getLabel(label_->getLabels(), 40), "skateboard");
}

TEST_F(Label, surfboard) {
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 41), 41);
  EXPECT_EQ(getLabel(label_->getLabels(), 41), "surfboard");
}

TEST_F(Label, tennis_racket) {
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 42), 42);
  EXPECT_EQ(getLabel(label_->getLabels(), 42), "tennis racket");
}

TEST_F(Label, bottle) {
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 43), 43);
  EXPECT_EQ(getLabel(label_->getLabels(), 43), "bottle");
}

TEST_F(Label, wine_glass) {
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 45), 45);
  EXPECT_EQ(getLabel(label_->getLabels(), 45), "wine glass");
}

TEST_F(Label, cup) {
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 46), 46);
  EXPECT_EQ(getLabel(label_->getLabels(), 46), "cup");
}

TEST_F(Label, fork) {
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 47), 47);
  EXPECT_EQ(getLabel(label_->getLabels(), 47), "fork");
}

TEST_F(Label, knife) {
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 48), 48);
  EXPECT_EQ(getLabel(label_->getLabels(), 48), "knife");
}

TEST_F(Label, spoon) {
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 49), 49);
  EXPECT_EQ(getLabel(label_->getLabels(), 49), "spoon");
}

TEST_F(Label, bowl) {
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 50), 50);
  EXPECT_EQ(getLabel(label_->getLabels(), 50), "bowl");
}

TEST_F(Label, banana) {
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 51), 51);
  EXPECT_EQ(getLabel(label_->getLabels(), 51), "banana");
}

TEST_F(Label, apple) {
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 52), 52);
  EXPECT_EQ(getLabel(label_->getLabels(), 52), "apple");
}

TEST_F(Label, sandwich) {
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 53), 53);
  EXPECT_EQ(getLabel(label_->getLabels(), 53), "sandwich");
}

TEST_F(Label, orange) {
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 54), 54);
  EXPECT_EQ(getLabel(label_->getLabels(), 54), "orange");
}

TEST_F(Label, broccoli) {
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 55), 55);
  EXPECT_EQ(getLabel(label_->getLabels(), 55), "broccoli");
}

TEST_F(Label, carrot) {
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 56), 56);
  EXPECT_EQ(getLabel(label_->getLabels(), 56), "carrot");
}

TEST_F(Label, hot_dog) {
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 57), 57);
  EXPECT_EQ(getLabel(label_->getLabels(), 57), "hot dog");
}

TEST_F(Label, pizza) {
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 58), 58);
  EXPECT_EQ(getLabel(label_->getLabels(), 58), "pizza");
}

TEST_F(Label, donut) {
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 59), 59);
  EXPECT_EQ(getLabel(label_->getLabels(), 59), "donut");
}

TEST_F(Label, cake) {
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 60), 60);
  EXPECT_EQ(getLabel(label_->getLabels(), 60), "cake");
}

TEST_F(Label, chair) {
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 61), 61);
  EXPECT_EQ(getLabel(label_->getLabels(), 61), "chair");
}

TEST_F(Label, couch) {
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 62), 62);
  EXPECT_EQ(getLabel(label_->getLabels(), 62), "couch");
}

TEST_F(Label, potted_plant) {
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 63), 63);
  EXPECT_EQ(getLabel(label_->getLabels(), 63), "potted plant");
}

TEST_F(Label, bed) {
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 64), 64);
  EXPECT_EQ(getLabel(label_->getLabels(), 64), "bed");
}

TEST_F(Label, dining_table) {
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 66), 66);
  EXPECT_EQ(getLabel(label_->getLabels(), 66), "dining table");
}

TEST_F(Label, toilet) {
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 69), 69);
  EXPECT_EQ(getLabel(label_->getLabels(), 69), "toilet");
}

TEST_F(Label, tv) {
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 71), 71);
  EXPECT_EQ(getLabel(label_->getLabels(), 71), "tv");
}

TEST_F(Label, laptop) {
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 72), 72);
  EXPECT_EQ(getLabel(label_->getLabels(), 72), "laptop");
}

TEST_F(Label, mouse) {
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 73), 73);
  EXPECT_EQ(getLabel(label_->getLabels(), 73), "mouse");
}

TEST_F(Label, remote) {
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 74), 74);
  EXPECT_EQ(getLabel(label_->getLabels(), 74), "remote");
}

TEST_F(Label, keyboard) {
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 75), 75);
  EXPECT_EQ(getLabel(label_->getLabels(), 75), "keyboard");
}

TEST_F(Label, cell_phone) {
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 76), 76);
  EXPECT_EQ(getLabel(label_->getLabels(), 76), "cell phone");
}

TEST_F(Label, microwave) {
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 77), 77);
  EXPECT_EQ(getLabel(label_->getLabels(), 77), "microwave");
}

TEST_F(Label, oven) {
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 78), 78);
  EXPECT_EQ(getLabel(label_->getLabels(), 78), "oven");
}

TEST_F(Label, toaster) {
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 79), 79);
  EXPECT_EQ(getLabel(label_->getLabels(), 79), "toaster");
}

TEST_F(Label, sink) {
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 80), 80);
  EXPECT_EQ(getLabel(label_->getLabels(), 80), "sink");
}

TEST_F(Label, refrigerator) {
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 81), 81);
  EXPECT_EQ(getLabel(label_->getLabels(), 81), "refrigerator");
}

TEST_F(Label, book) {
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 83), 83);
  EXPECT_EQ(getLabel(label_->getLabels(), 83), "book");
}

TEST_F(Label, clock) {
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 84), 84);
  EXPECT_EQ(getLabel(label_->getLabels(), 84), "clock");
}

TEST_F(Label, vase) {
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 85), 85);
  EXPECT_EQ(getLabel(label_->getLabels(), 85), "vase");
}

TEST_F(Label, scissors) {
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 86), 86);
  EXPECT_EQ(getLabel(label_->getLabels(), 86), "scissors");
}

TEST_F(Label, teddy_bear) {
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 87), 87);
  EXPECT_EQ(getLabel(label_->getLabels(), 87), "teddy bear");
}

TEST_F(Label, hair_drier) {
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 88), 88);
  EXPECT_EQ(getLabel(label_->getLabels(), 88), "hair drier");
}

TEST_F(Label, toothbrush) {
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 89), 89);
  EXPECT_EQ(getLabel(label_->getLabels(), 89), "toothbrush");
}
