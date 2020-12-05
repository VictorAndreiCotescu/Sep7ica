#ifndef SEPTICA_TEXTURA_H
#define SEPTICA_TEXTURA_H

#include <iostream>
#include <string>

#include <glfw3.h>
#include <SOIL.h>
class Textura {

public:

    Textura(): id(-1),wid(0),hgt(0){};

    explicit Textura(int _id):id(_id),wid(0),hgt(0){

        if (!getTextureParams()) {
            std::cerr << "Error loading image ID: " << id << std::endl;
        }

    }
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
