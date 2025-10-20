# 构建测试对象库
file(GLOB_RECURSE TEST_SRC "*/test.cpp")
add_library(leetcode_test_o OBJECT ${TEST_SRC})

add_executable(leetcode_test)
target_link_libraries(leetcode_test PRIVATE leetcode_test_o gtest_main pthread)
