#include <QApplication>
#include <QObject>

#include "../log/instrumentor.h"
#include "../tf/findmodel.hpp"
#include "../tf/model_tpu.hpp"
#include "../tf/util_label_image.hpp"
#include "mainwindow.hpp"

int main(int argc, char* argv[]) {
#if PROFILING
  Instrumentor::Get().BeginSession("Profile");
#endif
  QApplication a(argc, argv);
  MainWindow w;
  w.setWindowTitle("Receiver");
  w.show();
  // initiliaze qdialog for setup model and label
  FindModel m;
  m.exec();
  while (m.isVisible()) {
    m.show();
  }
  // get path
  auto dd = m.getLabelPath();
  auto zz = m.getModelPath();
  LabelDetection label(dd);
  label.read();
  ModelTensorFlowLite modeltflite(zz);
  modeltflite.setLabel(label.getLabels());
  QObject::connect(&w, &MainWindow::updateImage, [&modeltflite](QPixmap img) {
    modeltflite.imageAvailable(img);
  });

  auto r = a.exec();
#if PROFILING
  Instrumentor::Get().EndSession();
#endif
  return r;
}
