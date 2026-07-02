// 02-control-flow/01_if_switch.cpp
// AI 讲解：C++ 的分支控制——if/else 与 switch。
//
// if/else 是最通用的分支结构，可用任何条件表达式。
// switch 适合对整数/枚举类型做多路等值比较，比长串 if-else 更清晰。
//
// 关键点：
//   - if 条件必须为 bool 或能隐式转换为 bool（0 → false，非 0 → true）
//   - switch 中每个 case 必须用 break 退出，否则会"穿透"（fall-through）
//   - C++17 起可以用 [[fallthrough]] 显式标记故意穿透
//   - 三目运算符 ?: 是表达式（有返回值），不是语句

#include <iostream>

int main()
{
    // ========== 1. if / else if / else ==========
    std::cout << "===== 1. if / else if / else =====\n";

    int score{85};
    std::cout << "分数：" << score << " → ";

    if (score >= 90)
    {
        std::cout << "优秀（A）\n";
    }
    else if (score >= 75)
    {
        std::cout << "良好（B）\n";
    }
    else if (score >= 60)
    {
        std::cout << "及格（C）\n";
    }
    else
    {
        std::cout << "不及格（D）\n";
    }

    // ========== 2. 三目运算符 ?: ==========
    std::cout << "\n===== 2. 三目运算符 ?: =====\n";

    int age{17};
    std::string status = (age >= 18) ? "成年人" : "未成年人";
    std::cout << "年龄 " << age << " 岁 → " << status << "\n";

    // 三目也可嵌套（但可读性差，不推荐过深）
    int x{5}, y{10}, z{3};
    int max = (x > y) ? (x > z ? x : z) : (y > z ? y : z);
    std::cout << "max(" << x << ", " << y << ", " << z << ") = " << max << "\n";

    // ========== 3. switch ==========
    std::cout << "\n===== 3. switch =====\n";

    int day{3}; // 1=周一 … 7=周日
    std::cout << "day = " << day << " → ";

    switch (day)
    {
    case 1:
        std::cout << "周一\n";
        break;
    case 2:
        std::cout << "周二\n";
        break;
    case 3:
        std::cout << "周三\n";
        break;
    case 4:
        std::cout << "周四\n";
        break;
    case 5:
        std::cout << "周五\n";
        break;
    case 6: // [[fallthrough]]  // 故意穿透：周六和周日均输出"周末"
    case 7:
        std::cout << "周末\n";
        break;
    default:
        std::cout << "无效日期\n";
        break;
    }

    // ========== 4. switch 的 fall-through 警告抑制 ==========
    std::cout << "\n===== 4. 显式 fall-through (C++17) =====\n";

    int level{2};
    std::cout << "level = " << level << "：";

    switch (level)
    {
    case 1:
        std::cout << "基础 ";
        [[fallthrough]]; // 明确告诉编译器：这是故意的
    case 2:
        std::cout << "进阶 ";
        [[fallthrough]];
    case 3:
        std::cout << "高级";
        break;
    }
    std::cout << "\n";

    // ========== 5. if 的初始化语句 (C++17) ==========
    std::cout << "\n===== 5. if 带初始化语句 (C++17) =====\n";

    if (int value{42}; value > 0)
    {
        std::cout << "value = " << value << "，大于零\n";
    }
    // value 在这里已超出作用域

    // ========== 6. 菱形继承模拟（仅演示布尔逻辑）==========
    std::cout << "\n===== 6. 组合条件判定 =====\n";

    bool has_account{true};
    bool is_vip{false};
    double amount{150.0};

    if (has_account && amount >= 100.0)
    {
        if (is_vip)
        {
            std::cout << "VIP 客户免运费\n";
        }
        else
        {
            std::cout << "订单满 100 元免运费\n";
        }
    }
    else
    {
        std::cout << "需要支付运费\n";
    }

    return 0;
}

// 编译运行：
//   New-Item -ItemType Directory -Force -Path build/single | Out-Null
//   g++ -std=c++20 -Wall -Wextra -g -static 02-control-flow/01_if_switch.cpp -o build/single/01_if_switch.exe
//   chcp 65001 > $null; ./build/single/01_if_switch.exe
