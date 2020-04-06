add_executable(TravelAgency TravelAgency.cxx)

target_link_libraries(TravelAgency PRIVATE tsv_library)
target_include_directories(TravelAgency PRIVATE "${PROJECT_BINARY_DIR}/include")
