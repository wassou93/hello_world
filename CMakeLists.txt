cmake_minimum_required(VERSION 3.5.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set default build type to Debug if not specified
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type" FORCE)
endif()

# Set default optimization
set(CMAKE_CXX_FLAGS_DEBUG "-O0")

set(PROJECT_NAME hello_world)

project(${PROJECT_NAME} VERSION 0.1.0 LANGUAGES C CXX)

add_executable(${PROJECT_NAME} src/main.cpp)


