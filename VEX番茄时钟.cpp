#include "vex.h"

using namespace vex;

// 定义 Brain 对象
brain Brain;

// 定义 Timer 对象
timer Timer;

// 定义按钮对象
controller Controller;

int main() {
  // 初始化
  Brain.Screen.print("按下按钮开始计时");

  // 等待用户按下按钮开始计时
  while (!Controller.ButtonA.pressing()) {
    wait(20, msec);
  }

  // 启动计时器
  Timer.reset();

  // 显示计时器值
  while (!Controller.ButtonB.pressing()) {
    double currentTime = Timer.value(timeUnits::sec);

    // 在屏幕上显示当前时间
    Brain.Screen.clearScreen();
    Brain.Screen.print("计时: %.2f 秒", currentTime);

    wait(20, msec);
  }

  // 用户按下按钮停止计时
  double elapsedTime = Timer.value(timeUnits::sec);

  // 显示总计时时间
  Brain.Screen.clearScreen();
  Brain.Screen.print("总计时时间: %.2f 秒", elapsedTime);

  return 0;
}
