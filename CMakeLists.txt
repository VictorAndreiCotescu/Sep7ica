cmake_minimum_required(VERSION 3.17)
project(Septica)


set (CMAKE_CXX_STANDARD 14)
set (GCC_COMPILE_FLAGS "-Wall -Wextra")

add_executable (Septica main.cpp Carte.cpp Headers/Carte.h Pachet.cpp Headers/Pachet.h Jucator.cpp Headers/Jucator.h Calculator.cpp Headers/Calculator.h Fereastra.cpp Headers/Fereastra.h)
