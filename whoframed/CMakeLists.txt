cmake_minimum_required(VERSION 3.21)

add_executable(whoframed whoframed.cpp libs.cpp)
set_target_properties(whoframed PROPERTIES CXX_STANDARD 20)