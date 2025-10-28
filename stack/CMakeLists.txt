cmake_minimum_required(VERSION 3.21)

add_executable(stack stack.cpp libs.cpp)
set_target_properties(stack PROPERTIES CXX_STANDARD 20)
