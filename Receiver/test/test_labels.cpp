#include <string>

#include "../tf/util_label_image.hpp"
#include "gtest/gtest.h"

#define  label_path "/Users/francesco/Documents/Project/tcpsocket/Receiver/build_debug/test/resources/coco_labels.txt"

const std::string getLabel(std::unordered_map<int, std::string> label, int i) {
  std::unordered_map<int, std::string>::iterator it = label.find(i);
  return it->second;
}

const int getIndexLabel(std::unordered_map<int, std::string> label, int i) {
  std::unordered_map<int, std::string>::iterator it = label.find(i);
  return it->first;
}

TEST(Label, person) {
  LabelDetection label(label_path);
  label.read();

  EXPECT_EQ(getIndexLabel(label.getLabels(), 0), 0);
  EXPECT_EQ(getLabel(label.getLabels(), 0), "person");
}

TEST(Label, bicycle) {
  LabelDetection label(label_path);
  label.read();
  EXPECT_EQ(getIndexLabel(label.getLabels(), 1), 1);
  EXPECT_EQ(getLabel(label.getLabels(), 1), "bicycle");
}

TEST(Label, car) {
  LabelDetection label(label_path);
  label.read();
  EXPECT_EQ(getIndexLabel(label.getLabels(), 2), 2);
  EXPECT_EQ(getLabel(label.getLabels(), 2), "car");
}

TEST(Label, motorcycle) {
  LabelDetection label(label_path);
  label.read();
  EXPECT_EQ(getIndexLabel(label.getLabels(), 3), 3);
  EXPECT_EQ(getLabel(label.getLabels(), 3), "motorcycle");
}

TEST(Label, airplane) {
  LabelDetection label(label_path);
  label.read();
  EXPECT_EQ(getIndexLabel(label.getLabels(), 4), 4);
  EXPECT_EQ(getLabel(label.getLabels(), 4), "airplane");
}

TEST(Label, bus) {
  LabelDetection label(label_path);
  label.read();
  EXPECT_EQ(getIndexLabel(label.getLabels(), 5), 5);
  EXPECT_EQ(getLabel(label.getLabels(), 5), "bus");
}

TEST(Label, train) {
  LabelDetection label(label_path);
  label.read();
  EXPECT_EQ(getIndexLabel(label.getLabels(), 6), 6);
  EXPECT_EQ(getLabel(label.getLabels(), 6), "train");
}

TEST(Label, truck) {
  LabelDetection label(label_path);
  label.read();
  EXPECT_EQ(getIndexLabel(label.getLabels(), 7), 7);
  EXPECT_EQ(getLabel(label.getLabels(), 7), "truck");
}

TEST(Label, boat) {
  LabelDetection label(label_path);
  label.read();
  EXPECT_EQ(getIndexLabel(label.getLabels(), 8), 8);
  EXPECT_EQ(getLabel(label.getLabels(), 8), "boat");
}

TEST(Label, traffic_light) {
  LabelDetection label(label_path);
  label.read();
  EXPECT_EQ(getIndexLabel(label.getLabels(), 9), 9);
  EXPECT_EQ(getLabel(label.getLabels(), 9), "traffic light");
}

TEST(Label, fire_hydrant) {
  LabelDetection label(label_path);
  label.read();
  EXPECT_EQ(getIndexLabel(label.getLabels(), 10), 10);
  EXPECT_EQ(getLabel(label.getLabels(), 10), "fire hydrant");
}

TEST(Label, stop_sign) {
  LabelDetection label(label_path);
  label.read();
  EXPECT_EQ(getIndexLabel(label.getLabels(), 12), 12);
  EXPECT_EQ(getLabel(label.getLabels(), 12), "stop sign");
}

TEST(Label, parking_meter) {
  LabelDetection label(label_path);
  label.read();
  EXPECT_EQ(getIndexLabel(label.getLabels(), 13), 13);
  EXPECT_EQ(getLabel(label.getLabels(), 13), "parking meter");
}

TEST(Label, bench) {
  LabelDetection label(label_path);
  label.read();
  EXPECT_EQ(getIndexLabel(label.getLabels(), 14), 14);
  EXPECT_EQ(getLabel(label.getLabels(), 14), "bench");
}

