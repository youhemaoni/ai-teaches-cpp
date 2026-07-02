// 01-basics/04_io.cpp
// AI 讲解：C++ 的输入输出通过 iostream 库实现。
//
// 核心对象：
//   std::cin   — 标准输入（键盘），配合 >> 提取操作符
//   std::cout  — 标准输出（屏幕），配合 << 插入操作符
//   std::cerr  — 无缓冲错误输出
//   std::clog  — 缓冲日志输出
//
// 关键注意：
//   - cin >> 会自动跳过空白（空格/Tab/换行），适合读取单词/数字
//   - getline() 读取一整行（含空格），但要注意和 cin >> 混用时缓冲区的残留换行
//   - endl 不仅输出换行，还会刷新缓冲区；'\n' 仅换行不刷新，性能更优

#include <iostream>
#include <string>

int main()
{
    // ========== 1. 输出基础 ==========
    std::cout << "===== 1. 输出基础 =====\n";
    std::cout << "Hello, iostream!" << "\n";
    std::cout << "数字：" << 42 << "，布尔（默认）：" << true << "，浮点：" << 3.14 << "\n";
    std::cout << std::boolalpha << "布尔（boolalpha）：" << true << "\n\n";

    // ========== 2. 输入（cin >>）==========
    std::cout << "===== 2. cin >> 输入 =====\n";
    std::cout << "请输入一个整数和一个单词（用空格分隔）：";

    int number{};
    std::string word{};
    std::cin >> number >> word;

    std::cout << "你输入的整数：" << number << "\n";
    std::cout << "你输入的单词：" << word << "\n\n";

    // ========== 3. getline 读取整行 ==========
    std::cout << "===== 3. getline() 读取整行 =====\n";
    std::cin.ignore(999, '\n'); // 清空缓冲区中 cin >> 遗留的换行符

    std::cout << "请输入一个完整的句子（可含空格）：";
    std::string line{};
    std::getline(std::cin, line);
    std::cout << "你输入的句子：" << line << "\n\n";

    // ========== 4. cin 的状态检测 ==========
    std::cout << "===== 4. 输入状态检测 =====\n";
    std::cout << "请输入一个数字：";

    int value{};
    if (std::cin >> value)
    {
        std::cout << "成功读取：" << value << "\n";
    }
    else
    {
        std::cout << "输入无效！不是合法的数字。\n";
        std::cin.clear();           // 清除错误状态
        std::cin.ignore(999, '\n'); // 丢弃错误输入
    }

    std::cout << "\n";

    // ========== 5. cerr / clog ==========
    std::cout << "===== 5. cerr 输出 =====\n";
    std::cerr << "这是一条错误信息（cerr，无缓冲，立即输出）\n";
    std::clog << "这是一条日志信息（clog，有缓冲）\n";

    std::cout << "\n运行结束，试试输入不同内容观察行为！\n";

    return 0;
}

// 编译运行：
//   New-Item -ItemType Directory -Force -Path build/single | Out-Null
//   g++ -std=c++20 -Wall -Wextra -g -static 01-basics/04_io.cpp -o build/single/04_io.exe
//   ./build/single/04_io.exe
