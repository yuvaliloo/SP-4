// Test.cpp
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "MyContainer.hpp"
#include "MyContainer_Iterators.hpp"
#include <string>

using namespace MyNamespace;

TEST_CASE("MyContainer basic operations") {
    MyContainer<int> cont;
    CHECK(cont.size() == 0);

    cont.add(5);
    cont.add(10);
    cont.add(5);
    CHECK(cont.size() == 3);

    cont.remove(5);
    CHECK(cont.size() == 1);

    CHECK_THROWS(cont.remove(42));
}

TEST_CASE("MyContainer output operator") {
    MyContainer<int> cont;
    cont.add(1);
    cont.add(2);
    std::ostringstream oss;
    oss << cont;
    CHECK(oss.str() == "[ 1 2 ]");
}

TEST_CASE("AscendingOrder iteration") {
    MyContainer<int> cont;
    cont.add(4);
    cont.add(1);
    cont.add(7);

    std::vector<int> expected = {1, 4, 7};
    size_t i = 0;
    for (int val : AscendingOrder<int>(cont)) {
        CHECK(val == expected[i++]);
    }
}

TEST_CASE("DescendingOrder iteration") {
    MyContainer<int> cont;
    cont.add(4);
    cont.add(1);
    cont.add(7);

    std::vector<int> expected = {7, 4, 1};
    size_t i = 0;
    for (int val : DescendingOrder<int>(cont)) {
        CHECK(val == expected[i++]);
    }
}

TEST_CASE("SideCrossOrder iteration") {
    MyContainer<int> cont;
    cont.add(1);
    cont.add(2);
    cont.add(6);
    cont.add(7);
    cont.add(15);

    std::vector<int> expected = {1, 15, 2, 7, 6};
    size_t i = 0;
    for (int val : SideCrossOrder<int>(cont)) {
        CHECK(val == expected[i++]);
    }
}

TEST_CASE("ReverseOrder iteration") {
    MyContainer<int> cont;
    cont.add(7);
    cont.add(15);
    cont.add(6);
    cont.add(1);
    cont.add(2);

    std::vector<int> expected = {2, 1, 6, 15, 7};
    size_t i = 0;
    for (int val : ReverseOrder<int>(cont)) {
        CHECK(val == expected[i++]);
    }
}

TEST_CASE("Order iteration") {
    MyContainer<int> cont;
    cont.add(7);
    cont.add(15);
    cont.add(6);
    cont.add(1);
    cont.add(2);

    std::vector<int> expected = {7, 15, 6, 1, 2};
    size_t i = 0;
    for (int val : Order<int>(cont)) {
        CHECK(val == expected[i++]);
    }
}

TEST_CASE("MiddleOutOrder iteration odd size") {
    MyContainer<int> cont;
    cont.add(7);
    cont.add(15);
    cont.add(6);
    cont.add(1);
    cont.add(2);

    std::vector<int> expected = {6, 15, 1, 7, 2};
    size_t i = 0;
    for (int val : MiddleOutOrder<int>(cont)) {
        CHECK(val == expected[i++]);
    }
}

TEST_CASE("MiddleOutOrder iteration even size") {
    MyContainer<int> cont;
    cont.add(10);
    cont.add(20);
    cont.add(30);
    cont.add(40);

    // Implementation-dependent mid: 2 (indexing from 0)
    std::vector<int> expected = {30, 20, 40, 10};
    size_t i = 0;
    for (int val : MiddleOutOrder<int>(cont)) {
        CHECK(val == expected[i++]);
    }
}

TEST_CASE("Empty container iteration") {
    MyContainer<int> cont;

    CHECK(AscendingOrder<int>(cont).begin() == AscendingOrder<int>(cont).end());
    CHECK(DescendingOrder<int>(cont).begin() == DescendingOrder<int>(cont).end());
    CHECK(SideCrossOrder<int>(cont).begin() == SideCrossOrder<int>(cont).end());
    CHECK(ReverseOrder<int>(cont).begin() == ReverseOrder<int>(cont).end());
    CHECK(Order<int>(cont).begin() == Order<int>(cont).end());
    CHECK(MiddleOutOrder<int>(cont).begin() == MiddleOutOrder<int>(cont).end());
}


