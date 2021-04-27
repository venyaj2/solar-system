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
        
        /**
         * Parses data from JSON
         * @param file_ JSON
         */
        void ParseData(std::string file_);

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
    private:
        
        /**
         * Holding
         */
        float holding_;
        
        /**
         * Dimension for center of screen
         */
        glm::vec2 center;
        
        /**
         * Vector containing planets belonging to solar system
         */
        std::vector<Planet> planets_;
    };

} //namespace solarsystem