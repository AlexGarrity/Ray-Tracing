cmake_minimum_required (VERSION 3.10)
project (RayTracer)

add_definitions("-O4" "-std=c++17")
add_definitions("-D HEADLESS" "-D SUPER")

file (GLOB SOURCES
	include/*.h
	include/*.hpp
	src/*.cpp
)

add_executable (RayTracer src/Main.cpp ${SOURCES})