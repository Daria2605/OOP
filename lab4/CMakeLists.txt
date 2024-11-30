cmake_minimum_required(VERSION 3.10)

project(Lab4Project)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SOURCE_DIR ${CMAKE_SOURCE_DIR}/src)
set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)
set(TEST_DIR ${CMAKE_SOURCE_DIR}/tests)

include_directories(${INCLUDE_DIR})

add_executable(main_lab4 ${SOURCE_DIR}/main.cpp)

add_executable(tests_lab4 ${TEST_DIR}/test_figure.cpp)

add_subdirectory(${CMAKE_SOURCE_DIR}/googletest googletest)

target_link_libraries(tests_lab4 gtest gtest_main)

target_sources(main_lab4 PRIVATE 
    ${INCLUDE_DIR}/Figure.hpp
    ${INCLUDE_DIR}/FigureArray.hpp
    ${INCLUDE_DIR}/Pentagon.hpp
    ${INCLUDE_DIR}/Point.hpp
    ${INCLUDE_DIR}/Rhombus.hpp
    ${INCLUDE_DIR}/Trapezoid.hpp
    ${SOURCE_DIR}/Figure.tpp
    ${SOURCE_DIR}/FigureArray.tpp
    ${SOURCE_DIR}/Pentagon.tpp
    ${SOURCE_DIR}/Point.tpp
    ${SOURCE_DIR}/Rhombus.tpp
    ${SOURCE_DIR}/Trapezoid.tpp
)

target_sources(tests_lab4 PRIVATE 
    ${INCLUDE_DIR}/Figure.hpp
    ${INCLUDE_DIR}/FigureArray.hpp
    ${INCLUDE_DIR}/Pentagon.hpp
    ${INCLUDE_DIR}/Point.hpp
    ${INCLUDE_DIR}/Rhombus.hpp
    ${INCLUDE_DIR}/Trapezoid.hpp
    ${SOURCE_DIR}/Figure.tpp
    ${SOURCE_DIR}/FigureArray.tpp
    ${SOURCE_DIR}/Pentagon.tpp
    ${SOURCE_DIR}/Point.tpp
    ${SOURCE_DIR}/Rhombus.tpp
    ${SOURCE_DIR}/Trapezoid.tpp
)

include(GoogleTest)
gtest_discover_tests(tests_lab4)
