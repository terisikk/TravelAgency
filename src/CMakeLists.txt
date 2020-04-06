set(BINARY ${CMAKE_PROJECT_NAME})

file(GLOB HEADER_LIST CONFIGURE_DEPENDS "${TravelAgency_SOURCE_DIR}/include/*.hpp")

add_library(data_parser_library data_parser.cxx ${HEADER_LIST})
target_include_directories(data_parser_library PUBLIC ../include)
