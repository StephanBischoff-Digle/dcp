cmake_minimum_required(VERSION 3.15)
project(cpp_dcp)


add_compile_options(
    -fPIC
    -fdiagnostics-color=always
    -Wall
    -Wextra
    -Werror
    -pedantic)

add_subdirectory(001)
