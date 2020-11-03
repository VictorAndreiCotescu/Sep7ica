#include <iostream>
#include <random>
#include <algorithm>
#include <functional>
#include <chrono>
#include "Headers/pachet.h"

pachet::pachet() = default;

pachet::pachet(const pachet &p) {
    Pachet = p.Pachet;
}

pachet pachet::operator=(const pachet &p) {
    Pachet = p.Pachet;
    if (this != &p)
        return *this;
}

void pachet::InitializarePachetvec(pachet *Pachet) {

    int j = 0;
    for (int i = 0; i < 7; ++i) {

        carte Carte1(i + 1, 1);//inima rosie
        carte Carte2(i + 1, 2);//inima neagra
        carte Carte3(i + 1, 3);//romb
        carte Carte4(i + 1, 4);//trefla

        Pachet->Pachet.push_back(Carte1);
        Pachet->Pachet.push_back(Carte2);
        Pachet->Pachet.push_back(Carte3);
        Pachet->Pachet.push_back(Carte4);

    }
}

void pachet::AmestecareVec(pachet *Pachet) {

    /*auto rdz = std::random_device {};
    auto rng = std::default_random_engine { rdz() };
    std::shuffle(std::begin(Pachet->Pachet), std::end(Pachet->Pachet), rng);*/

    std::shuffle(Pachet->Pachet.begin(), Pachet->Pachet.end(), std::mt19937(std::random_device()()));

}

void pachet::AfisarePachetVec(const pachet &pachet) {

    int j = 0;
    for (auto &i : pachet.Pachet) {

        std::cout << i.numar << " " << i.culoare << std::endl;
    }
}

bool pachet::Gol() const {

    if(this->Pachet.empty())
        return true;
    else
        return false;
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

pachet::~pachet() = default;
