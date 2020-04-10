
add_executable(TravelAgency TravelAgency.cxx include/agency.hpp agency.cxx)

target_link_libraries(TravelAgency PRIVATE tsv_library)
target_include_directories(TravelAgency PRIVATE "${PROJECT_BINARY_DIR}/include")
target_include_directories(TravelAgency PUBLIC include)

