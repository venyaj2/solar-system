//
// Created by Venya Joshi on 4/22/21.
//

#include <catch2/catch.hpp>
#include <iostream>
#include <solarsystem.h>

TEST_CASE("Test incorrectly initialized solarsystem") {
    SECTION("Test negative x dimension") {
        REQUIRE_THROWS(std::invalid_argument(""), solarsystem::SolarSystem(-1, 100));
    }
    SECTION("Test negative y dimension") {
        REQUIRE_THROWS(std::invalid_argument(""), solarsystem::SolarSystem(100, -100));
    }
    SECTION("Test zero x dimension") {
        REQUIRE_THROWS(std::invalid_argument(""), solarsystem::SolarSystem(0, 100));
    }
    SECTION("Test zero y dimension") {
        REQUIRE_THROWS(std::invalid_argument(""), solarsystem::SolarSystem(100, 0));
    }
}

TEST_CASE("Test correctly initializes solarsystem") {
    solarsystem::SolarSystem solarSystem(500, 800);
    
    SECTION("Test solarsystem setters") {
        REQUIRE(solarSystem.GetXDimension() == 500);
        REQUIRE(solarSystem.GetYDimension() == 800);
    }
    
    SECTION("Test solarsystem planet loading by name") {
        REQUIRE(solarSystem.GetPlanets().at(8).GetName() == solarsystem::Planet::NEPTUNE.GetName());
        REQUIRE(solarSystem.GetPlanets().at(7).GetName() == solarsystem::Planet::URANUS.GetName());
        REQUIRE(solarSystem.GetPlanets().at(6).GetName() == solarsystem::Planet::SATURN.GetName());
        REQUIRE(solarSystem.GetPlanets().at(5).GetName() == solarsystem::Planet::JUPITER.GetName());
        REQUIRE(solarSystem.GetPlanets().at(4).GetName() == solarsystem::Planet::MARS.GetName());
        REQUIRE(solarSystem.GetPlanets().at(3).GetName() == solarsystem::Planet::EARTH.GetName());
        REQUIRE(solarSystem.GetPlanets().at(2).GetName() == solarsystem::Planet::VENUS.GetName());
        REQUIRE(solarSystem.GetPlanets().at(1).GetName() == solarsystem::Planet::MERCURY.GetName());
        REQUIRE(solarSystem.GetPlanets().at(0).GetName() == solarsystem::Planet::SUN.GetName());
    }
}

TEST_CASE("Test CalculatePosition()") {
    solarsystem::SolarSystem solarSystem(500, 800);
    glm::vec2 position(250, 400);
    REQUIRE(solarSystem.CalculatePositionPlanet(solarSystem.GetPlanets().at(0)) == position);

    REQUIRE(solarSystem.CalculatePositionPlanet(solarSystem.GetPlanets().at(1)).x == Approx(277.23).epsilon(.01));
    REQUIRE(solarSystem.CalculatePositionPlanet(solarSystem.GetPlanets().at(1)).y == Approx(441.93).epsilon(.01));

    REQUIRE(solarSystem.CalculatePositionPlanet(solarSystem.GetPlanets().at(8)).x == Approx(410).epsilon(.01));
    REQUIRE(solarSystem.CalculatePositionPlanet(solarSystem.GetPlanets().at(8)).y == Approx(122.87).epsilon(.01));
}

TEST_CASE("Test AdvanceOneFrame()") {
    solarsystem::SolarSystem solarSystem(500, 800);
    solarSystem.AdvanceOneFrame();
    REQUIRE(solarSystem.GetPlanets().at(0).GetAngle() == 1);
    solarSystem.AdvanceOneFrame();
    REQUIRE(solarSystem.GetPlanets().at(0).GetAngle() == 2);
}