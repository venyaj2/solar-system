
#include "cinder/gl/gl.h"
#include "../include/solarsystem.h"

#include <fstream>
namespace solarsystem {

    using glm::vec2;
    
    solarsystem::SolarSystem::SolarSystem(float dimension_x, float dimension_y) {
        if (dimension_x <= 0 || dimension_y <= 0) {
            throw std::invalid_argument("Entered invalid dimension");
        }
        
        center = glm::vec2(dimension_x/2, dimension_y/2);
        
        planets_.push_back(Planet::SUN);
        planets_.push_back(Planet::MERCURY);
        planets_.push_back(Planet::VENUS);
        planets_.push_back(Planet::EARTH);
        planets_.push_back(Planet::MARS);
        planets_.push_back(Planet::JUPITER);
        planets_.push_back(Planet::SATURN);
        planets_.push_back(Planet::URANUS);
        planets_.push_back(Planet::NEPTUNE);
        
    }

    void SolarSystem::Display() {
        for (size_t i = 0; i < planets_.size(); i++) {
            ci::gl::color(ci::Color(planets_[i].GetColor()));
            /*ci::gl::drawSolidCircle(CalculatePosition(planets_[i]),
                                    planets_[i].GetRadius(), 40);*/
            
            
            glm::vec3 vector(CalculatePosition (planets_[i]).x, CalculatePosition(planets_[i]).y, planets_[i].GetRadius() / 2.0);
            ci::gl::drawSphere(vector, planets_[i].GetRadius());
             
            //https://libcinder.org/docs/guides/opengl/part2.html
            /*ci::gl::enableDepthRead();
            ci::gl::enableDepthWrite();

            cinder::CameraPersp cam;
            cam.lookAt(glm::vec3(planets_[i].GetRadius(), planets_[i].GetRadius(), planets_[i].GetRadius()), glm::vec3(CalculatePosition (planets_[i]).x, CalculatePosition(planets_[i]).y, 0) );
            ci::gl::setMatrices( cam );
            
            auto lambert = ci::gl::ShaderDef().lambert();
            auto shader = ci::gl::getStockShader( lambert );
            shader->bind();
            
            ci::gl::drawSphere(glm::vec3(), planets_[i].GetRadius()/100.0, 40);*/
            
    }
        //Change from circles to spheres
    }

    void SolarSystem::AdvanceOneFrame() {
        for (size_t i = 0; i < planets_.size(); i++) {
            planets_[i].SetDegree(planets_[i].GetAngle() + planets_[i].GetVelocity());
        }
        
        //To Do: Change distance based on ellipse
    }

    glm::vec2 SolarSystem::CalculatePosition(Planet planet) const {
        float x_pos_ = center.x + planet.GetDistance() * cos(planet.GetAngle() * M_PI / 180);
        float y_pos_ = center.y + planet.GetDistance() * sin(planet.GetAngle() * M_PI / 180);
        glm::vec2 position(x_pos_, y_pos_);
        return position;
    }

    void SolarSystem::ParseData(std::string file_) {
        std::ifstream input_file(file_, std::ifstream::binary);
        //input_file >> planets_;
    }
} //namespace solarsystem