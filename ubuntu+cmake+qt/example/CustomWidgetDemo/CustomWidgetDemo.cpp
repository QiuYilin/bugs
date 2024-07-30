#include "CustomWidgetDemo.h"

#include <QLabel>

#include "StatusBar.h"
#include "ui_CustomWidgetDemo.h"

CustomWidgetDemo::CustomWidgetDemo(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::CustomWidgetDemoClass) {
  ui->setupUi(this);

  m_status_bar = new StatusBar(this);

  setStatusBar(m_status_bar);

  m_status_bar->showCameraStatus("127.127.127.127");
  m_status_bar->showRobotStatus("127.127.127.127");
  m_status_bar->showSystemMode("***");
  m_status_bar->showSystemStatus("***");
  m_status_bar->showCusorStatus(0, 0);
}

CustomWidgetDemo::~CustomWidgetDemo() {
  delete ui;
  delete m_status_bar;
}
