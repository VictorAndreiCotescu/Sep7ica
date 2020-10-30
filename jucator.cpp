//
// Created by victo on 30-Oct-20.
//

#include <iostream>
#include "Headers/jucator.h"

jucator::jucator() = default;

void jucator::trageCarte(pachet *Pachet, jucator *Jucator) {

    Jucator->carti.push_back(Pachet->Pachet.back());
    Pachet->Pachet.pop_back();
}

void jucator::AfisareCarti(jucator *Jucator) {

    for(auto & i : Jucator->carti){
        std::cout <<  i.numar;
        std::cout << " ";
        std::cout <<  i.culoare << std::endl;
    }

}
