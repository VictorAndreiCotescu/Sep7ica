#ifndef SEPTICA_CALCULATOR_H
#define SEPTICA_CALCULATOR_H


#include "Jucator.h"
#include "Carte.h"


class Calculator : public Jucator {

public:

    Calculator();

    int alegereCarteCalculator(Carte &c);

    Carte alegereCarteCalculator();

};



#endif //SEPTICA_CALCULATOR_H
