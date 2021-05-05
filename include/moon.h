//
// Created by Venya Joshi on 4/24/21.
//


#ifndef SOLAR_SYSTEM_MOON_H
#define SOLAR_SYSTEM_MOON_H
#pragma once
#endif //SOLAR_SYSTEM_MOON_H

namespace solarsystem {

    class Moon {
    public:
        /**
             * Creates a new planet instance
             * @param mass of planet
             * @param radius of planet
             * @param color of planet
             */
        Moon(float degree_from_center, float distance_from_center,
               float velocity, float radius);

        Moon();

        float GetRadius() const{
            return radius_;
        }

        float GetAngle() const{
            return degree_from_center_;
        }

        float GetDistance() const {
            return distance_from_center_;
        }
        
        void SetAngle(float angle) {
            degree_from_center_ = angle;
        }

        float GetVelocity() {
            return velocity_;
        }
        
    private:
        /**
         * The distance of moon from center
         */
        float distance_from_center_;

        /**
         * The degree from the center of what is being revolved
         */
        float degree_from_center_;

        /**
         * The radius of the planet
         */
        float radius_;

        /**
         * The velocity of the planet 
         */
        float velocity_;
    };
}