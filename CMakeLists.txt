cmake_minimum_required(VERSION 3.28)
project(Rubik_sCubeSolver)

set(CMAKE_CXX_STANDARD 17)

add_executable(Rubik_sCubeSolver main.cpp
        Models/RubikCube.h
        Models/RubikCube.cpp
        Models/RubikCube3DArray.cpp
        Models/RubikCube1DArray.cpp
)
