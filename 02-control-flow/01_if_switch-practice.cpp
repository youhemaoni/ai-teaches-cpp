// 02-control-flow/01_if_switch-practice.cpp
// 练习文件：在这里动手练习「分支 (if/switch)」。
//
// 建议练习任务（完成后到 PROGRESS.md 勾选「02-control-flow — 分支」）：
//   1. 输入一个成绩（0~100），用 if-else 判断等级（A≥90, B≥75, C≥60, D<60）
//   2. 输入一个年份，判断闰年并输出（能被 400 整除或（被 4 整除且不被 100 整除））
//   3. 用 switch 实现：输入 1~7 的数字，输出对应星期几的英文名
//   4. 用三目运算符找出三个数中的最小值
//   5. 用 if 初始化语句（C++17）判断一个随机数是否为偶数
//
// 学习进度记录（边学边记，日期格式 YYYY-MM-DD）：
//   - YYYY-MM-DD 学会了：______
//   - YYYY-MM-DD 卡住的点：______

#include <iostream>

int main()
{
    // 在这里动手练习吧！
    std::cout << "Hello, World!\n";
    int score{85};
    std::cin >> score;
    std::cout << "score = " << score << " → ";
    if (score >= 90)
    {
        std::cout << "A\n";
    }
    else if (score >= 80)
    {
        std::cout << "B\n";
    }
    else if (score >= 70)
    {
        std::cout << "C\n";
    }
    else
    {
        std::cout << "D\n";
    }

    int day{3};
    switch (day)
    {
    case 1:
        std::cout << "Monday\n";
    case 2:
        std::cout << "Tuesday\n";
        break;
    case 3:
        std::cout << "Wednesday\n";
        break;
    case 4:
        std::cout << "Thursday\n";
        break;
    case 5:
        std::cout << "Saturday\n";
        break;
    case 6:
        std::cout << "Sunday\n";
        break;
    }
    return 0;
}
