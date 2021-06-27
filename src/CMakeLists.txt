cmake_minimum_required(VERSION 3.20.3)

project(BASUdoku)
set (CMAKE_CXX_STANDARD 11)

add_executable(
  BASUdoku
  main.cpp
  constructs.cpp
  readings.cpp
  solving.cpp
  converts.cpp
)
