cmake_minimum_required(VERSION 3.12)
project(cpp_dcp)

add_compile_options(
    -g
    -fPIC
    -fdiagnostics-color=always
    -Wall
    -Wextra
    -Werror
    -pedantic)

# Use GoogleTest for Unit Tests
add_subdirectory(gtest)
include(GoogleTest)
enable_testing()

# Use dbg macro
# add_subdirectory(dbg)

# solutions and tests
add_subdirectory(solutions)
