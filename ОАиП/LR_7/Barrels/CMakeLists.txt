cmake_minimum_required(VERSION 3.28)
project("LR7")
set(CMAKE_CXX_STANDARD 20)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=thread")
# Добавьте исполняемый файл
add_executable(Barrels Barrels.cpp )