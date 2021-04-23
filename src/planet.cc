//
// Created by Venya Joshi on 4/20/21.
//

#include "cinder/gl/gl.h"

#include <planet.h>
#include <vector>

namespace solarsystem {

    using glm::vec2;

    Planet::Planet() {}
    
    Planet::Planet(const std::string name, float radius, const std::string color, float degree_from_center,
                   float distance_from_center, std::string description, float velocity) {
        if (radius < 0 || name == "" || color == "" || distance_from_center < 0 || description == "") {
            throw std::invalid_argument("Invalid Planet parameter passed");
        }
        
        name_ = name;
        radius_ = radius;
        color_ = new char[color.size() + 1];
        std::strcpy(color_, color.c_str());
        degree_from_center_ = degree_from_center;
        distance_from_center_ = distance_from_center;
        description_ = description;
        velocity_ = velocity;
    }
    

    const Planet Planet::SUN = Planet ("Sun", 30, "yellow", 0, 0,
                  "Moons: None \nDistance from Sun: 35.98 million mi\nRadius: 1,516 mi\nDiameter:"
                                  " 4,879 km\nOrbital period: 88 days"
                                  "\nMass: 3.285 × 10^23 kg\nSurface Temperature: -173 to 427°C", 0);

    const Planet Planet::MERCURY = Planet("Mercury", 4, "gray", 57, 50, "Radius: 432,690 mi\nDiameter: 1.3927 million km\nMass: 31.989 × 10^30 kg\nSurface Temperature: 5,505°C\nNumber of Moons: None\nFirst Record: 14th century BCE by Assyrian astronomers", 3);
    
    const Planet Planet::VENUS = Planet("Venus", 6, "brown", 87, 70, "Venus", 2);

    const Planet Planet::EARTH = Planet("Earth", 10, "green", 97, 90, "Earth", 1);

    const Planet Planet::MARS = Planet("Mars", 8, "red", 137, 115, "Mars", 2);

    const Planet Planet::JUPITER = Planet("Venus", 17, "orange", 200, 180, "Jupiter", .5);

    const Planet Planet::SATURN = Planet("Venus", 14, "yellow", 193, 280, "Saturn", .5);

    const Planet Planet::URANUS = Planet("Uranus", 6, "teal", 280, 300, "Uranus", 1);

    const Planet Planet::NEPTUNE = Planet("Neptune", 6, "blue", 300, 320, "Neptune", .6);
    
} //namespace solarsystem