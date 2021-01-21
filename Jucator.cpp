#include <iostream>
#include <algorithm>
#include "Headers/Jucator.h"

Jucator::Jucator() : mana(), puncte(0) {
    puncte = 0;
}

void Jucator::trageCarte(Pachet &Pachet, Jucator &Jucator) {

    Jucator.mana.push_back(Pachet.pachet.back());
    Pachet.pachet.pop_back();
}

void Jucator::afisareCarti(Jucator &Jucator) {

    for (auto &i : Jucator.mana) {

        std::cout << "texPath: ";
        std::cout << i.getTexPath() << std::endl;
    }
}

void Jucator::completareMana(Pachet &Pachet, Jucator &Jucator) {

    if (Pachet.pachet.size() < 8) {
        for (int i = 0; i < (int) Pachet.pachet.size() / 2; ++i)
            if (Jucator.mana.size() == 4)
                break;
            else
                Jucator.trageCarte(Pachet, Jucator);
    } else
        while (Jucator.mana.size() < 4)
            Jucator.trageCarte(Pachet, Jucator);
}

void Jucator::adaugarePuncte(int x) {

    Jucator::puncte += x;
}

bool Jucator::alegerePosibila(const Carte &c) const {

    if (std::find(this->mana.begin(), this->mana.end(), c) != this->mana.end())
        return true;
    else if (std::find(this->mana.begin(), this->mana.end(), Carte(7, 0)) != this->mana.end())
        return true;
    else
        return false;

}

int Jucator::getManaSize() {

    return this->mana.size();

}

const std::string &Jucator::getManaTexPath(int i) const {
    return mana[i].texPath;
}

Carte Jucator::getCarte(int i) {
    return mana[i];
}

int Jucator::alegereCarte(int i) {
    this->mana.erase(mana.begin() + i);
    return 0;
}

int Jucator::getPuncte() const {
    return puncte;
}

void Jucator::eliminareCarte(int i) {
    this->mana.erase(this->mana.begin() + i);
}



