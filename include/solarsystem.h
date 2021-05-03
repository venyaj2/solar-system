#pragma once

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "planet.h"
#include <vector>


namespace solarsystem {

/**
 * An app for visualizing the behavior of an ideal gas.
 */
    class SolarSystem {
    public:
        SolarSystem(float dimension_x, float dimension_y);
        /**
        * Displays the planets and their positions
        */
        void Display();

        /**
         * Updates the positions of all planets
         */
        void AdvanceOneFrame();

        /**
         * Calculates circular position of planet based on degree from center
         * @param planet 
         * @return vector containing x and y position of planet
         */
        glm::vec2 CalculatePositionPlanet(Planet planet) const;

        glm::vec2 CalculatePositionMoons(Moon moon);

        std::vector<Planet> GetPlanets() const {
            return planets_;
        }

        float GetXDimension() {
            return center.x * 2;
        }

        float GetYDimension() {
            return center.y * 2;
        }

        void DisplayStars();

        ci::gl::Texture2dRef SetUp(Planet planet);
        
        void DisplayDescription();
        
        bool GetDisplayDescription() {
            return display_description_;
        }
        
        void setDisplayDescription(bool description) {
            display_description_ = description;
        }
        
    private:
        
        /**
         * Whether or not to display description
         */
        bool display_description_;
        
        /**
         * Dimension for center of screen
         */
        glm::vec2 center;
        
        /**
         * Vector containing planets belonging to solar system
         */
        std::vector<Planet> planets_;
        
        /**
         * Holds texture for each planet
         */
        ci::gl::Texture2dRef texture;
    };

} //namespace solarsystem