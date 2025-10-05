cmake_minimum_required(VERSION 3.20)

project(Verry DESCRIPTION "A vector implementation.")
add_executable(verry-test main.cpp)
target_include_directories(verry-test PRIVATE include)