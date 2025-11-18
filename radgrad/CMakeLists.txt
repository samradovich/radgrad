# Minimum required version of CMake
cmake_minimum_required(VERSION 3.10)

# Define the project name
project(radgrad CXX)

# Export compile commands for language servers (clangd, etc.)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# -----------------------
# --- radgrad Library ---
# -----------------------
file(GLOB_RECURSE RADGRAD_LIB_SOURCES
     "${CMAKE_CURRENT_SOURCE_DIR}/lib/autograd/*.cpp"
     "${CMAKE_CURRENT_SOURCE_DIR}/lib/memory/*.cpp"
     "${CMAKE_CURRENT_SOURCE_DIR}/lib/ops/*.cpp"
     "${CMAKE_CURRENT_SOURCE_DIR}/lib/storage/*.cpp"
     "${CMAKE_CURRENT_SOURCE_DIR}/lib/tensor/*.cpp"
)

add_library(radgrad STATIC ${RADGRAD_LIB_SOURCES})

target_include_directories(radgrad PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/..)


# ---------------------
# --- Executable(s) ---
# ---------------------
add_executable(radgrad_app app/main.cpp)

# Link the app against the radgrad library
target_link_libraries(radgrad_app PRIVATE radgrad)

# Set the output directory for the executable
set_target_properties(radgrad_app PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)
