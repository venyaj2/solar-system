//
// Created by Venya Joshi on 4/21/21.
//


#include <planet-texture.h>
namespace solarsystem {
    using glm::vec2;

    PlanetTexture::PlanetTexture() {

    }

    PlanetTexture::PlanetTexture(cinder::gl::Texture2dRef texture) {
        texture_ = texture;
    }
}

