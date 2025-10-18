cmake_minimum_required(VERSION 3.16.5)

project(leetcode VERSION 0.1.0)

set(project_dir ${CMAKE_CURRENT_LIST_DIR})
set(3rd_dir ${project_dir}/third_party)
set(3rd_cmake_dir ${3rd_dir}/cmake)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_compile_options(-std=c++17 -Werror -Wall -Wextra)
set(EXECUTABLE_OUTPUT_PATH ${project_dir}/build/bin)

include(${3rd_cmake_dir}/googletest.cmake)
add_subdirectory(leetcode)
