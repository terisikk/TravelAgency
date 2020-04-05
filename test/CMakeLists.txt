macro(package_add_test TESTNAME)
    # create an exectuable in which the tests will be stored
    add_executable(${TESTNAME} ${ARGN})

    target_link_libraries(${TESTNAME} Catch2::Catch2)

    catch_discover_tests(${TESTNAME})

    set_target_properties(${TESTNAME} PROPERTIES FOLDER tests)
endmacro()

package_add_test(DataParser test_DataParser.cxx)
