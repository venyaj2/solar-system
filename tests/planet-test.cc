//
// Created by Venya Joshi on 4/20/21.
//

#include <catch2/catch.hpp>
#include <iostream>
#include <planet.h>

TEST_CASE("Test proper initialization of planet") {
    solarsystem::Planet planet("Pluto", 4, "gray", 55, 700, "Dwarf planet, formally removed from planet circulation by NASA");
    SECTION("Test initialized Planet getters") {
        REQUIRE(planet.GetAngle() == 55);
        REQUIRE(planet.GetDistance() == 700);
        REQUIRE(planet.GetRadius() == 4);
        REQUIRE(planet.GetColor() == std::string("gray"));
    }
    
    SECTION("Test initialized Planet setters") {
        planet.SetDegree(89);
        REQUIRE(planet.GetAngle() == 89);
    }
}

TEST_CASE("Test Sun setters and getters") {
    solarsystem::Planet planet = solarsystem::Planet::SUN;
    SECTION("Test initialized Planet getters") {
        REQUIRE(planet.GetAngle() == 0);
        REQUIRE(planet.GetDistance() == 0);
        REQUIRE(planet.GetRadius() == 30);
        REQUIRE(planet.GetColor() == std::string("yellow"));
    }

    SECTION("Test initialized Planet setters") {
        planet.SetDegree(89);
        REQUIRE(planet.GetAngle() == 89);
    }
}

TEST_CASE("Test Mercury setters and getters") {
    solarsystem::Planet planet = solarsystem::Planet::MERCURY;
    SECTION("Test initialized Planet getters") {
        REQUIRE(planet.GetAngle() == 57);
        REQUIRE(planet.GetDistance() == 50);
        REQUIRE(planet.GetRadius() == 4);
        REQUIRE(planet.GetColor() == std::string("gray"));
    }

    SECTION("Test initialized Planet setters") {
        planet.SetDegree(89);
        REQUIRE(planet.GetAngle() == 89);
    }
}

TEST_CASE("Test Venus setters and getters") {
    solarsystem::Planet planet = solarsystem::Planet::VENUS;
    SECTION("Test initialized Planet getters") {
        REQUIRE(planet.GetAngle() == 87);
        REQUIRE(planet.GetDistance() == 70);
        REQUIRE(planet.GetRadius() == 6);
        REQUIRE(planet.GetColor() == std::string("brown"));
    }

    SECTION("Test initialized Planet setters") {
        planet.SetDegree(89);
        REQUIRE(planet.GetAngle() == 89);
    }
}

TEST_CASE("Test Earth setters and getters") {
    solarsystem::Planet planet = solarsystem::Planet::EARTH;
    SECTION("Test initialized Planet getters") {
        REQUIRE(planet.GetAngle() == 97);
        REQUIRE(planet.GetDistance() == 80);
        REQUIRE(planet.GetRadius() == 10);
        REQUIRE(planet.GetColor() == std::string("green"));
    }

    SECTION("Test initialized Planet setters") {
        planet.SetDegree(89);
        REQUIRE(planet.GetAngle() == 89);
    }
}

TEST_CASE("Test Mars setters and getters") {
    solarsystem::Planet planet = solarsystem::Planet::MARS;
    SECTION("Test initialized Planet getters") {
        REQUIRE(planet.GetAngle() == 137);
        REQUIRE(planet.GetDistance() == 98);
        REQUIRE(planet.GetRadius() == 8);
        REQUIRE(planet.GetColor() == std::string("red"));
    }

    SECTION("Test initialized Planet setters") {
        planet.SetDegree(89);
        REQUIRE(planet.GetAngle() == 89);
    }
}

TEST_CASE("Test Jupiter setters and getters") {
    solarsystem::Planet planet = solarsystem::Planet::JUPITER;
    SECTION("Test initialized Planet getters") {
        REQUIRE(planet.GetAngle() == 200);
        REQUIRE(planet.GetDistance() == 180);
        REQUIRE(planet.GetRadius() == 17);
        REQUIRE(planet.GetColor() == std::string("orange"));
    }

    SECTION("Test initialized Planet setters") {
        planet.SetDegree(89);
        REQUIRE(planet.GetAngle() == 89);
    }
}

TEST_CASE("Test Saturn setters and getters") {
    solarsystem::Planet planet = solarsystem::Planet::SATURN;
    SECTION("Test initialized Planet getters") {
        REQUIRE(planet.GetAngle() == 193);
        REQUIRE(planet.GetDistance() == 280);
        REQUIRE(planet.GetRadius() == 14);
        REQUIRE(planet.GetColor() == std::string("yellow"));
    }

    SECTION("Test initialized Planet setters") {
        planet.SetDegree(89);
        REQUIRE(planet.GetAngle() == 89);
    }
}

TEST_CASE("Test Uranus setters and getters") {
    solarsystem::Planet planet = solarsystem::Planet::URANUS;
    SECTION("Test initialized Planet getters") {
        REQUIRE(planet.GetAngle() == 280);
        REQUIRE(planet.GetDistance() == 300);
        REQUIRE(planet.GetRadius() == 6);
        REQUIRE(planet.GetColor() == std::string("teal"));
    }

    SECTION("Test initialized Planet setters") {
        planet.SetDegree(89);
        REQUIRE(planet.GetAngle() == 89);
    }
}

TEST_CASE("Test Neptune setters and getters") {
    solarsystem::Planet planet = solarsystem::Planet::NEPTUNE;
    SECTION("Test initialized Planet getters") {
        REQUIRE(planet.GetAngle() == 300);
        REQUIRE(planet.GetDistance() == 320);
        REQUIRE(planet.GetRadius() == 6);
        REQUIRE(planet.GetColor() == std::string("blue"));
    }

    SECTION("Test initialized Planet setters") {
        planet.SetDegree(89);
        REQUIRE(planet.GetAngle() == 89);
    }
}