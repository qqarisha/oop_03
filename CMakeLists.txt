cmake_minimum_required(VERSION 3.10)
project(FiguresLab)

set(CMAKE_CXX_STANDARD 17)

add_executable(figures_main
    src/main.cpp
    src/Figure/Figure.cpp
    src/Triangle/Triangle.cpp
    src/Square/Square.cpp
    src/Rectangle/Rectangle.cpp
    src/Array/FigureArray.cpp
)

target_include_directories(figures_main PRIVATE src)

enable_testing()

find_package(GTest REQUIRED)

add_executable(figures_test
    tests/test_figures.cpp
    src/Figure/Figure.cpp
    src/Triangle/Triangle.cpp
    src/Square/Square.cpp
    src/Rectangle/Rectangle.cpp
    src/Array/FigureArray.cpp
)

target_include_directories(figures_test PRIVATE src)

target_link_libraries(figures_test GTest::gtest GTest::gtest_main)