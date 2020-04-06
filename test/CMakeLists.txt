macro(package_add_test TESTNAME LIBRARIES)
    # create an exectuable in which the tests will be stored
    add_executable(${TESTNAME} ${TESTNAME}.cxx)

    target_link_libraries(${TESTNAME} PRIVATE Catch2::Catch2 ${LIBRARIES})

    catch_discover_tests(${TESTNAME})
endmacro()

include(FetchContent)
FetchContent_Declare(
  catch
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v2.11.3
)

FetchContent_MakeAvailable(catch)
include(${catch_SOURCE_DIR}/contrib/Catch.cmake)

package_add_test(test_data_parser data_parser_library)
