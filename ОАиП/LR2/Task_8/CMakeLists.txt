cmake_minimum_required(VERSION 3.5.0)

project(Taskcm VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address")
add_executable(Task_8 Task_8.cpp)
