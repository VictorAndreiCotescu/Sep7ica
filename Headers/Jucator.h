#ifndef SEPTICA_JUCATOR_H
#define SEPTICA_JUCATOR_H


#include <vector>
#include "Carte.h"
#include "Pachet.h"


class Jucator {

public:

    Jucator();

    static void trageCarte(Pachet &Pachet, Jucator &Jucator);

    static void afisareCarti(Jucator &Jucator);

    static void completareMana(Pachet &Pachet, Jucator &Jucator);

    void alegereCarte(int i);

    bool alegerePosibila(const Carte &c) const;

    void adaugarePuncte(int x);

    const std::string & getManaTexPath(int i) const;

    Carte getCarte(int i);

    int getManaSize();

    std::string getCarteTexPath(int i);

    int getPuncte() const;

protected:

    std::vector<Carte> mana;
    int puncte;

private:
    Carte carteAleasa(char c);

    friend class Carte;

};


#endif //SEPTICA_JUCATOR_H
