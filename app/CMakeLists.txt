file(GLOB HEADER_LIST CONFIGURE_DEPENDS "include/*.hpp")
file(GLOB CXX_LIST CONFIGURE_DEPENDS "*.cxx")

add_executable(TravelAgency ${HEADER_LIST} ${CXX_LIST})

file(GLOB RESOURCES "resources/big/*.txt")
file(COPY ${RESOURCES} DESTINATION .)

target_link_libraries(TravelAgency PRIVATE tsv_library)
target_link_libraries(TravelAgency PRIVATE ui_library)
target_include_directories(TravelAgency PRIVATE "${PROJECT_BINARY_DIR}/include")
target_include_directories(TravelAgency PUBLIC include)

add_library(app_library ${HEADER_LIST} ${CXX_LIST})
target_link_libraries(app_library PRIVATE tsv_library)
target_link_libraries(app_library PRIVATE ui_library)
target_include_directories(app_library PRIVATE "${PROJECT_BINARY_DIR}/include")
target_include_directories(app_library PUBLIC include)