TEST(Label, bird) {
  LabelDetection label(label_path);
  label.read();
  EXPECT_EQ(getIndexLabel(label.getLabels(), 15), 15);
  EXPECT_EQ(getLabel(label.getLabels(), 15), "bird");
}

TEST(Label, cat) {
  LabelDetection label(label_path);
  label.read();
  EXPECT_EQ(getIndexLabel(label.getLabels(), 16), 16);
  EXPECT_EQ(getLabel(label.getLabels(), 16), "cat");
}

TEST(Label, dog) {
  LabelDetection label(label_path);
  label.read();
  EXPECT_EQ(getIndexLabel(label.getLabels(), 17), 17);
  EXPECT_EQ(getLabel(label.getLabels(), 17), "dog");
}

TEST(Label, horse) {
  LabelDetection label(label_path);
  label.read();
  EXPECT_EQ(getIndexLabel(label.getLabels(), 18), 18);
  EXPECT_EQ(getLabel(label.getLabels(), 18), "horse");
}

TEST(Label, sheep) {
  LabelDetection label(label_path);
  label.read();
  EXPECT_EQ(getIndexLabel(label.getLabels(), 19), 19);
  EXPECT_EQ(getLabel(label.getLabels(), 19), "sheep");
}

TEST(Label, cow) {
  LabelDetection label(label_path);
  label.read();
  EXPECT_EQ(getIndexLabel(label.getLabels(), 20), 20);
  EXPECT_EQ(getLabel(label.getLabels(), 20), "cow");
}

TEST(Label, elephant) {
  LabelDetection label(label_path);
  label.read();
  EXPECT_EQ(getIndexLabel(label.getLabels(), 21), 21);
  EXPECT_EQ(getLabel(label.getLabels(), 21), "elephant");
}

TEST(Label, bear) {
  LabelDetection label(label_path);
  label.read();
  EXPECT_EQ(getIndexLabel(label.getLabels(), 22), 22);
  EXPECT_EQ(getLabel(label.getLabels(), 22), "bear");
}

TEST(Label, zebra) {
  LabelDetection label(label_path);
  label.read();
  EXPECT_EQ(getIndexLabel(label.getLabels(), 23), 23);
  EXPECT_EQ(getLabel(label.getLabels(), 23), "zebra");
}

TEST(Label, giraffe) {
  LabelDetection label(label_path);
  label.read();
  EXPECT_EQ(getIndexLabel(label.getLabels(), 24), 24);
  EXPECT_EQ(getLabel(label.getLabels(), 24), "giraffe");
}

TEST(Label, backpack) {
  LabelDetection label(label_path);
  label.read();
  EXPECT_EQ(getIndexLabel(label.getLabels(), 26), 26);
  EXPECT_EQ(getLabel(label.getLabels(), 26), "backpack");
}

TEST(Label, umbrella) {
  LabelDetection label(label_path);
  label.read();
  EXPECT_EQ(getIndexLabel(label.getLabels(), 27), 27);
  EXPECT_EQ(getLabel(label.getLabels(), 27), "umbrella");
}

TEST(Label, handbag) {
  LabelDetection label(label_path);
  label.read();
  EXPECT_EQ(getIndexLabel(label.getLabels(), 30), 30);
  EXPECT_EQ(getLabel(label.getLabels(), 30), "handbag");
}

TEST(Label, tie) {
  LabelDetection label(label_path);
  label.read();
  EXPECT_EQ(getIndexLabel(label.getLabels(), 31), 31);
  EXPECT_EQ(getLabel(label.getLabels(), 31), "tie");
}

TEST(Label, suitcase) {
  LabelDetection label(label_path);
  label.read();
  EXPECT_EQ(getIndexLabel(label.getLabels(), 32), 32);
  EXPECT_EQ(getLabel(label.getLabels(), 32), "suitcase");
}

TEST(Label, frisbee) {
  LabelDetection label(label_path);
  label.read();
  EXPECT_EQ(getIndexLabel(label.getLabels(), 33), 33);
  EXPECT_EQ(getLabel(label.getLabels(), 33), "frisbee");
}

TEST(Label, skis) {
  LabelDetection label(label_path);
  label.read();
  EXPECT_EQ(getIndexLabel(label.getLabels(), 34), 34);
  EXPECT_EQ(getLabel(label.getLabels(), 34), "skis");
}

