
add_executable(TravelAgency TravelAgency.cxx include/agency.hpp include/agencybuilder.hpp agency.cxx agencybuilder.cxx)

target_link_libraries(TravelAgency PRIVATE tsv_library)
target_include_directories(TravelAgency PRIVATE "${PROJECT_BINARY_DIR}/include")
target_include_directories(TravelAgency PUBLIC include)

add_library(app_library include/agency.hpp include/agencybuilder.hpp agency.cxx agencybuilder.cxx)
target_include_directories(app_library PRIVATE "${PROJECT_BINARY_DIR}/include")
target_include_directories(app_library PUBLIC include)
