#ifndef OBJECT_DETECTION_HPP
#define OBJECT_DETECTION_HPP

#include <QObject>

#include <vector>
#include <memory>
#include "tensorflow/lite/kernels/internal/tensor.h"
#include "tensorflow/lite/kernels/internal/tensor_utils.h"

QT_BEGIN_NAMESPACE
class QImage;
class QRectF;
QT_END_NAMESPACE


class ObjectDetection {
    public:
    explicit ObjectDetection() = default;

    void SearchObject(const std::vector<TfLiteTensor *> &outputs,
                      float threshold, const QImage &img);

    std::vector<std::tuple<int, float, QRectF>> getResult() const;

    private:


    int     num_detections_;
    std::unique_ptr<float>   detection_classes_ {nullptr};
    std::unique_ptr<float>   detection_scores_     {nullptr};
    std::unique_ptr<float>   detection_boxes_  {nullptr};
    std::unique_ptr<float>   detection_masks_  {nullptr};

    std::vector<std::tuple<int, float, QRectF>> class_box_;
};




#endif // OBJECT_DETECTION_HPP











// bool ModelTensorFlowLite::get_object_outputs() {
//     bool status{false};
//     if (outputs.size() >= 4) {
//       const int num_detections =
//           static_cast<int>(*TensorData<float>(outputs[3], 0));
//       const float *detection_classes = TensorData<float>(outputs[1], 0);
//       const float *detection_scores = TensorData<float>(outputs[2], 0);
//       const float *detection_boxes = TensorData<float>(outputs[0], 0);
//       const float *detection_masks = !has_detection_mask_ || outputs.size() < 5
//                                          ? nullptr
//                                          : TensorData<float>(outputs[4], 0);
//       ColorManager cm;
  
//       for (int i = 0; i < num_detections; i++) {
//         // Get class
//         const int cls = static_cast<int>(detection_classes[i]);
//         // Ignore first one
//         if (cls == 0) continue;
//         // Get score
//         auto score = detection_scores[i];
//         // Check minimum score
//         if (score < kThreshold) {
//           LOG(WARN, "low score: %3.3lf, class %s", static_cast<double>(score),
//               getLabel(cls).c_str())
//           break;
//         }
//         // Get class label
//         const auto label = getLabel(cls);
//         // Get coordinates
//         const float top = detection_boxes[4 * i] * img_height;
//         const float left = detection_boxes[4 * i + 1] * img_width;
//         const float bottom = detection_boxes[4 * i + 2] * img_height;
//         const float right = detection_boxes[4 * i + 3] * img_width;
//         // Save coordinates
//         QRectF box(left, top, right - left, bottom - top);
//         // Get masks
//         // WARNING: Under development
//         // https://github.com/matterport/Mask_RCNN/issues/222
//         if (detection_masks != nullptr) {
//           const int dim1 = outputs[4]->dims->data[2];
//           const int dim2 = outputs[4]->dims->data[3];
//           QImage mask(dim1, dim2, QImage::Format_ARGB32_Premultiplied);
//           // Set binary mask [dim1,dim2]
//           for (int j = 0; j < mask.height(); j++) {
//             for (int k = 0; k < mask.width(); k++) {
//               auto index = i * dim1 * dim2 + j * dim2 + k;
//               auto check = detection_masks[index] >= kMaskThreshold;
//               auto fill = (check == true)
//                               ? cm.getColor(QString::fromStdString(label))
//                               : QColor(Qt::transparent);
//               mask.setPixel(k, j, fill.rgba());
//             }
//           }
  
//           // Billinear interpolation
//           // https://chu24688.tian.yam.com/posts/44797337
//           // QImage maskScaled =
//           //
//           ColorManager::billinearInterpolation(mask, box.height(), box.width());
  
//           // Scale mask to box size
//           QImage maskScaled = mask.scaled(
//               static_cast<int>(box.width()), static_cast<int>(box.height()),
//               Qt::IgnoreAspectRatio, Qt::FastTransformation);
  
//           // Border detection
//           //         QTransform trans(-1,0,1,-2,0,2,-1,0,1);
//           //         maskScaled =
//           //         ColorManager::applyTransformation(maskScaled,trans);
  
//           // Append to masks
//           //        result->masks.append(maskScaled);
//         }
//         // Append data
//         LOG(DEBUG, "label: %s, score: %3.3lf", label.c_str(),
//             static_cast<double>(score))
//         //      result->caption.append(label);
//         //      result->confidences.append(static_cast<double>(score));
//         //      result->box.append(box);
//         resu.push_back(
//             {QString::fromStdString(label), cls, static_cast<double>(score)});
//         status = true;
//       }
//     }
//     return status;
//   }
