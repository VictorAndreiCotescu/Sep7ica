//
// Created by victo on 02-Nov-20.
//

#include "Headers/Calculator.h"
#include <algorithm>
#include <iostream>


Calculator::Calculator()  = default;

carte Calculator::AlegereCarteCalculator(carte &c) {

    for (int i = 0; i < this->mana.size(); ++i)
        if (this->mana[i].culoare == c.culoare && this->mana[i].numar == c.numar) {
            this->mana.erase(this->mana.begin() + i);
            std::cout << "Raspuns calculator: " << c.numar << " " << c.culoare << "\n";
            return c;
        }

    for (int i = 0; i < this->mana.size(); ++i)
        if (this->mana[i].numar != 1 || this->mana[i].numar != 10) {
            c = this->mana[i];
            this->mana.erase(this->mana.begin() + i);
            std::cout << "\nRaspuns calculator: " << c.numar << " " << c.culoare << "\n";
            return c;
        }
}

carte Calculator::AlegereCarteCalculator() {

    for(int i = 0; i < this->mana.size()/2+1; ++i)
        if(std::find(this->mana.begin()+i+1, this->mana.end(), this->mana[i]) != this->mana.end()) {
            std::cout << "\nCarte calculator: " << this->mana[i].numar << " " << this->mana[i].culoare << "\n";
            return this->mana[i];
        }

    for(int i = 0; i < this->mana.size(); ++i)
        if(this->mana[i] != carte(1,0) || this->mana[i] != carte(10,0)) {
            std::cout << "\nCarte calculator: " << this->mana[i].numar << " " << this->mana[i].culoare << "\n";
            return this->mana[i];
        }
}



/*std::ostream &operator<<(std::ostream &os, const carte &cl) {

    os << cl.culoare
    return os;
}*/


