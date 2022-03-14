#define CATCH_CONFIG_MAIN

#include "hwlib.hpp"
#include "integerSet.hpp"
#include "catch.hpp"
#include "ostream"
#include <sstream>


TEST_CASE("Add test_case"){
    integerSet object;

    object.add(1);
    object.add(2);
    object.add(3);
    object.add(4);
    object.add(5);
    object.add(6);
    object.add(7);
    object.add(8);
    object.add(8);
    object.add(9);
    object.add(10);
    object.add(17);

    for(unsigned int i = 1; i <= 10; i++){
        REQUIRE(object.contains(i) == true);
    }

    REQUIRE(object.contains(17) == false);
}

TEST_CASE("Remove test_case"){
    integerSet object;

    object.add(1);
    object.add(2);
    object.remove(1);
    object.remove(100);

    REQUIRE(object.contains(1) == false);
    REQUIRE(object.contains(2) == true);
}