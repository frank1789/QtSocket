#include <QImage>
#include <QObject>

#include "gtest/gtest.h"
#include "labels.hpp"
#include "model_tpu.hpp"
class InferenceTestCase : public ::testing::Test {
 protected:
  const std::string label_path{"../build_debug/test/resources/coco_labels.txt"};
  const std::string model_path{"../build_debug/test/resources/detect.tflite"};
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

TEST_F(InferenceTestCase, Person) {}