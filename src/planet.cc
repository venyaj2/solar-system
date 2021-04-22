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
                   float distance_from_center, std::string description) {
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
    }
    

    const Planet Planet::SUN = Planet ("Sun", 30, "yellow", 0, 0,
                  "Moons: None \nDistance from Sun: 35.98 million mi\nRadius: 1,516 mi\nDiameter:"
                                  " 4,879 km\nOrbital period: 88 days"
                                  "\nMass: 3.285 × 10^23 kg\nSurface Temperature: -173 to 427°C");

    const Planet Planet::MERCURY = Planet("Mercury", 4, "gray", 57, 50, "Radius: 432,690 mi\nDiameter: 1.3927 million km\nMass: 31.989 × 10^30 kg\nSurface Temperature: 5,505°C\nNumber of Moons: None\nFirst Record: 14th century BCE by Assyrian astronomers");
    
    const Planet Planet::VENUS = Planet("Venus", 6, "brown", 87, 70, "Venus");

    const Planet Planet::EARTH = Planet("Earth", 10, "green", 97, 80, "Earth");

    const Planet Planet::MARS = Planet("Mars", 8, "red", 137, 98, "Mars");

    const Planet Planet::JUPITER = Planet("Venus", 17, "orange", 200, 180, "Jupiter");

    const Planet Planet::SATURN = Planet("Venus", 14, "yellow", 193, 280, "Saturn");

    const Planet Planet::URANUS = Planet("Uranus", 6, "teal", 280, 300, "Uranus");

    const Planet Planet::NEPTUNE = Planet("Neptune", 6, "blue", 300, 320, "Neptune");
    
} //namespace solarsystem