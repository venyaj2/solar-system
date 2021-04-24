//
// Created by Venya Joshi on 4/21/21.
//

#include "solarsystem_simulation.h"
#include "cinder/gl/gl.h"

namespace solarsystem {

    SolarSystemApp::SolarSystemApp() {
        ci::app::setWindowSize(solarsystem.GetXDimension(), solarsystem.GetYDimension());
    }

    void SolarSystemApp::draw() {
        ci::Color background_color("black");
        ci::gl::clear(background_color);
        

        solarsystem.Display();
    }

    void SolarSystemApp::update() {
        solarsystem.AdvanceOneFrame();
    }

}  // namespace solarsystem