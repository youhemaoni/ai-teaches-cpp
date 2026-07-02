// 02-control-flow/02_loops-practice.cpp
// 练习文件：在这里动手练习「循环 (for/while/range-for)」。
//
// 建议练习任务（完成后到 PROGRESS.md 勾选「02-control-flow — 循环」）：
//   1. 用 while 循环计算 1 到 100 的和并输出
//   2. 用 for 循环打印 1~100 中的所有 7 的倍数
//   3. 输入一个正整数 n，用 for 计算 n!（阶乘）
//   4. 用 range-for 遍历一个 double 数组，计算平均值
//   5. 用嵌套循环打印一个等腰三角形（*号）
//
// 学习进度记录（边学边记，日期格式 YYYY-MM-DD）：
//   - YYYY-MM-DD 学会了：______
//   - YYYY-MM-DD 卡住的点：______

#include <iostream>
using namespace std;
int main()
{
    // 在这里动手练习吧！
    cout << "=======================  1.while 循环 ==================" << endl;
    int count{1};
    while (count <= 5)
    {
        cout << count << " ";
        count++;
    }

    int input{};
    do
    {
        cout << "请输入一个正整数（输入0时退出）：";
        cin >> input;
        if (input > 0)
        {
            cout << " 你输入了 " << input << endl;
        }

    } while (input != 0);

    return 0;
}
