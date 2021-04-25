
#include "cinder/gl/gl.h"
#include "../include/solarsystem.h"

#include <fstream>
#include "planet.h"



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
        DisplayStars();
        
        for (size_t i = 0; i < planets_.size(); i++) {
            ci::gl::color(ci::Color(planets_[i].GetColor()));
            
            
            ci::gl::drawSolidCircle(CalculatePositionPlanet(planets_[i]),
                                    planets_[i].GetRadius(), 40);
            
            /*for (size_t j = 0; j < planets_[i].GetMoons().size(); i++) {
                ci::gl::color(ci::Color("gray"));
                ci::gl::drawSolidCircle(CalculatePositionMoons(planets_[i].GetMoons()[j], CalculatePositionPlanet(planets_[i])),
                                        planets_[i].GetMoons()[j].GetRadius(), 40);
            }*/
            
            /*glm::vec3 vector(CalculatePosition (planets_[i]).x, CalculatePosition(planets_[i]).y, planets_[i].GetRadius() / 2.0);
            ci::gl::drawSphere(vector, planets_[i].GetRadius());*/
            
    }
        //Change from circles to spheres
    }

    void SolarSystem::AdvanceOneFrame() {
        for (size_t i = 0; i < planets_.size(); i++) {
            planets_[i].SetDegree(planets_[i].GetAngle() + planets_[i].GetVelocity());
            /*for (size_t j = 0; j < planets_[i].GetMoons().size(); i++ ) {
                planets_[i].GetMoons()[j].SetDegree(planets_[i].GetMoons()[j].GetAngle() + planets_[i].GetMoons()[j].GetVelocity());
            }*/
        }
        
        //To Do: Change distance based on ellipse
    }

    //Make sure angle matches velocity (90 degrees divided by distance when it's halfway through)
    glm::vec2 SolarSystem::CalculatePositionPlanet(Planet planet) const {
        float x_pos_ = center.x + planet.GetDistanceX() * cos(planet.GetAngle() * M_PI / 180);
        float y_pos_ = center.y + planet.GetDistanceX() * sin(planet.GetAngle() * M_PI / 180);
        glm::vec2 position(x_pos_, y_pos_);
        return position;
        
        //Planning ellipse:
        //Whenever 0 degrees or 180 degrees, must be x distance
        //Whenever 90 degrees or 270 degrees, must be y distance
        //In between, must be leading up to other distance
    }

    void SolarSystem::ParseData(std::string file_) {
        std::ifstream input_file(file_, std::ifstream::binary);
        //input_file >> planets_;
    }

    void SolarSystem::DisplayStars() {
        ci::gl::color(ci::Color("white"));
        for (size_t j = 0; j < GetXDimension() * GetYDimension() / (GetXDimension() + GetYDimension() * 6); j++) {
            glm::vec2 position_(rand() % (int)GetXDimension(), rand() % (int)GetYDimension());
            ci::gl::drawSolidCircle(position_, (rand() % 100) /100.0, 40);
        }
    }

    glm::vec2 SolarSystem::CalculatePositionMoons(Moon moon, glm::vec2 planet_position) const {
        float x_pos_ = planet_position.x + moon.GetDistance() * cos(moon.GetAngle() * M_PI / 180);
        float y_pos_ = planet_position.y + moon.GetDistance() * sin(moon.GetAngle() * M_PI / 180);
        glm::vec2 position(x_pos_, y_pos_);
        return position;
    }

} //namespace solarsystem