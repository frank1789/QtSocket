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

TEST_F(InferenceTestCase, GraceHooper){
  const QImage img("../build_debug/test/testdata/grace_hopper.bmp");
  ASSERT_TRUE(!img.isNull());
  model_tflite.setInput(img);
}

TEST_F(InferenceTestCase, Dog) {
  const QImage img("../build_debug/test/testdata/dog_1.jpeg");
  ASSERT_TRUE(!img.isNull());
  model_tflite.setInput(img);
  
  
  
  
  
  


  // img_directory.setFilter(QDir::Files);
  // QFileInfoList entries = img_directory.entryInfoList(QDir::AllEntries);
  // EXPECT_GT(entries.size(), 0);
  // qDebug() << entries.size();
  // if (entries.size() != 0) {

    // qDebug() << entries.at(qrand() % entries.size()).absoluteFilePath();

  // }





  // QImage img(img_path);
  // ASSERT_TRUE(img.isNull());
  // model_tflite.setInput(img);
}


TEST_F(InferenceTestCase, Cat) {
  const QImage img("../build_debug/test/testdata/cat_1.jpg");
  ASSERT_TRUE(!img.isNull());
  model_tflite.setInput(img);
  
}
