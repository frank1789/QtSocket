///
///
///
///
///
///
///
///

#ifndef MODEL_SUPPORT_FUNCTION_HPP
#define MODEL_SUPPORT_FUNCTION_HPP 

// --------------------------------------------------------------------------------------
// Code from:
// https://github.com/YijinLiu/tf-cpu/blob/master/benchmark/obj_detect_lite.cc
// --------------------------------------------------------------------------------------
template <typename T>
T* TensorData(TfLiteTensor* tensor, int batch_index);

template <>
float* TensorData(TfLiteTensor* tensor, int batch_index) {
  int nelems = 1;
  for (int i = 1; i < tensor->dims->size; i++) nelems *= tensor->dims->data[i];
  switch (tensor->type) {
    case kTfLiteFloat32:
      return tensor->data.f + nelems * batch_index;
    default:
      qDebug() << "Should not reach here!";
  }
  return nullptr;
}

template <>
uint8_t* TensorData(TfLiteTensor* tensor, int batch_index) {
  int nelems = 1;
  for (int i = 1; i < tensor->dims->size; i++) nelems *= tensor->dims->data[i];
  switch (tensor->type) {
    case kTfLiteUInt8:
      return tensor->data.uint8 + nelems * batch_index;
    default:
      qDebug() << "Should not reach here!";
  }
  return nullptr;
}











#endif // MODEL_SUPPORT_FUNCTION_HPP