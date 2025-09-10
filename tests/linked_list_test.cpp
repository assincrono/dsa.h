#include <catch2/catch_test_macros.hpp>
#include <cstdint>
#include "dsa.h"

TEST_CASE("front() works properly") {
    LinkedList l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);

    REQUIRE( l.front() == 1 );
}

TEST_CASE("back() works properly") {
    LinkedList l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);

    REQUIRE( l.back() == 3 );
}

TEST_CASE("empty() works properly") {
    LinkedList l;
    REQUIRE( l.empty() == true );
}

TEST_CASE("size() works properly") {
    LinkedList l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    
    REQUIRE( l.size() == 3 );
}

TEST_CASE("push_front() works properly") {
    LinkedList l;
    l.push_front(1);
    l.push_front(2);
    l.push_front(3);

    REQUIRE( l.front() == 3 );
}

TEST_CASE("push_back() works properly") {
    LinkedList l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);

    REQUIRE( l.front() == 1 );
}

TEST_CASE("pop_front() works properly") {
    LinkedList l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);

    REQUIRE( l.pop_front() == 1 );
    REQUIRE( l.front() == 2 );
    REQUIRE( l.size() == 2 );
}

TEST_CASE("pop_back() works properly") {
    LinkedList l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);

    REQUIRE( l.pop_back() == 3 );
    REQUIRE( l.back() == 2 );
    REQUIRE( l.size() == 2 );
}

TEST_CASE("insert() works properly") {
    LinkedList l;
    l.insert(0, 1);
    l.insert(1, 2);
    l.insert(2, 3);
    l.insert(1, 9);

    REQUIRE( l.size() == 4 );
}