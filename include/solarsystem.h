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
        SolarSystem(std::string input_JSON);
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


    private:
        std::vector<float> CalculatePosition(Planet planet) const;
        
        std::vector<Planet> planets_;
    }

} 