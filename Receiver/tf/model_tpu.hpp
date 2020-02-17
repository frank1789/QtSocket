#ifndef MODEL_TPU_HPP
#define MODEL_TPU_HPP


#include <memory>
#include <string>

#include <QObject>
#include <QString>

#include <tensorflow/lite/error_reporter.h>
#include <tensorflow/lite/graph_info.h>
#include <tensorflow/lite/interpreter.h>
#include <tensorflow/lite/kernels/register.h>
#include <tensorflow/lite/model.h>

QT_BEGIN_NAMESPACE
class QImage;
QT_END_NAMESPACE

struct result_t {
  QStringList caption;
  QList<double> confidence;
};

class ModelTPU {
 public:
  //  explicit ModelTPU(const std::string &path);
  explicit ModelTPU(const QString &path);
  ~ModelTPU() {}

 private:
  std::unique_ptr<tflite::FlatBufferModel> model;
  tflite::ops::builtin::BuiltinOpResolver resolver;
  std::unique_ptr<tflite::Interpreter> interpreter;
  std::vector<TfLiteTensor *> outputs;
  tflite::StderrReporter error_reporter;
};

class ModelTensorFlowTFlite {
 public:
  explicit ModelTensorFlowTFlite(const QString &path_to_model);

  ~ModelTensorFlowTFlite() {}

  void run();

  void setInput(QImage image);

 private:
  //  functions
  void init_model_TFLite(const std::string &path);
  bool getObjectOutputsTFLite(QStringList &captions, QList<double> &confidences,
                              QList<QRectF> &locations, QList<QImage> &masks);

  // constants
  static constexpr double MASK_THRESHOLD{0.3};

  // parametric threshold
  float threshold;

  // output string
  const QString m_num_detections = "num_detections: ";
  const QString m_detection_classes = "detection_classes: ";
  const QString m_detection_scores = "detection_scores: ";
  const QString m_detection_boxes = "detection_boxes: ";
  const QString m_detection_masks = "detection_masks: ";

  // image properties
  const int m_num_channels{3};
  int img_height, img_width;

  // detection mask
  bool has_detection_mask;

  // model
  std::unique_ptr<tflite::FlatBufferModel> model;
  tflite::ops::builtin::BuiltinOpResolver resolver;
  tflite::StderrReporter error_reporter;
  std::unique_ptr<tflite::Interpreter> interpreter;
  std::vector<TfLiteTensor *> outputs;
};

#endif  // MODEL_TPU_HPP
