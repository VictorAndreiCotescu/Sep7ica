#include "Joc.h"
#include "IO/MOUSE.h"

Joc::Joc() {

}

void Joc::initializareJoc() {

    fereastra.initialize("Sep7ica");
    Sprite fundal = Sprite("Tex/bg.jpg", 0, 0);
    fundal.setScale(1.0f);
    fundal.setPos(0, 0);
    Sprite start = Sprite("Tex/start.png", 0, 0);
    start.setScale(0.5f);
    start.setPos(320, 512);

    while (true) {

        fereastra.update();
        fundal.update();

        if (MOUSE::getMouseX() > 320 && MOUSE::getMouseX() < 960 &&
            MOUSE::getMouseY() > 300 && MOUSE::getMouseY() < 512) {
            start.setScale(0.55f);

            if (MOUSE::buttonDown(GLFW_MOUSE_BUTTON_LEFT)) {
                Joc::startJoc(fereastra);
                return;
            }
        } else start.setScale(0.5f);

        start.update();
        fereastra.beginRender();

        fundal.render();
        start.render();

        fereastra.endRender();

    }
}

void Joc::startJoc(Fereastra fereastra) {


    Pachet::initializarePachetVec(&pachet);
    Pachet::amestecareVec(&pachet);


    Jucator::completareMana(&pachet, &jucator);
    Calculator::completareMana(&pachet, &calculator);


    for (int i = 0; i < pachet.getSize() / 7; ++i) {
        pachetAfis.emplace_back("Tex/back.png", 0, 0);
        pachetAfis[i].setPos((float) (900 + 2 * i), (float) (230 + 2 * i));
        pachetAfis[i].setScale(0.06f);
    }

    for (int i = 0; i < jucator.getManaSize(); ++i) {
        spritesJucator.emplace_back(jucator.getManaTexPath(i), -100, -100);
        spritesJucator[i].setScale(0.06f);

        spritesCalculator.emplace_back(calculator.getManaTexPath(i), 0, 0);
        spritesCalculator[i].setScale(0.06f);

        spritesJucator[i].setPos((float) (i + i) * 100, 10);
        spritesCalculator[i].setPos((float) (i + i) * 100, 760);
    }

    for (int i = 0; i < pachet.getSize() / 7; ++i)
        pachetAfis[i].update();


    std::cout << "CARTI JUCATOR: \n";
    jucator.afisareCarti(&jucator);

    std::cout << "\nCARTI CALCULATOR: \n";
    calculator.afisareCarti(&calculator);

    std::cout << jucator.getManaSize() << "\n";
    std::cout << calculator.getManaSize();


    while (true) {
        fereastra.update();

        while(true) {
            bool bk = Joc::alegereJucator();

            if(!bk)
                break;
        }



        fereastra.beginRender();

        for (int i = 0; i < jucator.getManaSize(); ++i) {//in functie de cine incepe trebuie schimbata ordinea de render

            spritesCalculator[i].update();
            spritesJucator[i].update();

            spritesCalculator[i].render();
            spritesJucator[i].render();
        }

        for (int i = 0; i < spritesAleseJuc.size(); ++i) {

            spritesAleseJuc[i].update();
            spritesAleseCalc[i].update();

            spritesAleseJuc[i].render();
            spritesAleseCalc[i].render();
        }

        if(!pachet.Gol())
        for (int i = 0; i < pachet.getSize() / 7 + 1; ++i) pachetAfis[i].render();

        fereastra.endRender();

    }

}

