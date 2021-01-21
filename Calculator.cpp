#include "Headers/Calculator.h"

Calculator::Calculator() = default;

int Calculator::alegereCarte(int nrCarte) {
    for (int i = 0; i < (int) this->mana.size(); ++i)
        if (this->mana[i].numar == nrCarte) {
            Carte raspunsCalculator(this->mana[i]);
            return i;
        }

    for (int i = 0; i < (int) this->mana.size(); ++i)
        if (this->mana[i].numar == Carte(7, 0).numar) {
            Carte raspunsCalculator(this->mana[i]);
            return i;
        }

    for (int i = 0; i < (int) this->mana.size(); ++i)
        if (this->mana[i].numar != 14 || this->mana[i].numar != 10) {
            Carte raspunsCalculator(this->mana[i]);
            return i;
        }
    return 0;
}
