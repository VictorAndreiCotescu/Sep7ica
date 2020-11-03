#include <iostream>
#include "Headers/carte.h"

//carte::carte() = default;

carte::carte(const carte &c) {
    numar = c.numar;
    culoare = c.culoare;
}

carte carte::operator=(const carte &c) {

    numar = c.numar;
    culoare = c.culoare;

    if (this != &c)
        return *this;
}

bool carte::operator==(const carte &c) const {
    if (this->numar == c.numar)
        return true;
    else
        return false;
}

bool carte::operator!=(const carte &c) const {
    if (this->numar == c.numar)
        return false;
    else
        return true;
}

void carte::afisare() const {

    std::cout << this->numar << " " << this->culoare;

}



carte::~carte() = default;

carte::carte() = default;
