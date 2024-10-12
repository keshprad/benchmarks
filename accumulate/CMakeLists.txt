cmake_minimum_required(VERSION 3.10)
project(false_sharing)

set(CMAKE_CXX_STANDARD 20)

# Set compile flags for optimizations and architecture
set(CMAKE_CXX_FLAGS, "${CMAKE_CXX_FLAGS} -O3 -march=native -mtune=native")
# Set linker flags for LTO
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -flto -fuse-linker-plugin")

# Add executables
add_executable(accumulate accumulate.cpp)

# Find the benchmark package
find_package(benchmark REQUIRED)

# Include directories for benchmark
include_directories(/usr/local/Cellar/google-benchmark/1.9.0/include)

# Link the benchmark library
target_link_libraries(accumulate PRIVATE benchmark::benchmark)