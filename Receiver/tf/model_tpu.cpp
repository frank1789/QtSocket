#include "model_tpu.hpp"

#include <QDebug>
#include <QImage>
#include <QPixmap>
#include <QThread>

#include "colormanager.hpp"
#include "image_utils.hpp"
#include "instrumentor.h"
#include "logger.h"
#include "model_support_function.hpp"
#include "tensorflow/lite/examples/label_image/bitmap_helpers_impl.h"
#include "tensorflow/lite/examples/label_image/get_top_n_impl.h"
#include "tensorflow/lite/kernels/internal/tensor.h"
#include "tensorflow/lite/kernels/internal/tensor_utils.h"

namespace tfclassif = tflite::label_image;

constexpr float kMinimumThreshold{0.001f};

constexpr float kThreshold{0.001f};

ModelTensorFlowLite::ModelTensorFlowLite()
    : QObject(),
      threshold(kMinimumThreshold),
      img_height(512),
      img_width(512),
      wanted_height(0),
      wanted_width(0),
      wanted_channels(3),
      has_detection_mask(false),
      kind_network(type_detection::none),
      numThreads(QThread::idealThreadCount()) {
  LOG(INFO, "ctor model tensorflow lite")
  LOG(DEBUG, "ideal thread count: %d", numThreads)
}

void ModelTensorFlowLite::LoadModelFromFile(const std::string &path) {
  InitializeModelTFLite(path);
}

void ModelTensorFlowLite::LoadModelFromFile(const QString &path) {
  InitializeModelTFLite(path.toStdString());
}

void ModelTensorFlowLite::InitializeModelTFLite(const std::string &path) {
  // open model and assign error reporter
  try {
    model =
        tflite::FlatBufferModel::BuildFromFile(path.c_str(), &error_reporter);
    if (model == nullptr) {
      LOG(FATAL, "can't load TensorFLow lite model from: %", path.c_str())
    }
    // link model and resolver
    tflite::InterpreterBuilder(*model.get(), resolver)(&interpreter);

    // Apply accelaration (Neural Network Android)
    //    interpreter->UseNNAPI(accelaration);

    if (interpreter->AllocateTensors() != kTfLiteOk) {
      LOG(ERROR, "failed to allocate tensor")
    }

    if (interpreter->outputs().size() > 1) {
      kind_network = type_detection::object_detection;
    } else {
      kind_network = type_detection::image_classifier;
    }

    // Get input dimension from the input tensor metadata
    // Assuming one input only
    int input = interpreter->inputs()[0];
    TfLiteIntArray *dims = interpreter->tensor(input)->dims;

    // Save outputs
    outputs.clear();
    for (unsigned int i = 0; i < interpreter->outputs().size(); ++i) {
      outputs.push_back(interpreter->tensor(interpreter->outputs()[i]));
    }

    wanted_height = dims->data[1];
    wanted_width = dims->data[2];
    wanted_channels = dims->data[3];

    if (numThreads > 1) {
      interpreter->SetNumThreads(numThreads);
    }
    LOG(INFO, "Tensorflow initialization: OK")

#if LOGGER_CNN
    LOG(INFO, "verbose mode enable")
    auto i_size = interpreter->inputs().size();
    auto o_size = interpreter->outputs().size();
    auto t_size = interpreter->tensors_size();

    qDebug() << "tensors size: " << t_size;
    qDebug() << "nodes size: " << interpreter->nodes_size();
    qDebug() << "inputs: " << i_size;
    qDebug() << "outputs: " << o_size;

    for (auto i = 0; i < i_size; i++)
      qDebug() << "input" << i << "name:" << interpreter->GetInputName(i)
               << ", type:"
               << interpreter->tensor(interpreter->inputs()[i])->type;

    for (auto i = 0; i < o_size; i++)
      qDebug() << "output" << i << "name:" << interpreter->GetOutputName(i)
               << ", type:"
               << interpreter->tensor(interpreter->outputs()[i])->type;

    for (auto i = 0; i < t_size; i++) {
      if (interpreter->tensor(i)->name)
        qDebug() << i << ":" << interpreter->tensor(i)->name << ","
                 << interpreter->tensor(i)->bytes << ","
                 << interpreter->tensor(i)->type << ","
                 << interpreter->tensor(i)->params.scale << ","
                 << interpreter->tensor(i)->params.zero_point;
    }

    qDebug() << "Wanted height:" << wanted_height;
    qDebug() << "Wanted width:" << wanted_width;
    qDebug() << "Wanted channels:" << wanted_channels;
#endif

  } catch (...) {
    LOG(FATAL, "can't load TensorFLow lite model from: %", path.c_str())
    std::abort();
  }
}

