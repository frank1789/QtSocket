#include "list_colour.hpp"

#include "../log/logger.h"

QColor def_color(const QList<colorwheel_t>& colour, int index) {
  int i{0};
  QString name_colour{""};
  QColor code_colour;
  std::tie(i, name_colour, code_colour) = colour.at(index % colour.count());
  LOG(DEBUG, "colour selected: %d, %c", i, name_colour.toStdString().c_str())
  return code_colour.toRgb();
}
