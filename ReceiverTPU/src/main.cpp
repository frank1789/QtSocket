#include <QApplication>
#include <QObject>
#include <iostream>

#include "../log/instrumentor.h"
#include "../tf/findmodel.hpp"
#include "../tf/model_tpu.hpp"
#include "../tf/model_utils.h"
#include "../tf/util_label_image.hpp"
#include "edgetpu.h"
#include "mainwindow.hpp"

const QString model_path{
    "/resources/mobilenet_ssd_v1_coco_quant_postprocess_edgetpu.tflite"};

int main(int argc, char* argv[]) {
#if PROFILING
  Instrumentor::Get().BeginSession("Profile");
#endif
  QApplication a(argc, argv);
  MainWindow w;
  w.setWindowTitle("Receiver");
  w.show();

  //    initialize model
  auto path = QApplication::applicationDirPath() + model_path;
  // Read model.
  std::unique_ptr<tflite::FlatBufferModel> model =
      tflite::FlatBufferModel::BuildFromFile(path.toStdString().c_str());
  if (model == nullptr) {
    std::cerr << "Fail to build FlatBufferModel from file: "
              << path.toStdString().c_str() << std::endl;
    std::abort();
  }

  // Build interpreter.
  std::shared_ptr<edgetpu::EdgeTpuContext> edgetpu_context =
      edgetpu::EdgeTpuManager::GetSingleton()->OpenDevice();
  std::unique_ptr<tflite::Interpreter> interpreter =
      coral::BuildEdgeTpuInterpreter(*model, edgetpu_context.get());

  //    // Read the resized image file.
  int width{0}, height{0}, channels{0};
  //    const std::vector<uint8_t>& input =
  //        read_bmp(resized_image_path, &width, &height, &channels);

  const auto& required_shape = coral::GetInputShape(*interpreter, 0);
  if (height != required_shape[0] || width != required_shape[1] ||
      channels != required_shape[2]) {
    std::cerr << "Input size mismatches: "
              << "width: " << width << " vs " << required_shape[0]
              << ", height: " << height << " vs " << required_shape[1]
              << ", channels: " << channels << " vs " << required_shape[2]
              << std::endl;
    std::abort();
  }

  //  ModelTensorFlowLite modeltflite(path);
  //  modeltflite.setLabel(label);
  //  QObject::connect(&w, &MainWindow::updateImage, [&modeltflite](QPixmap img)
  //  {
  //    modeltflite.imageAvailable(img);
  //  });

  auto r = a.exec();
#if PROFILING
  Instrumentor::Get().EndSession();
#endif
  return r;
}
