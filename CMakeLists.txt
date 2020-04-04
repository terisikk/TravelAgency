cmake_minimum_required(VERSION 3.14)

project(TravelAgency VERSION 1.0)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_CXX_COMPILER "clang++")
set(CMAKE_CXX_FLAGS "-Wall -stdlib=libc++")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_CLANG_TIDY clang-tidy -checks=*,-fuchsia*,-cppcoreguidelines-pro-bounds-pointer-arithmetic;-header-filter=.*;-warnings-as-errors=*)

configure_file(include/TravelAgencyConfig.h.in include/TravelAgencyConfig.h)

add_subdirectory(src)
add_executable(TravelAgency src/TravelAgency.cxx)

target_include_directories(TravelAgency PUBLIC "${PROJECT_BINARY_DIR}")
target_include_directories(TravelAgency PRIVATE "${PROJECT_BINARY_DIR}/include")
