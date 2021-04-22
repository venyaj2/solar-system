//
// Created by Venya Joshi on 4/21/21.
//

#include "solarsystem_simulation.h"
#include "cinder/gl/gl.h"

namespace solarsystem {

    SolarSystemApp::SolarSystemApp() {
        ci::app::setWindowSize(800, 800);
    }

    void IdealGasApp::draw() {
        ci::Color background_color("black");
        ci::gl::clear(background_color);

        //container_.Display();
    }

    /*void IdealGasApp::update() {
        container_.AdvanceOneFrame();
    }*/

}  // namespace solarsystem