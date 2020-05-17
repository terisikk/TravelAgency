macro(package_add_test TESTNAME LIBRARY)
    # create an exectuable in which the tests will be stored
    add_executable(${TESTNAME} ${ARGN})

    target_link_libraries(${TESTNAME} PRIVATE Catch2::Catch2 ${LIBRARY})

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

package_add_test(test_tsv tsv_library 
  tsv/test_reader.cxx 
  tsv/test_table.cxx
)

package_add_test(test_ui ui_library ui/test_ui.cxx)

add_executable(test_acceptance acceptance/test_agencybuilder.cxx)
target_link_libraries(test_acceptance PRIVATE Catch2::Catch2 tsv_library app_library)
catch_discover_tests(test_acceptance)

