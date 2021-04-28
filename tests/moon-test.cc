//
// Created by Venya Joshi on 4/20/21.
//

#include <catch2/catch.hpp>
#include <iostream>
#include <moon.h>

TEST_CASE("Test proper initialization of Moon") {
    solarsystem::Moon moon(4, 2, 1, 2);
    SECTION("Check setter methods") {
        REQUIRE(moon.UpdateDegree() == 5);
    }
}