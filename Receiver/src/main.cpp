#include "mainwindow.hpp"

#include <QApplication>
#include <QObject>

#include "../log/instrumentor.h"

int main(int argc, char *argv[]) {
#if PROFILING
  Instrumentor::Get().BeginSession("Profile");
#endif
  QApplication a(argc, argv);
  MainWindow w;
  w.show();
  auto r = a.exec();
#if PROFILING
  Instrumentor::Get().EndSession();
#endif
  return r;
}
