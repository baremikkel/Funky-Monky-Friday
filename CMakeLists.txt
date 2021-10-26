cmake_minimum_required(VERSION 3.0)

# Set the project name
project(Graphics)

# Require C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add SFML !!! SET DIR HERE !!!
set(SFML_DIR "C:/DIR/TO/SFML-2.5.1/lib/cmake/SFML")
find_package(SFML COMPONENTS graphics window system)

# Include headers from SFML
include_directories( include ${SFML_INCLUDE_DIR})

# Add the executable (remember cpp files) 
add_executable(${CMAKE_PROJECT_NAME} main.cpp)

# Link SFML
target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE sfml-graphics sfml-window sfml-system)
