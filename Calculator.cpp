#include "Headers/Calculator.h"
#include <algorithm>
#include <iostream>


Calculator::Calculator()  = default;

carte Calculator::AlegereCarteCalculator(carte &c) {


    for (int i = 0; i < this->mana.size(); ++i)
        if (this->mana[i].numar == c.numar) {
            carte raspunsCalculator(this->mana[i]);
            this->mana.erase(this->mana.begin() + i);
            std::cout << "Raspuns calculator1: " << raspunsCalculator.numar << " " << raspunsCalculator.culoare << "\n";
            return raspunsCalculator;
        }

    for (int i = 0; i < this->mana.size(); ++i)
        if (this->mana[i].numar != 1 || this->mana[i].numar != 10) {
            carte raspunsCalculator(this->mana[i]);
            this->mana.erase(this->mana.begin() + i);
            std::cout << "\nRaspuns calculator2: " << raspunsCalculator.numar << " " << raspunsCalculator.culoare << "\n";
            return raspunsCalculator;
        }
}

carte Calculator::AlegereCarteCalculator() {

    for(int i = 0; i < this->mana.size()/2+1; ++i)
        if(std::find(this->mana.begin()+i+1, this->mana.end(), this->mana[i]) != this->mana.end()) {
            carte raspunsCalculator(this->mana[i]);
            this->mana.erase(this->mana.begin() + i);
            std::cout << "\nCarte calculator1: " << raspunsCalculator.numar << " " << raspunsCalculator.culoare << "\n";
            return raspunsCalculator;
        }

    for(int i = 0; i < this->mana.size(); ++i)
        if(this->mana[i] != carte(1,0) || this->mana[i] != carte(10,0)) {
            carte raspunsCalculator(this->mana[i]);
            this->mana.erase(this->mana.begin() + i);
            std::cout << "\nCarte calculator2: " << raspunsCalculator.numar << " " << raspunsCalculator.culoare << "\n";
            return raspunsCalculator;
        }
}



/*std::ostream &operator<<(std::ostream &os, const carte &cl) {

    os << cl.culoare
    return os;
}*/


