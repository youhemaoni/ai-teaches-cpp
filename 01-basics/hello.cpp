// 01-basics/hello.cpp
// AI 讲解：C++ 程序的入口是 main 函数，返回 int。
// #include 是预处理指令，把头文件内容插入到此处。
// iostream 提供标准输入输出：std::cout（输出）、std::endl（换行+刷新缓冲区）。
// std:: 是命名空间前缀，标准库的内容都在 std 命名空间下。

#include <iostream>

int main() {
    std::cout << "Hello, AI 教我学 C++!" << std::endl;
    return 0;  // 0 表示程序正常结束
}

// 编译运行：
//   g++ -std=c++20 hello.cpp -o hello && ./hello
// 或用 CMake：cmake -B build && cmake --build build && ./build/01-basics_hello_cpp
