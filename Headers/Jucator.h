#ifndef SEPTICA_JUCATOR_H
#define SEPTICA_JUCATOR_H


#include <vector>
#include "Carte.h"
#include "Pachet.h"


class Jucator {

public:

    Jucator();

    static void trageCarte(Pachet &pachet, Jucator &jucator);

    static void afisareCarti(Jucator &jucator);

    static void completareMana(Pachet &pachet, Jucator &jucator);

    virtual int alegereCarte(int i);

    bool alegerePosibila(const Carte &c) const;

    void eliminareCarte(int i);

    void adaugarePuncte(int x);

    const std::string &getManaTexPath(int i) const;

    Carte getCarte(int i);

    int getManaSize();

    int getPuncte() const;

    virtual ~Jucator() = default;

protected:

    std::vector<Carte> mana;
    int puncte;

private:

    friend class Carte;

};


#endif //SEPTICA_JUCATOR_H
