cmake_minimum_required(VERSION 3.2)
project(mp3_player)

cmake_policy(SET CMP0026 OLD)
include(cmake/libtool.cmake)

add_subdirectory(src)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
