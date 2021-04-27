//
// Created by Venya Joshi on 4/20/21.
//

#include "cinder/gl/gl.h"
#include <iostream>
#include <planet.h>
#include <vector>
#include <moon.h>

namespace solarsystem {

    using glm::vec2;

    Planet::Planet() {}
    
    Planet::Planet(const std::string name, float radius, const std::string color, float degree_from_center,
                   float distance_from_center_x, float distance_from_center_y, std::string description, float velocity,
                   size_t number_of_moons) {
        if (radius < 0 || name == "" || color == "" || distance_from_center_x < 0 || distance_from_center_y < 0 || description == "") {
            throw std::invalid_argument("Invalid Planet parameter passed");
        }
        
        name_ = name;
        radius_ = radius;
        color_ = new char[color.size() + 1];
        std::strcpy(color_, color.c_str());
        degree_from_center_ = degree_from_center;
        distance_from_center_y_ = distance_from_center_y;
        distance_from_center_x_ = distance_from_center_x;
        description_ = description;
        velocity_ = velocity;
        for (size_t i = 0; i < number_of_moons; i++) {
            Moon moon((rand() % 360), radius_ * 2, 2, radius_ / 2);
            moons.push_back(moon);
        }
    }
    

    const Planet Planet::SUN = Planet ("Sun", 40, "yellow", 0, 0, 0,
                  "Moons: None \nDistance from Sun: 35.98 million mi\nRadius: 1,516 mi\nDiameter:"
                                  " 4,879 km\nOrbital period: 88 days"
                                  "\nMass: 3.285 × 10^23 kg\nSurface Temperature: -173 to 427°C", 0, 0);

    const Planet Planet::MERCURY = Planet("Mercury", 4, "gray", 57, 48, 55, "Radius: 432,690 mi\nDiameter: 1.3927 million km\nMass: 31.989 × 10^30 kg\nSurface Temperature: 5,505°C\nNumber of Moons: None\nFirst Record: 14th century BCE by Assyrian astronomers", 3, 0);
    
    const Planet Planet::VENUS = Planet("Venus", 6, "brown", 87, 65, 70, "Venus", 2, 0);

    const Planet Planet::EARTH = Planet("Earth", 10, "green", 97, 90, 95, "Earth", 1.3, 1);

    const Planet Planet::MARS = Planet("Mars", 8, "red", 137, 200, 130, "Mars", 1, 1);

    const Planet Planet::JUPITER = Planet("Jupiter", 17, "orange", 200, 260, 278, "Jupiter", .8, 4);

    const Planet Planet::SATURN = Planet("Saturn", 14, "yellow", 193, 300, 320, "Saturn", .7, 3);

    const Planet Planet::URANUS = Planet("Uranus", 11, "teal", 280, 360, 340, "Uranus", .3, 2);

    const Planet Planet::NEPTUNE = Planet("Neptune", 10, "blue", 300, 400, 400, "Neptune", .2, 2);
    

} //namespace solarsystem