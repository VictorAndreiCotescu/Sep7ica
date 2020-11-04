#ifndef SEPTICA_JUCATOR_H
#define SEPTICA_JUCATOR_H


#include <vector>
#include "carte.h"
#include "pachet.h"


class jucator {

public:

    jucator();

    void trageCarte(pachet *Pachet, jucator *Jucator);

    void AfisareCarti(jucator *Jucator);

    void CompletareMana(pachet *Pachet, jucator *Jucator);

    carte AlegereCarte(jucator *Jucator);

    bool alegerePosibila(const carte &c) const;

    void AdaugarePuncte(int x);

protected:

    std::vector<carte> mana;
    int puncte;

};


#endif //SEPTICA_JUCATOR_H
