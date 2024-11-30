cmake_minimum_required(VERSION 3.22)
project(oop CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror=maybe-uninitialized")

include(FetchContent)

FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/release-1.12.1.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_library(GTest::GTest INTERFACE IMPORTED)
target_link_libraries(GTest::GTest INTERFACE gtest_main)

add_executable(${CMAKE_PROJECT_NAME}_exe src/main.cpp)
target_include_directories(${CMAKE_PROJECT_NAME}_exe PRIVATE include ${googletest_SOURCE_DIR}/googletest/include)

enable_testing()

add_executable(${CMAKE_PROJECT_NAME}_tests tests/tests.cpp)
target_include_directories(${CMAKE_PROJECT_NAME}_tests PRIVATE include ${googletest_SOURCE_DIR}/googletest/include)
target_link_libraries(${CMAKE_PROJECT_NAME}_tests PRIVATE GTest::GTest)

add_test(NAME ${CMAKE_PROJECT_NAME}_tests COMMAND ${CMAKE_PROJECT_NAME}_tests)