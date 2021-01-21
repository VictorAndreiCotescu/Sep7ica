#ifndef SEPTICA_CALCULATOR_H
#define SEPTICA_CALCULATOR_H


#include "Jucator.h"
#include "Carte.h"


class Calculator : public Jucator {

public:

    Calculator();
    
    int alegereCarte(int nrCarte) override;


};


#endif //SEPTICA_CALCULATOR_H
