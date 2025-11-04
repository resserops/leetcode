# 构建测试对象库
file(GLOB_RECURSE TEST_SRC "*.cpp")
add_library(test_leetcode_o OBJECT ${TEST_SRC})
target_include_directories(test_leetcode_o PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/test)
target_compile_definitions(test_leetcode_o PRIVATE PROBLEM_PATH=\"${CMAKE_CURRENT_SOURCE_DIR}\")
target_compile_options(test_leetcode_o PRIVATE -Werror -Wall -Wextra -Wodr)

# 构建测试二进制
add_executable(test_leetcode)
target_link_libraries(test_leetcode PRIVATE test_leetcode_o pthread gtest_main yaml-cpp)
