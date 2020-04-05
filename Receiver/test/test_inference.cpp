#include "gtest/gtest.h"
#include "../tf/model_tpu.hpp"
#include "../tf/labels.hpp"

#include <QImage>
#include <QObject>

#define path "/Users/francesco/Documents/Project/tcpsocket/Receiver/build_debug/test/resources/coco_labels.txt"

class InferenceTestCase : public ::testing::Test {


 protected:

  
  const std::string label_path = "/Users/francesco/Documents/Project/tcpsocket/Receiver/build_debug/test/resources/coco_labels.txt";
  const std::string model_path {"/Users/francesco/Documents/Project/tcpsocket/Receiver/build_debug/test/resources/detect.tflite"};
  ModelTensorFlowLite model_tflite;




  void SetUp() {
    LabelDetection label(label_path);
    label.read();
    model_tflite.LoadModelFromFile(model_path);
    model_tflite.setLabel(label.getLabels());
  }

  void TearDown() {
    // code here will be called just after the test completes
    // ok to through exceptions from here if need be
  }

  
};

TEST_F(InferenceTestCase, Person) {

}