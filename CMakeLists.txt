cmake_minimum_required(VERSION 3.22)
project(radgrad VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Header-only library
add_library(radgrad INTERFACE)
add_library(radgrad::radgrad ALIAS radgrad)

# Specify include directories for header-only library
target_include_directories(radgrad
    INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

# Require C++20 for consumers
target_compile_features(radgrad INTERFACE cxx_std_20)

# Optional: Add compile options for consumers
# target_compile_options(radgrad INTERFACE ...)

# Build examples
option(RADGRAD_BUILD_EXAMPLES "Build radgrad examples" OFF)
if(RADGRAD_BUILD_EXAMPLES)
    add_subdirectory(examples)
endif()

# todo
# option(RADGRAD_BUILD_TESTS "Build radgrad tests" OFF)
# if(RADGRAD_BUILD_TESTS)
    # add_subdirectory(tests)
# endif()
