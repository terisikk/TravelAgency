file(GLOB HEADER_LIST CONFIGURE_DEPENDS "include/*.hpp")

add_library(tsv_library parser.cxx reader.cxx ${HEADER_LIST})
target_include_directories(tsv_library PUBLIC include)
