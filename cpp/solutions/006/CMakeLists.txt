cmake_minimum_required(VERSION 3.12)
project(Day006)

add_library(${PROJECT_NAME}
    solution.h
    solution.cc
)

target_link_libraries(${PROJECT_NAME})
target_include_directories(${PROJECT_NAME} PUBLIC .)
set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_STANDARD 17
    LINKER_LANGUAGE CXX)


# Generate testing binary
add_executable(${PROJECT_NAME}_test tests.cc)
set_target_properties(${PROJECT_NAME}_test PROPERTIES
    CXX_STANDARD 17
    LINKER_LANGUAGE CXX)

target_link_libraries(${PROJECT_NAME}_test ${PROJECT_NAME} gtest_main)
gtest_add_tests(${PROJECT_NAME}_test "" AUTO)

