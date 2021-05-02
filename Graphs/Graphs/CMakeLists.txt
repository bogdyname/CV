cmake_minimum_required(VERSION 3.8)
add_library(graphs_lib "Graphs.cpp" "Graphs.h")
target_include_directories(graphs_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})