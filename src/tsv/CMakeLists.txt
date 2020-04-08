file(GLOB HEADER_LIST CONFIGURE_DEPENDS "include/tsv/*.hpp")
file(GLOB CXX_LIST CONFIGURE_DEPENDS "*.cxx")

add_library(tsv_library ${CXX_LIST} ${HEADER_LIST})
target_include_directories(tsv_library PUBLIC include)
