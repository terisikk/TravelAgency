file(GLOB HEADER_LIST CONFIGURE_DEPENDS "include/tsv/*.hpp")

add_library(tsv_library reader.cxx ${HEADER_LIST})
target_include_directories(tsv_library PUBLIC include)
