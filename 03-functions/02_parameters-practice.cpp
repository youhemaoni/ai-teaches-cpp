// 03-functions/02_parameters-practice.cpp
// 练习文件：在这里动手练习「参数传递——值/引用/指针」。
//
// 建议练习任务（完成后到 PROGRESS.md 勾选「03-functions — 参数传递」）：
//   1. 写一个 swap 函数，交换两个 int 的值（分别用引用和指针实现）
//   2. 写一个 get_min_max 函数，接收两个 int 的引用，返回它们的较大值和较小值
//      （提示：可以用两个输出参数，或者返回 struct）
//   3. 写一个 find_char 函数，接收 const std::string& 和 char，返回该字符首次
//      出现的位置（索引），找不到返回 -1
//   4. 编写一个函数，接收一个 vector<int>&，将所有元素翻倍（乘以 2）
//   5. 思考题：以下传递方式各有什么优缺点？分别在什么场景下使用？
//      - 值传递 (int x)
//      - 引用传递 (int& x)
//      - const 引用传递 (const int& x)
//      - 指针传递 (int* p)
//
// 学习进度记录（边学边记，日期格式 YYYY-MM-DD）：
//   - YYYY-MM-DD 学会了：______
//   - YYYY-MM-DD 卡住的点：______

#include <iostream>
#include <string>
#include <vector>

int main()
{
    // 在这里动手练习吧！

    return 0;
}

// 编译运行：
//   New-Item -ItemType Directory -Force -Path 'build/single' | Out-Null
//   g++ -std=c++20 -Wall -Wextra -Wpedantic -g 03-functions/02_parameters-practice.cpp -o build/single/02_parameters-practice
//   ./build/single/02_parameters-practice
