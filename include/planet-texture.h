//
// Created by Venya Joshi on 4/21/21.
//

#ifndef SOLAR_SYSTEM_PLANETTEXTURE_H
#define SOLAR_SYSTEM_PLANETTEXTURE_H
#pragma once

#endif //SOLAR_SYSTEM_PLANETTEXTURE_H

#include <string>
#include <vector>
#include "cinder/gl/gl.h"

namespace solarsystem {
    class PlanetTexture {
    public:
        PlanetTexture();

        PlanetTexture(cinder::gl::Texture2dRef texture);


    private:
        cinder::gl::Texture2dRef texture_;

    };
}