void ModelTensorFlowLite::setLabel(
    const std::unordered_map<int, std::string> &l) {
  m_labels = l;
}

void ModelTensorFlowLite::imageAvailable(QPixmap image) {
  if (!image.isNull()) {
    LOG(DEBUG, "image not null: %s", !image.isNull() ? "true" : "false")
    QImage input = image.toImage().convertToFormat(QImage::Format_RGB888);
    RunInference(input);
  }
}

void ModelTensorFlowLite::imageAvailable(QImage image) {
  if (!image.isNull()) {
    LOG(DEBUG, "image not null: %s", !image.isNull() ? "true" : "false")
    QImage input = image.convertToFormat(QImage::Format_RGB888);
    RunInference(image);
  }
}

void ModelTensorFlowLite::RunInference(const QImage &image) {
  LOG(DEBUG, "RunInference")
  PROFILE_FUNCTION();
  // const std::vector<int> inputs = interpreter->inputs();
  // const std::vector<int> outputs = interpreter->outputs();
  // detect kind input
  int input = interpreter->inputs()[0];
  TfLiteType input_type = interpreter->tensor(input)->type;
  LOG(DEBUG, "detect input type")
  switch (input_type) {
    case kTfLiteFloat32:
      LOG(DEBUG, "case kTfLiteFloat32")
      resize_image<float>(interpreter->typed_tensor<float>(input), image.bits(),
                          img_height, img_width, m_num_channels, wanted_height,
                          wanted_width, wanted_channels, input_type);
      break;
    case kTfLiteInt8:
      LOG(DEBUG, "case kTfLiteInt8")
      resize_image<int8_t>(interpreter->typed_tensor<int8_t>(input),
                           image.bits(), img_height, img_width, m_num_channels,
                           wanted_height, wanted_width, wanted_channels,
                           input_type);
      break;
    case kTfLiteUInt8:
      LOG(DEBUG, "case kTfLiteUInt8")
      resize_image<uint8_t>(interpreter->typed_tensor<uint8_t>(input),
                            image.bits(), img_height, img_width, m_num_channels,
                            wanted_height, wanted_width, wanted_channels,
                            input_type);
      break;
    default:
      LOG(FATAL, "cannot handle input type %s yet",
          interpreter->tensor(input)->type)
      std::exit(-1);
  }
  for (int i = 0; i < 2; i++) {
    interpreter->Invoke();
    if (interpreter->Invoke() != kTfLiteOk) {
      LOG(FATAL, "Failed to invoke tflite!")
    }
  }

  if (kind_network == type_detection::image_classifier) {
    ClassifierOutput();
  } else {
    get_object_outputs();
  }
}

// void ModelTensorFlowLite::run(QImage image) {
//   LOG(DEBUG, "run inference tflite")
//   PROFILE_FUNCTION();
//   setInput(image);
//   // perform inference
//   if (interpreter->Invoke() != kTfLiteOk) {
//     LOG(ERROR, "failed to invoke interpreter")
//     return;
//   }
//   // check if classifier or object detection
//   LOG(DEBUG, "detect network: %d", kind_network)
//   switch (kind_network) {
//     case type_detection::image_classifier: {
//       if (!get_classifier_output(&top_results)) {
//         LOG(DEBUG, "empty result")
//         return;
//       }
//       break;
//     }
//     case type_detection::object_detection: {
//       LOG(DEBUG, "retrive object detection result")
//       if (!get_object_outputs()) {
//         LOG(DEBUG, "empty result")
//         return;
//       }
//       break;
//     }
//   }
// }

// void ModelTensorFlowLite::init_model_TFLite(const std::string &path) {
//   // open model and assign error reporter
//   try {
//     model =
//         tflite::FlatBufferModel::BuildFromFile(path.c_str(),
//         &error_reporter);
//     if (model == nullptr) {
//       LOG(FATAL, "can't load TensorFLow lite model from: %", path.c_str())
//     }
//     // link model and resolver
//     tflite::InterpreterBuilder builder(*model.get(), resolver);
//     // Check interpreter
//     if (builder(&interpreter) != kTfLiteOk) {
//       LOG(ERROR, "interpreter is not ok")
//     }

//     // Apply accelaration (Neural Network Android)
//     //    interpreter->UseNNAPI(accelaration);

//     if (interpreter->AllocateTensors() != kTfLiteOk) {
//       LOG(ERROR, "failed to allocate tensor")
//     }

//     // Set kind of network
//     kind_network = interpreter->outputs().size() > 1
//                        ? type_detection::object_detection
//                        : type_detection::image_classifier;

// #if LOGGER_CNN
//     LOG(INFO, "verbose mode enable")
//     auto i_size = interpreter->inputs().size();
//     auto o_size = interpreter->outputs().size();
//     auto t_size = interpreter->tensors_size();

