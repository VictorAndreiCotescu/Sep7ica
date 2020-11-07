#include <iostream>
#include "Headers/Carte.h"
#include "Headers/Pachet.h"
#include "Headers/Jucator.h"
#include "Headers/Calculator.h"
#include "Headers/Fereastra.h"
#include "Grafica/Sprite.h"
#include "IO/MOUSE.h"
#include "Joc.h"


bool randulJucatorului(Jucator *Jucator1, Calculator *Calculator) {

    static int inx = 0;
    int puncte = 0;

    std::cout << "Carti Calculator: \n";
    Calculator::afisareCarti(Calculator);
    std::cout << std::endl;
    static std::vector<Carte> runda;
    Carte septar(7, 0);

    while (true) {

        Carte juc(Jucator1->alegereCarte(Jucator1));
        runda.push_back(juc);

        Carte calc(Calculator->alegereCarteCalculator(runda[0]));
        runda.push_back(calc);

        std::cout << std::endl;

        if (calc != runda[0]) {

            if (calc != septar) {
                for (int i = 0; i < inx; ++i)
                    if (runda[i] == Carte(1, 0) || runda[i] == Carte(10, 0))
                        ++puncte;
                Jucator1->adaugarePuncte(puncte);
                return true;

            } else return false;

        }

        if (!Jucator1->alegerePosibila(runda[0]))
            return false;

        ++inx;
    }
}

bool randulCalculatorului(Jucator *Jucator1, Calculator *Calculator) {

    int inx = 0;
    int puncte = 0;
    static std::vector<Carte> runda;

    std::cout << "Carti Calculator: \n";
    Calculator->afisareCarti(Calculator);
    std::cout << std::endl;

    while (true) {
        Carte calc(Calculator->alegereCarteCalculator());
        runda.push_back(calc);

        Carte juc(Jucator1->alegereCarte(Jucator1));
        runda.push_back(juc);

        if (juc != runda[0] || juc != Carte(7, 0)) {

            for (int i = 0; i < inx; ++i)
                if (runda[i] == Carte(1, 0) || runda[i] == Carte(10, 0))
                    ++puncte;

            Calculator->adaugarePuncte(puncte);
            return true;
        }

        if (calc != runda[0] || calc != Carte(7, 0)) {

            for (int i = 0; i < inx; ++i)
                if (runda[i] == Carte(1, 0) || runda[i] == Carte(10, 0))
                    ++puncte;

            Jucator1->adaugarePuncte(puncte);
            return false;

        }

        if (!Calculator->alegerePosibila(runda[0]))
            return false;

        ++inx;
    }
}

/*void Joc() {

    Pachet Pachet;
    Jucator Jucator1;
    Calculator Calculator;

    Pachet::initializarePachetVec(&Pachet);
    Pachet::amestecareVec(&Pachet);

    Jucator::completareMana(&Pachet, &Jucator1);
    Calculator::completareMana(&Pachet, &Calculator);

    bool okj = randulJucatorului(&Jucator1, &Calculator);
    bool okc = !okj;
    Jucator::completareMana(&Pachet, &Jucator1);
    Calculator::completareMana(&Pachet, &Calculator);
    while (!Pachet.Gol()) {

        std::cout << "---------------\n";

        Jucator::completareMana(&Pachet, &Jucator1);
        Calculator::completareMana(&Pachet, &Calculator);

        if (okj) {
            okj = randulJucatorului(&Jucator1, &Calculator);

            Jucator::completareMana(&Pachet, &Jucator1);
            Calculator::completareMana(&Pachet, &Calculator);
        } else if (okc) {
            okc = randulCalculatorului(&Jucator1, &Calculator);
            Jucator::completareMana(&Pachet, &Jucator1);
            Calculator::completareMana(&Pachet, &Calculator);
        }

        okc = !okj;
        okj = !okc;

    }
}*/

int main() {

    /* Fereastra fereastra;

     fereastra.initialize("SEPTICA");

     Sprite testSprite = Sprite("Tex/1.png", -100, -100);
     testSprite.setScale(0.06f);

     while(true){

         fereastra.update();
         testSprite.update();

         testSprite.setPos((float) MOUSE::getMouseX(), -(float)MOUSE::getMouseY());

         fereastra.beginRender();
         testSprite.render();
         fereastra.endRender();

     }*/

    /* Joc jocTest;

     jocTest.initializareJoc();*/

    Pachet pachet;
    Pachet::initializarePachetVec(&pachet);
    //Pachet::amestecareVec(&pachet);
    Pachet::afisarePachetVec(pachet);
    Jucator jucator;

    Jucator::completareMana(&pachet, &jucator);
    Jucator::afisareCarti(&jucator);
    std::vector<Sprite> spriteCarteJucator;
    std::vector<Sprite> spriteCarteCalculator;


    //Jucator::afisareCarti(&jucator);



}

