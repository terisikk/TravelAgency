cmake_minimum_required(VERSION 3.14)

set(CMAKE_CXX_COMPILER "/usr/bin/clang++")

project(TravelAgency VERSION 1.0)

set(CMAKE_CXX_FLAGS "-Wall -std=c++11 -stdlib=libc++")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
#set(CMAKE_CXX_CLANG_TIDY /usr/bin/clang-tidy -checks=*,-fuchsia*,-cppcoreguidelines-pro-bounds-pointer-arithmetic;-header-filter=.*;-warnings-as-errors=*)

##################################
# Download and install GoogleTest

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.10.0
)

FetchContent_GetProperties(googletest)
if(NOT googletest_POPULATED)
  FetchContent_Populate(googletest)
  add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})
endif()

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

configure_file(include/TravelAgencyConfig.h.in include/TravelAgencyConfig.h)

add_subdirectory(src)
add_subdirectory(test)