bool Joc::alegereJucator() {
    for (int i = 0; i < jucator.getManaSize(); ++i) {
        //afisez cartile pentru debug

        if (MOUSE::getMouseX() < 180 * (i + 1) && MOUSE::getMouseX() > 180 * i && MOUSE::getMouseY() > 790) {
            spritesJucator[i].setScale(0.065f);

            if (MOUSE::buttonDown(GLFW_MOUSE_BUTTON_LEFT)) {

                spritesAleseJuc.emplace_back(jucator.getManaTexPath(i), 900, 505);
                Carte carteAleasaJuc = jucator.getCarte(i);
                jucator.alegereCarte(i); // elimina cartea din mana jucatorului;
                spritesJucator.erase(spritesJucator.begin() + i);

                int carteAlC = calculator.alegereCarteCalculator(carteAleasaJuc);
                spritesAleseCalc.emplace_back(calculator.getManaTexPath(carteAlC), 990, 505);
                Carte carteAleasaCalc = calculator.getCarte(carteAlC);
                calculator.alegereCarte(carteAlC); // elimina cartea din mana calculatorului;
                spritesCalculator.erase(spritesCalculator.begin() + carteAlC);

                if (carteAleasaJuc == Carte(10, 0))
                    ++puncte;
                if (carteAleasaCalc == Carte(10, 0))
                    ++puncte;
                if (carteAleasaJuc == Carte(14, 0))
                    ++puncte;
                if (carteAleasaCalc == Carte(14, 0))
                    ++puncte;

                if (!pachet.Gol()) {
                    jucator.trageCarte(&pachet, &jucator);
                    calculator.trageCarte(&pachet, &calculator);

                    spritesJucator.emplace_back(jucator.getManaTexPath(jucator.getManaSize() - 1), 0, 0);
                    spritesCalculator.emplace_back(calculator.getManaTexPath(calculator.getManaSize() - 1), 0, 0);
                }

                jucator.afisareCarti(&jucator);

                for (int j = 0; j < jucator.getManaSize(); ++j) {

                    spritesJucator[j].setPos((float) (j + j) * 100, 10);
                    spritesCalculator[j].setPos((float) (j + j) * 100, 760);

                }
                return true;

            }
        } else {
            spritesJucator[i].setScale(0.06f);
        }
    }
}


bool Joc::alegereCalculator() {
    replay:

    int carteAlC = calculator.alegereCarteCalculator();
    spritesAleseCalc.emplace_back(calculator.getManaTexPath(carteAlC), 990, 505);
    Carte carteAleasaCalc = calculator.getCarte(carteAlC);
    calculator.alegereCarte(carteAlC); // elimina cartea din mana calculatorului;
    spritesCalculator.erase(spritesCalculator.begin() + carteAlC);

    for (int i = 0; i < jucator.getManaSize(); ++i) {
        //afisez cartile pentru debug

        if (MOUSE::getMouseX() < 180 * (i + 1) && MOUSE::getMouseX() > 180 * i && MOUSE::getMouseY() > 790) {
            spritesJucator[i].setScale(0.065f);

            if (MOUSE::buttonDown(GLFW_MOUSE_BUTTON_LEFT)) {

                spritesAleseJuc.emplace_back(jucator.getManaTexPath(i), 900, 505);
                Carte carteAleasaJuc = jucator.getCarte(i);
                jucator.alegereCarte(i); // elimina cartea din mana jucatorului;
                spritesJucator.erase(spritesJucator.begin() + i);


                if (carteAleasaJuc == Carte(10, 0))
                    ++puncte;
                if (carteAleasaCalc == Carte(10, 0))
                    ++puncte;
                if (carteAleasaJuc == Carte(14, 0))
                    ++puncte;
                if (carteAleasaCalc == Carte(14, 0))
                    ++puncte;

                if (carteAleasaJuc == carteAleasaCalc) {
                    if (calculator.alegerePosibila(carteAleasaCalc))
                        goto replay;
                    else {
                        jucator.adaugarePuncte(puncte);
                        puncte = 0;
                        return false;
                    }
                } else {
                    calculator.adaugarePuncte(puncte);
                    puncte = 0;
                    return true;
                }
            }
        } else {
            spritesJucator[i].setScale(0.06f);
        }
    }
}