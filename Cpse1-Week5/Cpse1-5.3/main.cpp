#define CATCH_CONFIG_MAIN

#include "hwlib.hpp"
#include "integerSet.hpp"
#include "catch.hpp"
#include "ostream"
#include <sstream>


TEST_CASE("Add test_case INT"){
    integerSet<int, 10> object;

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

TEST_CASE("Add test_case CHAR"){
    integerSet<char, 4> object;

    object.add('m');
    object.add('e');
    object.add('o');
    object.add('w');

    REQUIRE(object.contains('m') == true);
    REQUIRE(object.contains('e') == true);
    REQUIRE(object.contains('o') == true);
    REQUIRE(object.contains('w') == true);
    REQUIRE(object.contains('u') == false);
}

TEST_CASE("Remove test_case"){
    integerSet<int,10> object;

    object.add(1);
    object.add(2);
    object.remove(1);
    object.remove(100);

    REQUIRE(object.contains(1) == false);
    REQUIRE(object.contains(2) == true);
}

TEST_CASE("remove test_case CHAR"){
    integerSet<char, 4> object;

    object.add('m');
    object.add('e');
    object.remove('o');
    object.remove('w');
    object.add('o');
    object.remove('o');

    REQUIRE(object.contains('m') == true);
    REQUIRE(object.contains('e') == true);
    REQUIRE(object.contains('o') == false);
}

TEST_CASE("Add test_case maximum"){
    integerSet<int, 10> object;

    object.add(1);
    object.add(2);
    object.add(3);
    object.add(4);
    object.add(5);
    std::cout << object.setMax();

    REQUIRE(object.setMax() == 5);
}