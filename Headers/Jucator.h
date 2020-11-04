#ifndef SEPTICA_JUCATOR_H
#define SEPTICA_JUCATOR_H


#include <vector>
#include "Carte.h"
#include "Pachet.h"


class Jucator {

public:

    Jucator();

    static void trageCarte(Pachet *Pachet, Jucator *Jucator);

    static void afisareCarti(Jucator *Jucator);

    static void completareMana(Pachet *Pachet, Jucator *Jucator);

    Carte alegereCarte(Jucator *Jucator);

    bool alegerePosibila(const Carte &c) const;

    void adaugarePuncte(int x);

protected:

    std::vector<Carte> mana;
    int puncte;

private:
    Carte carteAleasa(char c);

};


#endif //SEPTICA_JUCATOR_H
