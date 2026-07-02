# AGENTS.md

This file provides guidance to Lingma (lingma.aliyun.com) when working with code in this repository.

## 项目性质

这是一个 **AI 辅助学习 C++ 的个人项目**，不是生产代码库。每个 `.cpp` 文件是一个自包含的、可独立编译运行的教学示例。新增内容时应遵循"一份概念一个文件、文件即笔记"的约定。

## 构建与运行

环境：Windows（PowerShell），C++ 标准定为 **C++20**。

单文件运行（最常用，开发循环）：
```powershell
mkdir -p build/single; g++ -std=c++20 -Wall -Wextra -g <file>.cpp -o build/single/<file>; ./build/single/<file>
```

CMake 全量构建（自动收集所有阶段目录下的 `.cpp`，各自生成独立可执行文件）：
```powershell
cmake -B build; cmake --build build
# 运行某个示例（target 名由相对路径生成，/ 和 . 都替换为 _）：
./build/01-basics_hello_cpp
```

格式化：`clang-format -i <file>.cpp`

## 架构关键点

- **顶层 [CMakeLists.txt](CMakeLists.txt)** 用 `GLOB_RECURSE` 扫描所有阶段目录（`01-basics/` … `10-concurrency/`）+ `projects/` + `exercises/` 下的 `.cpp`，逐个 `add_executable`。target 名 = 相对路径，其中 `/` 和 `.` 替换为 `_`（如 `01-basics/hello.cpp` → `01-basics_hello_cpp`）。新增 `.cpp` 无需改 CMake，`CONFIGURE_DEPENDS` 会自动感知。
- **学习路线分 10 个阶段目录**（`01-basics/` … `10-concurrency/`），详见 [README.md](README.md) 表格。顺序即学习路径。
- **[PROGRESS.md](PROGRESS.md)** 是进度勾选清单；`notes/` 沉淀每主题笔记并在 PROGRESS.md 登记链接；`exercises/` 放练习。`projects/`、`exercises/`、`notes/` 目前尚未创建。

## 文件与代码约定

- 命名：`xx_topic_subtopic.cpp`（如 `01_variables.cpp`）。
- 每新增一个示例文件，**必须同时创建配套的空练习文件** `<同目录>/<同名>-practice.cpp`（如 `02_variables.cpp` → `02_variables-practice.cpp`）。练习文件含建议练习任务和「学习进度记录」区，留空给学习者动手填，完成后去 [PROGRESS.md](PROGRESS.md) 勾选对应项。
- 每个 `.cpp` 顶部必须有中文注释，写明该示例讲解的概念（AI 讲解风格），文件末尾注释给出编译运行命令。
- 严格警告已全局开启（`-Wall -Wextra -Wpedantic`），新代码应做到零警告。
- 遵循现代 C++：RAII、智能指针、`auto`、`constexpr`、避免裸 `new`/`delete` 与 C 风格数组。
- `.gitignore` 忽略 `build/` 与单文件编译产物；不要提交可执行文件。

## IDE 配置

[.vscode/tasks.json](.vscode/tasks.json) 提供单文件构建/运行/调试任务；[.vscode/launch.json](.vscode/launch.json) 的 `F5` 调试依赖 `gdb`。CMake 任务默认未启用，单文件开发用 g++ 任务即可。[.vscode/settings.json](.vscode/settings.json) 配置了 Code Runner 扩展使用 g++ 编译当前文件到 `build/single/`。
