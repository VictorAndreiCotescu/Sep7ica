#include <iostream>
#include <random>
#include <algorithm>
#include <functional>
#include <chrono>
#include "Headers/Pachet.h"

Pachet::Pachet() = default;

Pachet::Pachet(const Pachet &p) {
    pachet = p.pachet;
}

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wreturn-type"
Pachet Pachet::operator=(const Pachet &p) {
    pachet = p.pachet;
    if (this != &p)
        return *this;
}

void Pachet::initializarePachetVec(Pachet *Pachet) {

    for (int i = 6; i < 14; ++i) {
        Carte Carte1(i + 1, 1, " ");//trefla
        Carte Carte2(i + 1, 2," ");//inima neagra
        Carte Carte3(i + 1, 3, " ");//inima rosie
        Carte Carte4(i + 1, 4, " ");//romb

        Carte1.setTexPath(Carte1.genTexPath(Carte1));
        std::cout << Carte1.texPath << std::endl; // afiseaza corect

        Pachet->pachet.push_back(Carte1);
        Pachet->pachet.push_back(Carte2);
        Pachet->pachet.push_back(Carte3);
        Pachet->pachet.push_back(Carte4);
    }

    std::cout << "Initailizare terminata " << std::endl;

    Pachet::afisarePachetVec(*Pachet);


}

#pragma GCC diagnostic pop
void Pachet::amestecareVec(Pachet *Pachet) {

    /*auto rdz = std::random_device {};
    auto rng = std::default_random_engine { rdz() };
    std::shuffle(std::begin(pachet->pachet), std::end(pachet->pachet), rng);*/

    std::shuffle(Pachet->pachet.begin(), Pachet->pachet.end(), std::mt19937(std::random_device()()));

}

void Pachet::afisarePachetVec(const Pachet &pachet) {

    for (auto &i : pachet.pachet) {

        std::cout << i.numar << " " << i.culoare << " texPath: " << i.texPath << std::endl;
    }
}

bool Pachet::Gol() const {

    if(this->pachet.empty())
        return true;
    else
        return false;
}

void Pachet::AfisarePachet(Carte pachet[]) {
    for (int i = 0; i < 27; ++i)
        std::cout << pachet[i].numar << " " << pachet[i].culoare << std::endl;
}

void Pachet::Amestecare(Carte *pachet) {

    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::knuth_b generator(seed);
    std::uniform_int_distribution<int> distribution(1, 27);

    for (int i = 0; i < 50; ++i) //amestecare buna?

        std::swap(pachet[distribution(generator)], pachet[distribution(generator)]);


}

void Pachet::InitializarePachet(Carte pachet[]) {
    int j = 0;
    for (int i = 0; i < 7; ++i) {

        Carte Carte1(i + 1, 3);//inima rosie
        Carte Carte2(i + 1, 2);//inima neagra
        Carte Carte3(i + 1, 4);//romb
        Carte Carte4(i + 1, 1);//trefla

        pachet[j++] = Carte1;
        pachet[j++] = Carte2;
        pachet[j++] = Carte3;
        pachet[j++] = Carte4;
    }
}

Pachet::~Pachet() = default;
