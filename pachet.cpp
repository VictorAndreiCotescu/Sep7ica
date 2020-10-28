#include <iostream>
#include <random>
#include <ctime>
#include <functional>
#include <chrono>
#include "Headers/pachet.h"

pachet::pachet() = default;

void pachet::InitializarePachet(carte pachet[]) {
    int j = 0;
    for (int i = 0; i < 7; ++i) {

        carte Carte1(i + 1, 1);//inima rosie
        carte Carte2(i + 1, 2);//inima neagra
        carte Carte3(i + 1, 3);//romb
        carte Carte4(i + 1, 4);//trefla

        pachet[j++] = Carte1;
        pachet[j++] = Carte2;
        pachet[j++] = Carte3;
        pachet[j++] = Carte4;
    }
}

void pachet::AfisarePachet(carte pachet[]) {
    for (int i = 0; i < 27; ++i)
        std::cout << pachet[i].numar << " " << pachet[i].culoare << std::endl;
}


void pachet::Amestecare(carte *pachet) {

    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::knuth_b generator(seed);
    std::uniform_int_distribution<int> distribution(1, 27);

    for (int i = 0; i < 50; ++i) //amestecare buna?

        std::swap(pachet[distribution(generator)], pachet[distribution(generator)]);


}