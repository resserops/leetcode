# 构建测试对象库
file(GLOB_RECURSE TEST_SRC "*/test.cpp")
add_library(leetcode_test_o OBJECT ${TEST_SRC})
target_include_directories(leetcode_test_o PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/test)

# 构建测试二进制
add_executable(leetcode_test)
target_compile_options(leetcode_test PRIVATE -Werror -Wall -Wextra -Wodr)
target_link_libraries(leetcode_test PRIVATE leetcode_test_o pthread gtest_main yaml-cpp)
