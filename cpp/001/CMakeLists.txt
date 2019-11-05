cmake_minimum_required(VERSION 3.15)
project(Day001)

add_library(${PROJECT_NAME}
    solution.h
)

target_include_directories(${PROJECT_NAME} PUBLIC .)
set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_STANDARD 14
    LINKER_LANGUAGE CXX)
