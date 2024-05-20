cmake_minimum_required(VERSION 3.25)
project(FSM)

set(CMAKE_CXX_STANDARD 17)

add_executable(FSM main.cpp FSM.cpp FSM.h State.cpp State.h)
