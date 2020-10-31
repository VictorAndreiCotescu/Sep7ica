#include <iostream>
#include "Headers/jucator.h"

jucator::jucator() = default;

void jucator::trageCarte(pachet *Pachet, jucator *Jucator) {

    Jucator->mana.push_back(Pachet->Pachet.back());
    Pachet->Pachet.pop_back();
}

void jucator::AfisareCarti(jucator *Jucator) {

    for(auto & i : Jucator->mana){
        std::cout <<  i.numar;
        std::cout << " ";
        std::cout <<  i.culoare << std::endl;
    }

}

void jucator::CompletareMana(pachet *Pachet, jucator *Jucator) {


    if(Pachet->Pachet.size() < 8) {
        for(int i = 0; i < Pachet->Pachet.size()/2; ++i)
            if(Jucator->mana.size() == 4)
                break;
            else
                Jucator->trageCarte(Pachet, Jucator);
    }
    else
        while(Jucator->mana.size() < 4)
                Jucator->trageCarte(Pachet, Jucator);
}

