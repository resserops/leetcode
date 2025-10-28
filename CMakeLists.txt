cmake_minimum_required(VERSION 3.16.5)

project(leetcode VERSION 0.1.0)

# options
option(ENABLE_ASAN "Enable ASan for memory error detection" OFF)

set(project_dir ${CMAKE_CURRENT_LIST_DIR})
set(3rd_dir ${project_dir}/third_party)
set(3rd_cmake_dir ${3rd_dir}/cmake)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(EXECUTABLE_OUTPUT_PATH ${project_dir}/build/bin)

if(ENABLE_ASAN)
    if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
        add_compile_options(-fsanitize=address -fno-omit-frame-pointer)
        add_link_options(-fsanitize=address)
    else()
        message(WARNING "ASan is not supported by this compiler")
    endif()
endif()

include(${3rd_cmake_dir}/googletest.cmake)
include(${3rd_cmake_dir}/yaml-cpp.cmake)
add_subdirectory(leetcode)
