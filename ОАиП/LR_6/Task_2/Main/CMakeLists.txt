cmake_minimum_required(VERSION 3.28)
project("")
set(CMAKE_CXX_STANDARD 20)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address")
# Добавьте исполняемый файл
add_executable(MAINEXE Task_2.cpp prot.h Fun.cpp)