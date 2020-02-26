#include <QApplication>
#include <QObject>

#include "../log/instrumentor.h"
#include "../tf/findmodel.hpp"
#include "../tf/model_tpu.hpp"
#include "../tf/util_label_image.hpp"
#include "mainwindow.hpp"

const QString model_path{"/resources/detect.tflite"};

int main(int argc, char* argv[]) {
#if PROFILING
  Instrumentor::Get().BeginSession("Profile");
#endif
  QApplication a(argc, argv);
  MainWindow w;
  w.setWindowTitle("Receiver");
  w.show();
  //  initialize model
  auto path = QApplication::applicationDirPath() + model_path;
  ModelTensorFlowLite modeltflite(path);
  modeltflite.setLabel(label);
  QObject::connect(&w, &MainWindow::updateImage, [&modeltflite](QPixmap img) {
    modeltflite.imageAvailable(img);
  });

  auto r = a.exec();
#if PROFILING
  Instrumentor::Get().EndSession();
#endif
  return r;
}
