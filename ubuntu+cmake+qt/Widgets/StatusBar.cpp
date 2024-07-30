#include "StatusBar.h"

#include <QHBoxLayout>
#include <QLabel>

StatusBar::StatusBar(QWidget *parent) : QStatusBar(parent) {
  this->setSizeGripEnabled(false);

  m_camera_status_label = new QLabel(this);
  m_robot_status_label = new QLabel(this);
  m_system_mode_label = new QLabel(this);
  m_system_status_label = new QLabel(this);
  m_cusor_status_label = new QLabel(this);

  m_camera_status_label->setAlignment(Qt::AlignCenter);
  m_robot_status_label->setAlignment(Qt::AlignCenter);
  m_system_mode_label->setAlignment(Qt::AlignCenter);
  m_system_status_label->setAlignment(Qt::AlignCenter);
  m_cusor_status_label->setAlignment(Qt::AlignCenter);

  m_camera_status_label->setText("camera: none");
  m_robot_status_label->setText("robot: none");

  this->addWidget(m_camera_status_label, 1);
  this->addWidget(m_robot_status_label, 1);
  this->addWidget(m_system_mode_label, 1);
  this->addWidget(m_system_status_label, 5);
  this->addWidget(m_cusor_status_label, 1);
}

StatusBar::~StatusBar() {
  delete m_camera_status_label;
  delete m_robot_status_label;
  delete m_system_mode_label;
  delete m_system_status_label;
  delete m_cusor_status_label;
}

void StatusBar::showCameraStatus(std::string camera_ip) {
  m_camera_status_label->setText("camera: " +
                                 QString::fromStdString(camera_ip));
}

void StatusBar::showRobotStatus(std::string robot_ip) {
  m_robot_status_label->setText("robot: " + QString::fromStdString(robot_ip));
}

void StatusBar::showSystemMode(std::string mode) {
  m_system_mode_label->setText(QString::fromStdString(mode));
}

void StatusBar::showSystemStatus(std::string step) {
  m_system_status_label->setText(QString::fromStdString(step));
}

void StatusBar::showCusorStatus(int x, int y) {
  m_cusor_status_label->setText(QString::number(x, 10) + "," +
                                QString::number(y, 10));
}