#include <QImage>
#include <QObject>
#include <QPixmap>
#include <QString>

#include "gtest/gtest.h"
#include "labels.hpp"
#include "model_tpu.hpp"

//////////////////////////////////////////////////////////////////////////////
/// GitHub example case
//////////////////////////////////////////////////////////////////////////////

class Inference : public ::testing::Test {
 protected:
  const std::string mobilenet{
      "../build_debug/test/resources/mobilenet_v1_1.0_224.tflite"};
  const std::string mobnet_label{"../build_debug/test/resources/labels.txt"};

  void SetUp() {
    LabelDetection label(mobnet_label);
    label.read();
    model_tflite.LoadModelFromFile(mobilenet);
    model_tflite.setLabel(label.getLabels());
  }

  void TearDown() {
    // code here will be called just after the test completes
    // ok to through exceptions from here if need be
  }

 public:
  ModelTensorFlowLite model_tflite;
};

TEST_F(Inference, GraceHooper) {
  const QImage img("../build_debug/test/testdata/grace_hopper.bmp");
  ASSERT_FALSE(img.isNull());
  model_tflite.imageAvailable(img);
  auto results = model_tflite.getResultClassification();
  EXPECT_GT(results.size(), 0);
  EXPECT_EQ(results.size(), 5);

  // labels
  EXPECT_EQ(model_tflite.getLabel(results[0].second), "military uniform");
  // EXPECT_EQ(, "Windsor tie");
  // EXPECT_EQ(, "bulletproof vest");
  // EXPECT_EQ(, "cornet, horn, trumpet, trump");
  // EXPECT_EQ(, "drumstick";

  // scores
  EXPECT_GE(results[0].first, 0.860174);
  EXPECT_GE(results[1].first, 0.0481017);
  EXPECT_GE(results[2].first, 0.00786704);
  EXPECT_GE(results[3].first, 0.00644932);
  EXPECT_GE(results[4].first, 0.00608029);
}

//////////////////////////////////////////////////////////////////////////////
/// Other Case
//////////////////////////////////////////////////////////////////////////////

class InferenceTestCase : public ::testing::Test {
 protected:
  const QString label_path{"../build_debug/test/resources/coco_labels.txt"};
  const QString model_path{"../build_debug/test/resources/detect.tflite"};

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

 public:
  ModelTensorFlowLite model_tflite;
};

TEST_F(InferenceTestCase, Dog) {
  // const QImage img("../build_debug/test/testdata/dog_2.jpg");
  // ASSERT_FALSE(img.isNull());
  // model_tflite.imageAvailable(img);
  // auto results = model_tflite.getResults();
  // EXPECT_GT(results.size(), 0);

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
  ASSERT_FALSE(img.isNull());
  model_tflite.imageAvailable(img);
  auto results = model_tflite.getResults();
  EXPECT_GT(results.size(), 0);
}
