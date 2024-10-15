cmake_minimum_required(VERSION 3.28)

# Project name
project(DSA_2)

# Set the C++ standard to C++20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Find the ncurses package
find_package(Curses REQUIRED)

# Include ncurses directories
include_directories(${CURSES_INCLUDE_DIR})

# Add the executable
add_executable(DSA_2 main.cpp)

# Link the ncurses library
target_link_libraries(DSA_2 ${CURSES_LIBRARIES})
