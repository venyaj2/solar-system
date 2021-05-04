#pragma once

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "planet.h"
#include <vector>
#include "planet-texture.h"

namespace solarsystem {

/**
 * An app for visualizing the behavior of an ideal gas.
 */
    class SolarSystem {
    public:
        SolarSystem(float dimension_x, float dimension_y);
        /**
        * Displays the sun and their positions
        */
        void Display();

        /**
         * Updates the positions of all sun
         */
        void AdvanceOneFrame();

        /**
         * Calculates elliptical position of planet based on degree from center
         * @param planet 
         * @return vector containing x and y position of planet
         */
        glm::vec2 CalculatePositionPlanet(Planet planet) const;

        /**
         * Calculates circular position of moon based on degree from center
         * @param planet 
         * @return vector containing x and y position of moon
         */
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

        /**
         * Displays a series of randomized stars
         */
        void DisplayStars();
        
        /**
         * Check position click
         */
        void CheckPosition(glm::vec2 pos);

        /**
         * Clears descriptions
         */
        void ClearDescriptions();
        
        /**
         * Pauses motion
         */
        void Pause();
        
        /**
         * Parses and draws from descripiton file of planet
         * @param planet 
         */
        void DrawDescription(Planet planet);
        
    private:
        /**
         * Playing boolean
         */
        bool play;
        
        /**
         * Image
         */
        PlanetTexture planetTexture;
        /**
         * Dimension for center of screen
         */
        glm::vec2 center;
        
        /**
         * Vector containing sun belonging to solar system
         */
        std::vector<Planet> planets_;
    };

} //namespace solarsystem