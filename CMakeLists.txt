cmake_minimum_required(VERSION 3.10)
project(ipChaifenProject)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# GTest 配置
include(FetchContent)
set(FETCHCONTENT_DOWNLOAD_TIMEOUT 300)

FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
  DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)

set(INSTALL_GTEST OFF CACHE BOOL "" FORCE)
set(BUILD_GMOCK OFF CACHE BOOL "" FORCE)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_GetProperties(googletest)
if(NOT googletest_POPULATED)
  FetchContent_Populate(googletest)
  add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()

# 包含头文件目录
include_directories(include)

# 构建主程序
add_executable(ip_filter
    src/main.cpp
    src/ipChaifen.cpp
)

# -------------------------- 测试程序配置（修正目标名称） --------------------------
# 1. 将测试目标名称定义为 iptest（与后续链接语句匹配）
add_executable(iptest  # 这里修改为 iptest
    test/iptest.cpp
    src/ipChaifen.cpp
)

if(TARGET GTest::GTest AND TARGET GTest::Main)
    target_link_libraries(iptest PRIVATE GTest::GTest GTest::Main)
else()
    target_link_libraries(iptest PRIVATE gtest gtest_main)
endif()

target_include_directories(iptest PRIVATE
    ${googletest_SOURCE_DIR}/googletest/include
)