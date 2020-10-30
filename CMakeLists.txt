cmake_minimum_required(VERSION 3.17)
project(Septica)

set(CMAKE_CXX_STANDARD 14)


add_executable(Septica main.cpp carte.cpp Headers/carte.h pachet.cpp Headers/pachet.h jucator.cpp Headers/jucator.h)
