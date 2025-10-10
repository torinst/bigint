cmake_minimum_required(VERSION 3.14)
project(bigint)

# libgtest-dev 1.16.0-1 requires C++14
set(CMAKE_CXX_STANDARD 14)

enable_testing()

add_executable(bigint_out bigint_test.cc)
target_link_libraries(bigint_out PRIVATE gtest gtest_main)

include(GoogleTest)
# gtest_discover_tests(bigint_out)
