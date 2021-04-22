//
// Created by Venya Joshi on 4/21/21.
//

#ifndef SOLAR_SYSTEM_PLANETTEXTURE_H
#define SOLAR_SYSTEM_PLANETTEXTURE_H

#endif //SOLAR_SYSTEM_PLANETTEXTURE_H

#include <string>
#include <vector>

namespace solarsystem {
    class PlanetTexture {
    public:
        PlanetTexture();
        PlanetTexture(vector<*char> image_layout, size_t dimension_);
            

    private:
        vector<char> image_layout_;
        
        size_t dimension;
    };
}