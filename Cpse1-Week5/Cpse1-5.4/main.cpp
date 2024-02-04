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
    integerSet<char, 3> object;

    object.add('m');
    object.add('e');
    object.add('o');

    REQUIRE(object.contains('m') == true);
    REQUIRE(object.contains('e') == true);
    REQUIRE(object.contains('o') == true);
    REQUIRE(object.contains('u') == false);

}

TEST_CASE("Remove test_case INT"){
    integerSet<int,2> object;

    object.add(1);
    object.add(2);
    object.remove(1);
    object.remove(100);

    REQUIRE(object.contains(1) == false);
    REQUIRE(object.contains(2) == true);
}

TEST_CASE("Remove test_case CHAR"){
    integerSet<char, 3> object;

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

TEST_CASE("Add test_case maximum INT"){
    integerSet<int, 5> object;

    object.add(1);
    object.add(2);
    object.add(3);
    object.add(4);
    object.add(5);

    REQUIRE(object.setMax() == 5);
}

TEST_CASE("Add test_case maximum CHAR"){
    integerSet<char, 3> object;
    object.add('a');
    object.add('c');
    object.add('b');

    REQUIRE(object.setMax() == 'c');
}

TEST_CASE("Contains test_case INT"){
    integerSet<int, 3> object;
    object.add(1);
    object.add(2);
    object.add(3);

    REQUIRE(object.contains(1));
    REQUIRE(object.contains(2));
    REQUIRE(object.contains(3));
    REQUIRE(!object.contains(4));
}

TEST_CASE("Contains test_case CHAR"){
    integerSet<char, 3> object;
    object.add('m');
    object.add('e');
    object.add('o');
    object.add('f');

    REQUIRE(object.contains('m'));
    REQUIRE(object.contains('e'));
    REQUIRE(object.contains('o'));
    REQUIRE(!object.contains('f'));
}

//STRINGS TESTCASES---------------------------------------------------------

TEST_CASE("Add test_case string CHAR"){
    integerSet<char, 3> object;
    std::stringstream string;

    object.add('m');
    object.add('e');
    object.add('o');

    string << object;

    REQUIRE(string.str() == "[m, e, o, ]");
}

TEST_CASE("Remove test_case string CHAR"){
    integerSet<char, 3> object;
    std::stringstream string;

    object.add('m');
    object.add('e');
    object.remove('o');
    object.remove('w');
    object.add('o');
    object.remove('o');
    object.add('v');

    string << object;

    REQUIRE(string.str() == "[m, e, v, ]");
}

TEST_CASE("Empty test_case string CHAR"){
    integerSet<char, 3> object;
    std::stringstream string;

    string << object;

    REQUIRE(string.str() == "[None, None, None, ]");
}

TEST_CASE("Over maximum test_case string CHAR"){
    integerSet<char, 3> object;
    std::stringstream string;

    object.add('m');
    object.add('e');
    object.add('o');
    object.add('w');

    string << object;

    REQUIRE(string.str() == "[m, e, o, ]");
}

TEST_CASE("Unique test_case string CHAR"){
    integerSet<char, 3> object;
    std::stringstream string;

    object.add('m');
    object.add('m');

    string << object;

    REQUIRE(string.str() == "[m, None, None, ]");
}
