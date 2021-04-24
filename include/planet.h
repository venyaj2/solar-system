//
// Created by Venya Joshi on 4/20/21.
//
#pragma once
#ifndef SOLAR_SYSTEM_PLANET_H
#define SOLAR_SYSTEM_PLANET_H
#include <string>
#endif //SOLAR_SYSTEM_PLANET_H

namespace solarsystem {
    
    class Planet {
    public:
        
        /**
             * Creates a new planet instance
             * @param mass of planet
             * @param radius of planet
             * @param color of planet
             */
        Planet(const std::string name, float radius, const std::string color, float degree_from_center, float distance_from_center, std::string description,
               float velocity);

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
        
        std::string GetName() const {
            return name_;
        }
        
        void SetDegree(float degree) {
            degree_from_center_ = degree;
        }
        
        std::string GetDescription() const {
            return description_;
        }
        
        float GetVelocity() {
            return velocity_;
        }
        
        /**
         * Enum for Sun
         */
        static const Planet SUN;

        /**
         * Enum for Mercury
         */
        static const Planet MERCURY;

        /**
         * Enum for Venus
         */
        static const Planet VENUS;

        /**
         * Enum for Earth
         */
        static const Planet EARTH;

        /**
         * Enum for Mars
         */
        static const Planet MARS;

        /**
         * Enum for Jupiter
         */
        static const Planet JUPITER;

        /**
         * Enum for Saturn 
         */
        static const Planet SATURN;

        /**
         * Enum for Uranus
         */
        static const Planet URANUS;

        /**
         * Enum for Neptune
         */
        static const Planet NEPTUNE;
        

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
         std::string description_;
         
         /**
          * The velocity of the planet 
          */
          float velocity_;
          
    };
}