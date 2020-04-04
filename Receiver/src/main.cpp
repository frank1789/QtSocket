#include <QApplication>
#include <QObject>

#include "../log/instrumentor.h"
#include "../tf/findmodel.hpp"
#include "../tf/model_tpu.hpp"
#include "../tf/util_label_image.hpp"
#include "mainwindow.hpp"

const QString local_model_path{"/resources/detect.tflite"};
const QString local_label_path{"/resources/coco_labels.txt"};

int main(int argc, char* argv[]) {
#if PROFILING
  Instrumentor::Get().BeginSession("Profile");
#endif
  QApplication a(argc, argv);
  MainWindow w;
  w.setWindowTitle("Receiver");
  w.show();
  // initialize QDialog, then setup model and label
  auto model_path = QApplication::applicationDirPath() + local_model_path;
  auto label_path = QApplication::applicationDirPath() + local_label_path;
  if (!QFile::exists(model_path) && !QFile::exists(label_path)) {
#if LOGGER
    LOG(ERROR, "model file and label file not found, throw ui")
#endif
    FindModel m;
    m.exec();
    while (m.isVisible()) {
      m.show();
    }
    // update path
    label_path = m.getLabelPath();
    model_path = m.getModelPath();
  }
  LabelDetection label(label_path);
  label.read();
  ModelTensorFlowLite model_tflite(model_path);
  model_tflite.setLabel(label.getLabels());
  QObject::connect(&w, &MainWindow::updateImage, &model_tflite,
                   &ModelTensorFlowLite::imageAvailable);

  auto r = a.exec();
#if PROFILING
  Instrumentor::Get().EndSession();
#endif
  return r;
}
