//
// Created by Venya Joshi on 4/20/21.
//

#include "cinder/gl/gl.h"
#include "../include/planet.h"

#include <planer.h>
#include <vector>

namespace solarsystem {

    using glm::vec2;
    
    Planet::Planet(const std::string &name, float radius, const std::string &color, float degree_from_center,
                   float distance_from_center, std::string description) {
        name_ = name;
        radius_ = radius;
        color_ = color;
        degree_from_center_ = degree_from_center;
        distance_from_center_ = distance_from_center;
        description_ = description;
    }

    Planet::Planet() {}
    
    
} //namespace solarsystem