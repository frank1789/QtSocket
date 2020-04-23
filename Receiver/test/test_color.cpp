#include "colormanager.hpp"
#include "gtest/gtest.h"
#include "list_colour.hpp"

TEST(Color, AirForceBlue) {
  auto color = Colors[0];
  auto [i, name, code_hex] = color;
  EXPECT_EQ(i, 1);
  EXPECT_EQ(name, QString("Air Force blue"));
  EXPECT_EQ(code_hex, QColor("#5D8AA8"));
}

TEST(Color, FerrariRed) {
  auto color = Colors[257];
  auto [i, name, code_hex] = color;
  EXPECT_EQ(i, 258);
  EXPECT_EQ(name, QString("Ferrari Red"));
  EXPECT_EQ(code_hex, QColor("#FF2800"));
}

TEST(Color, Ivory) {
  auto color = Colors[333];
  auto [i, name, code_hex] = color;
  EXPECT_EQ(i, 334);
  EXPECT_EQ(name, QString("Ivory"));
  EXPECT_EQ(code_hex, QColor("#FFFFF0"));
}

TEST(Color, Melon) {
  auto color = Colors[432];
  auto [i, name, code_hex] = color;
  EXPECT_EQ(i, 433);
  EXPECT_EQ(name, QString("Melon"));
  EXPECT_EQ(code_hex, QColor("#FDBCB4"));
}

TEST(Color, Red) {
  auto color = Colors[578];
  auto [i, name, code_hex] = color;
  EXPECT_EQ(i, 579);
  EXPECT_EQ(name, QString("Red"));
  EXPECT_EQ(code_hex, QColor("#FF0000"));
}

TEST(Color, ZinnwalditeBrown) {
  auto color = Colors[757];
  auto [i, name, code_hex] = color;
  EXPECT_EQ(i, 758);
  EXPECT_EQ(name, QString("Zinnwaldite brown"));
  EXPECT_EQ(code_hex, QColor("#2C1608"));
}

TEST(Color, ManageRed) {
    ColorManager cm;
    QColor color = cm.getColor(757);
    EXPECT_EQ(color, QColor("#2C1608"));
}