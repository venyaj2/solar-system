//
// Created by Venya Joshi on 4/20/21.
//

#ifndef SOLAR_SYSTEM_PLANET_H
#define SOLAR_SYSTEM_PLANET_H
#include <string>
#endif //SOLAR_SYSTEM_PLANET_H

namespace solarsystem {
    class Planet {
    public:

        Planet();

        float GetRadius() const{
            return radius_;
        }
        

        char* GetColor() const{
            return color_;
        }
        
        float GetAngle() const{
            return degree_from_center_;
        }
        
        float GetDistance() const {
            return distance_from_center_;
        }
        
        
    private:
        /**
         * Name of planet
         */
        std::string name_; 
        
        /**
         * The distance of planet from center
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
         * The color of the planet
         */
        char* color_;
        
        /**
         * The description of the planet
         */
         float description_;

        /**
         * Creates a new planet instance
         * @param mass of planet
         * @param radius of planet
         * @param color of planet
         */
        Planet(const std::string& name, float radius, const std::string& color, float degree_from_center, float distance_from_center, std::string description);
    };
}