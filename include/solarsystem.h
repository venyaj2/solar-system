#pragma once

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include <planet.h>
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

    private:
        glm::vec2 center;
        
        glm::vec2 CalculatePosition(Planet planet) const;
        
        std::vector<Planet> planets_;
    };

} 