file(GLOB HEADER_LIST CONFIGURE_DEPENDS "include/ui/*.hpp")
file(GLOB CXX_LIST CONFIGURE_DEPENDS "*.cxx")

add_library(ui_library ${CXX_LIST} ${HEADER_LIST})
target_include_directories(ui_library PUBLIC include)
