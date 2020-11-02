#include <iostream>
#include <conio.h>
#include "Headers/jucator.h"

jucator::jucator() = default;

void jucator::trageCarte(pachet *Pachet, jucator *Jucator) {

    Jucator->mana.push_back(Pachet->Pachet.back());
    Pachet->Pachet.pop_back();
}

void jucator::AfisareCarti(jucator *Jucator) {

    for (auto &i : Jucator->mana) {
        std::cout << i.numar;
        std::cout << " ";
        std::cout << i.culoare << std::endl;
    }

}

void jucator::CompletareMana(pachet *Pachet, jucator *Jucator) {


    if (Pachet->Pachet.size() < 8) {
        for (int i = 0; i < Pachet->Pachet.size() / 2; ++i)
            if (Jucator->mana.size() == 4)
                break;
            else
                Jucator->trageCarte(Pachet, Jucator);
    } else
        while (Jucator->mana.size() < 4)
            Jucator->trageCarte(Pachet, Jucator);
}

carte jucator::AlegereCarte(jucator *Jucator) {

    switch (getch()) {

        case '1':
            Jucator->mana.erase(Jucator->mana.begin() + 0);
            return Jucator->mana[0];
            break;

        case '2':
            if (Jucator->mana.size() > 1) {
                Jucator->mana.erase(Jucator->mana.begin() + 1);
                return Jucator->mana[1];
            }
            break;

        case '3':
            if (Jucator->mana.size() > 2) {
                Jucator->mana.erase(Jucator->mana.begin() + 2);
                return Jucator->mana[2];
            }
            break;

        case '4':
            if (Jucator->mana.size() > 3) {
               // Jucator->mana.erase(Jucator->mana.begin() + 3);
                return Jucator->mana[3];
            }
            break;

        default:
            AlegereCarte(Jucator);
            break;


    }


}

