
#include "cinder/gl/gl.h"
#include <nlohmann/json.hpp>
namespace solarsystem {
    using json = nlohmann::json;

    IdealGasApp::IdealGasApp() {
        ci::app::setWindowSize(800, 800);
    }

    void IdealGasApp::draw() {
        ci::Color background_color("black");
        ci::gl::clear(background_color);

        container_.Display();
    }

    void IdealGasApp::update() {
        container_.AdvanceOneFrame();
    }

}