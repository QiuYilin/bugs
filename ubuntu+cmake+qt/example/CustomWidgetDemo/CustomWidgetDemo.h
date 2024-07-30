#pragma once

#include <QtWidgets/QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class CustomWidgetDemoClass;
}
QT_END_NAMESPACE

class StatusBar;
class CustomWidgetDemo : public QMainWindow {
  Q_OBJECT

 public:
  explicit CustomWidgetDemo(QWidget *parent = nullptr);
  ~CustomWidgetDemo();

 private:
  Ui::CustomWidgetDemoClass *ui;
  StatusBar *m_status_bar;
};
