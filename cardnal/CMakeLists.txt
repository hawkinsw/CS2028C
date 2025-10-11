cmake_minimum_required(VERSION 3.21)

add_executable(cardnal cardnal.cpp libs.cpp)
set_target_properties(cardnal PROPERTIES CXX_STANDARD 20)
