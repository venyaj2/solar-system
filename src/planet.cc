//
// Created by Venya Joshi on 4/20/21.
//

#include "cinder/gl/gl.h"
#include <planet.h>
#include <vector>
#include <moon.h>

namespace solarsystem {

    using glm::vec2;

    Planet::Planet() {}
    
    Planet::Planet(const std::string name, float radius, const std::string color, float degree_from_center,
                   float distance_from_center_x, float distance_from_center_y, std::string description, float velocity,
                   size_t number_of_moons, const std::string file) {
        glEnable (GL_TEXTURE_2D);
        
        if (radius < 0 || name == "" || color == "" || distance_from_center_x < 0 || distance_from_center_y < 0 || description == "") {
            throw std::invalid_argument("Invalid Planet parameter passed");
        }
        
        name_ = name;
        radius_ = radius;
        color_ = new char[color.size() + 1];
        std::strcpy(color_, color.c_str());
        degree_from_center_ = degree_from_center;
        distance_from_center_y_ = distance_from_center_y;
        distance_from_center_x_ = distance_from_center_x;
        description_ = description;
        velocity_ = velocity;
        file_ = file;
        visible_description_ = false;
        
        //Adds moons to planet
        for (size_t i = 0; i < number_of_moons; i++) {
            Moon moon(360.0 * i / number_of_moons, radius_ * 2.5, velocity_ * 2, .25 * radius_);
            moons.push_back(moon);
        }
    }
    

    //Initializes planets in solarsystem
    const Planet Planet::SUN = Planet ("Sun", 40, "gold", 0, 0, 0,"Moons: None \nDistance from Sun: 35.98 million mi\nRadius: 1,516 mi\nDiameter: 4,879 km\nOrbital period: 88 days \nMass: 3.285 × 10^23 kg\nSurface Temperature: -173 to 427°C", 0,0, "http://assets.stickpng.com/thumbs/580b585b2edbce24c47b270f.png");

    const Planet Planet::MERCURY = Planet("Mercury", 4, "gray", 55, 45,55, "Radius: 432,690 mi\nDiameter: 1.3927 million km\nMass: 31.989 × 10^30 kg\nSurface Temperature: 5,505°C\nNumber of Moons: None\nFirst Record: 14th century BCE by Assyrian astronomers", 3, 0, "https://lh3.googleusercontent.com/proxy/njZJHNM-J168hhnrC4cx8EoCHYgr5CRHj2MjQL4pzK3WCUwy48PBKKD20SPtd3LT5SStCze2xk6ggngO-9oKQR4exQMuVkrNEfPP6us-v9aMh7EBGw");
    
    const Planet Planet::VENUS = Planet("Venus", 6, "brown", 75, 84, 65, "Venus", 2, 0, "http://assets.stickpng.com/images/580b585b2edbce24c47b2712.png");

    const Planet Planet::EARTH = Planet("Earth", 10, "green", 100, 98, 100, "Earth", 1.3, 1, "https://lh3.googleusercontent.com/proxy/YiKbqyrr3kfN3a1mJEJwWKs7wMB_jqEPeLtsVcEE79Xnk8tKFZoJFTA2EBBX5ePwlbF4hCYwh8-gx8YE9TXs58mplcN7hiJrNREg7qNB-Hmm8Swnj5xHTNfr5pvd3ixw22uUgA");

    const Planet Planet::MARS = Planet("Mars", 8, "red", 127, 160, 150, "Mars", 1, 1, "https://www.freepnglogos.com/uploads/mars-png/mars-transparent-png-stickpng-0.png");

    const Planet Planet::JUPITER = Planet("Jupiter", 17, "orange", 200, 240, 278, "Jupiter", .8, 11, "https://upload.wikimedia.org/wikipedia/commons/e/e1/Jupiter_%28transparent%29.png");

    const Planet Planet::SATURN = Planet("Saturn", 14, "yellow", 193, 340, 310, "Saturn", .7, 5, "https://i2.wp.com/freepngimages.com/wp-content/uploads/2016/04/saturn-transparent-background-planet-1.png?fit=797%2C620");

    const Planet Planet::URANUS = Planet("Uranus", 11, "teal", 280, 390, 340, "Uranus", .3, 2, "https://www.freeiconspng.com/uploads/planet-uranus-icon-png-8.png");

    const Planet Planet::NEPTUNE = Planet("Neptune", 10, "blue", 300, 430, 400, "Neptune", .2, 3, "https://www.seekpng.com/png/full/2-26520_neptune-neptune-transparent-background.png");
    

} //namespace solarsystem