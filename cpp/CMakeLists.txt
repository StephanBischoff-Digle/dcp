cmake_minimum_required(VERSION 3.12)
project(cpp_dcp)

add_compile_options(
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

# List of days
add_subdirectory(001)
add_subdirectory(002)
add_subdirectory(003)
add_subdirectory(004)