//     qDebug() << "tensors size: " << t_size;
//     qDebug() << "nodes size: " << interpreter->nodes_size();
//     qDebug() << "inputs: " << i_size;
//     qDebug() << "outputs: " << o_size;

//     for (auto i = 0; i < i_size; i++)
//       qDebug() << "input" << i << "name:" << interpreter->GetInputName(i)
//                << ", type:"
//                << interpreter->tensor(interpreter->inputs()[i])->type;

//     for (auto i = 0; i < o_size; i++)
//       qDebug() << "output" << i << "name:" << interpreter->GetOutputName(i)
//                << ", type:"
//                << interpreter->tensor(interpreter->outputs()[i])->type;

//     for (auto i = 0; i < t_size; i++) {
//       if (interpreter->tensor(i)->name)
//         qDebug() << i << ":" << interpreter->tensor(i)->name << ","
//                  << interpreter->tensor(i)->bytes << ","
//                  << interpreter->tensor(i)->type << ","
//                  << interpreter->tensor(i)->params.scale << ","
//                  << interpreter->tensor(i)->params.zero_point;
//     }
// #endif

//     // Get input dimension from the input tensor metadata
//     // Assuming one input only
//     int input = interpreter->inputs()[0];
//     TfLiteIntArray *dims = interpreter->tensor(input)->dims;

//     // Save outputs
//     outputs.clear();
//     for (unsigned int i = 0; i < interpreter->outputs().size(); ++i)
//       outputs.push_back(interpreter->tensor(interpreter->outputs()[i]));

//     wanted_height = dims->data[1];
//     wanted_width = dims->data[2];
//     wanted_channels = dims->data[3];

// #if LOGGER_CNN
//     qDebug() << "Wanted height:" << wanted_height;
//     qDebug() << "Wanted width:" << wanted_width;
//     qDebug() << "Wanted channels:" << wanted_channels;
// #endif

//     if (numThreads > 1) interpreter->SetNumThreads(numThreads);
//     LOG(INFO, "Tensorflow initialization: OK")
//   } catch (...) {
//     LOG(FATAL, "can't load TensorFLow lite model from: %", path.c_str())
//     std::abort();
//   }
// }

// void ModelTensorFlowLite::setInput(QImage image) {
//   // get inputs
//   std::vector<int> inputs = interpreter->inputs();
//   // set inputs
//   for (unsigned int i = 0; i < interpreter->inputs().size(); ++i) {
//     auto input = inputs[i];
//     // convert input
//     switch (interpreter->tensor(input)->type) {
//       case kTfLiteFloat32:
//         formatImageTFLite<float>(interpreter->typed_tensor<float>(input),
//                                  image.bits(), image.height(), image.width(),
//                                  m_num_channels, wanted_height, wanted_width,
//                                  wanted_channels, true);
//         break;
//       case kTfLiteUInt8:
//         formatImageTFLite<uint8_t>(interpreter->typed_tensor<uint8_t>(input),
//                                    image.bits(), img_height, img_width,
//                                    m_num_channels, wanted_height,
//                                    wanted_width, wanted_channels, false);
//         break;
//       default:
//         LOG(WARN, "Cannot handle input type %s yet",
//             interpreter->tensor(input)->type)
//         return;
//     }
//   }
// }

// bool ModelTensorFlowLite::get_classifier_output(
//     std::vector<std::pair<float, int>> *top_results) {
//   bool status{false};
//   const int output_size = 1000;
//   const size_t num_results = 5;
//   // Assume one output
//   if (interpreter->outputs().size() > 0) {
//     int output = interpreter->outputs()[0];
//     switch (interpreter->tensor(output)->type) {
//       case kTfLiteFloat32: {
//         tflite::label_image::get_top_n<float>(
//             interpreter->typed_output_tensor<float>(0), output_size,
//             num_results, threshold, top_results, true);
//         status = true;
//         break;
//       }
//       case kTfLiteUInt8: {
//         tflite::label_image::get_top_n<uint8_t>(
//             interpreter->typed_output_tensor<uint8_t>(0), output_size,
//             num_results, threshold, top_results, false);
//         status = true;
//         break;
//       }
//       default: {
//         LOG(ERROR, "Cannot handle output type %s yet",
//             interpreter->tensor(output)->type)
//         status = false;
//       }
//     }
//   }
//   return status;
// }

