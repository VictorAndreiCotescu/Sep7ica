#include "Textura.h"


Textura::Textura(std::string path):id(0),wid(0),hgt(0) {

    id = SOIL_load_OGL_texture(path.c_str(), SOIL_LOAD_AUTO,
                               SOIL_CREATE_NEW_ID,
                               SOIL_FLAG_MULTIPLY_ALPHA | SOIL_FLAG_INVERT_Y);

    if (!getTextureParams()) {
        std::cerr << "Error loading texture: " << path << std::endl;
    }

}

int Textura::getId() {
    return id;
}

int Textura::getWidth() {
    return wid;
}

int Textura::getHeight() {
    return hgt;
}

bool Textura::getTextureParams() {

    if (id > 0) {

        int mipLevel = 0;
        glBindTexture(GL_TEXTURE_2D, id);
        glGetTexLevelParameteriv(GL_TEXTURE_2D, mipLevel, GL_TEXTURE_HEIGHT, &hgt);
        glGetTexLevelParameteriv(GL_TEXTURE_2D, mipLevel, GL_TEXTURE_WIDTH, &wid);

        return true;
    }

    return false;
}

Textura::~Textura() = default;
