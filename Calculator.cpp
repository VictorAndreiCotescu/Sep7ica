//
// Created by victo on 02-Nov-20.
//

#include "Headers/Calculator.h"
#include <algorithm>


Calculator::Calculator()  = default;

carte Calculator::AlegereCarteCalculator(carte &c) {


    for (int i = 0; i < this->mana.size(); ++i) {
        if (this->mana[i].culoare == c.culoare && this->mana[i].numar == c.numar) {
            this->mana.erase(this->mana.begin() + i);
            return c;
        }

    }

    for (int i = 0; i < this->mana.size(); ++i)
        if (this->mana[i].numar != 1 || this->mana[i].numar != 10) {
            c = this->mana[i];
            this->mana.erase(this->mana.begin() + i);
            return c;
        }

}

/*std::ostream &operator<<(std::ostream &os, const carte &cl) {

    os << cl.culoare
    return os;
}*/


