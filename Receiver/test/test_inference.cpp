#include <QImage>
#include <QObject>
#include <QPixmap>
#include <QString>
#include <vector>

#include "gtest/gtest.h"
#include "labels.hpp"
#include "model_tpu.hpp"
#include "tensorflow/lite/examples/label_image/bitmap_helpers.h"
#include "tensorflow/lite/examples/label_image/label_image.h"

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
  // check dimension
  ASSERT_EQ(img.height(), 606);
  ASSERT_EQ(img.width(), 517);
  
  // input
  auto sz = img.sizeInBytes();
  auto input = std::make_unique<uint8_t[]>(sz);
  memcpy(input.get(), img.bits(), sz);
  
  // output
  tflite::label_image::Settings s;
  s.input_type = kTfLiteUInt8;
  s.model_name = mobilenet;
  
  // ASSERT_EQ(img.channels, 3);
  std::vector<uint8_t> output(606 * 517 * 3);
  tflite::label_image::resize<uint8_t>(output.data(), input.get(), 606, 517, 3, 214, 214, 3, &s);
  ASSERT_EQ(output[0], 0x15);
  ASSERT_EQ(output[214 * 214 * 3 - 1], 0x11);
  
  
  
  
  
  
  
  
  
  
  ASSERT_FALSE(img.isNull());
  // model_tflite.imageAvailable(img);
  // auto results = model_tflite.getResultClassification();
  // EXPECT_EQ(results.size(), 0);
  // EXPECT_LE(results.size(), 5);

  // labels
  // EXPECT_EQ(model_tflite.getLabel(results[0].second), "military uniform");
  // EXPECT_EQ(, "Windsor tie");
  // EXPECT_EQ(, "bulletproof vest");
  // EXPECT_EQ(, "cornet, horn, trumpet, trump");
  // EXPECT_EQ(, "drumstick";

  // scores
  // EXPECT_GE(results[0].first, 0.860174);
  // EXPECT_GE(results[1].first, 0.0481017);
  // EXPECT_GE(results[2].first, 0.00786704);
  // EXPECT_GE(results[3].first, 0.00644932);
  // EXPECT_GE(results[4].first, 0.00608029);
}

//////////////////////////////////////////////////////////////////////////////
/// Other Case
//////////////////////////////////////////////////////////////////////////////

class InferenceTestCase : public ::testing::Test {
 protected:
  const QString label_path{"../build_debug/test/resources/coco_labels.txt"};
  const QString model_path{"../build_debug/test/resources/detect.tflite"};
  ModelTensorFlowLite model_tflite;

  void SetUp() override {
    LabelDetection label(label_path);
    label.read();
    model_tflite.LoadModelFromFile(model_path);
    model_tflite.setLabel(label.getLabels());
  }

  void TearDown() override {
    // code here will be called just after the test completes
    // ok to through exceptions from here if need be
  }

  QImage readImageFile(const QString &filename){
    QFile file(filename);
    file.open(QIODevice::ReadOnly);
    return QImage::fromData(file.readAll());
  }

  
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

TEST_F(InferenceTestCase, Cat1) {
  const QString cat_file("../build_debug/test/testdata/cat_1.jpg");
  auto img = readImageFile(cat_file);
  ASSERT_FALSE(img.isNull());
  ASSERT_EQ(img.height(), 1800);
  ASSERT_EQ(img.width(), 1200);
  model_tflite.imageAvailable(img);
  auto results = model_tflite.getResults();
  EXPECT_GT(results.size(), 0);
  // labels
  // EXPECT_EQ(model_tflite.getLabel(results[0].second), "cat");
  // scores
  // EXPECT_GE(results[0].first, 0.01);
}

TEST_F(InferenceTestCase, Cat2) {
  const QString cat_file("../build_debug/test/testdata/cat_2.jpg");
  auto img = readImageFile(cat_file);
  ASSERT_FALSE(img.isNull());
  ASSERT_EQ(img.height(), 400);
  ASSERT_EQ(img.width(), 600);
  model_tflite.imageAvailable(img);
  auto results = model_tflite.getResults();
  EXPECT_GT(results.size(), 0);
  // labels
  // EXPECT_EQ(model_tflite.getLabel(results[0].second), "cat");
  // scores
  // EXPECT_GE(results[0].first, 0.01);
}

TEST_F(InferenceTestCase, Cat3) {
  const QString cat_file("../build_debug/test/testdata/cat_3.jpg");
  auto img = readImageFile(cat_file);
  ASSERT_FALSE(img.isNull());
  ASSERT_EQ(img.height(), 260);
  ASSERT_EQ(img.width(), 402);
  model_tflite.imageAvailable(img);
  auto results = model_tflite.getResults();
  EXPECT_GT(results.size(), 0);
  // labels
  // EXPECT_EQ(model_tflite.getLabel(results[0].second), "cat");
  // scores
  // EXPECT_GE(results[0].first, 0.01);
}

TEST_F(InferenceTestCase, Cat4) {
  const QString cat_file("../build_debug/test/testdata/cat_4.jpg");
  auto img = readImageFile(cat_file);
  ASSERT_FALSE(img.isNull());
  ASSERT_EQ(img.height(), 700);
  ASSERT_EQ(img.width(), 1600);
  model_tflite.imageAvailable(img);
  auto results = model_tflite.getResults();
  EXPECT_GT(results.size(), 0);
  // labels
  // EXPECT_EQ(model_tflite.getLabel(results[0].second), "cat");
  // scores
  // EXPECT_GE(results[0].first, 0.01);
}

TEST_F(InferenceTestCase, Cat5) {
  const QString cat_file("../build_debug/test/testdata/cat_5.jpg");
  auto img = readImageFile(cat_file);
  ASSERT_FALSE(img.isNull());
  ASSERT_EQ(img.height(), 678);
  ASSERT_EQ(img.width(), 800);
  model_tflite.imageAvailable(img);
  auto results = model_tflite.getResults();
  EXPECT_GT(results.size(), 0);
  // labels
  // EXPECT_EQ(model_tflite.getLabel(results[0].second), "cat");
  // scores
  // EXPECT_GE(results[0].first, 0.01);
}
