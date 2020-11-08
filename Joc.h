#ifndef SEPTICA_JOC_H
#define SEPTICA_JOC_H


#include "Headers/Fereastra.h"
#include "Grafica/Sprite.h"
#include "Headers/Jucator.h"
#include "Headers/Calculator.h"
#include "Headers/Pachet.h"
#include <chrono>
#include <thread>

#ifdef WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

class Joc : public Fereastra, public Sprite{

public:

    Joc();

    void initializareJoc();
    void startJoc(Fereastra fereastra);

    bool alegereJucator();

    bool alegereCalculator();


private:

    Jucator jucator;
    Calculator calculator;
    Pachet pachet;
    Fereastra fereastra;
    std::vector<Sprite> spritesJucator;
    std::vector<Sprite> spritesCalculator;
    std::vector<Sprite> pachetAfis;
    std::vector<Sprite> spritesAleseJuc;
    std::vector<Sprite> spritesAleseCalc;

    friend class Jucator;

};


#endif //SEPTICA_JOC_H
