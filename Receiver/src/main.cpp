#include "mainwindow.hpp"

#include <QApplication>
#include <QObject>
#include <iostream>

#include "../log/instrumentor.h"
#include "tf/findmodel.hpp"
#include "tf/model_tpu.hpp"
//#include "util_label_image.hpp"

#include <chrono>
#include <thread>

const QString model_path{
    "/Users/francesco/Documents/Project/tcpsocket/Receiver/models"};

int main(int argc, char* argv[]) {
#if PROFILING
  Instrumentor::Get().BeginSession("Profile");
#endif
  QApplication a(argc, argv);
  MainWindow w;
  w.show();
  FindModel m;
  m.show();
  //  FindModel all_models(model_path);
  //  switch (all_models.count()) {
  //    case 1: {
  //      QString first_model = all_models.getModelPath();
  //      break;
  //    }
  //    case 2: {
  //      std::this_thread::sleep_for(std::chrono::milliseconds(20));
  //      break;
  //    }
  //    default: {
  //      std::this_thread::sleep_for(std::chrono::milliseconds(450));
  //      all_models.show();
  //      //      qDebug() << all_models.getModelPath();
  //    }
  //  }

  //  auto model =
  //      ModelTPU(QString("/Users/francesco/Documents/Project/tcpsocket/Receiver/"
  //                       "models/detect.tflite"));

  //  ModelTensorFlowTFlite modeltflite;
  auto r = a.exec();

  //  std::unordered_map<int, std::string> mymap = read_label_file(
  //      "/Users/francesco/Documents/Project/tcpsocket/Receiver/"
  //      "imagenet_labels.txt",
  //      LabelSplitter::imagenet_label_split);

  //  for (const auto& n : mymap) {
  //    qDebug() << n.first << QString::fromStdString(n.second).trimmed();
  //    //    std::cout << n.second;
  //  }

#if PROFILING
  Instrumentor::Get().EndSession();
#endif
  return r;
}
