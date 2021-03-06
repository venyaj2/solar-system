//
// Created by Venya Joshi on 4/20/21.
//

#include "cinder/gl/gl.h"
#include <planet.h>
#include <vector>
#include <moon.h>

namespace solarsystem {
    using glm::vec2;

    Planet::Planet() {}

    Planet::Planet(const std::string name, float radius, const std::string color, float degree_from_center,
                   float distance_from_center_x, float distance_from_center_y, float velocity,
                   size_t number_of_moons, const std::string file) {

        if (radius < 0 || name == "" || color == "" || distance_from_center_x < 0 || distance_from_center_y < 0) {
            throw std::invalid_argument("Invalid Planet parameter passed");
        }

        name_ = name;
        radius_ = radius;
        color_ = new char[color.size() + 1];
        std::strcpy(color_, color.c_str());
        degree_from_center_ = degree_from_center;
        distance_from_center_y_ = distance_from_center_y;
        distance_from_center_x_ = distance_from_center_x;
        velocity_ = velocity;
        file_ = file;
        visible_description_ = false;

        //Adds moons to planet
        for (size_t i = 0; i < number_of_moons; i++) {
            Moon moon(360.0 * i / number_of_moons, radius_ * 2.5, velocity_ * 2, .25 * radius_);
            moons.push_back(moon);
        }
    }

    //Initializes planets in solarsystem
    const Planet Planet::SUN = Planet ("Sun", 40, "gold", 0, 0, 0,0,0, "/Users/venyajoshi/Downloads/Cinder/my-projects/final-project-venyaj2/assets/sun");

    const Planet Planet::MERCURY = Planet("Mercury", 4, "gray", 55, 45,55, 3, 0, "/Users/venyajoshi/Downloads/Cinder/my-projects/final-project-venyaj2/assets/mercury");

    const Planet Planet::VENUS = Planet("Venus", 6, "brown", 75, 84, 65, 2, 0, "/Users/venyajoshi/Downloads/Cinder/my-projects/final-project-venyaj2/assets/venus");

    const Planet Planet::EARTH = Planet("Earth", 10, "green", 100, 98, 100, 1.3, 1, "/Users/venyajoshi/Downloads/Cinder/my-projects/final-project-venyaj2/assets/earth");

    const Planet Planet::MARS = Planet("Mars", 8, "red", 127, 160, 150, 1, 1, "/Users/venyajoshi/Downloads/Cinder/my-projects/final-project-venyaj2/assets/mars");

    const Planet Planet::JUPITER = Planet("Jupiter", 17, "orange", 200, 240, 278, .8, 11, "/Users/venyajoshi/Downloads/Cinder/my-projects/final-project-venyaj2/assets/jupiter");

    const Planet Planet::SATURN = Planet("Saturn", 14, "yellow", 193, 340, 310, .7, 5, "/Users/venyajoshi/Downloads/Cinder/my-projects/final-project-venyaj2/assets/saturn");

    const Planet Planet::URANUS = Planet("Uranus", 11, "teal", 280, 390, 340, .3, 2, "/Users/venyajoshi/Downloads/Cinder/my-projects/final-project-venyaj2/assets/uranus");

    const Planet Planet::NEPTUNE = Planet("Neptune", 10, "blue", 300, 430, 400, .2, 3, "/Users/venyajoshi/Downloads/Cinder/my-projects/final-project-venyaj2/assets/neptune");
} //namespace solarsystem