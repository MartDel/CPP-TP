cmake_minimum_required(VERSION 3.20.5)
project(tp3)

include_directories(headers)

file(GLOB SOURCES "src/*.cpp")

add_executable(tp3 ${SOURCES})
