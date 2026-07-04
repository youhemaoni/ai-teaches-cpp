// 03-functions/02_parameters.cpp
// AI 讲解：C++ 参数传递——值传递、引用传递、指针传递
//
// 调用函数时，实参（argument）传递给形参（parameter）有三种方式：
//
// 1. 值传递（pass by value）
//    - 形参是实参的副本，修改形参不影响实参
//    - 适合小对象（int, double, char 等）
//    - 缺点：大对象复制有性能开销
//
// 2. 引用传递（pass by reference）
//    - 形参是实参的别名（alias），修改形参 = 修改实参
//    - 语法：在类型后加 &，如 int&
//    - 没有复制开销，适合大对象
//    - 引用一定不为空，比指针更安全
//
// 3. const 引用传递（pass by const reference）
//    - 结合引用的高效和 const 的保护
//    - 形参绑定到实参但不允许修改
//    - 默认首选：const std::string&, const std::vector<int>&
//
// 4. 指针传递（pass by pointer）
//    - 形参接收实参的地址，通过解引用修改实参
//    - 可以为空（nullptr），需要检查有效性
//    - C 风格，在现代 C++ 中引用通常是更好的选择

#include <iostream>
#include <string>
#include <vector>

// ========== 函数声明 ==========

// 1. 值传递 —— 形参是副本
void increment_by_value(int x);

// 2. 引用传递 —— 形参是别名
void increment_by_reference(int &x);

// 3. const 引用传递 —— 高效只读
void print_vector(const std::vector<int> &vec);

// 4. 指针传递 —— 形参是地址（可为空）
void increment_by_pointer(int *p);

// 5. string 的 const 引用 —— 常见实践
void greet(const std::string &name);

// ========== main ==========
int main()
{
    std::cout << "========= 1. 值传递 (pass by value) =========\n";
    int a{10};
    std::cout << "调用前: a = " << a << "\n";
    increment_by_value(a);
    std::cout << "调用后: a = " << a << "  ← 值传递，a 不变\n\n";

    // -------------------------------------------------------

    std::cout << "========= 2. 引用传递 (pass by reference) =========\n";
    int b{10};
    std::cout << "调用前: b = " << b << "\n";
    increment_by_reference(b);
    std::cout << "调用后: b = " << b << "  ← 引用传递，b 被修改了！\n\n";

    // -------------------------------------------------------

    std::cout << "========= 3. const 引用传递 =========\n";
    std::vector<int> numbers{1, 2, 3, 4, 5};
    print_vector(numbers); // 无需复制整个 vector
    std::cout << "\n";

    // -------------------------------------------------------

    std::cout << "========= 4. 指针传递 (pass by pointer) =========\n";
    int c{10};
    std::cout << "调用前: c = " << c << "\n";
    increment_by_pointer(&c); // 传入地址
    std::cout << "调用后: c = " << c << "  ← 指针传递，c 被修改了！\n\n";

    // 指针可以为空，调用时需检查
    increment_by_pointer(nullptr); // 不会崩溃，内部做了检查
    std::cout << "\n";

    // -------------------------------------------------------

    std::cout << "========= 5. const 引用传 string =========\n";
    greet("Alice");
    greet("Bob");

    return 0;
}

// ========== 函数定义 ==========

// 值传递：x 是 a 的副本
void increment_by_value(int x)
{
    ++x;
    std::cout << "函数内部: x = " << x << "  (仅修改副本)\n";
}

// 引用传递：&x 是 b 的别名，操作 x 就是操作 b
void increment_by_reference(int &x)
{
    ++x;
    std::cout << "函数内部: x = " << x << "  (修改了原始变量)\n";
}

// const 引用：vec 绑定到实参，但不能修改
void print_vector(const std::vector<int> &vec)
{
    std::cout << "vector 大小: " << vec.size() << "，元素: ";
    for (size_t i{0}; i < vec.size(); ++i)
    {
        std::cout << vec[i] << (i + 1 < vec.size() ? ", " : "");
    }
    std::cout << "\n";
    // vec.push_back(6); // 错误！const 引用不能修改
}

// 指针传递：p 接收地址，通过 *p 访问原始变量
void increment_by_pointer(int *p)
{
    if (p == nullptr)
    {
        std::cout << "指针为空，跳过操作\n";
        return;
    }
    ++(*p);
    std::cout << "函数内部: *p = " << *p << "  (通过指针修改了原始变量)\n";
}

// const string& —— 参数传递的"默认首选"模式
void greet(const std::string &name)
{
    std::cout << "你好，" << name << "！\n";
}

// 编译运行：
//   New-Item -ItemType Directory -Force -Path 'build/single' | Out-Null
//   g++ -std=c++20 -Wall -Wextra -Wpedantic -g 03-functions/02_parameters.cpp -o build/single/02_parameters
//   ./build/single/02_parameters
