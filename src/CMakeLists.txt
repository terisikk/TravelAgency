set(BINARY ${CMAKE_PROJECT_NAME})

file(GLOB HEADER_LIST CONFIGURE_DEPENDS "${TravelAgency_SOURCE_DIR}/include/*.hpp")

add_library(tabular_data_parser_library tabular_data_parser.cxx ${HEADER_LIST})
target_include_directories(tabular_data_parser_library PUBLIC ../include)
