#! /usr/bin/env bash
find leetcode -type f -name "*.hpp" -o -name "*.cpp" -o -name "*.tpp" | xargs clang-format -i
