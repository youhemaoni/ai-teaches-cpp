// 01-basics/03_operators.cpp
// AI 讲解：C++ 运算符 — 对数据进行运算的符号。
// 运算符按功能分为：算术、赋值、关系、逻辑、位运算等。
// 按操作数个数分为：一元（一个操作数）、二元（两个）、三元（一个，即 ?:）。
//
// 🌟 关键原则：
//   - 整数除法会截断（丢弃小数部分）
//   - 取模 % 只用于整数
//   - 自增/自减有前缀（先增减再用）和后缀（先用再增减）之分
//   - 短路求值：&& 左边为 false 则右边不运算；|| 左边为 true 则右边不运算

#include <iostream>

int main()
{
    // ========== 1. 算术运算符 ==========
    int a{15};
    int b{4};

    std::cout << "a=" << a << ", b=" << b << "\n\n";
    std::cout << "a + b = " << (a + b) << "   // 加法\n";
    std::cout << "a - b = " << (a - b) << "   // 减法\n";
    std::cout << "a * b = " << (a * b) << "   // 乘法\n";
    std::cout << "a / b = " << (a / b) << "   // ★ 整数除法，结果截断为 3（不是 3.75）\n";
    std::cout << "a % b = " << (a % b) << "   // 取模（余数），15 ÷ 4 = 3 余 3\n";

    double x{15.0};
    double y{4.0};
    std::cout << "x / y = " << (x / y) << "   // 浮点除，结果是 3.75\n\n";

    // ========== 2. 自增与自减 ==========
    int count{5};
    std::cout << "初始 count = " << count << "\n";
    int pre_result{++count};
    std::cout << "前缀 ++count = " << pre_result << "   // 先加 1，再使用，count=" << count << "\n";
    int post_result{count++};
    std::cout << "后缀 count++ = " << post_result << "   // 先使用旧值（" << post_result << "），再加 1，count=" << count << "\n";

    count = 5;
    std::cout << "\n重置 count=" << count << "，对比：\n";
    int pre{++count};  // count → 6, pre = 6
    int post{count++}; // post = 6, count → 7
    std::cout << "pre  = " << pre << ", post = " << post << ", count = " << count << "\n\n";

    // ========== 3. 复合赋值 ==========
    int v{10};
    v += 5; // v = v + 5
    std::cout << "v += 5  → " << v << "\n";
    v -= 3; // v = v - 3
    std::cout << "v -= 3  → " << v << "\n";
    v *= 2; // v = v * 2
    std::cout << "v *= 2  → " << v << "\n";
    v /= 4; // v = v / 4
    std::cout << "v /= 4  → " << v << "\n";
    v %= 3; // v = v % 3
    std::cout << "v %%= 3  → " << v << "\n\n";

    // ========== 4. 关系运算符（返回 bool） ==========
    int p{10};
    int q{20};
    std::cout << "p=" << p << ", q=" << q << "\n";
    std::cout << "p == q : " << (p == q) << "\n";
    std::cout << "p != q : " << (p != q) << "\n";
    std::cout << "p <  q : " << (p < q) << "\n";
    std::cout << "p >  q : " << (p > q) << "\n";
    std::cout << "p <= q : " << (p <= q) << "\n";
    std::cout << "p >= q : " << (p >= q) << "\n\n";

    // ========== 5. 逻辑运算符 ==========
    bool t{true};
    bool f{false};
    std::cout << "t=" << t << ", f=" << f << "（boolalpha 模式见下方)\n";
    std::cout << std::boolalpha; // 此后 true/false 输出为单词
    std::cout << "t && f : " << (t && f) << "   // && 逻辑与：全真才真\n";
    std::cout << "t || f : " << (t || f) << "   // || 逻辑或：一真即真\n";
    std::cout << "!t     : " << (!t) << "       // ! 逻辑非：取反\n\n";

    // 短路求值演示
    int score{85};
    bool passed = (score >= 60) && (std::cout << "及格啦！\n", true);
    std::cout << "passed = " << passed << "\n\n";

    // ========== 6. 三元运算符 ==========
    int age{17};
    std::string status = (age >= 18) ? "成年人" : "未成年人";
    std::cout << "年龄 " << age << " → " << status << "\n\n";

    // ========== 7. 运算符优先级小提醒 ==========
    // 不确定优先级时，用 () 明确表达意图
    int r = 3 + 4 * 2;    // 乘法优先：3 + 8 = 11
    int r2 = (3 + 4) * 2; // 括号改变顺序：7 * 2 = 14
    std::cout << "3 + 4 * 2     = " << r << "\n";
    std::cout << "(3 + 4) * 2   = " << r2 << "\n";

    return 0;
}

// 编译运行：
//   mkdir -p build/single && g++ -std=c++20 03_operators.cpp -o build/single/03_operators && ./build/single/03_operators
//
// 练习：见同目录 03_operators-practice.cpp
