cmake_minimum_required(VERSION 3.14)

set(CMAKE_CXX_COMPILER "/usr/bin/clang++")

project(TravelAgency VERSION 1.0)

set(CMAKE_CXX_FLAGS "-Wall -stdlib=libc++ -std=c++17")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_CLANG_TIDY /usr/bin/clang-tidy 
    -checks=*,-fuchsia*,-cppcoreguidelines-pro-bounds-pointer-arithmetic,-cppcoreguidelines-pro-type-vararg,-hicpp-vararg,-cert-*,-google-readability-braces-around-statements,-hicpp-braces-around-statements,-modernize-use-nodiscard;
    -header-filter=.*/\(src|test|include\)/.*;
    -warnings-as-errors=*;
    -fix)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

configure_file(include/TravelAgencyConfig.h.in include/TravelAgencyConfig.h)

add_subdirectory(src)
add_subdirectory(test)
add_subdirectory(app)