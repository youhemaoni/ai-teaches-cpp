# AI Teaches Me C++

> A project for learning C++ step by step with AI assistance. From syntax basics to modern C++ and concurrency — each step comes with AI explanation, hands-on code, and notes.

## Learning Path

| Stage | Directory | Topics |
|-------|-----------|--------|
| 1 | `01-basics/` | Variables, types, operators, I/O |
| 2 | `02-control-flow/` | Branching, loops, jumps |
| 3 | `03-functions/` | Function definition, parameter passing, overloading, lambda |
| 4 | `04-pointers-references/` | Pointers, references, arrays, memory addresses |
| 5 | `05-oop/` | Classes, encapsulation, inheritance, polymorphism, virtual functions |
| 6 | `06-templates/` | Function templates, class templates, SFINAE, concepts |
| 7 | `07-stl/` | Containers, iterators, algorithms, function objects |
| 8 | `08-modern-cpp/` | C++11/14/17/20/23 new features |
| 9 | `09-memory-management/` | RAII, smart pointers, memory model |
| 10 | `10-concurrency/` | thread, mutex, atomic, coroutines |

## Directory Structure

```
ai-teaches-cpp/
├── 01-basics/            # Stage-by-stage learning code
├── ...
├── projects/             # Comprehensive practice projects
├── exercises/            # Exercises and solutions
├── notes/                # Study notes (one file per topic)
├── .vscode/              # Editor configuration
├── CMakeLists.txt        # Top-level CMake build script
├── PROGRESS.md           # Learning progress tracker
└── README.md
```

## How to Use

1. Enter each stage directory in order — every `.cpp` file is a self-contained, independently compilable example
2. Read the AI explanation in the comments at the top of each file
3. Capture your understanding in `notes/`
4. Reinforce learning with exercises in `exercises/`
5. Track your progress in `PROGRESS.md`

## Build

```bash
cmake -B build && cmake --build build
```

## Conventions

- Language standard: C++20
- Every `.cpp` file is self-contained and compiles standalone
- File naming: `xx_topic_subtopic.cpp` (e.g. `01_variables.cpp`)
