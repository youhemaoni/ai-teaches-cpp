// 02-control-flow/02_loops.cpp
// AI 讲解：C++ 的循环控制——while、do-while、for、range-for。
//
// 四种循环适用场景：
//   while       — 条件驱动，可能一次都不执行
//   do-while    — 至少执行一次，再判断条件
//   for         — 已知迭代次数或范围（初始化;条件;步进）
//   range-for   — 遍历容器/数组（C++11 起，最推荐）
//
// 控制语句：
//   break      — 立即跳出整个循环
//   continue   — 跳过本次循环剩余部分，进入下一次迭代

#include <iostream>
#include <vector>

int main()
{
    // ========== 1. while 循环 ==========
    std::cout << "===== 1. while 循环 =====\n";

    int count{1};
    while (count <= 5)
    {
        std::cout << count << " ";
        ++count;
    }
    std::cout << "（1 到 5）\n\n";

    // ========== 2. do-while 循环 ==========
    std::cout << "===== 2. do-while 循环 =====\n";

    int input{};
    do
    {
        std::cout << "请输入一个正整数（输入 0 退出）：";
        std::cin >> input;
        if (input > 0)
        {
            std::cout << "  你输入了 " << input << "\n";
        }
    } while (input != 0);
    std::cout << "（输入 0，循环结束）\n\n";

    // 重置 cin 状态以便后续输入（练习中可能用到，这里清空缓冲区）
    std::cin.clear();
    std::cin.ignore(999, '\n');

    // ========== 3. for 循环 ==========
    std::cout << "===== 3. for 循环 =====\n";

    // 传统三段式 for
    for (int i{1}; i <= 5; ++i)
    {
        std::cout << i << " ";
    }
    std::cout << "（1 到 5）\n\n";

    // 递减
    std::cout << "递减：";
    for (int i{5}; i >= 1; --i)
    {
        std::cout << i << " ";
    }
    std::cout << "（5 到 1）\n\n";

    // 跳步
    std::cout << "步长为 2：";
    for (int i{0}; i <= 10; i += 2)
    {
        std::cout << i << " ";
    }
    std::cout << "（0 到 10 的偶数）\n\n";

    // 循环中申明多个变量
    std::cout << "斐波那契前 10 项：";
    for (int a{0}, b{1}, i{0}; i < 10; ++i)
    {
        std::cout << a << " ";
        int next{a + b};
        a = b;
        b = next;
    }
    std::cout << "\n\n";

    // ========== 4. 范围 for (range-based for) ==========
    std::cout << "===== 4. 范围 for (range-based for) =====\n";

    std::vector<int> numbers{10, 20, 30, 40, 50};

    // 按值遍历（只读）
    std::cout << "按值遍历：";
    for (int n : numbers)
    {
        std::cout << n << " ";
    }
    std::cout << "\n";

    // 按引用遍历（可修改）
    std::cout << "每个数加 5 后：";
    for (int &n : numbers)
    {
        n += 5;
    }
    for (int n : numbers)
    {
        std::cout << n << " ";
    }
    std::cout << "\n";

    // 用 auto 简化
    std::cout << "用 auto：";
    for (const auto &n : numbers)
    {
        std::cout << n << " ";
    }
    std::cout << "\n\n";

    // ========== 5. break / continue ==========
    std::cout << "===== 5. break / continue =====\n";

    // break：提前终止
    std::cout << "break 示例（遇到 3 停止）：";
    for (int i{1}; i <= 10; ++i)
    {
        if (i == 3)
        {
            std::cout << "[遇到 " << i << "，跳出]";
            break;
        }
        std::cout << i << " ";
    }
    std::cout << "\n";

    // continue：跳过当前次
    std::cout << "continue 示例（跳过 3）：";
    for (int i{1}; i <= 5; ++i)
    {
        if (i == 3)
        {
            std::cout << "[跳过] ";
            continue;
        }
        std::cout << i << " ";
    }
    std::cout << "\n\n";

    // ========== 6. 嵌套循环 ==========
    std::cout << "===== 6. 嵌套循环（乘法表）=====\n";

    for (int i{1}; i <= 9; ++i)
    {
        for (int j{1}; j <= i; ++j)
        {
            std::cout << j << "×" << i << "=" << (i * j) << "\t";
        }
        std::cout << "\n";
    }

    return 0;
}

// 编译运行：
//   New-Item -ItemType Directory -Force -Path build/single | Out-Null
//   g++ -std=c++20 -Wall -Wextra -g -static 02-control-flow/02_loops.cpp -o build/single/02_loops.exe
//   chcp 65001 > $null; ./build/single/02_loops.exe
