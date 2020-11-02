#include "Headers/carte.h"

//carte::carte() = default;

carte::carte(const carte &c){
    numar = c.numar;
    culoare = c.culoare;
}

carte carte::operator=(const carte &c) {

    numar = c.numar;
    culoare = c.culoare;

    if (this != &c)
        return *this;
}

carte::carte() = default;