TEST(Label, snowboard) {
  LabelDetection label(label_path);
  label.read();
  EXPECT_EQ(getIndexLabel(label.getLabels(), 35), 35);
  EXPECT_EQ(getLabel(label.getLabels(), 35), "snowboard");
}

TEST(Label, sports_ball) {
  LabelDetection label(label_path);
  label.read();
  EXPECT_EQ(getIndexLabel(label.getLabels(), 36), 36);
  EXPECT_EQ(getLabel(label.getLabels(), 36), "sports ball");
}

TEST(Label, kite) {
  LabelDetection label(label_path);
  label.read();
  EXPECT_EQ(getIndexLabel(label.getLabels(), 37), 37);
  EXPECT_EQ(getLabel(label.getLabels(), 37), "kite");
}

TEST(Label, baseball_bat) {
  LabelDetection label(label_path);
  label.read();
  EXPECT_EQ(getIndexLabel(label.getLabels(), 38), 38);
  EXPECT_EQ(getLabel(label.getLabels(), 38), "baseball bat");
}

TEST(Label, baseball_glove) {
  LabelDetection label(label_path);
  label.read();
  EXPECT_EQ(getIndexLabel(label.getLabels(), 39), 39);
  EXPECT_EQ(getLabel(label.getLabels(), 39), "baseball glove");
}

TEST(Label, skateboard) {
  LabelDetection label(label_path);
  label.read();
  EXPECT_EQ(getIndexLabel(label.getLabels(), 40), 40);
  EXPECT_EQ(getLabel(label.getLabels(), 40), "skateboard");
}

TEST(Label, surfboard) {
  LabelDetection label(label_path);
  label.read();
  EXPECT_EQ(getIndexLabel(label.getLabels(), 41), 41);
  EXPECT_EQ(getLabel(label.getLabels(), 41), "surfboard");
}

TEST(Label, tennis_racket) {
  LabelDetection label(label_path);
  label.read();
  EXPECT_EQ(getIndexLabel(label.getLabels(), 42), 42);
  EXPECT_EQ(getLabel(label.getLabels(), 42), "tennis racket");
}

TEST(Label, bottle) {
  LabelDetection label(label_path);
  label.read();
  EXPECT_EQ(getIndexLabel(label.getLabels(), 43), 43);
  EXPECT_EQ(getLabel(label.getLabels(), 43), "bottle");
}

TEST(Label, wine_glass) {
  LabelDetection label(label_path);
  label.read();
  EXPECT_EQ(getIndexLabel(label.getLabels(), 45), 45);
  EXPECT_EQ(getLabel(label.getLabels(), 45), "wine glass");
}

TEST(Label, cup) {
  LabelDetection label(label_path);
  label.read();
  EXPECT_EQ(getIndexLabel(label.getLabels(), 46), 46);
  EXPECT_EQ(getLabel(label.getLabels(), 46), "cup");
}

TEST(Label, fork) {
  LabelDetection label(label_path);
  label.read();
  EXPECT_EQ(getIndexLabel(label.getLabels(), 47), 47);
  EXPECT_EQ(getLabel(label.getLabels(), 47), "fork");
}

TEST(Label, knife) {
  LabelDetection label(label_path);
  label.read();
  EXPECT_EQ(getIndexLabel(label.getLabels(), 48), 48);
  EXPECT_EQ(getLabel(label.getLabels(), 48), "knife");
}

TEST(Label, spoon) {
  LabelDetection label(label_path);
  label.read();
  EXPECT_EQ(getIndexLabel(label.getLabels(), 49), 49);
  EXPECT_EQ(getLabel(label.getLabels(), 49), "spoon");
}

TEST(Label, bowl) {
  LabelDetection label(label_path);
  label.read();
  EXPECT_EQ(getIndexLabel(label.getLabels(), 50), 50);
  EXPECT_EQ(getLabel(label.getLabels(), 50), "bowl");
}

TEST(Label, banana) {
  LabelDetection label(label_path);
  label.read();
  EXPECT_EQ(getIndexLabel(label.getLabels(), 51), 51);
  EXPECT_EQ(getLabel(label.getLabels(), 51), "banana");
}

