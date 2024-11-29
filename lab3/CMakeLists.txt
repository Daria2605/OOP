cmake_minimum_required(VERSION 3.10)

project(Lab3Project)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SOURCE_DIR ${CMAKE_SOURCE_DIR}/src)
set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)
set(TEST_DIR ${CMAKE_SOURCE_DIR}/tests)

include_directories(${INCLUDE_DIR})

# Добавление исполняемых файлов
add_executable(main_lab3 ${SOURCE_DIR}/main.cpp)

# Добавление библиотеки для фигур
add_library(Figures STATIC
    ${SOURCE_DIR}/Figure.cpp
    ${SOURCE_DIR}/FigureArray.cpp
    ${SOURCE_DIR}/Pentagon.cpp
    ${SOURCE_DIR}/Point.cpp
    ${SOURCE_DIR}/Rhombus.cpp
    ${SOURCE_DIR}/Trapezoid.cpp
)

# Линковка библиотеки с исполняемым файлом
target_link_libraries(main_lab3 Figures)

# Добавление тестов
add_executable(tests_lab3 ${TEST_DIR}/test_figure.cpp)

# Линковка библиотеки с тестами
target_link_libraries(tests_lab3 gtest gtest_main Figures)

# Добавление поддиректории для Google Test
add_subdirectory(${CMAKE_SOURCE_DIR}/googletest googletest)

# Включение Google Test
include(GoogleTest)
gtest_discover_tests(tests_lab3)