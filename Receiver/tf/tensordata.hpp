#ifndef TENSOR_DATA_HPP
#define TENSOR_DATA_HPP

#include <cstdint>

#include "tensordata_impl.hpp"

template <typename T>
T* TensorData(TfLiteTensor* tensor, int batch_index);

template <>
float* TensorData(TfLiteTensor* tensor, int batch_index);

template <>
int8_t* TensorData(TfLiteTensor* tensor, int batch_index);

template <>
uint8_t* TensorData(TfLiteTensor* tensor, int batch_index);

#endif  // TENSOR_DATA_HPP