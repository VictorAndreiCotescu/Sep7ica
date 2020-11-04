#include <iostream>
#include "Headers/Carte.h"

//Carte::Carte() = default;

Carte::Carte(const Carte &c) {
    numar = c.numar;
    culoare = c.culoare;
}

Carte Carte::operator=(const Carte &c) {

    numar = c.numar;
    culoare = c.culoare;

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

    std::cout << this->numar << " " << this->culoare;

}



Carte::~Carte() = default;

Carte::Carte() = default;
