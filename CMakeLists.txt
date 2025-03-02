cmake_minimum_required(VERSION 3.10)

project(GraphISOBench)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add source files
add_executable(GraphISOBench
    src/main.cpp
    src/core/graph.cpp
    src/algorithms/vf2.cpp
    src/algorithms/weisfeiler_lehman.cpp
    src/algorithms/nauty_traces.cpp
)

# Include directories
target_include_directories(GraphISOBench PRIVATE src/core src/algorithms)

# Enable compiler warnings
target_compile_options(GraphISOBench PRIVATE -Wall -Wextra)