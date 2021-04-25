//
// Created by Venya Joshi on 4/24/21.
//

#include <moon.h>

namespace solarsystem {

    using glm::vec2;

    solarsystem::Moon::Moon(float degree_from_center, float distance_from_center, float velocity) {
        radius_ = 1;
        degree_from_center_ = degree_from_center;
        distance_from_center_ = distance_from_center;
        velocity_ = velocity;
    }

    Moon::Moon() {};
}
