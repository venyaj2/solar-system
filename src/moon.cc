//
// Created by Venya Joshi on 4/24/21.
//
#include <iostream>
#include <moon.h>
#include <glm/vec2.hpp>

namespace solarsystem {
    using glm::vec2;
    
    Moon::Moon(float degree_from_center, float distance_from_center, float velocity, float radius) {
        radius_ = radius;
        degree_from_center_ = degree_from_center;
        distance_from_center_ = distance_from_center;
        velocity_ = velocity;
        radius_ = radius;
    }
    
    Moon::Moon() {}
}
