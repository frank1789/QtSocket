#include "model_tpu.hpp"

#include <QDebug>
#include <QImage>

#include <tensorflow/lite/kernels/builtin_op_kernels.h>
#include <tensorflow/lite/kernels/internal/tensor.h>
#include <tensorflow/lite/kernels/internal/tensor_utils.h>

#include "log/instrumentor.h"
#include "log/logger.h"
#include "model_support_function.hpp"

///
///-----------------------------------------------------------------------------------------------------------------------
///
/// https://github.com/tensorflow/tensorflow/blob/master/tensorflow/contrib/lite/examples/label_image/bitmap_helpers_impl.h
///
///-----------------------------------------------------------------------------------------------------------------------

// template <class T>
// void formatImageTFLite(T* out, const uint8_t* in, int image_height,
//                       int image_width, int image_channels, int wanted_height,
//                       int wanted_width, int wanted_channels,
//                       bool input_floating) {
//  constexpr float input_mean = 127.5f;
//  constexpr float input_std = 127.5f;

//  int number_of_pixels = image_height * image_width * image_channels;
//  std::unique_ptr<tflite::Interpreter> interpreter(new tflite::Interpreter);

//  int base_index = 0;

//  // two inputs: input and new_sizes
//  interpreter->AddTensors(2, &base_index);

//  // one output
//  interpreter->AddTensors(1, &base_index);

//  // set input and output tensors
//  interpreter->SetInputs({0, 1});
//  interpreter->SetOutputs({2});

//  // set parameters of tensors
//  TfLiteQuantizationParams quant;
//  interpreter->SetTensorParametersReadWrite(
//      0, kTfLiteFloat32, "input",
//      {1, image_height, image_width, image_channels}, quant);
//  interpreter->SetTensorParametersReadWrite(1, kTfLiteInt32, "new_size", {2},
//                                            quant);
//  interpreter->SetTensorParametersReadWrite(
//      2, kTfLiteFloat32, "output",
//      {1, wanted_height, wanted_width, wanted_channels}, quant);

//  tflite::ops::builtin::BuiltinOpResolver resolver;
//  const TfLiteRegistration* resize_op =
//      resolver.FindOp(tflite::BuiltinOperator_RESIZE_BILINEAR, 1);
//  auto* params = reinterpret_cast<TfLiteResizeBilinearParams*>(
//      malloc(sizeof(TfLiteResizeBilinearParams)));
//  params->align_corners = false;
//  interpreter->AddNodeWithParameters({0, 1}, {2}, nullptr, 0, params,
//  resize_op,
//                                     nullptr);
//  interpreter->AllocateTensors();

//  // fill input image
//  // in[] are integers, cannot do memcpy() directly
//  auto input = interpreter->typed_tensor<float>(0);
//  for (int i = 0; i < number_of_pixels; i++) input[i] = in[i];

//  // fill new_sizes
//  interpreter->typed_tensor<int>(1)[0] = wanted_height;
//  interpreter->typed_tensor<int>(1)[1] = wanted_width;

//  interpreter->Invoke();

//  auto output = interpreter->typed_tensor<float>(2);
//  auto output_number_of_pixels =
//      wanted_height * wanted_height * wanted_channels;

//  for (int i = 0; i < output_number_of_pixels; i++) {
//    if (input_floating)
//      out[i] = (output[i] - input_mean) / input_std;
//    else
//      out[i] = (uint8_t)output[i];
//  }
//}

// ModelTensorFlowTFlite::ModelTensorFlowTFlite(const QString& path_to_model) {
//  init_model_TFLite(path_to_model.toStdString());
//}

// void ModelTensorFlowTFlite::run() {
//  PROFILE_FUNCTION();
//  // check input

//  // perform inference

//  // check if classifier or object detection
//}

// void ModelTensorFlowTFlite::init_model_TFLite(const std::string& path) {
//  // open model and assign error reporter
//  try {
//    model =
//        tflite::FlatBufferModel::BuildFromFile(path.c_str(), &error_reporter);
//    if (model == nullptr) {
//      LOG(FATAL, "can't load TensorFLow lite model from: %", path.c_str())
//    }
//    // link model and resolver
//    tflite::InterpreterBuilder builder(*model.get(), resolver);
//    // Check interpreter
//    if (builder(&interpreter) != kTfLiteOk) {
//      LOG(ERROR, "interpreter is not ok")
//    }

//    // Apply accelaration (Neural Network Android)
//    //    interpreter->UseNNAPI(accelaration);

//    if (interpreter->AllocateTensors() != kTfLiteOk) {
//      LOG(ERROR, "failed to allocate tensor")
//    }

//    //    // Set kind of network
//    //    kind_network = interpreter->outputs().size() > 1 ?
//    knOBJECT_DETECTION
//    //                                                     :
//    knIMAGE_CLASSIFIER;

//    //    if (verbose) {
//    //      int i_size = interpreter->inputs().size();
//    //      int o_size = interpreter->outputs().size();
//    //      int t_size = interpreter->tensors_size();

//    //      qDebug() << "tensors size: " << t_size;
//    //      qDebug() << "nodes size: " << interpreter->nodes_size();
//    //      qDebug() << "inputs: " << i_size;
//    //      qDebug() << "outputs: " << o_size;

//    //      for (int i = 0; i < i_size; i++)
//    //        qDebug() << "input" << i << "name:" <<
//    //        interpreter->GetInputName(i)
//    //                 << ", type:"
//    //                 << interpreter->tensor(interpreter->inputs()[i])->type;

