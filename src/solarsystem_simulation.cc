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

    void SolarSystemApp::mouseDown(ci::app::MouseEvent event) {
       solarsystem.CheckPosition( event.getPos());
    }

    void SolarSystemApp::keyDown(ci::app::KeyEvent event) {
        switch (event.getCode()) {
            case ci::app::KeyEvent::KEY_DELETE:
                solarsystem.ClearDescriptions();
                break;

            case ci::app::KeyEvent::KEY_SPACE:
                solarsystem.Pause();
                break;
        }
    }

}  // namespace solarsystem