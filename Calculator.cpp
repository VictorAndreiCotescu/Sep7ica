#include "Headers/Calculator.h"
#include <algorithm>
#include <iostream>


Calculator::Calculator() = default;


int Calculator::alegereCarteCalculator(Carte &c) {

    for (int i = 0; i < (int)this->mana.size(); ++i)
        if (this->mana[i].numar == c.numar) {
            Carte raspunsCalculator(this->mana[i]);
            //this->mana.erase(this->mana.begin() + i);
            std::cout << "Raspuns calculator1: " << raspunsCalculator.numar << " " << raspunsCalculator.culoare << "\n";
            return i;
        }

    for (int i = 0; i < (int)this->mana.size(); ++i)
        if (this->mana[i].numar == Carte(7,0).numar) {
            Carte raspunsCalculator(this->mana[i]);
            //this->mana.erase(this->mana.begin() + i);
            std::cout << "Raspuns calculator1: " << raspunsCalculator.numar << " " << raspunsCalculator.culoare << "\n";
            return i;
        }

    for (int i = 0; i < (int)this->mana.size(); ++i)
        if (this->mana[i].numar != 14 || this->mana[i].numar != 10) {
            Carte raspunsCalculator(this->mana[i]);
            //this->mana.erase(this->mana.begin() + i);
            std::cout << "Raspuns calculator2: " << raspunsCalculator.numar << " " << raspunsCalculator.culoare
                      << "\n";
            return i;
        }

    std::cout << "Raspuns calculator3: " << this->mana[0].numar << " " <<this->mana[0].culoare << "\n";
    return 0;
}


int Calculator::alegereCarteCalculator() {

    for (int i = 0; i < (int)this->mana.size() / 2 + 1; ++i)
        if (std::find(this->mana.begin() + i + 1, this->mana.end(), this->mana[i]) != this->mana.end()) {
            Carte raspunsCalculator(this->mana[i]);
            this->mana.erase(this->mana.begin() + i);
            std::cout << "Carte calculator1: " << raspunsCalculator.numar << " " << raspunsCalculator.culoare << "\n";
            return i;
        }

    for (int i = 0; i < (int)this->mana.size(); ++i)
        if (this->mana[i] != Carte(1, 0) || this->mana[i] != Carte(10, 0)) {
            Carte raspunsCalculator(this->mana[i]);
            this->mana.erase(this->mana.begin() + i);
            std::cout << "Carte calculator2: " << raspunsCalculator.numar << " " << raspunsCalculator.culoare << "\n";
            return i;
        }

    return 0;
}




/*std::ostream &operator<<(std::ostream &os, const Carte &cl) {

    os << cl.culoare
    return os;
}*/