TEST(Label, apple) {
  LabelDetection label(label_path);
  label.read();
  EXPECT_EQ(getIndexLabel(label.getLabels(), 52), 52);
  EXPECT_EQ(getLabel(label.getLabels(), 52), "apple");
}

TEST(Label, sandwich) {
  LabelDetection label(label_path);
  label.read();
  EXPECT_EQ(getIndexLabel(label.getLabels(), 53), 53);
  EXPECT_EQ(getLabel(label.getLabels(), 53), "sandwich");
}

TEST(Label, orange) {
  LabelDetection label(label_path);
  label.read();
  EXPECT_EQ(getIndexLabel(label.getLabels(), 54), 54);
  EXPECT_EQ(getLabel(label.getLabels(), 54), "orange");
}

TEST(Label, broccoli) {
  LabelDetection label(label_path);
  label.read();
  EXPECT_EQ(getIndexLabel(label.getLabels(), 55), 55);
  EXPECT_EQ(getLabel(label.getLabels(), 55), "broccoli");
}

TEST(Label, carrot) {
  LabelDetection label(label_path);
  label.read();
  EXPECT_EQ(getIndexLabel(label.getLabels(), 56), 56);
  EXPECT_EQ(getLabel(label.getLabels(), 56), "carrot");
}

TEST(Label, hot_dog) {
  LabelDetection label(label_path);
  label.read();
  EXPECT_EQ(getIndexLabel(label.getLabels(), 57), 57);
  EXPECT_EQ(getLabel(label.getLabels(), 57), "hot dog");
}

TEST(Label, pizza) {
  LabelDetection label(label_path);
  label.read();
  EXPECT_EQ(getIndexLabel(label.getLabels(), 58), 58);
  EXPECT_EQ(getLabel(label.getLabels(), 58), "pizza");
}

TEST(Label, donut) {
  LabelDetection label(label_path);
  label.read();
  EXPECT_EQ(getIndexLabel(label.getLabels(), 59), 59);
  EXPECT_EQ(getLabel(label.getLabels(), 59), "donut");
}

TEST(Label, cake) {
  LabelDetection label(label_path);
  label.read();
  EXPECT_EQ(getIndexLabel(label.getLabels(), 60), 60);
  EXPECT_EQ(getLabel(label.getLabels(), 60), "cake");
}

TEST(Label, chair) {
  LabelDetection label(label_path);
  label.read();
  EXPECT_EQ(getIndexLabel(label.getLabels(), 61), 61);
  EXPECT_EQ(getLabel(label.getLabels(), 61), "chair");
}

TEST(Label, couch) {
  LabelDetection label(label_path);
  label.read();
  EXPECT_EQ(getIndexLabel(label.getLabels(), 62), 62);
  EXPECT_EQ(getLabel(label.getLabels(), 62), "couch");
}

TEST(Label, potted_plant) {
  LabelDetection label(label_path);
  label.read();
  EXPECT_EQ(getIndexLabel(label.getLabels(), 63), 63);
  EXPECT_EQ(getLabel(label.getLabels(), 63), "potted plant");
}

TEST(Label, bed) {
  LabelDetection label(label_path);
  label.read();
  EXPECT_EQ(getIndexLabel(label.getLabels(), 64), 64);
  EXPECT_EQ(getLabel(label.getLabels(), 64), "bed");
}

TEST(Label, dining_table) {
  LabelDetection label(label_path);
  label.read();
  EXPECT_EQ(getIndexLabel(label.getLabels(), 66), 66);
  EXPECT_EQ(getLabel(label.getLabels(), 66), "dining table");
}

TEST(Label, toilet) {
  LabelDetection label(label_path);
  label.read();
  EXPECT_EQ(getIndexLabel(label.getLabels(), 69), 69);
  EXPECT_EQ(getLabel(label.getLabels(), 69), "toilet");
}

TEST(Label, tv) {
  LabelDetection label(label_path);
  label.read();
  EXPECT_EQ(getIndexLabel(label.getLabels(), 71), 71);
  EXPECT_EQ(getLabel(label.getLabels(), 71), "tv");
}

TEST(Label, laptop) {
  LabelDetection label(label_path);
  label.read();
  EXPECT_EQ(getIndexLabel(label.getLabels(), 72), 72);
  EXPECT_EQ(getLabel(label.getLabels(), 72), "laptop");
}

