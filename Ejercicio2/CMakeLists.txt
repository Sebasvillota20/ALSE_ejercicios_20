cmake_minimum_required(VERSION 2.8.12)

project(Ejercicio2)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

find_package(Qt5Core)

add_executable(${PROJECT_NAME} "main.cpp" "geometrica.h" "geometrica.cpp" "triangulo.h" "triangulo.cpp" "cuadrado.cpp" "cuadrado.h" "pentagono.cpp" "pentagono.h" "circulo.h" "circulo.cpp")

target_link_libraries(${PROJECT_NAME} Qt5::Core)
