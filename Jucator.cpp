#include <iostream>
#include <algorithm>
#include "Headers/Jucator.h"

Jucator::Jucator() {
    puncte = 0;
};

void Jucator::trageCarte(Pachet *Pachet, Jucator *Jucator) {

    Jucator->mana.push_back(Pachet->pachet.back());
    Pachet->pachet.pop_back();
}

void Jucator::afisareCarti(Jucator *Jucator) {

    /*for (auto &i : Jucator->mana) {
        std::cout << i.numar;
        std::cout << " " <<  i.culoare;
        std::cout << " texPath: ";
        std::cout << i.getTexPath() << std::endl;
    }*/

    for (int i = 0; i < Jucator->mana.size(); ++i) {

        std::cout << "texPath: ";
        std::cout << Jucator->mana[i].getTexPath() << std::endl;


    }

}

void Jucator::completareMana(Pachet *Pachet, Jucator *Jucator) {

    if (Pachet->pachet.size() < 8) {
        for (int i = 0; i < Pachet->pachet.size() / 2; ++i)
            if (Jucator->mana.size() == 4)
                break;
            else
                Jucator->trageCarte(Pachet, Jucator);
    } else
        while (Jucator->mana.size() < 4)
            Jucator->trageCarte(Pachet, Jucator);
}

Carte Jucator::carteAleasa(char c) {

    if (mana.size() > (c - '0') - 1) {

        Carte CarteAleasa(mana[(c - '0') - 1]);
        mana.erase(mana.begin() + (c - '0') - 1);
        std::cout << "Carte Jucator: " << CarteAleasa.numar << " " << CarteAleasa.culoare << "\n";
        return CarteAleasa;
    }
}

Carte Jucator::alegereCarte(Jucator *Jucator) {

    std::cout << std::endl;
    std::cout << "Alege o Carte: \n";
    Jucator->afisareCarti(Jucator);
    char c;
    std::cin >> c;
    Carte carteAleasaReturn(1, 1);

    switch (c) {

        case '1':
            carteAleasaReturn = carteAleasa(c);
            return carteAleasaReturn;

        case '2':
            carteAleasaReturn = carteAleasa(c);
            return carteAleasaReturn;

        case '3':
            carteAleasaReturn = carteAleasa(c);
            return carteAleasaReturn;

        case '4':
            carteAleasaReturn = carteAleasa(c);
            return carteAleasaReturn;

        default:
            if (!Jucator->mana.empty())
                alegereCarte(Jucator);
            break;
    }
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

std::string Jucator::getCarteTexPath(int i) {

    std::cout << this->mana[i].getTexPath();
    return this->mana[i].getTexPath();

}

int Jucator::getManaSize() {

    return this->mana.size();

}

const std::string &Jucator::getMana(int i) const {
    return mana[i].texPath;
}



