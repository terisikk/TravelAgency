#include <catch2/catch.hpp>

#include <typeinfo>

#include "tsv/field.hpp"

SCENARIO( "Fields can be created" ) {
    GIVEN( "two fields with different types" ) {
        tsv::Field<std::string> name("name");
        tsv::Field<int> number("number");

        WHEN( "field types are compared" ) {
            bool result = typeid(name) == typeid(number);

            THEN( "field types are not equal") {
                REQUIRE(result == false);
            }
        }
    }

    GIVEN( "two fields with same type" ) {
        tsv::Field<std::string> firstName("firstName");
        tsv::Field<std::string> lastName("lastName");

        WHEN( "field types are compared" ) {
            bool result = typeid(firstName) == typeid(lastName);

            THEN( "field types are equal") {
                REQUIRE(result == true);
            }
        }
    }

    GIVEN( "fields with names" ) {
        tsv::Field<std::string> lastname("lastname");
        tsv::Field<int> street_number("street_number");
        tsv::Field<bool> isAlive("isAlive");

        WHEN( "the field names are printed" ) {
            std::string name__lastname = lastname.getName();
            std::string name__street_number = street_number.getName();
            std::string name__isAlive = isAlive.getName();

            THEN( "the names equal the original object names" ) {
                REQUIRE( name__lastname == "lastname" );
                REQUIRE( name__street_number == "street_number" );
                REQUIRE( name__isAlive == "isAlive" );
            } 
        }
    }
}