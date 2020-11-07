#include <iostream>
#include "Headers/Carte.h"

//Carte::Carte() = default;

Carte::Carte(const Carte &c) {

    numar = c.numar;
    culoare = c.culoare;
    texPath = c.texPath;

}

Carte Carte::operator=(const Carte &c){

    numar = c.numar;
    culoare = c.culoare;
    texPath = c.texPath;

        return *this;
}

bool Carte::operator==(const Carte &c) const {

    if (this->numar == c.numar)
        return true;
    else
        return false;
}

bool Carte::operator!=(const Carte &c) const {

    if (this->numar == c.numar)
        return false;
    else
        return true;
}

void Carte::afisare() const {

    std::cout << this->numar << " " << this->culoare << " " << texPath;
}

void Carte::setTexPath(const std::string &_texPath) {

    texPath = _texPath;

}

const std::string &Carte::getTexPath() {
    return texPath;
}

int Carte::getCuloare() const {
    return culoare;
}

int Carte::getNumar() const {
    return numar;
}

std::string Carte::genTexPath(Carte &c) {

    std::string tex = "Tex/";
    tex.append(std::to_string(c.getNumar()));
    tex.append(std::to_string(c.getCuloare()));
    tex.append(".png");

    return tex;
}



Carte::~Carte() = default;

Carte::Carte() = default;
