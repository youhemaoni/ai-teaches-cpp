cmake_minimum_required(VERSION 3.16)
project(ai_teaches_cpp CXX)

# C++20 标准
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# 严格警告
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# 自动收集所有阶段目录下的 .cpp 作为独立可执行文件
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS
    "01-basics/*.cpp"
    "02-control-flow/*.cpp"
    "03-functions/*.cpp"
    "04-pointers-references/*.cpp"
    "05-oop/*.cpp"
    "06-templates/*.cpp"
    "07-stl/*.cpp"
    "08-modern-cpp/*.cpp"
    "09-memory-management/*.cpp"
    "10-concurrency/*.cpp"
    "projects/*.cpp"
    "exercises/*.cpp"
)

foreach(SOURCE ${SOURCES})
    # 用相对路径生成可执行名，点替换为下划线
    file(RELATIVE_PATH REL_SOURCE ${CMAKE_SOURCE_DIR} ${SOURCE})
    string(REPLACE "/" "_" TARGET_NAME ${REL_SOURCE})
    string(REPLACE "." "_" TARGET_NAME ${TARGET_NAME})
    add_executable(${TARGET_NAME} ${SOURCE})
endforeach()
