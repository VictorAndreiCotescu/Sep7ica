#include "Sprite.h"

#include <utility>

Sprite::Sprite():   textura(Textura()),
                    xPos(0),
                    yPos(0),
                    rot(0),
                    xScale(0),
                    yScale(0){}

Sprite::Sprite(std::string imagePath):  textura(Textura(std::move(imagePath))),
                                        xPos(0),
                                        yPos(0),
                                        rot(0),
                                        xScale(0),
                                        yScale(0) {}

Sprite::Sprite(std::string imagePath, float _xPos, float _yPos):  textura(Textura(std::move(imagePath))),
                                                                  xPos(_xPos),
                                                                  yPos(_yPos),
                                                                  rot(0),
                                                                  xScale(0),
                                                                  yScale(0)  {}

void Sprite::update() {

}

void Sprite::render() {
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textura.getId());
    glLoadIdentity();

    glTranslatef(xPos, yPos, 0);
    glRotatef(rot, 0,0,1);
    glScalef(xScale, yScale, 1);

    glColor4f(1,1,1,1);
    glBegin(GL_QUADS);

    glTexCoord2f(0, 0); glVertex2f(0,0);
    glTexCoord2f(1, 0); glVertex2f(textura.getWidth(),0);
    glTexCoord2f(1, 1); glVertex2f(textura.getWidth(),textura.getHeight());
    glTexCoord2f(0, 1); glVertex2f(0,textura.getHeight());
    glEnd();

    glDisable(GL_TEXTURE_2D);

}

void Sprite::setPos(float _xSprite, float _ySprite) {
    xPos = _xSprite;
    yPos = _ySprite;
}

void Sprite::setRot(float _xRot) {
    rot = _xRot;
}

void Sprite::setScale(float _xyScale) {
    xScale = _xyScale;
    yScale = _xyScale;
}

void Sprite::setScale(float _xScale, float _yScale) {
    xScale = _xScale;
    yScale = _yScale;
}

float Sprite::getXPos() const {
    return xPos;
}

float Sprite::getYPos() const {
    return yPos;
}

bool Sprite::isUsed() const {
    return used;
}

void Sprite::setUsed(bool used) {
    Sprite::used = used;
}


