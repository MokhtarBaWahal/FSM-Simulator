cmake_minimum_required(VERSION 3.25)
project(FSM)

set(CMAKE_CXX_STANDARD 17)

add_executable(FSM main.cpp FSM.cpp FSM.h Command.cpp Command.h StateFactory.cpp StateFactory.h ConcreteState.cpp ConcreteState.h State.cpp State.h PrintCommand.cpp PrintCommand.h EndCommand.cpp EndCommand.h JumpCommand.cpp JumpCommand.h TransitionTable.cpp TransitionTable.h Parameters.cpp Parameters.h WaitForInputCommand.cpp WaitForInputCommand.h IncrementCommand.cpp IncrementCommand.h Parser.h)

