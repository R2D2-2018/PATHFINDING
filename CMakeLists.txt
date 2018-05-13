#cmake_minimum_required (VERSION 2.8.11)
#
#option (test_build "test_build" FALSE)

# Toolchain:

set (build_environment "$ENV{R2D2_BUILD_ENVIRONMENT}") # Your path to kvasir_toolchain

if (build_environment)
set (toolchain ${build_environment}/toolchain)
else (build_environment)
set (build_environment ../..)
set (toolchain ../../toolchain)
endif (build_environment)

#include (Sources.cmake)
#
#if (NOT ${test_build})
#set (CMAKE_TOOLCHAIN_FILE ${toolchain}/compilers/arm-none-eabi.cmake)
#else (NOT ${test_build})
#set (CMAKE_TOOLCHAIN_FILE ${toolchain}/compilers/host-gcc.cmake)
#endif (NOT ${test_build})
#
#if (NOT ${test_build})
#set (CMAKE_TOOLCHAIN_FILE ${toolchain}/compilers/arm-none-eabi.cmake)
#else (NOT ${test_build})
#set (CMAKE_TOOLCHAIN_FILE ${toolchain}/compilers/host-gcc.cmake)
#endif (NOT ${test_build})
#
#project (arduino-template CXX)
#
#set (build_test_enabled TRUE)
#set (unit_test_enabled TRUE)
#set (complexity_test_enabled TRUE)
#set (memcheck_enabled TRUE)
#set (unit_test_main test/test_main.cpp)
#
#if (NOT ${test_build})
#include (BuildModule.cmake)
#else (NOT ${test_build})
#include (TestModule.cmake)
#endif (NOT ${test_build})

cmake_minimum_required(VERSION 2.6)

project(template-pc)
set(exe_name "template-pc")

enable_testing()
include(${build_environment}/flags.cmake)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

set(sources
    src/main.cpp
    src/a_star.cpp
    src/graph.cpp
    src/library_interface.cpp
    src/serial_interface.cpp
    src/node.cpp
)

add_executable(${exe_name} ${sources})