TEST(Label, mouse) {
  LabelDetection label(label_path);
  label.read();
  EXPECT_EQ(getIndexLabel(label.getLabels(), 73), 73);
  EXPECT_EQ(getLabel(label.getLabels(), 73), "mouse");
}

TEST(Label, remote) {
  LabelDetection label(label_path);
  label.read();
  EXPECT_EQ(getIndexLabel(label.getLabels(), 74), 74);
  EXPECT_EQ(getLabel(label.getLabels(), 74), "remote");
}

TEST(Label, keyboard) {
  LabelDetection label(label_path);
  label.read();
  EXPECT_EQ(getIndexLabel(label.getLabels(), 75), 75);
  EXPECT_EQ(getLabel(label.getLabels(), 75), "keyboard");
}

TEST(Label, cell_phone) {
  LabelDetection label(label_path);
  label.read();
  EXPECT_EQ(getIndexLabel(label.getLabels(), 76), 76);
  EXPECT_EQ(getLabel(label.getLabels(), 76), "cell phone");
}

TEST(Label, microwave) {
  LabelDetection label(label_path);
  label.read();
  EXPECT_EQ(getIndexLabel(label.getLabels(), 77), 77);
  EXPECT_EQ(getLabel(label.getLabels(), 77), "microwave");
}

TEST(Label, oven) {
  LabelDetection label(label_path);
  label.read();
  EXPECT_EQ(getIndexLabel(label.getLabels(), 78), 78);
  EXPECT_EQ(getLabel(label.getLabels(), 78), "oven");
}

TEST(Label, toaster) {
  LabelDetection label(label_path);
  label.read();
  EXPECT_EQ(getIndexLabel(label.getLabels(), 79), 79);
  EXPECT_EQ(getLabel(label.getLabels(), 79), "toaster");
}

TEST(Label, sink) {
  LabelDetection label(label_path);
  label.read();
  EXPECT_EQ(getIndexLabel(label.getLabels(), 80), 80);
  EXPECT_EQ(getLabel(label.getLabels(), 80), "sink");
}

TEST(Label, refrigerator) {
  LabelDetection label(label_path);
  label.read();
  EXPECT_EQ(getIndexLabel(label.getLabels(), 81), 81);
  EXPECT_EQ(getLabel(label.getLabels(), 81), "refrigerator");
}

TEST(Label, book) {
  LabelDetection label(label_path);
  label.read();
  EXPECT_EQ(getIndexLabel(label.getLabels(), 83), 83);
  EXPECT_EQ(getLabel(label.getLabels(), 83), "book");
}

TEST(Label, clock) {
  LabelDetection label(label_path);
  label.read();
  EXPECT_EQ(getIndexLabel(label.getLabels(), 84), 84);
  EXPECT_EQ(getLabel(label.getLabels(), 84), "clock");
}

TEST(Label, vase) {
  LabelDetection label(label_path);
  label.read();
  EXPECT_EQ(getIndexLabel(label.getLabels(), 85), 85);
  EXPECT_EQ(getLabel(label.getLabels(), 85), "vase");
}

TEST(Label, scissors) {
  LabelDetection label(label_path);
  label.read();
  EXPECT_EQ(getIndexLabel(label.getLabels(), 86), 86);
  EXPECT_EQ(getLabel(label.getLabels(), 86), "scissors");
}

TEST(Label, teddy_bear) {
  LabelDetection label(label_path);
  label.read();
  EXPECT_EQ(getIndexLabel(label.getLabels(), 87), 87);
  EXPECT_EQ(getLabel(label.getLabels(), 87), "teddy bear");
}

TEST(Label, hair_drier) {
  LabelDetection label(label_path);
  label.read();
  EXPECT_EQ(getIndexLabel(label.getLabels(), 88), 88);
  EXPECT_EQ(getLabel(label.getLabels(), 88), "hair drier");
}

TEST(Label, toothbrush) {
  LabelDetection label(label_path);
  label.read();
  EXPECT_EQ(getIndexLabel(label.getLabels(), 89), 89);
  EXPECT_EQ(getLabel(label.getLabels(), 89), "toothbrush");
}
