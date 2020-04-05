cmake_minimum_required(VERSION 3.14)

set(CMAKE_CXX_COMPILER "/usr/bin/clang++")

project(TravelAgency VERSION 1.0)

set(CMAKE_CXX_FLAGS "-Wall -stdlib=libc++")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_CLANG_TIDY /usr/bin/clang-tidy -checks=*,-fuchsia*,-cppcoreguidelines-pro-bounds-pointer-arithmetic;-header-filter=/\(src|test\)/.*;-line-filter=[{"name":"catch.hpp"}];-warnings-as-errors=*)

##################################
# Download and install Catch2

include(FetchContent)
FetchContent_Declare(
  catch
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v2.11.3
)

FetchContent_MakeAvailable(catch)
include(${catch_SOURCE_DIR}/contrib/Catch.cmake)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

configure_file(include/TravelAgencyConfig.h.in include/TravelAgencyConfig.h)

add_subdirectory(src)
add_subdirectory(test)
