#include <QFile>
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

TEST(InferenceExample, GraceHooper) {
  const std::string mobilenet{
      "../build_debug/test/resources/mobilenet_v1_1.0_224.tflite"};
  const std::string mobnet_label{"../build_debug/test/resources/labels.txt"};
  ModelTensorFlowLite model_tflite;
  LabelDetection label(mobnet_label);
  label.read();
  model_tflite.LoadModelFromFile(mobilenet);
  model_tflite.setLabel(label.getLabels());
  const QImage img("../build_debug/test/testdata/grace_hopper.bmp");
  // check dimension
  ASSERT_FALSE(img.isNull());
  ASSERT_EQ(img.height(), 606);
  ASSERT_EQ(img.width(), 517);
  model_tflite.imageAvailable(img);
  auto results = model_tflite.getResultClassification();
  EXPECT_EQ(results.size(), 5);

  // labels
  EXPECT_EQ(model_tflite.getLabel(results[0].second), "military uniform");
  EXPECT_EQ(model_tflite.getLabel(results[1].second), "Windsor tie");
  EXPECT_EQ(model_tflite.getLabel(results[2].second), "bulletproof vest");
  EXPECT_EQ(model_tflite.getLabel(results[3].second),
            "cornet, horn, trumpet, trump");
  EXPECT_EQ(model_tflite.getLabel(results[4].second), "drumstick");

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

TEST(InferenceAnimal, Dog1) {
  const QString label_path{"../build_debug/test/resources/coco_labels.txt"};
  const QString model_path{"../build_debug/test/resources/detect.tflite"};
  ModelTensorFlowLite model_tflite;
  LabelDetection label(label_path);
  label.read();
  model_tflite.LoadModelFromFile(model_path);
  model_tflite.setLabel(label.getLabels());
  const QImage img("../build_debug/test/testdata/dog_1.jpg");
  ASSERT_FALSE(img.isNull());
  ASSERT_EQ(img.height(), 248);
  ASSERT_EQ(img.width(), 203);
  model_tflite.imageAvailable(img);
  int cls;
  float score;
  QRectF box;
  auto result = model_tflite.getResults();
  for (auto it = result.begin(); it != result.end(); ++it) {
    auto cls = it->index_class;
    auto score = it->score;
    // labels
    EXPECT_EQ(model_tflite.getLabel(cls), "dog");
    // scores
    EXPECT_GE(score, 0.01);
  }
}

TEST(InferenceAnimal, Dog2) {
  const QString label_path{"../build_debug/test/resources/coco_labels.txt"};
  const QString model_path{"../build_debug/test/resources/detect.tflite"};
  ModelTensorFlowLite model_tflite;
  LabelDetection label(label_path);
  label.read();
  model_tflite.LoadModelFromFile(model_path);
  model_tflite.setLabel(label.getLabels());
  const QImage img("../build_debug/test/testdata/dog_2.jpg");
  ASSERT_FALSE(img.isNull());
  ASSERT_EQ(img.height(), 485);
  ASSERT_EQ(img.width(), 729);
  model_tflite.imageAvailable(img);
  int cls;
  float score;
  QRectF box;
  auto result = model_tflite.getResults();
  for (auto it = result.begin(); it != result.end(); ++it) {
    auto cls = it->index_class;
    auto score = it->score;
    // labels
    EXPECT_EQ(model_tflite.getLabel(cls), "dog");
    // scores
    EXPECT_GE(score, 0.01);
  }
}

TEST(InferenceAnimal, Dog3) {
  const QString label_path{"../build_debug/test/resources/coco_labels.txt"};
  const QString model_path{"../build_debug/test/resources/detect.tflite"};
  ModelTensorFlowLite model_tflite;
  LabelDetection label(label_path);
  label.read();
  model_tflite.LoadModelFromFile(model_path);
  model_tflite.setLabel(label.getLabels());
  const QImage img("../build_debug/test/testdata/dog_3.jpg");
  ASSERT_FALSE(img.isNull());
  ASSERT_EQ(img.height(), 1385);
  ASSERT_EQ(img.width(), 1385);
  model_tflite.imageAvailable(img);
  int cls;
  float score;
  QRectF box;
  auto result = model_tflite.getResults();
  for (auto it = result.begin(); it != result.end(); ++it) {
    auto cls = it->index_class;
    auto score = it->score;
    // labels
    EXPECT_EQ(model_tflite.getLabel(cls), "dog");
    // scores
    EXPECT_GE(score, 0.01);
  }
}

TEST(InferenceAnimal, Dog4) {
  const QString label_path{"../build_debug/test/resources/coco_labels.txt"};
  const QString model_path{"../build_debug/test/resources/detect.tflite"};
  ModelTensorFlowLite model_tflite;
  LabelDetection label(label_path);
  label.read();
  model_tflite.LoadModelFromFile(model_path);
  model_tflite.setLabel(label.getLabels());
  const QImage img("../build_debug/test/testdata/dog_4.jpg");
  ASSERT_FALSE(img.isNull());
  ASSERT_EQ(img.height(), 478);
  ASSERT_EQ(img.width(), 640);
  model_tflite.imageAvailable(img);
  int cls;
  float score;
  QRectF box;
  auto result = model_tflite.getResults();
  for (auto it = result.begin(); it != result.end(); ++it) {
    auto cls = it->index_class;
    auto score = it->score;
    // labels
    EXPECT_EQ(model_tflite.getLabel(cls), "dog");
    // scores
    EXPECT_GE(score, 0.01);
  }
}

TEST(InferenceAnimal, Dog5) {
  const QString label_path{"../build_debug/test/resources/coco_labels.txt"};
  const QString model_path{"../build_debug/test/resources/detect.tflite"};
  ModelTensorFlowLite model_tflite;
  LabelDetection label(label_path);
  label.read();
  model_tflite.LoadModelFromFile(model_path);
  model_tflite.setLabel(label.getLabels());
  const QImage img("../build_debug/test/testdata/dog_5.jpg");
  ASSERT_FALSE(img.isNull());
  ASSERT_EQ(img.height(), 500);
  ASSERT_EQ(img.width(), 750);
  model_tflite.imageAvailable(img);
  int cls;
  float score;
  QRectF box;
  auto result = model_tflite.getResults();
  for (auto it = result.begin(); it != result.end(); ++it) {
    auto cls = it->index_class;
    auto score = it->score;
    // labels
    EXPECT_EQ(model_tflite.getLabel(cls), "dog");
    // scores
    EXPECT_GE(score, 0.01);
  }
}

TEST(InferenceAnimal, Cat1) {
  const QString label_path{"../build_debug/test/resources/coco_labels.txt"};
  const QString model_path{"../build_debug/test/resources/detect.tflite"};
  ModelTensorFlowLite model_tflite;
  LabelDetection label(label_path);
  label.read();
  model_tflite.LoadModelFromFile(model_path);
  model_tflite.setLabel(label.getLabels());
  const QImage img("../build_debug/test/testdata/cat_1.jpg");
  ASSERT_FALSE(img.isNull());
  ASSERT_EQ(img.height(), 1800);
  ASSERT_EQ(img.width(), 1200);
  model_tflite.imageAvailable(img);
  int cls;
  float score;
  QRectF box;
  auto result = model_tflite.getResults();
  for (auto it = result.begin(); it != result.end(); ++it) {
    auto cls = it->index_class;
    auto score = it->score;
    // labels
    EXPECT_EQ(model_tflite.getLabel(cls), "cat");
    // scores
    EXPECT_GE(score, 0.01);
  }
}

TEST(InferenceAnimal, Cat2) {
  const QString label_path{"../build_debug/test/resources/coco_labels.txt"};
  const QString model_path{"../build_debug/test/resources/detect.tflite"};
  ModelTensorFlowLite model_tflite;
  LabelDetection label(label_path);
  label.read();
  model_tflite.LoadModelFromFile(model_path);
  model_tflite.setLabel(label.getLabels());
  const QImage img("../build_debug/test/testdata/cat_2.jpg");
  ASSERT_FALSE(img.isNull());
  ASSERT_EQ(img.height(), 400);
  ASSERT_EQ(img.width(), 600);
  model_tflite.imageAvailable(img);
  int cls;
  float score;
  QRectF box;
  auto result = model_tflite.getResults();
  for (auto it = result.begin(); it != result.end(); ++it) {
    auto cls = it->index_class;
    auto score = it->score;
    // labels
    EXPECT_EQ(model_tflite.getLabel(cls), "cat");
    // scores
    EXPECT_GE(score, 0.01);
  }
}

TEST(InferenceAnimal, Cat3) {
  const QString label_path{"../build_debug/test/resources/coco_labels.txt"};
  const QString model_path{"../build_debug/test/resources/detect.tflite"};
  ModelTensorFlowLite model_tflite;
  LabelDetection label(label_path);
  label.read();
  model_tflite.LoadModelFromFile(model_path);
  model_tflite.setLabel(label.getLabels());
  const QImage img("../build_debug/test/testdata/cat_3.jpg");
  ASSERT_FALSE(img.isNull());
  ASSERT_EQ(img.height(), 710);
  ASSERT_EQ(img.width(), 836);
  model_tflite.imageAvailable(img);
  int cls;
  float score;
  QRectF box;
  auto result = model_tflite.getResults();
  for (auto it = result.begin(); it != result.end(); ++it) {
    auto cls = it->index_class;
    auto score = it->score;
    // labels
    EXPECT_EQ(model_tflite.getLabel(cls), "cat");
    // scores
    EXPECT_GE(score, 0.01);
  }
}

TEST(InferenceAnimal, Cat4) {
  const QString label_path{"../build_debug/test/resources/coco_labels.txt"};
  const QString model_path{"../build_debug/test/resources/detect.tflite"};
  ModelTensorFlowLite model_tflite;
  LabelDetection label(label_path);
  label.read();
  model_tflite.LoadModelFromFile(model_path);
  model_tflite.setLabel(label.getLabels());
  const QImage img("../build_debug/test/testdata/cat_4.jpg");
  ASSERT_FALSE(img.isNull());
  ASSERT_EQ(img.height(), 700);
  ASSERT_EQ(img.width(), 1600);
  model_tflite.imageAvailable(img);
  int cls;
  float score;
  QRectF box;
  auto result = model_tflite.getResults();
  for (auto it = result.begin(); it != result.end(); ++it) {
    auto cls = it->index_class;
    auto score = it->score;
    // labels
    EXPECT_EQ(model_tflite.getLabel(cls), "cat");
    // scores
    EXPECT_GE(score, 0.01);
  }
}

TEST(InferenceAnimal, Cat5) {
  const QString label_path{"../build_debug/test/resources/coco_labels.txt"};
  const QString model_path{"../build_debug/test/resources/detect.tflite"};
  ModelTensorFlowLite model_tflite;
  LabelDetection label(label_path);
  label.read();
  model_tflite.LoadModelFromFile(model_path);
  model_tflite.setLabel(label.getLabels());
  const QImage img("../build_debug/test/testdata/cat_5.jpg");
  ASSERT_FALSE(img.isNull());
  ASSERT_EQ(img.height(), 678);
  ASSERT_EQ(img.width(), 800);
  model_tflite.imageAvailable(img);
  int cls;
  float score;
  QRectF box;
  auto result = model_tflite.getResults();
  for (auto it = result.begin(); it != result.end(); ++it) {
    auto cls = it->index_class;
    auto score = it->score;
    // labels
    EXPECT_EQ(model_tflite.getLabel(cls), "cat");
    // scores
    EXPECT_GE(score, 0.01);
  }
}
