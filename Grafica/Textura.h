#ifndef SEPTICA_TEXTURA_H
#define SEPTICA_TEXTURA_H

#include <iostream>
#include <string>

#include <glfw3.h>
#include <SOIL.h>
class Textura {

public:

    Textura();
    explicit Textura(int _id);
    explicit Textura(std::string path);
    ~Textura();

    int getId();
    int getWidth();
    int getHeight();

private:

    bool getTextureParams();

    int id;
    int wid;
    int hgt;


};


#endif //SEPTICA_TEXTURA_H
