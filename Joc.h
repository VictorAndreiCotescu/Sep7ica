#ifndef SEPTICA_JOC_H
#define SEPTICA_JOC_H


#include "Headers/Fereastra.h"
#include "Grafica/Sprite.h"
#include "Headers/Jucator.h"
#include "Headers/Calculator.h"
#include "Headers/Pachet.h"
#include <chrono>
#include <thread>

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

class Joc : public Fereastra, public Sprite{

public:

    //Joc();

    int initializareJoc();

    void startJoc();

    bool alegereJucator();

    Joc(const Joc&) = delete;
    Joc& operator=(const Joc&) = delete;

    //bool alegereCalculator();

    static Joc *getInstance() {
        if (!instance)
            instance = new Joc;
        return instance;
    }

    void pierdut();

    int replay();

private:

    static Joc *instance;

    Joc() : jucator(),
            calculator(),
            pachet(),
            fereastra(),
            spritesJucator(),
            spritesCalculator(),
            pachetAfis(),
            spritesAleseJuc(),
            spritesAleseCalc() {};

    Jucator jucator;
    Calculator calculator;
    Pachet pachet;
    Fereastra fereastra;
    Carte carteJos = Carte(0,0);
    std::vector<Sprite> spritesJucator;
    std::vector<Sprite> spritesCalculator;
    std::vector<Sprite> pachetAfis;
    Sprite spritesAleseJuc;
    Sprite spritesAleseCalc;

    bool complJ = false;



    int puncte = 0;

    friend class Jucator;


};


#endif //SEPTICA_JOC_H
