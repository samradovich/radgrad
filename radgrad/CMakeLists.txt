# Minimum required version of CMake
cmake_minimum_required(VERSION 3.10)

# Prefer Clang over GCC if available
if(NOT DEFINED ENV{CXX})
  find_program(CLANG_CPP 
    NAMES clang++ clang++-17 clang++-16 clang++-15 clang++-14 clang++-13 clang++-12
    PATHS /usr/bin /usr/local/bin
  )
  if(CLANG_CPP)
    set(CMAKE_CXX_COMPILER ${CLANG_CPP})
    message(STATUS "Using Clang compiler: ${CMAKE_CXX_COMPILER}")
  endif()
endif()

# Define the project name
project(radgrad CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Generate compile_commands.json for IDE support
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Base include directory for all libraries
# This allows includes like: #include "radgrad/lib/tensor/tensor.h"
get_filename_component(RADGRAD_BASE_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/.. ABSOLUTE)

# --- radgrad Library ---
# The main library containing all code from radgrad/lib
add_library(radgrad STATIC
    lib/tensor/tensor.cpp
    # Add more source files here as you implement them:
    # lib/autograd/engine.cpp
    # etc.
)

# Set include directory so #include "radgrad/lib/..." works
target_include_directories(radgrad PUBLIC
    ${RADGRAD_BASE_INCLUDE_DIR}
)

# Optional: Set output directory for library
set_target_properties(radgrad PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
)

# --- Executable (app) ---
# The executable that uses the radgrad library
add_executable(radgrad_app
    app/main.cpp
)

# Link the app against the radgrad library
target_link_libraries(radgrad_app PRIVATE
    radgrad
)

# Set the output directory for the executable
set_target_properties(radgrad_app PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)
