cmake_minimum_required(VERSION 3.0)

project(mytest)

# Conan.io (package manager) integration 
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

## Source files and target executable
set(SOURCE src/main.cpp)
add_executable(${PROJECT_NAME} ${SOURCE})

## SQLite3 package and usage
find_package(sqlite3 REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE sqlite3)