//    //      for (int i = 0; i < o_size; i++)
//    //        qDebug() << "output" << i << "name:" <<
//    //        interpreter->GetOutputName(i)
//    //                 << ", type:"
//    //                 <<
//    interpreter->tensor(interpreter->outputs()[i])->type;

//    //      for (int i = 0; i < t_size; i++) {
//    //        if (interpreter->tensor(i)->name)
//    //          qDebug() << i << ":" << interpreter->tensor(i)->name << ","
//    //                   << interpreter->tensor(i)->bytes << ","
//    //                   << interpreter->tensor(i)->type << ","
//    //                   << interpreter->tensor(i)->params.scale << ","
//    //                   << interpreter->tensor(i)->params.zero_point;
//    //      }
//    //    }

//    // Get input dimension from the input tensor metadata
//    // Assuming one input only
//    int input = interpreter->inputs()[0];
//    TfLiteIntArray* dims = interpreter->tensor(input)->dims;

//    // Save outputs
//    outputs.clear();
//    for (unsigned int i = 0; i < interpreter->outputs().size(); ++i)
//      outputs.push_back(interpreter->tensor(interpreter->outputs()[i]));

//    //    wanted_height = dims->data[1];
//    //    wanted_width = dims->data[2];
//    //    wanted_channels = dims->data[3];

//    //    if (verbose) {
//    //      qDebug() << "Wanted height:" << wanted_height;
//    //      qDebug() << "Wanted width:" << wanted_width;
//    //      qDebug() << "Wanted channels:" << wanted_channels;
//    //    }

//    //    if (numThreads > 1) interpreter->SetNumThreads(numThreads);

//    //    // Read labels
//    //    if (readLabels())
//    //      qDebug() << "There are" << labels.count() << "labels.";
//    //    else
//    //      qDebug() << "There are NO labels";

//    //    qDebug() << "Tensorflow initialization: OK";
//    //    return true;

//  } catch (...) {
//    LOG(FATAL, "can't load TensorFLow lite model from: %", path.c_str())
//    std::abort();
//  }
//}

// void ModelTensorFlowTFlite::setInput(QImage image) {
//  // get inputs
//  std::vector<int> inputs = interpreter->inputs();
//  // set inputs
//  for (unsigned int i = 0; i < interpreter->inputs().size(); ++i) {
//    auto input = inputs[i];
//    // convert input
//    switch (interpreter->tensor(input)->type) {
//      case kTfLiteFloat32:
//        break;
//      case kTfLiteUInt8:
//        break;
//      default:
//        LOG(WARN, "Cannot handle input type %c yet",
//            interpreter->tensor(input)->type)
//        return;
//    }
//  }
//}

// bool ModelTensorFlowTFlite::getObjectOutputsTFLite(QStringList& captions,
//                                                   QList<double>& confidences,
//                                                   QList<QRectF>& locations,
//                                                   QList<QImage>& masks) {
//  if (outputs.size() >= 4) {
//    const int num_detections =
//        static_cast<int>(*TensorData<float>(outputs[3], 0));
//    const float* detection_classes = TensorData<float>(outputs[1], 0);
//    const float* detection_scores = TensorData<float>(outputs[2], 0);
//    const float* detection_boxes = TensorData<float>(outputs[0], 0);
//    const float* detection_masks = !has_detection_mask || outputs.size() < 5
//                                       ? nullptr
//                                       : TensorData<float>(outputs[4], 0);
//    //    ColorManager cm;

//    for (int i = 0; i < num_detections; i++) {
//      // Get class
//      const int cls = static_cast<int>(detection_classes[i] + 1);

//      // Ignore first one
//      if (cls == 0) continue;

//      // Get score
//      auto score = detection_scores[i];

//      // Check minimum score
//      if (score < threshold) break;

//      // Get class label
//      const QString label = getLabel(cls);

//      // Get coordinates
//      const float top = detection_boxes[4 * i] * img_height;
//      const float left = detection_boxes[4 * i + 1] * img_width;
//      const float bottom = detection_boxes[4 * i + 2] * img_height;
//      const float right = detection_boxes[4 * i + 3] * img_width;

//      // Save coordinates
//      QRectF box(left, top, right - left, bottom - top);

//      // Get masks
//      // WARNING: Under development
//      // https://github.com/matterport/Mask_RCNN/issues/222
//      if (detection_masks != nullptr) {
//        const int dim1 = outputs[4]->dims->data[2];
//        const int dim2 = outputs[4]->dims->data[3];
//        QImage mask(dim1, dim2, QImage::Format_ARGB32_Premultiplied);

//        // Set binary mask [dim1,dim2]
//        for (int j = 0; j < mask.height(); j++)
//          for (int k = 0; k < mask.width(); k++)
//            mask.setPixel(k, j,
//                          detection_masks[i * dim1 * dim2 + j * dim2 + k] >=
//                                  MASK_THRESHOLD
//                              ? cm.getColor(label).rgba()
//                              : QColor(Qt::transparent).rgba());

//        // Billinear interpolation
//        // https://chu24688.tian.yam.com/posts/44797337
//        // QImage maskScaled =
//        //
//        ColorManager::billinearInterpolation(mask,box.height(),box.width());

//        // Scale mask to box size
//        QImage maskScaled =
//            mask.scaled(box.width(), box.height(), Qt::IgnoreAspectRatio,
//                        Qt::FastTransformation);

//        // Border detection
//        // QTransform trans(-1,0,1,-2,0,2,-1,0,1);
//        // maskScaled = ColorManager::applyTransformation(maskScaled,trans);

//        // Append to masks
//        masks.append(maskScaled);
//      }

//      // Save remaining data
//      captions.append(label);
//      confidences.append(score);
//      locations.append(box);
//    }

//    return true;
//  }
//  return false;
//}
