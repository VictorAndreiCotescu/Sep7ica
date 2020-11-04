#ifndef SEPTICA_CALCULATOR_H
#define SEPTICA_CALCULATOR_H


#include "Jucator.h"
#include "Carte.h"


class Calculator : public Jucator {

public:

    Calculator();

    Carte alegereCarteCalculator(Carte &c);

    Carte alegereCarteCalculator();
    //friend std::ostream& operator<<(std::ostream& os, const Carte& cl);

};


#endif //SEPTICA_CALCULATOR_H
