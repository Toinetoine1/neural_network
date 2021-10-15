cmake_minimum_required(VERSION 3.20)
project(XOR C)

set(CMAKE_C_STANDARD 99)

add_executable(XOR main.c XOR.c XOR.h 2DArray.c 2DArray.h MatrixUtils.c MatrixUtils.h MathUtils.c MathUtils.h)
