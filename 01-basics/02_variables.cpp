// 01-basics/02_variables.cpp
// AI 讲解：变量是给一块内存起名字，方便存取数据。
// C++ 是静态类型语言：每个变量必须先声明类型，编译器据此分配内存、检查操作是否合法。
//
// 基本类型一览：
//   int        整数（通常 4 字节，范围约 ±21 亿）
//   double     双精度浮点（8 字节，存小数，默认就用它而非 float）
//   char       单个字符（1 字节）
//   bool       布尔（true / false）
//   std::string 字符串（需 #include <string>，不是内置类型而是标准库类型）
//
// 三种初始化方式（推荐用花括号 {} —— 列表初始化，能防止窄化转换）：
//   int a = 10;        // C 风格赋值初始化
//   int b(20);         // 构造式初始化
//   int c{30};         // 列表初始化（推荐）
//
// const 与 constexpr：
//   const int x = 5;       // 运行期常量，不可修改
//   constexpr int y = 5;   // 编译期常量（更严格，编译时就能求值，推荐用于真常量）
//
// auto：让编译器自动推导类型（类型明显时用，提升可读性；不明显时显式写出）
//   auto z = 3.14;  // z 推导为 double

#include <iostream>
#include <string>

int main() {
    // 基本类型声明与初始化
    int age{25};
    double pi{3.14159};
    char grade{'A'};
    bool is_learning{true};
    std::string name{"AI 教我学 C++"};

    std::cout << "name    = " << name << '\n';
    std::cout << "age     = " << age << '\n';
    std::cout << "pi      = " << pi << '\n';
    std::cout << "grade   = " << grade << '\n';
    std::cout << "learning= " << std::boolalpha << is_learning << '\n';  // boolalpha: 输出 true/false 而非 1/0

    // 常量：一旦定义不可修改，尝试修改会编译报错
    constexpr int days_per_week{7};
    std::cout << "一周有 " << days_per_week << " 天\n";

    // auto 自动推导
    auto count{10};       // int
    auto ratio{2.5};      // double
    std::cout << "count=" << count << ", ratio=" << ratio << '\n';

    // 变量可重新赋值（非常量）
    age = 26;
    std::cout << "一年后 age=" << age << '\n';

    return 0;
}

// 编译运行（产物统一输出到 build/single/，已被 .gitignore 忽略）：
//   mkdir -p build/single && g++ -std=c++20 02_variables.cpp -o build/single/02_variables && ./build/single/02_variables
//
// 练习：见同目录 02_variables-practice.cpp
