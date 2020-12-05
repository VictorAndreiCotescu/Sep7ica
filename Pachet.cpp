#include <iostream>
#include <random>
#include <algorithm>
#include <functional>
#include <chrono>
#include "Headers/Pachet.h"


Pachet& Pachet::operator=(const Pachet &p) {
        if(!(this->pachet == p.pachet))
            return *this;
        return *this;
}

void Pachet::initializarePachetVec(Pachet &Pachet) {

    for (int i = 6; i < 14; ++i) {
        Carte Carte1(i + 1, 1, " ");//trefla
        Carte Carte2(i + 1, 2, " ");//inima neagra
        Carte Carte3(i + 1, 3, " ");//inima rosie
        Carte Carte4(i + 1, 4, " ");//romb

        Carte1.setTexPath(Carte::genTexPath(Carte1));
        Carte2.setTexPath(Carte::genTexPath(Carte2));
        Carte3.setTexPath(Carte::genTexPath(Carte3));
        Carte4.setTexPath(Carte::genTexPath(Carte4));


        Pachet.pachet.push_back(Carte1);
        Pachet.pachet.push_back(Carte2);
        Pachet.pachet.push_back(Carte3);
        Pachet.pachet.push_back(Carte4);
    }

    std::cout << "Initailizare terminata " << std::endl;

    //Pachet::afisarePachetVec(*Pachet);


}


void Pachet::amestecareVec(Pachet &Pachet) {

    /*auto rdz = std::random_device {};
    auto rng = std::default_random_engine { rdz() };
    std::shuffle(std::begin(pachet->pachet), std::end(pachet->pachet), rng);*/

    std::shuffle(Pachet.pachet.begin(), Pachet.pachet.end(), std::mt19937(std::random_device()()));

}

void Pachet::afisarePachetVec(const Pachet &pachet) {

    for (auto &i : pachet.pachet) {

        std::cout << i.numar << " " << i.culoare << " texPath: " << i.texPath << std::endl;
    }
}

bool Pachet::Gol() const {

    if (this->pachet.empty())
        return true;
    else
        return false;
}

int Pachet::getSize() {
    return pachet.size();
}


Pachet::~Pachet() = default;
