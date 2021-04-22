
#include "cinder/gl/gl.h"
#include "../include/solarsystem.h"

#include <json/value.h>
#include <fstream>
namespace solarsystem {
    using json = nlohmann::json;


    solarsystem::SolarSystem::SolarSystem(std::string input_JSON) {
        for (size_t i = 0; i < )
    }

    void SolarSystem::Display() {
        for (size_t i = 0; i < planets_.size(); i++) {
            ci::gl::color(ci::Color(planets_[i].GetColor());
            ci::gl::drawSolidCircle(CalculatePosition(planets_[i]),
                                    particles[i].GetRadius(), 40);
            /*ci::gl::color(ci::Color("white"));
            ci::gl::drawStrokedRect(
                    ci::Rectf(vec2(x_boundary_begins_, y_boundary_begins_),
                              vec2(x_boundary_ends_, y_boundary_ends_)));
        }*/
    }
    }

    void SolarSystem::AdvanceOneFrame() {

    }

    std::vector<float> SolarSystem::CalculatePosition(Planet planet) const {
        std::vector<float> position;
        position.resize(2);
        position.at(0) = planet.GetDistance() * cos(planet.GetAngle() * PI / 180);
        position.at(1) = planet.GetDistance() * sin(planet.GetAngle() * PI / 180); 
    }

    void SolarSystem::ParseData(std::string file_) {
        std::ifstream input_file(file_, std::ifstream::binary);
        input_file >> planets_;
    }


}


