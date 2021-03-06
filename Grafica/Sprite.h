#ifndef SEPTICA_SPRITE_H
#define SEPTICA_SPRITE_H

#include "Textura.h"
#include <glfw3.h>
#include <iostream>
#include <string.h>

class Sprite {
public:
    Sprite();

    explicit Sprite(std::string imagePath);

    Sprite(std::string imagePath, float _xPos, float _yPos);

    void update();

    void render();

    void setPos(float _xSprite, float _ySprite);

    void setScale(float _xyScale);

    float getXPos() const;

    float getYPos() const;

    float getScale() const;

    void setUsed(bool _used);

private:
    Textura textura;
    float xPos;
    float yPos;
    float rot;
    float xScale;
    float yScale;
    bool used = false;


};

#endif //SEPTICA_SPRITE_H
