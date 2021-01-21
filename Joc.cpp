#include "Joc.h"
#include "IO/MOUSE.h"

int Joc::replay() {

    Sprite fundal = Sprite("Tex/bg3.jpg", 0, 0);
    fundal.setScale(0.9f);
    fundal.setPos(0, 0);
    Sprite start = Sprite("Tex/replayBttn.png", 0, 0);
    start.setScale(2.0f);
    start.setPos(480, 512);
    Sprite exit = Sprite("Tex/exitBttn.png", 0, 0);
    exit.setScale(2.0f);
    exit.setPos(480, 412);

    while (true) {

        Fereastra::update();

        fundal.update();

        if (MOUSE::getMouseX() > 480 && MOUSE::getMouseX() < 740 &&
            MOUSE::getMouseY() > 450 && MOUSE::getMouseY() < 512) {

            start.setScale(2.2f);
            if (MOUSE::buttonDown(GLFW_MOUSE_BUTTON_LEFT)) {

                start = Sprite("Tex/replayBttnClicked.png", 480, 512);
                start.setScale(2.2f);


                Fereastra::beginRender();

                fundal.render();
                start.render();

                Fereastra::endRender();

                startJoc();

            }
        } else {
            start = Sprite("Tex/replayBttn.png", 0, 0);
            start.setScale(2.0f);
            start.setPos(480, 512);
        }

        if (MOUSE::getMouseX() > 480 && MOUSE::getMouseX() < 740 &&
            MOUSE::getMouseY() > 550 && MOUSE::getMouseY() < 612) {

            exit.setScale(2.2f);
            if (MOUSE::buttonDown(GLFW_MOUSE_BUTTON_LEFT)) {

                exit = Sprite("Tex/exitBttnClicked.png", 480, 412);
                exit.setScale(2.2f);


                Fereastra::beginRender();

                fundal.render();
                start.render();
                exit.render();

                Fereastra::endRender();

                return 0;

            }
        } else {
            exit = Sprite("Tex/exitBttn.png", 0, 0);
            exit.setScale(2.0f);
            exit.setPos(480, 412);
        }

        exit.update();
        start.update();
        Fereastra::beginRender();

        fundal.render();
        start.render();
        exit.render();

        Fereastra::endRender();

    }
}

void Joc::pierdut() {

    Sprite fundal = Sprite("Tex/gameLost.jpg", 0, 0);
    fundal.setScale(1.5f);
    fundal.setPos(-310, 0);

    while (fundal.getScale() < 1.8) {

        fundal.setScale((float) (fundal.getScale() + 0.001));
        fundal.setPos((float) (fundal.getXPos() - 0.6), (float) (fundal.getYPos() - 0.35));

        Fereastra::beginRender();

        fundal.render();

        Fereastra::endRender();
    }

    replay();
}

int Joc::initializareJoc() {

    Fereastra::initialize("Sep7ica");

    Sprite fundal = Sprite("Tex/bg3.jpg", 0, 0);
    fundal.setScale(0.9f);
    fundal.setPos(0, 0);
    Sprite start = Sprite("Tex/playBttn.png", 0, 0);
    start.setScale(2.0f);
    start.setPos(480, 512);
    Sprite exit = Sprite("Tex/exitBttn.png", 0, 0);
    exit.setScale(2.0f);
    exit.setPos(480, 412);

    while (true) {

        Fereastra::update();

        fundal.update();

        if (MOUSE::getMouseX() > 480 && MOUSE::getMouseX() < 740 &&
            MOUSE::getMouseY() > 450 && MOUSE::getMouseY() < 512) {

            start.setScale(2.2f);
            if (MOUSE::buttonDown(GLFW_MOUSE_BUTTON_LEFT)) {

                start = Sprite("Tex/playBttnClicked.png", 480, 512);
                start.setScale(2.2f);

                Fereastra::beginRender();

                fundal.render();
                start.render();

                Fereastra::endRender();

                Joc::startJoc();
            }
        } else {
            start = Sprite("Tex/playBttn.png", 0, 0);
            start.setScale(2.0f);
            start.setPos(480, 512);
        }

        if (MOUSE::getMouseX() > 480 && MOUSE::getMouseX() < 740 &&
            MOUSE::getMouseY() > 550 && MOUSE::getMouseY() < 612) {

            exit.setScale(2.2f);
            if (MOUSE::buttonDown(GLFW_MOUSE_BUTTON_LEFT)) {

                exit = Sprite("Tex/exitBttnClicked.png", 480, 412);
                exit.setScale(2.2f);

                Fereastra::beginRender();

                fundal.render();
                start.render();
                exit.render();

                Fereastra::endRender();

                return 0;
            }
        } else {
            exit = Sprite("Tex/exitBttn.png", 0, 0);
            exit.setScale(2.0f);
            exit.setPos(480, 412);
        }

        exit.update();
        start.update();
        Fereastra::beginRender();

        fundal.render();
        start.render();
        exit.render();

        Fereastra::endRender();
    }
}

void Joc::startJoc() {

    Sprite fundal = Sprite("Tex/bgame2.jpg", 0, 0);
    fundal.setScale(1.0f);
    fundal.setPos(-200, 0);

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

            complJ = false;
        }

        Joc::alegereJucator();

        if (pachet.Gol() && jucator.getManaSize() == 0 && calculator.getManaSize() == 0) {

            if (jucator.getPuncte() > calculator.getPuncte())
                pierdut();
            else
                replay();
        }

        Fereastra::beginRender();

        fundal.render();

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

        if (MOUSE::getMouseX() < 200 * (i + 1) && MOUSE::getMouseX() > 200 * i && MOUSE::getMouseY() > 790) {

            spritesJucator[i].setScale(0.065f);

            if (MOUSE::buttonDown(GLFW_MOUSE_BUTTON_LEFT)) {

                spritesAleseJuc = Sprite(jucator.getManaTexPath(i), 900, 505);
                spritesAleseJuc.setScale(0.06f);
                Carte carteAleasaJuc = jucator.getCarte(i);

                if (carteJos == Carte(0, 0))
                    carteJos = carteAleasaJuc;

                spritesJucator.erase(spritesJucator.begin() + i);

                jucator.alegereCarte(i);

                int carteAlC = calculator.alegereCarte(carteAleasaJuc.getNumar());
                spritesAleseCalc = Sprite(calculator.getManaTexPath(carteAlC), 990, 505);
                spritesAleseCalc.setScale(0.06f);

                Carte carteAleasaCalc = calculator.getCarte(carteAlC);
                calculator.eliminareCarte(carteAlC);
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
        } else
            spritesJucator[i].setScale(0.06f);
    }
    return true;
}