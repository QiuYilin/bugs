#include <QtWidgets/QApplication>

#include "CustomWidgetDemo.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  CustomWidgetDemo w;
  w.show();
  return a.exec();
}
