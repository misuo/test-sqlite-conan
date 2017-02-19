cmake_minimum_required(VERSION 3.0)

project(mytest)

## Do debug builds on default if not specified.
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "DEBUG") 
endif (NOT CMAKE_BUILD_TYPE)
message(STATUS "Configured to compile in ${CMAKE_BUILD_TYPE} mode.")

#if(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
# set(CMAKE_INSTALL_PREFIX "extern/" CACHE PATH "mytest install cache" FORCE)
#endif(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)

# Conan.io (package manager) integration 
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

##
include(ExternalProject)
set(EXTERNAL_INSTALL_LOCATION ${CMAKE_BINARY_DIR}/extern)

## Other
# https://coderwall.com/p/y3zzbq/use-cmake-enabled-libraries-in-your-cmake-project

## Source files and target executable
set(SOURCE src/main.cpp)
add_executable(${PROJECT_NAME} ${SOURCE})

## SQLite3 alternative 1) Download to local ./extern
#ExternalProject_Add(sqlite3
#  GIT_REPOSITORY https://github.com/jgsogo/conan-sqlite3
#  CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${EXTERNAL_INSTALL_LOCATION}
#)
#include_directories(${EXTERNAL_INSTALL_LOCATION}/inc)
#link_directories(${EXTERNAL_INSTALL_LOCATION}/lib)
#add_dependencies(${PROJECT_NAME} sqlite3)

## SQLite3 alternative 2) Use package dependency (nothing is downloaded automatically)
find_package(sqlite3 REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE sqlite3)

#install(TARGETS ${PROJECT_NAME} DESTINATION bin)
