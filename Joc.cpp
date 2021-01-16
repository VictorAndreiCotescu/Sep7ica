#include "Joc.h"
#include "IO/MOUSE.h"
#include <chrono> // std::chrono::microseconds
#include <thread> // std::this_thread::sleep_for

/*Joc::Joc() : jucator(),
             calculator(),
             pachet(),
             fereastra(),
             spritesJucator(),
             spritesCalculator(),
             pachetAfis(),
             spritesAleseJuc(),
             spritesAleseCalc() {}*/

void Joc::initializareJoc() {


    fereastra.initialize("Sep7ica");

    Sprite fundal = Sprite("Tex/bg.jpg", 0, 0);
    fundal.setScale(1.0f);
    fundal.setPos(0, 0);
    Sprite start = Sprite("Tex/start.png", 0, 0);
    start.setScale(0.5f);
    start.setPos(320, 512);

    while (true) {

        Fereastra::update();
        fundal.update();

        if (MOUSE::getMouseX() > 320 && MOUSE::getMouseX() < 960 &&
            MOUSE::getMouseY() > 300 && MOUSE::getMouseY() < 512) {
            start.setScale(0.55f);

            if (MOUSE::buttonDown(GLFW_MOUSE_BUTTON_LEFT)) {
                Joc::startJoc();
                return;
            }
        } else start.setScale(0.5f);

        start.update();
        Fereastra::beginRender();

        fundal.render();
        start.render();

        Fereastra::endRender();

    }
}

void Joc::startJoc() {


    Pachet::initializarePachetVec(pachet);
    Pachet::amestecareVec(pachet);


    Jucator::completareMana(pachet, jucator);
    Calculator::completareMana(pachet, calculator);


    for (int i = 0; i < pachet.getSize() / 7; ++i) {
        pachetAfis.emplace_back("Tex/back.png", 0, 0);
        pachetAfis[i].setPos((float) (900 + 2 * i), (float) (230 + 2 * i));
        pachetAfis[i].setScale(0.06f);
    }

    for (int i = 0; i < jucator.getManaSize(); ++i) {
        spritesJucator.emplace_back(jucator.getManaTexPath(i), -100, -100);
        spritesJucator[i].setScale(0.06f);

        spritesCalculator.emplace_back("Tex/back.png", 0, 0);
        spritesCalculator[i].setScale(0.06f);

        spritesJucator[i].setPos((float) (i + i) * 100, 10);
        spritesCalculator[i].setPos((float) (i + i) * 100, 760);
    }

    for (int i = 0; i < pachet.getSize() / 7; ++i)
        pachetAfis[i].update();


    while (true) {
        Fereastra::update();

        if (complJ) {
            std::cout << "\n";
            if (!pachet.Gol())
                while (!pachet.Gol() && jucator.getManaSize() < 4) {
                    Jucator::trageCarte(pachet, jucator);
                    Calculator::trageCarte(pachet, calculator);

                    spritesJucator.emplace_back(jucator.getManaTexPath(jucator.getManaSize() - 1), 0, 0);
                    spritesCalculator.emplace_back("Tex/back.png", 0, 0);
                    spritesCalculator.back().setScale(0.06f);
                }

            for (int j = 0; j < jucator.getManaSize(); ++j) {

                spritesJucator[j].setPos((float) (j + j) * 100, 10);
                spritesCalculator[j].setPos((float) (j + j) * 100, 760);

            }

            spritesAleseJuc.setPos(-1000, -1000);
            spritesAleseCalc.setPos(-1000, -1000);

            carteJos = Carte(0, 0);
            //complC = true;
            complJ = false;
        }
        Joc::alegereJucator();
/*
        if(!bk) {
            if (complC) {
                std::cout << "\n";
                if(!pachet.Gol())
                while(!pachet.Gol() && jucator.getManaSize() < 4) {
                    jucator.trageCarte(&pachet, &jucator);
                    calculator.trageCarte(&pachet, &calculator);

                    spritesJucator.emplace_back(jucator.getManaTexPath(jucator.getManaSize() - 1), 0, 0);
                    spritesCalculator.emplace_back(calculator.getManaTexPath(calculator.getManaSize() - 1), 0, 0);
                }

                for (int j = 0; j < jucator.getManaSize(); ++j) {

                    spritesJucator[j].setPos((float) (j + j) * 100, 10);
                    spritesCalculator[j].setPos((float) (j + j) * 100, 760);

                }

                carteJos = Carte(0,0);
                complJ = true;
                complC = false;
            }


                bk = Joc::alegereCalculator();


        }*/

        if (pachet.Gol() && jucator.getManaSize() == 0 && calculator.getManaSize() == 0) {

            if (jucator.getPuncte() > calculator.getPuncte()) {

                std::cout << "\nAi castigat! Puncte jucator: ";
                std::cout << jucator.getPuncte();
                std::cout << " Puncte calculator ";
                std::cout << calculator.getPuncte();
                return;
            } else {

                std::cout << "\nAi pierdut! Puncte jucator: ";
                std::cout << jucator.getPuncte();
                std::cout << " Puncte calculator ";
                std::cout << calculator.getPuncte();
                return;

            }
        }

        std::this_thread::sleep_for(std::chrono::microseconds{5000});

        Fereastra::beginRender();

        for (int i = 0; i < jucator.getManaSize(); ++i) {

            spritesCalculator[i].update();
            spritesJucator[i].update();

            spritesCalculator[i].render();
            spritesJucator[i].render();
        }


        spritesAleseJuc.update();
        spritesAleseCalc.update();

        spritesAleseJuc.render();
        spritesAleseCalc.render();


        if (!pachet.Gol())
            for (int i = 0; i < pachet.getSize() / 7 + 1; ++i) pachetAfis[i].render();

        Fereastra::endRender();

    }
}

