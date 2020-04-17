#include <QApplication>
#include <QObject>

#include "findmodel.hpp"
#include "instrumentor.h"
#include "labels.hpp"
#include "mainwindow.hpp"
#include "model_tpu.hpp"

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
    LOG(LevelAlert::E, "model file and label file not found, throw ui")
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
  ModelTensorFlowLite model_tflite;
  model_tflite.LoadModelFromFile(model_path);
  model_tflite.setLabel(label.getLabels());
  QObject::connect(
      &w, &MainWindow::updateImage,
      [&model_tflite](QPixmap pixmap) { model_tflite.imageAvailable(pixmap); });
  QObject::connect(&model_tflite, &ModelTensorFlowLite::objAvailable,
                   [&w](QImage frame, BoxDetection result) { w.boxDetection(frame, result); });

  auto r = a.exec();
#if PROFILING
  Instrumentor::Get().EndSession();
#endif
  return r;
}
