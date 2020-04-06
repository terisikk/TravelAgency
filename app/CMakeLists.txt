add_executable(TravelAgency TravelAgency.cxx)

target_link_libraries(TravelAgency PRIVATE data_parser_library)
target_include_directories(TravelAgency PRIVATE "${PROJECT_BINARY_DIR}/include")
