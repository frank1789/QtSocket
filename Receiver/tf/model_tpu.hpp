#ifndef MODEL_TPU_HPP
#define MODEL_TPU_HPP

#include <QObject>
#include <memory>
#include <string>

#include "tensorflow/lite/interpreter.h"
#include "tensorflow/lite/kernels/register.h"
#include "tensorflow/lite/model.h"

QT_BEGIN_NAMESPACE
class QImage;
class QString;
class QPixmap;
QT_END_NAMESPACE

enum class TypeDetection : int { ImageClassifier, ObjectDetection };

struct result_t {
  // Results
  QList<QString> caption;
  QList<double> confidences;
  QList<QRectF> box;
  QList<QImage> masks;
};

struct Res {
  QString label;
  int index;
  double score;
};

class ModelTensorFlowLite : public QObject {
 public:
  explicit ModelTensorFlowLite();
  void InitializeModelTFLite(const std::string &path);
  void LoadModelFromFile(const std::string &path);
  void LoadModelFromFile(const QString &path);
  void RunInference(const QImage &image);
  void ClassifierOutput();
  void setInput(QImage image);

  bool get_classifier_output(std::vector<std::pair<float, int>> *top_results);
  bool get_object_outputs();

  void setLabel(const std::unordered_map<int, std::string> &l);
  std::string getLabel(int i);

  std::vector<Res> getResults();

  std::vector<std::pair<float, int>> getResultClassification() const;

 public slots:
  void imageAvailable(QPixmap image);
  void imageAvailable(QImage image);

 private:
  //  methods
  void init_model_TFLite(const std::string &path);
  bool getObjectOutputsTFLite(QStringList &captions, QList<double> &confidences,
                              QList<QRectF> &locations, QList<QImage> &masks);

  // input image properties
  const int m_num_channels{3};
  int img_height, img_width;
  // size tensor image desired
  int wanted_height_;
  int wanted_width_;
  int wanted_channels_;
  // detection mask
  bool has_detection_mask_;
  TypeDetection kind_network_{TypeDetection::ObjectDetection};

  // thread
  unsigned int num_threads_;

  result_t m_result;

  std::vector<Res> resu;

  std::vector<std::pair<float, int>> top_results;

  std::unordered_map<int, std::string> m_labels;

  // model
  std::unique_ptr<tflite::FlatBufferModel> model{nullptr};
  tflite::ops::builtin::BuiltinOpResolver resolver;
  tflite::StderrReporter error_reporter;
  std::unique_ptr<tflite::Interpreter> interpreter{nullptr};
  std::vector<TfLiteTensor *> outputs;
};

#endif  // MODEL_TPU_HPP
