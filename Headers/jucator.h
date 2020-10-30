//
// Created by victo on 30-Oct-20.
//

#ifndef SEPTICA_JUCATOR_H
#define SEPTICA_JUCATOR_H


#include <vector>
#include "carte.h"
#include "pachet.h"

class jucator {
public:

    jucator();
    static void trageCarte(pachet *Pachet, jucator *Jucator);
    static void AfisareCarti(jucator *Jucator);

private:

    std::vector<carte> carti;

};

carte carte::operator=(const carte &c) {

    numar = c.numar;
    culoare = c.culoare;
}


#endif //SEPTICA_JUCATOR_H
