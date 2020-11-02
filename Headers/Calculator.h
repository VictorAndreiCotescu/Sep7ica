#ifndef SEPTICA_CALCULATOR_H
#define SEPTICA_CALCULATOR_H


#include "jucator.h"

class Calculator : public jucator{
public:
    Calculator();

    carte AlegereCarteCalculator(carte &c);

    //friend std::ostream& operator<<(std::ostream& os, const carte& cl);

};


#endif //SEPTICA_CALCULATOR_H