bool Joc::alegereJucator() {
    for (int i = 0; i < jucator.getManaSize(); ++i) {
        //afisez cartile pentru debug

        if (MOUSE::getMouseX() < 180 * (i + 1) && MOUSE::getMouseX() > 180 * i && MOUSE::getMouseY() > 790) {
            spritesJucator[i].setScale(0.065f);
            if (MOUSE::buttonDown(GLFW_MOUSE_BUTTON_LEFT)) {

                spritesAleseJuc = Sprite(jucator.getManaTexPath(i), 900, 505);
                spritesAleseJuc.setScale(0.06f);
                Carte carteAleasaJuc = jucator.getCarte(i);
                if (carteJos == Carte(0, 0))
                    carteJos = carteAleasaJuc;
                spritesJucator.erase(spritesJucator.begin() + i);
                jucator.alegereCarte(i); // elimina cartea din mana jucatorului;
                Jucator::afisareCarti(jucator);
                int carteAlC = calculator.alegereCarte(carteAleasaJuc.getNumar());
                //calculator.afisareCarti(calculator);
                spritesAleseCalc = Sprite(calculator.getManaTexPath(carteAlC), 990, 505);
                spritesAleseCalc.setScale(0.06f);
                Carte carteAleasaCalc = calculator.getCarte(carteAlC);
                calculator.eliminareCarte(carteAlC);
                //calculator.alegereCarte(carteAlC); // elimina cartea din mana calculatorului;
                spritesCalculator.erase(spritesCalculator.begin() + carteAlC);

                if (carteAleasaJuc == Carte(10, 0))
                    ++puncte;
                if (carteAleasaCalc == Carte(10, 0))
                    ++puncte;
                if (carteAleasaJuc == Carte(14, 0))
                    ++puncte;
                if (carteAleasaCalc == Carte(14, 0))
                    ++puncte;


                for (int j = 0; j < jucator.getManaSize(); ++j) {

                    spritesJucator[j].setPos((float) (j + j) * 100, 10);
                    spritesCalculator[j].setPos((float) (j + j) * 100, 760);

                }


                if (carteAleasaCalc == carteJos) {
                    if (jucator.alegerePosibila(carteJos)) {
                        complJ = false;
                        return true;
                    } else {
                        calculator.adaugarePuncte(puncte);
                        puncte = 0;
                        complJ = true;
                        return false;
                    }
                } else {
                    jucator.adaugarePuncte(puncte);
                    puncte = 0;
                    complJ = true;

                    return true;
                }


            }
        } else {
            spritesJucator[i].setScale(0.06f);
            //return true;
        }
    }
    return true;
}