bool ModelTensorFlowLite::get_object_outputs() {
  bool status{false};
  if (outputs.size() >= 4) {
    const int num_detections =
        static_cast<int>(*TensorData<float>(outputs[3], 0));
    const float *detection_classes = TensorData<float>(outputs[1], 0);
    const float *detection_scores = TensorData<float>(outputs[2], 0);
    const float *detection_boxes = TensorData<float>(outputs[0], 0);
    const float *detection_masks = !has_detection_mask || outputs.size() < 5
                                       ? nullptr
                                       : TensorData<float>(outputs[4], 0);
    ColorManager cm;

    for (int i = 0; i < num_detections; i++) {
      // Get class
      const int cls = static_cast<int>(detection_classes[i]);
      // Ignore first one
      if (cls == 0) continue;
      // Get score
      auto score = detection_scores[i];
      // Check minimum score
      if (score < threshold) {
        LOG(WARN, "low score: %3.3lf, class %s", static_cast<double>(score),
            getLabel(cls).c_str())
        break;
      }
      // Get class label
      const auto label = getLabel(cls);
      // Get coordinates
      const float top = detection_boxes[4 * i] * img_height;
      const float left = detection_boxes[4 * i + 1] * img_width;
      const float bottom = detection_boxes[4 * i + 2] * img_height;
      const float right = detection_boxes[4 * i + 3] * img_width;
      // Save coordinates
      QRectF box(left, top, right - left, bottom - top);
      // Get masks
      // WARNING: Under development
      // https://github.com/matterport/Mask_RCNN/issues/222
      if (detection_masks != nullptr) {
        const int dim1 = outputs[4]->dims->data[2];
        const int dim2 = outputs[4]->dims->data[3];
        QImage mask(dim1, dim2, QImage::Format_ARGB32_Premultiplied);
        // Set binary mask [dim1,dim2]
        for (int j = 0; j < mask.height(); j++) {
          for (int k = 0; k < mask.width(); k++) {
            auto index = i * dim1 * dim2 + j * dim2 + k;
            auto check = detection_masks[index] >= MASK_THRESHOLD;
            auto fill = (check == true)
                            ? cm.getColor(QString::fromStdString(label))
                            : QColor(Qt::transparent);
            mask.setPixel(k, j, fill.rgba());
          }
        }

        // Billinear interpolation
        // https://chu24688.tian.yam.com/posts/44797337
        // QImage maskScaled =
        //
        ColorManager::billinearInterpolation(mask, box.height(), box.width());

        // Scale mask to box size
        QImage maskScaled = mask.scaled(
            static_cast<int>(box.width()), static_cast<int>(box.height()),
            Qt::IgnoreAspectRatio, Qt::FastTransformation);

        // Border detection
        //         QTransform trans(-1,0,1,-2,0,2,-1,0,1);
        //         maskScaled =
        //         ColorManager::applyTransformation(maskScaled,trans);

        // Append to masks
        //        result->masks.append(maskScaled);
      }
      // Append data
      LOG(DEBUG, "label: %s, score: %3.3lf", label.c_str(),
          static_cast<double>(score))
      //      result->caption.append(label);
      //      result->confidences.append(static_cast<double>(score));
      //      result->box.append(box);
      resu.push_back(
          {QString::fromStdString(label), cls, static_cast<double>(score)});
      status = true;
    }
  }
  return status;
}

std::string ModelTensorFlowLite::getLabel(int i) {
  std::unordered_map<int, std::string>::iterator it = m_labels.find(i);
  LOG(DEBUG, "search for class %d, found %s", i, it->second.c_str())
  return it->second;
}

std::vector<Res> ModelTensorFlowLite::getResults() { return resu; }

std::vector<std::pair<float, int>>
ModelTensorFlowLite::getResultClassification() const {
  return top_results;
}

void ModelTensorFlowLite::ClassifierOutput() {
  int output = interpreter->outputs()[0];
  TfLiteIntArray *output_dims = interpreter->tensor(output)->dims;
  // assume output dims to be something like (1, 1, ... ,size)
  auto output_size = output_dims->data[output_dims->size - 1];
  auto number_of_results = 5;
  auto input_type = interpreter->tensor(output)->type;
  switch (interpreter->tensor(output)->type) {
    case kTfLiteFloat32:
      tfclassif::get_top_n<float>(interpreter->typed_output_tensor<float>(0),
                                  output_size, number_of_results, threshold,
                                  &top_results, input_type);
      break;
    case kTfLiteInt8:
      tfclassif::get_top_n<int8_t>(interpreter->typed_output_tensor<int8_t>(0),
                                   output_size, number_of_results, threshold,
                                   &top_results, input_type);
      break;
    case kTfLiteUInt8:
      tfclassif::get_top_n<uint8_t>(
          interpreter->typed_output_tensor<uint8_t>(0), output_size,
          number_of_results, threshold, &top_results, input_type);
      break;
    default:
      LOG(FATAL, "cannot handle output type %s yet",
          interpreter->tensor(output)->type)
      std::exit(-1);
  }
}
