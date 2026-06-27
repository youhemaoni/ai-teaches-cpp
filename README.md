# AI 教我学 C++

> 一个由 AI 辅助、循序渐进学习 C++ 的项目。从语法基础到现代 C++、并发编程，每一步都有 AI 讲解 + 代码实战 + 笔记沉淀。

## 学习路线

| 阶段 | 目录 | 主题 |
|------|------|------|
| 1 | `01-basics/` | 变量、类型、运算符、输入输出 |
| 2 | `02-control-flow/` | 分支、循环、跳转 |
| 3 | `03-functions/` | 函数定义、参数传递、重载、lambda |
| 4 | `04-pointers-references/` | 指针、引用、数组、内存地址 |
| 5 | `05-oop/` | 类、封装、继承、多态、虚函数 |
| 6 | `06-templates/` | 函数模板、类模板、SFINAE、concepts |
| 7 | `07-stl/` | 容器、迭代器、算法、函数对象 |
| 8 | `08-modern-cpp/` | C++11/14/17/20/23 新特性 |
| 9 | `09-memory-management/` | RAII、智能指针、内存模型 |
| 10 | `10-concurrency/` | thread、mutex、atomic、协程 |

## 目录结构

```
AI教我学cpp/
├── 01-basics/            # 各阶段学习代码
├── ...
├── projects/             # 综合实战项目
├── exercises/            # 练习题与解答
├── notes/                # 学习笔记（每个主题一篇）
├── .vscode/              # 编辑器配置
├── CMakeLists.txt        # 顶层 CMake 构建脚本
├── PROGRESS.md           # 学习进度跟踪
└── README.md
```

## 如何使用

1. 按顺序进入各阶段目录，每个 `.cpp` 文件都是一个可独立编译运行的示例
2. 阅读代码顶部注释中的 AI 讲解
3. 在 `notes/` 沉淀自己的理解
4. 在 `exercises/` 完成练习巩固
5. 在 `PROGRESS.md` 勾选进度

## 构建

```bash
cmake -B build && cmake --build build
```

## 约定

- 编译标准：C++20
- 每个 `.cpp` 文件自包含，可单独编译
- 文件命名：`xx_topic_subtopic.cpp`（如 `01_variables.cpp`）
