//
// Created by Venya Joshi on 4/21/21.
//

#ifndef SOLAR_SYSTEM_SOLARSYSTEM_SIMULATION_H
#define SOLAR_SYSTEM_SOLARSYSTEM_SIMULATION_H

#endif //SOLAR_SYSTEM_SOLARSYSTEM_SIMULATION_H

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include <solarsystem.h>


namespace solarsystem {

/**
 * An app for visualizing the behavior of an ideal gas.
 */
    class SolarSystemApp : public ci::app::App {
    public:
        SolarSystemApp();

        void draw() override;

        void update() override;

    private:
        solarsystem::SolarSystem solarsystem = SolarSystem(700, 700);

    };
}// namespace solarsystem
