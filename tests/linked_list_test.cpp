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

TEST_CASE("erase() works properly") {
    LinkedList l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.erase(1);

    REQUIRE( l.size() == 2 );
}

TEST_CASE("value_n_from_end() works properly") {
    LinkedList l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.push_back(4);
    l.push_back(5);
    l.push_back(6);

    REQUIRE( l.value_n_from_end(1) == 5 );
    REQUIRE( l.value_n_from_end(4) == 2 );
}

TEST_CASE("reverse() works properly") {
    LinkedList l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.reverse();

    REQUIRE( l.value_n_from_end(0) == 1 );
    REQUIRE( l.value_n_from_end(1) == 2 );
    REQUIRE( l.value_n_from_end(2) == 3 );
}

TEST_CASE("value_at() works properly") {
    LinkedList l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);

    REQUIRE( l.value_at(0) == 1 );
    REQUIRE( l.value_at(1) == 2 );
    REQUIRE( l.value_at(2) == 3 );
    REQUIRE( l.value_at(2) != 7 );
}

TEST_CASE("remove_value() works properly") {
    LinkedList l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.remove_value(2);

    REQUIRE( l.size() == 2 );
    REQUIRE( l.value_at(1) == 3 );
}