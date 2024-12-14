cmake_minimum_required(VERSION 3.10)
project(RPGEditor)

set(CMAKE_CXX_STANDARD 17)

# Добавляем основной исполняемый файл
add_executable(RPGEditor main.cpp NPC.h NPCFactory.h BattleVisitor.h Observer.h)

# Указываем путь к заголовочным файлам
target_include_directories(RPGEditor PRIVATE ${CMAKE_SOURCE_DIR})

# Добавляем Google Test
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/release-1.12.1.zip
)
FetchContent_MakeAvailable(googletest)

# Добавляем тесты
enable_testing()
add_executable(RPGEditorTests tests.cpp)
target_link_libraries(RPGEditorTests gtest_main)

# Добавляем тесты в проект
add_test(NAME RPGEditorTests COMMAND RPGEditorTests)