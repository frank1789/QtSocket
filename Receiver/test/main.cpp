#include <QCoreApplication>
#include <QTimer>

#include "gtest/gtest.h"

int main(int argc, char *argv[]) {
  QCoreApplication app{argc, argv};
  QTimer::singleShot(0, [&]() {
    ::testing::InitGoogleTest(&argc, argv);
    auto testResult = RUN_ALL_TESTS();
    app.exit(testResult);
  });
  return app.exec();
}