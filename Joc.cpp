#include "Joc.h"
#include "IO/MOUSE.h"

Joc::Joc() {

}

void Joc::initializareJoc() {

    fereastra.initialize("Sep7ica");
    Sprite fundal = Sprite("Tex/bg.jpg", 0, 0);
    fundal.setScale(1.0f);
    fundal.setPos(0, 0);
    Sprite start = Sprite("Tex/start.png", 0 , 0);
    start.setScale(0.5f);
    start.setPos(320, 512);

    while(true){

        fereastra.update();
        fundal.update();

        if (MOUSE::getMouseX() > 320 && MOUSE::getMouseX() < 960 &&
            MOUSE::getMouseY() > 300 && MOUSE::getMouseY() < 512) {
            start.setScale(0.55f);

            if (MOUSE::buttonDown(GLFW_MOUSE_BUTTON_LEFT)) {
                Joc::startJoc(fereastra);
                return;
            }
        }   else start.setScale(0.5f);

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
    //Pachet::afisarePachetVec(pachet);
    Jucator::completareMana(&pachet, &jucator);
    //Jucator::afisareCarti(&jucator);


    for (int i = 0; i < 6; ++i) {
        pachetAfis.emplace_back("Tex/back.png", 0, 0);
        pachetAfis[i].setPos((float)(900 + 2*i),(float)(230 + 2*i));
        pachetAfis[i].setScale(0.06f);
    }
    for (int i = 0; i < jucator.getManaSize(); ++i) {
        spritesJucator.emplace_back(jucator.getMana(i), -100, -100);
        spritesJucator[i].setScale(0.06f);

        spritesCalculator.emplace_back("Tex/back.png", 0, 0);
        spritesCalculator[i].setScale(0.06f);

        spritesJucator[i].setPos((float) (i + i) * 100, 10);
        spritesCalculator[i].setPos((float) (i + i) * 100, 760);
    }


    while (true) {
        fereastra.update();

        for (int i = 0; i < 6; ++i)
            pachetAfis[i].update();
        for (int i = 0; i < jucator.getManaSize(); ++i) {
            spritesJucator[i].update();
            spritesCalculator[i].update();

            if (MOUSE::getMouseX() < 180 * (i + 1) && MOUSE::getMouseX() > 180 * i && MOUSE::getMouseY() > 740 &&
                !spritesJucator[i].isUsed()) {
                spritesJucator[i].setScale(0.065f);

                if (MOUSE::buttonDown(GLFW_MOUSE_BUTTON_LEFT)) {

                    spritesJucator[i].setUsed(true);
                    spritesJucator[i].setPos(900, 500);

                }


            } else {
                spritesJucator[i].setScale(0.06f);
            }


        }

        fereastra.beginRender();

        for (int i = 0; i < jucator.getManaSize(); ++i) {
            spritesJucator[i].render();
            spritesCalculator[i].render();
        }
        for (int i = 0; i < 6; ++i)
            pachetAfis[i].render();

        fereastra.endRender();


    }

}



