cmake_minimum_required(VERSION 3.21)

add_executable(cardnale cardnale.cpp libs.cpp)
set_target_properties(cardnale PROPERTIES CXX_STANDARD 20)
