#ifndef SEPTICA_CARTE_H
#define SEPTICA_CARTE_H

#include <cstring>
#include <string>
#include <utility>

class carte {

    friend class pachet;
    friend class jucator;

public:
    carte();

    explicit carte(int numar_ = 1, int culoare_ = 1) : numar(numar_), culoare(culoare_){}

    carte(const carte &c);

    carte operator= (const carte &c);


private:

    int culoare;
    int numar;

};


#endif //SEPTICA_CARTE_H
