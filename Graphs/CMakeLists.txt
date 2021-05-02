cmake_minimum_required(VERSION 3.8)

project("SMT")

#main bin file
set(main "main.cpp")
add_executable(TTS ${main})

add_subdirectory("Graphs")

target_link_libraries(TTS PUBLIC graphs_lib)
target_include_directories(TTS PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/Graphs)