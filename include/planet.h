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

        /*
         * Enum for Mercury
         */
        static const Planet MERCURY;

        /*
         * Enum for Venus
         */
        static const Planet VENUS;

        /*
         * Enum for Earth
         */
        static const Planet EARTH;

        /*
        * Enum for Mars
        */
        static const Planet MARS;

        /*
        * Enum for Jupiter
        */
        static const Planet JUPITER;

        /*
        * Enum for Saturn
        */
        static const Planet SATURN;

        /*
        * Enum for Uranus
        */
        static const Planet URANUS;

        /*
        * Enum for Neptune
        */
        static const Planet NEPTUNE;
        
        glm::vec2 GetPosition() const{
            return position;
        }

        glm::vec2 GetVelocity() const{
            return velocity;
        }

        void SetPosition(const glm::vec2 set_position){
            position = set_position;
        }

        void SetVelocity(float x_velocity, float y_velocity) {
            glm::vec2 temp_velocity(x_velocity, y_velocity);
            velocity = temp_velocity;
        }

        float GetRadius() const{
            return radius_;
        }

        float GetMass() const{
            return mass_;
        }

        char* GetColor() const{
            return color_;
        }

    private:
        /**
         * Name of planet
         */
        std::string name_; 
        
        /**
         * The rotation of the planet
         */
         float rotation
         
         /**
          * The axis tilt of planet
          */
        float tilt_;
         
        /**
         * The position of the planet
         */
        glm::vec2 position_;

        /**
         * The velocity of the planet
         */
        glm::vec2 velocity_;

        /**
         * The radius of the planet
         */
        float radius_;
        

        /**
         * The color of the planet
         */
        char* color_;

        /**
         * Creates a new planet instance
         * @param mass of planet
         * @param radius of planet
         * @param color of planet
         */
        Planet(const std::string& name, float radius, const std::string& color, float position_x, float position_y, float velocity_x, float velocity_y, float tilt, float axis, std::string description);
    };
}