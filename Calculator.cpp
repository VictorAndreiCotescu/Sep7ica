#include "Headers/Calculator.h"
#include <algorithm>
#include <iostream>


Calculator::Calculator() = default;

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wreturn-type"

Carte Calculator::alegereCarteCalculator(Carte &c) {


    for (int i = 0; i < this->mana.size(); ++i)
        if (this->mana[i].numar == c.numar) {
            Carte raspunsCalculator(this->mana[i]);
            this->mana.erase(this->mana.begin() + i);
            std::cout << "Raspuns calculator1: " << raspunsCalculator.numar << " " << raspunsCalculator.culoare << "\n";
            return raspunsCalculator;
        }

    for (int i = 0; i < this->mana.size(); ++i)
        if (this->mana[i].numar != 1 || this->mana[i].numar != 10) {
            Carte raspunsCalculator(this->mana[i]);
            this->mana.erase(this->mana.begin() + i);
            std::cout << "\nRaspuns calculator2: " << raspunsCalculator.numar << " " << raspunsCalculator.culoare
                      << "\n";
            return raspunsCalculator;
        }
}


Carte Calculator::alegereCarteCalculator() {

    for (int i = 0; i < this->mana.size() / 2 + 1; ++i)
        if (std::find(this->mana.begin() + i + 1, this->mana.end(), this->mana[i]) != this->mana.end()) {
            Carte raspunsCalculator(this->mana[i]);
            this->mana.erase(this->mana.begin() + i);
            std::cout << "\nCarte calculator1: " << raspunsCalculator.numar << " " << raspunsCalculator.culoare << "\n";
            return raspunsCalculator;
        }

    for (int i = 0; i < this->mana.size(); ++i)
        if (this->mana[i] != Carte(1, 0) || this->mana[i] != Carte(10, 0)) {
            Carte raspunsCalculator(this->mana[i]);
            this->mana.erase(this->mana.begin() + i);
            std::cout << "\nCarte calculator2: " << raspunsCalculator.numar << " " << raspunsCalculator.culoare << "\n";
            return raspunsCalculator;
        }
}

#pragma GCC diagnostic pop



/*std::ostream &operator<<(std::ostream &os, const Carte &cl) {

    os << cl.culoare
    return os;
}*/


