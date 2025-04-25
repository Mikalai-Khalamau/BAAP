cmake_minimum_required(VERSION 3.28)
project(Google_Test)

set(CMAKE_CXX_STANDARD 20)

# Найдите пакет Google Test
find_package(GTest REQUIRED)

# Добавьте исполняемый файл
add_executable(runtests Tests.cpp "../Main/prot.h" "../Main/Fun.cpp")

# Линковка с библиотеками Google Test
target_link_libraries(runtests ${GTEST_LIBRARIES})

# Включите тестирование
enable_testing()
