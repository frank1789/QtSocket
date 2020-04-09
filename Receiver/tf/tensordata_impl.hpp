#ifndef TENSOR_DATA_IMPL_HPP
#define TENSOR_DATA_IMPL_HPP

#include "logger.h"
#include "tensorflow/lite/builtin_op_data.h"
#include "tensorflow/lite/interpreter.h"
#include "tensorflow/lite/kernels/register.h"
#include "tensorflow/lite/string_util.h"

// --------------------------------------------------------------------------------------
// Code from:
// https://github.com/YijinLiu/tf-cpu/blob/master/benchmark/obj_detect_lite.cc
// --------------------------------------------------------------------------------------
template <typename T>
T* TensorData(TfLiteTensor* tensor, int batch_index) {
  int nelems = 1;
  for (int i = 1; i < tensor->dims->size; i++) nelems *= tensor->dims->data[i];
  switch (tensor->type) {
    case kTfLiteFloat32:
      return tensor->data.f + nelems * batch_index;

    case kTfLiteInt8:
      return tensor->data.int8 + nelems * batch_index;

    case kTfLiteUInt8:
      return tensor->data.uint8 + nelems * batch_index;

    default:
      LOG(FATAL, "cannot handle input type yet");
  }
  return nullptr;
}

#endif  // TENSOR_DATA_IMPL_HPP
