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

    std::cout << std::endl;
    std::cout << "Alege o carte: \n";
    jucator::AfisareCarti(Jucator);
    char c = getch();
    carte CarteAleasa(1, 1);
    switch (c) {

        case '1':
            if (!Jucator->mana.empty()) {
                CarteAleasa = Jucator->mana[0];
                Jucator->mana.erase(Jucator->mana.begin() + 0);
                std::cout << "Carte Jucator: " << CarteAleasa.numar << " " << CarteAleasa.culoare << "\n";
                return CarteAleasa;
            }
            break;

        case '2':
            if (Jucator->mana.size() > 1) {
                CarteAleasa = Jucator->mana[1];
                Jucator->mana.erase(Jucator->mana.begin() + 1);
                std::cout << "Carte Jucator: " << CarteAleasa.numar << " " << CarteAleasa.culoare << "\n";
                return CarteAleasa;
            }
            break;

        case '3':
            if (Jucator->mana.size() > 2) {
                CarteAleasa = Jucator->mana[2];
                Jucator->mana.erase(Jucator->mana.begin() + 2);
                std::cout << "Carte Jucator: " << CarteAleasa.numar << " " << CarteAleasa.culoare << "\n";
                return CarteAleasa;
            }
            break;

        case '4':
            if (Jucator->mana.size() > 3) {
                CarteAleasa = Jucator->mana[3];
                Jucator->mana.erase(Jucator->mana.begin() + 3);
                std::cout << "Carte Jucator: " << CarteAleasa.numar << " " << CarteAleasa.culoare << "\n";
                return CarteAleasa;
            }
            break;

        default:
            if (!Jucator->mana.empty())
                AlegereCarte(Jucator);
            break;
    }

    return carte(0,0);
}

void jucator::AdaugarePuncte(int x) {

   jucator::puncte += x;

}

