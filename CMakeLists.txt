cmake_minimum_required(VERSION 3.17)
project(Septica)

set(CMAKE_CXX_STANDARD 14)

set(GLFW_DIR C:/Users/victo/CLionProjects/Septica/GLFW)
set(SOIL_DIR C:/Users/victo/CLionProjects/Septica/SOIL)

set(GCC_COMPILE_FLAGS "-Wall -Wextra -pedantic -Weffc++ -Werror")

add_compile_options(-Wall -Wextra -pedantic -Werror -Weffc++)

add_executable(Septica main.cpp Carte.cpp Headers/Carte.h Pachet.cpp Headers/Pachet.h Jucator.cpp Headers/Jucator.h Calculator.cpp Headers/Calculator.h Fereastra.cpp Headers/Fereastra.h Grafica/Textura.cpp Grafica/Textura.h Grafica/Sprite.cpp Grafica/Sprite.h IO/MOUSE.cpp IO/MOUSE.h Joc.cpp Joc.h)

target_include_directories(${PROJECT_NAME} PUBLIC ${GLFW_DIR})
target_include_directories(${PROJECT_NAME} PUBLIC ${SOIL_DIR}/src)

target_link_directories(${PROJECT_NAME} PUBLIC ${GLFW_DIR})
target_link_directories(${PROJECT_NAME} PUBLIC ${SOIL_DIR}/lib)

target_link_libraries(${PROJECT_NAME} soil glu32 opengl32 glfw3)
