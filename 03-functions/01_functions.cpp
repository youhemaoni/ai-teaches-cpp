// 03-functions/01_functions.cpp
// AI 讲解：C++ 函数定义与调用——让代码模块化、可复用的核心机制。
//
// 函数由四部分组成：
//   返回类型  函数名(参数列表) { 函数体 }
//   int       add    (int a, int b) { return a + b; }
//
// 关键概念：
//   函数声明（原型） — 告诉编译器函数"长什么样"，可以放在调用之前
//   函数定义       — 函数的完整实现，包含函数体
//   函数调用       — 使用函数名 + 实参列表来执行函数
//   返回语句       — return 将结果传递回调用者（void 函数可省略）
//
// 为什么要用函数：
//   1. 避免重复代码（DRY 原则）
//   2. 将复杂问题拆解为小问题（分而治之）
//   3. 提高可读性和可维护性

#include <iostream>
#include <string>
#include <cmath>   // std::sqrt, std::pow
#include <cstdlib> // std::abs

// ========== 函数声明（原型）==========
// 声明放在 main 之前，定义可放 main 之后，编译器就能"认识"这些函数
int add(int a, int b);
void print_greeting(const std::string &name);
bool is_even(int n);
double circle_area(double radius);
int factorial(int n);

// ========== main 函数 ==========
// 每个 C++ 程序有且仅有一个 main 函数——它是程序的入口点
int main()
{
    // ---- 1. 基础函数调用 ----
    std::cout << "===== 1. 基础函数调用 =====\n";

    int x{5}, y{3};
    int result{add(x, y)};
    std::cout << x << " + " << y << " = " << result << "\n\n";

    // ---- 2. void 函数（无返回值）----
    std::cout << "===== 2. void 函数 =====\n";
    print_greeting("小明");
    std::cout << "\n";

    // ---- 3. 返回 bool 的函数 ----
    std::cout << "===== 3. 返回 bool 的函数 =====\n";
    for (int i{1}; i <= 5; ++i)
    {
        std::cout << i << (is_even(i) ? " 是偶数" : " 是奇数") << "\n";
    }
    std::cout << "\n";

    // ---- 4. 函数调用函数 ----
    std::cout << "===== 4. 函数内部调用其他函数 =====\n";
    double r{3.0};
    std::cout << "半径为 " << r << " 的圆面积 = " << circle_area(r) << "\n\n";

    // ---- 5. 递归函数 ----
    std::cout << "===== 5. 递归函数 =====\n";
    std::cout << "5! = " << factorial(5) << "\n";
    std::cout << "10! = " << factorial(10) << "\n\n";

    // ---- 6. 函数返回值可直接用于表达式 ----
    std::cout << "===== 6. 返回值用于表达式 =====\n";
    std::cout << "add(2, 3) * add(4, 5) = " << add(2, 3) * add(4, 5) << "\n\n";

    // ---- 7. 标准库函数示例 ----
    std::cout << "===== 7. 标准库函数 =====\n";
    std::cout << "sqrt(16.0) = " << std::sqrt(16.0) << "\n";
    std::cout << "pow(2.0, 10.0) = " << std::pow(2.0, 10.0) << "\n";
    std::cout << "abs(-42) = " << std::abs(-42) << "\n";

    return 0;
}

// ========== 函数定义 ==========

// 两数相加
int add(int a, int b)
{
    return a + b;
}

// 打印问候语（无返回值）
void print_greeting(const std::string &name)
{
    std::cout << "你好，" << name << "！欢迎来到 C++ 函数的世界。\n";
}

// 判断是否为偶数
bool is_even(int n)
{
    return n % 2 == 0;
}

// 计算圆面积（内部调用标准库的 pow）
double circle_area(double radius)
{
    constexpr double pi{3.14159265358979323846};
    return pi * std::pow(radius, 2);
}

// 递归计算阶乘: n! = n * (n-1)!
int factorial(int n)
{
    if (n <= 1)
    {
        return 1; // 基准情形：1! = 1, 0! = 1
    }
    return n * factorial(n - 1); // 递归情形
}

// 编译运行：
//   mkdir -p build/single
//   g++ -std=c++20 -Wall -Wextra -Wpedantic -g 03-functions/01_functions.cpp -o build/single/01_functions
//   ./build/single/01_functions
