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
    void setRot(float _xRot);
    void setScale(float _xyScale);
    void setScale(float _xScale, float _yScale);

    float getXPos() const;
    float getYPos() const;


private:
    Textura textura;
    float xPos;
    float yPos;
    float rot;
    float xScale;
    float yScale;
};


#endif //SEPTICA_SPRITE_H
