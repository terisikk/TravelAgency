cmake_minimum_required(VERSION 3.10)

project(TravelAgency VERSION 1.0)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_CLANG_TIDY clang-tidy -checks=*,-fuchsia*,-cppcoreguidelines-pro-bounds-pointer-arithmetic;-header-filter=.*;-warnings-as-errors=*)

configure_file(inc/TravelAgencyConfig.h.in inc/TravelAgencyConfig.h)

add_subdirectory(src)

target_include_directories(TravelAgency PUBLIC "${PROJECT_BINARY_DIR}")
