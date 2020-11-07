#ifndef SEPTICA_JOC_H
#define SEPTICA_JOC_H


#include "Headers/Fereastra.h"
#include "Grafica/Sprite.h"
#include "Headers/Jucator.h"
#include "Headers/Calculator.h"
#include "Headers/Pachet.h"

class Joc : public Fereastra, public Sprite{

public:

    Joc();

    void initializareJoc();


private:

    Jucator jucator;
    Calculator calculator;
    Pachet pachet;
    Fereastra fereastra;

    friend class Jucator;

};


#endif //SEPTICA_JOC_H
