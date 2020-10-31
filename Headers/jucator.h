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
private:

    std::vector<carte> carti;
    std::vector<carte> mana;

};





#endif //SEPTICA_JUCATOR_H
