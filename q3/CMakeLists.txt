# ZJU_OOP Assignment 6
# written by: Charles Sun
# date:       2022/05/09
cmake_minimum_required(VERSION 3.15)

project(mcm_q3)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")
add_executable(q3)
aux_source_directory(src source)
target_sources(q3 PUBLIC ${source})
target_include_directories(q3 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)