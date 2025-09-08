#include <catch2/catch_test_macros.hpp>
#include <cstdint>
#include "dsa.h"

TEST_CASE("size() works properly") {
    SimpleVector v;
    REQUIRE( v.size() == 0);

    v.push(3);
    v.push(4);
    v.push(5);
    REQUIRE( v.size() == 3 );
}

TEST_CASE("capacity() is working properly") {
    SimpleVector v;

    for (int i = 1; i <= 17; i++) {
        v.push(i);
    }

    REQUIRE( v.capacity() > 16 );
}

TEST_CASE("is_empty() is working properly") {
    SimpleVector v;
    REQUIRE( v.is_empty() == true );
}

TEST_CASE("at() is working properly") {
    SimpleVector v;
    v.push(1);
    v.push(2);
    v.push(3);

    REQUIRE( v.at(0) == 1);
}

TEST_CASE("insert() is working properly") {
    SimpleVector v;
    v.push(1);
    v.push(2);
    v.push(3);
    v.insert(0, 7);
    v.insert(4, 9);

    REQUIRE( v.at(0) == 7 );
    REQUIRE( v.at(4) == 9 );
}

TEST_CASE("prepend() is working properly") {
    SimpleVector v;
    v.push(1);
    v.push(2);
    v.push(3);
    v.prepend(7);

    REQUIRE( v.at(0) == 7 );
}

TEST_CASE("pop() is working properly") {
    SimpleVector v;
    v.push(1);
    v.push(2);
    v.push(3);

    REQUIRE( v.size() == 3 );
    REQUIRE( v.pop() == 3 );
    REQUIRE( v.size() == 2 );
}

TEST_CASE("deleteAt() is working properly") {
    SimpleVector v;
    v.push(1);
    v.push(2);
    v.push(3);
    v.deleteAt(0);

    REQUIRE( v.size() == 2 );
    REQUIRE( v.at(0) == 2 ); 
}

TEST_CASE("remove() is working properly") {
    SimpleVector v;
    v.push(3);
    v.push(1);
    v.push(3);
    v.push(2);
    v.push(3);
    v.remove(3);

    REQUIRE( v.find(3) == -1);
}

TEST_CASE("find() is working properly") {
    SimpleVector v;
    v.push(1);
    v.push(2);
    v.push(3);

    REQUIRE( v.find(3) == 2 );
}