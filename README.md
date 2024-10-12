# benchmarks

Benchmarks to showcase various low-level features

## Setup

1. Install [google benchmark library](https://github.com/google/benchmark)
2. `cd` into any directory and use the CMake configuration to build
3. `cd` into generated build directory and run `make`
4. run the generated executable

## Notes

- accumulate
  - Simple example benchmark using the google benchmarks library
  - Also used as a template for my other benchmarks
- prefetching
  - Three benchmarks included here
    - row major traversal
      - good spatial locality -> caching helps here
    - column major traversal
      - predictable stride pattern -> prefetching helps here
    - random stride traversal
      - bad spatial locality and unpredictable stride pattern -> high # of cache misses
- false_sharing
