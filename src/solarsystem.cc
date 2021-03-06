
#include "cinder/gl/gl.h"
#include "../include/solarsystem.h"

#include <iostream>
#include "planet.h"



namespace solarsystem {
    using glm::vec2;
    using glm::vec3;

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
        play = true;
    }

    void SolarSystem::Display() {
        DisplayStars();

        for (size_t i = 0; i < planets_.size(); i++) {
            ci::gl::color(ci::Color(planets_[i].GetColor()));
            glm::vec2 position (CalculatePositionPlanet(planets_[i]));
            ci::gl::drawSolidCircle(position,
                                    planets_[i].GetRadius(), 40);

            //Draws moons
            for (size_t j = 0; j < planets_[i].GetMoons().size(); j++) {
                ci::gl::color(ci::Color("gray"));
                ci::gl::drawSolidCircle(position + CalculatePositionMoons(planets_[i].GetMoons()[j]),
                                        planets_[i].GetMoons()[j].GetRadius(), 40);
            }

            //Draws rings
            if (planets_[i].GetName() == "Saturn") {
                ci::gl::color(ci::Color("gray"));
                ci::gl::drawSolidRect(
                        ci::Rectf(vec2(CalculatePositionPlanet(planets_[i]).x - (planets_[i].GetRadius() * 2), CalculatePositionPlanet(planets_[i]).y - 1),
                                  vec2(CalculatePositionPlanet(planets_[i]).x + (planets_[i].GetRadius() * 2), CalculatePositionPlanet(planets_[i]).y + 1)));
            }
            if (planets_[i].GetName() == "Uranus") {
                ci::gl::color(ci::Color("gray"));
                ci::gl::drawSolidRect(
                        ci::Rectf(vec2(CalculatePositionPlanet(planets_[i]).x - 1, CalculatePositionPlanet(planets_[i]).y - (planets_[i].GetRadius() * 2)),
                                  vec2(CalculatePositionPlanet(planets_[i]).x + 1, CalculatePositionPlanet(planets_[i]).y + (planets_[i].GetRadius() * 2))));
            }
            if (planets_[i].GetName() == "Jupiter") {
                ci::gl::color(ci::Color(rand() % 7, rand() % 7, rand() % 7));
                ci::gl::drawSolidRoundedRect(
                        ci::Rectf(vec2(CalculatePositionPlanet(planets_[i]).x - (planets_[i].GetRadius() * 2), CalculatePositionPlanet(planets_[i]).y - (planets_[i].GetRadius() / 7.0)),
                                  vec2(CalculatePositionPlanet(planets_[i]).x + (planets_[i].GetRadius() * 2), CalculatePositionPlanet(planets_[i]).y + (planets_[i].GetRadius() / 7.0))), planets_[i].GetRadius() / 2.0, 40);
            }
            if (planets_[i].GetName() == "Neptune") {
                ci::gl::color(ci::Color("gray"));
                ci::gl::drawSolidRect(
                        ci::Rectf(vec2(CalculatePositionPlanet(planets_[i]).x - (planets_[i].GetRadius() * 2), CalculatePositionPlanet(planets_[i]).y - 1),
                                  vec2(CalculatePositionPlanet(planets_[i]).x + (planets_[i].GetRadius() * 2), CalculatePositionPlanet(planets_[i]).y + 1)));
            }

            //Displays description if planet's boolean is true
            if (planets_[i].GetVisibleDescription()) {
                DrawDescription(planets_[i]);
            }
        }
    }

    void SolarSystem::AdvanceOneFrame() {
        if (play){
            for (size_t i = 0; i < planets_.size(); i++) {
                planets_[i].SetDegree(planets_[i].GetAngle() + planets_[i].GetVelocity());
                for (size_t j = 0; j < planets_[i].GetMoons().size(); j++) {
                    planets_[i].GetMoons()[j].SetAngle(planets_[i].GetMoons()[j].GetAngle() + planets_[i].GetMoons()[j].GetVelocity());
                }
            }
        }
    }

    glm::vec2 SolarSystem::CalculatePositionPlanet(Planet planet) const {
        float x_pos_ = center.x + planet.GetDistanceX() * cos(planet.GetAngle() * M_PI / 180);
        float y_pos_ = center.y + planet.GetDistanceY() * sin(planet.GetAngle() * M_PI / 180);
        glm::vec2 position(x_pos_, y_pos_);
        return position;
    }

    void SolarSystem::DisplayStars() {
        ci::gl::color(ci::Color("white"));
        for (size_t j = 0; j < GetXDimension() * GetYDimension() / (GetXDimension() + GetYDimension() * 6); j++) {
            glm::vec2 position_(rand() % (int)GetXDimension(), rand() % (int)GetYDimension());
            ci::gl::drawSolidCircle(position_, (rand() % 100) /100.0, 40);
        }
    }

    glm::vec2 SolarSystem::CalculatePositionMoons(Moon moon) {
        float x_pos_ = moon.GetDistance() * cos(180 - moon.GetAngle() * M_PI / 180);
        float y_pos_ = moon.GetDistance() * sin(180 - moon.GetAngle() * M_PI / 180);
        glm::vec2 position(x_pos_, y_pos_);
        return position;
    }

    void SolarSystem::CheckPosition(glm::vec2 pos) {
        float index_of_minimum_distance = 0;
        for (size_t i = 1; i < planets_.size(); i++) {
            //Finds planet closest to pos
            if (glm::distance(CalculatePositionPlanet(planets_[i]), pos) < glm::distance(CalculatePositionPlanet(planets_[index_of_minimum_distance]), pos)) {
                index_of_minimum_distance = i;
            }
        }
        planets_[index_of_minimum_distance].SetVisibleDescription(!planets_[index_of_minimum_distance].GetVisibleDescription());
    }

    void SolarSystem::ClearDescriptions() {
        for (size_t i = 0; i < planets_.size(); i++) {
            planets_[i].SetVisibleDescription(false);
        }
    }

    void SolarSystem::Pause() {
        play = !play;
    }

    void SolarSystem::DrawDescription(Planet planet) {
        std::ifstream input_file_ (planet.GetFile());
        size_t counter = 0;
        ci::Font kLabelFont;
        while (!input_file_.eof()) {
            if (counter == 0) {
                kLabelFont = ci::Font("Times New Roman", 16);
            } else {
                kLabelFont = ci::Font("Times New Roman", 14);
            }
            std::string line_;
            std::string fulltext_;
            std::getline(input_file_, line_);
            ci::gl::drawString(line_,
                               vec2(CalculatePositionPlanet(planet).x - planet.GetRadius(), CalculatePositionPlanet(planet).y - (100 - (15 * counter) + planet.GetRadius())), ci::Color("white"), kLabelFont);
            counter++;
        }
    }
} //namespace solarsystem