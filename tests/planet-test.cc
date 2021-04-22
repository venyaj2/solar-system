//
// Created by Venya Joshi on 4/20/21.
//

#include <solarsystem.h>
#include <catch2/catch.hpp>
#include <iostream>
#include "../include/solarsystem.h"

TEST_CASE("Test parsing of json") {
    solarsystem::SolarSystem solarSystem("planet.json");
    REQUIRE(solarSystem.GetPlanets().at(0).GetName() == "Sun");
}