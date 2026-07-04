// 03-functions/01_functions-practice.cpp
// 练习文件：在这里动手练习「函数定义与调用」。
//
// 建议练习任务（完成后到 PROGRESS.md 勾选「03-functions — 函数定义与调用」）：
//   1. 编写一个 max 函数，接收两个 int，返回较大的那个，并在 main 中测试
//   2. 编写一个 is_prime 函数，判断一个正整数是否为质数，打印 1~50 中的质数
//   3. 编写一个 celsius_to_fahrenheit 函数，接收 double 摄氏度，返回华氏度 (F = C * 9/5 + 32)
//   4. 编写一个 sum_to_n 函数，用递归计算 1+2+...+n（不用循环）
//   5. 编写一个 void 函数 print_triangle(n)，打印出 n 行的直角三角形（*号）
//
// 学习进度记录（边学边记，日期格式 YYYY-MM-DD）：
//   - YYYY-MM-DD 学会了：______
//   - YYYY-MM-DD 卡住的点：______

#include <cmath>
#include <iostream>
#include <cstdlib>
// 在这里声明你的函数原型
int add(int a, int b);
void print_greeting(const std::string &name);
bool is_even(int n);
double circle_area(double radius);
int factorial(int n);

int main()
{
    std::cout << "=============== 1.基础函数调用 =================" << std::endl;
    int x{5}, y{3};
    int result{add(x, y)};
    std::cout << x << " + " << y << " = " << result << std::endl;

    // ---- 2. void 函数（无返回值）----
    std::cout << "===== 2. void 函数 =====\n";
    print_greeting("小明");
    std::cout << "\n";

    std::string name{"cici"};
    std::cout << name;
    name = "11";
    std::cout << name << std::endl;

    for (int i{1}; i <= 5; ++i)
    {
        std::cout << i << (is_even(i) ? " 是偶数" : " 是奇数") << " \n";
    }

    double r{3.0};
    std::cout << "半径为 " << r << " 的圆面积 = " << circle_area(r) << "\n\n";

    return 0;
}

double circle_area(double radius)
{

    constexpr double pi{3.14159265};
    return pi * std::pow(radius, 2);
}

bool is_even(int n)
{
    return n % 2 == 0;
}

int add(int a, int b)
{
    return a + b;
}

// 打印问候语（无返回值）
void print_greeting(const std::string &name)
{
    std::cout << "你好，" << name << "！欢迎来到 C++ 函数的世界。\n";
}
// 在这里定义你的函数

// 编译运行：
//   mkdir -p build/single
//   g++ -std=c++20 -Wall -Wextra -Wpedantic -g 03-functions/01_functions-practice.cpp -o build/single/01_functions-practice
//   ./build/single/01_functions-practice
