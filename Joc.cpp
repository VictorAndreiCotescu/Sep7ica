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

    while (true) {
        fereastra.update();

            Joc::alegereJucator();



        fereastra.beginRender();

        for (int i = 0; i < jucator.getManaSize(); ++i) {//in functie de cine incepe trebuie schimbata ordinea de render

            spritesCalculator[i].update();
            spritesJucator[i].update();

            spritesCalculator[i].render();
            spritesJucator[i].render();
        }

        for (int i = 0; i < spritesAleseCalc.size(); ++i) {

            spritesAleseJuc[i].update();
            spritesAleseCalc[i].update();
            spritesAleseJuc[i].render();
            spritesAleseCalc[i].render();
        }


        for (int i = 0; i < pachet.getSize() / 7; ++i)
            pachetAfis[i].render();

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

                spritesAleseCalc.emplace_back(calculator.getManaTexPath(i), 900, 505);
                Carte carteAleasaCalc = calculator.getCarte(i);
                calculator.alegereCarte(i); // elimina cartea din mana calculatorului;
                spritesCalculator.erase(spritesCalculator.begin() + i);

                for (int j = 0; j < jucator.getManaSize(); ++j) {

                    spritesJucator.emplace_back(jucator.getManaTexPath(j), -100, -100);
                    spritesJucator[j].setScale(0.06f);

                    spritesCalculator.emplace_back(calculator.getManaTexPath(j), 0, 0);
                    spritesCalculator[j].setScale(0.06f);

                    spritesJucator[j].setPos((float) (j + j) * 100, 10);
                    spritesCalculator[j].setPos((float) (j + j) * 100, 760);
                }
            }
        } else {
            spritesJucator[i].setScale(0.06f);
        }
    }
}



