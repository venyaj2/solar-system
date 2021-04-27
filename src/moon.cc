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

    float Moon::UpdateDegree() {
        std::cout<< "IN METHOD: " << degree_from_center_<<std::endl;
        degree_from_center_ += velocity_;
        std::cout<< "IN METHOD: " << degree_from_center_<<std::endl;
        std::cout<< "IN METHOD: " << GetAngle() <<std::endl;
        return GetAngle();
    };
}
