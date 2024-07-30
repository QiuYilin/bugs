#pragma once
#include <QStatusBar>

#include "WidgetsExport.h"

class QLabel;
class QHBoxLayout;

/// <summary>
/// Standard Menu Bar.
/// </summary>
class WIDGETS_EXPORT StatusBar : public QStatusBar {
 public:
  explicit StatusBar(QWidget *parent = nullptr);
  ~StatusBar();
  // TODO �����������Ժ궨����ʽ���й淶 Ŀǰ����string��Ϊ����

  /// <summary>
  /// Show the status of Camera.
  /// </summary>
  /// <param name="camera_ip">The ip address of Camera.</param>
  void showCameraStatus(std::string camera_ip);

  /// <summary>
  /// Show the status of Robot.
  /// </summary>
  /// <param name="robot_ip">The ip address of Robot.</param>
  void showRobotStatus(std::string robot_ip);

  /// <summary>
  /// Show the Main status of system.
  /// </summary>
  /// <param name="mode">The name of the main status.</param>
  void showSystemMode(std::string mode);

  /// <summary>
  /// Show the detailed status of system.
  /// </summary>
  /// <param name="step">The name of the detailed status.</param>
  void showSystemStatus(std::string step);

  /// <summary>
  /// Show the pix coordinate of cusor when RGB is shown.
  /// </summary>
  /// <param name="x">X coordinate of cusor.</param>
  /// <param name="y">Y coordinate of cusor.</param>
  void showCusorStatus(int x, int y);

 private:
  QLabel *m_camera_status_label;
  QLabel *m_robot_status_label;
  QLabel *m_system_mode_label;
  QLabel *m_system_status_label;
  QLabel *m_cusor_status_label;
};
