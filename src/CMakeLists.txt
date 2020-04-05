set(BINARY ${CMAKE_PROJECT_NAME})

file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true *.h *.cxx)
set(SOURCES ${SOURCES})

add_executable(${BINARY}_run ${SOURCES})

target_include_directories(${BINARY}_run PUBLIC "${PROJECT_BINARY_DIR}")
target_include_directories(${BINARY}_run PRIVATE "${PROJECT_BINARY_DIR}/include")
