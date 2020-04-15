#ifndef TEST_LABEL_FUNCTION_HPP
#define TEST_LABEL_FUNCTION_HPP

#include <unordered_map>
#include <string>

inline const std::string getLabel(std::unordered_map<int, std::string> label, int i) {
  std::unordered_map<int, std::string>::iterator it = label.find(i);
  return it->second;
}

inline const int getIndexLabel(std::unordered_map<int, std::string> label, int i) {
  std::unordered_map<int, std::string>::iterator it = label.find(i);
  return it->first;
}

#endif //TEST_LABEL_FUNCTION_HPP