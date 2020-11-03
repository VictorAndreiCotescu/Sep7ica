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

    static void CompletareMana(pachet *Pachet, jucator *Jucator);

    static carte AlegereCarte(jucator *Jucator);

    void AdaugarePuncte(int x);

protected:

    std::vector<carte> mana;
    int puncte;

};


#endif //SEPTICA_JUCATOR_H
