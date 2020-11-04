#include <iostream>
#include "Headers/Carte.h"
#include "Headers/Pachet.h"
#include "Headers/Jucator.h"
#include "Headers/Calculator.h"
#include "Headers/Fereastra.h"


bool randulJucatorului(Jucator *Jucator1, Calculator *Calculator) {

    static int inx = 0;
    int puncte = 0;

    std::cout << "Carti Calculator: \n";
    Calculator::afisareCarti(Calculator);
    std::cout << std::endl;
    static std::vector<Carte> runda;

    while (true) {

        Carte juc(Jucator1->alegereCarte(Jucator1));
        runda.push_back(juc);

        Carte calc(Calculator->alegereCarteCalculator(runda[0]));
        runda.push_back(calc);

        runda[0].afisare();

        if (calc != runda[0] || calc != Carte(7, 0)) {

            for (int i = 0; i < inx; ++i)
                if (runda[i] == Carte(1, 0) || runda[i] == Carte(10, 0))
                    ++puncte;

            Jucator1->adaugarePuncte(puncte);
            return true;

        }

        if(!Jucator1->alegerePosibila(runda[0]))
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

        if(!Calculator->alegerePosibila(runda[0]))
            return false;

        ++inx;
    }
}

void Joc() {

    Pachet Pachet;
    Jucator Jucator1;
    Calculator Calculator;

    Pachet::initializarePachetvec(&Pachet);
    Pachet::amestecareVec(&Pachet);

    Jucator::completareMana(&Pachet, &Jucator1);
    Calculator::completareMana(&Pachet, &Calculator);

    bool okj = randulJucatorului(&Jucator1, &Calculator);
    bool okc = !okj;
    Jucator::completareMana(&Pachet, &Jucator1);
    Calculator::completareMana(&Pachet, &Calculator);
    while (!Pachet.Gol()) {

        std::cout << "---------------\n";

        randulJucatorului(&Jucator1, &Calculator);

        Jucator::completareMana(&Pachet, &Jucator1);
        Calculator::completareMana(&Pachet, &Calculator);

        if (okj) {
            okj = randulJucatorului(&Jucator1, &Calculator);
            okc = !okj;
            Jucator::completareMana(&Pachet, &Jucator1);
            Calculator::completareMana(&Pachet, &Calculator);
        } else if (okc) {
            okc = randulCalculatorului(&Jucator1, &Calculator);
            okj = !okc;
            Jucator::completareMana(&Pachet, &Jucator1);
            Calculator::completareMana(&Pachet, &Calculator);
        }
    }


    /* if (randulJucatorului(&Jucator1, &Calculator) && ok) {


         Jucator::CompletareMana(&pachet, &Jucator1);
         Calculator::CompletareMana(&pachet, &Calculator);
         ok = randulJucatorului(&Jucator1, &Calculator);

     } else if (randulCalculatorului(&Jucator1, &Calculator)) {

         Jucator::CompletareMana(&pachet, &Jucator1);
         Calculator::completareMana(&pachet, &Calculator);
         ok = randulCalculatorului(&Jucator1, &Calculator);
     }
 }*/


}

int main() {


    Joc();

    /*pachet pachet;
    Jucator Jucator1;

    pachet.initializarePachetvec(&pachet);
    pachet.amestecareVec(&pachet);

    Jucator1.CompletareMana(&pachet, &Jucator1);
    Carte joc(Jucator1.AlegereCarte(&Jucator1));

    joc.afisare();

    Jucator1.completareMana(&pachet, &Jucator1);

    Jucator1.afisareCarti(&Jucator1);

    Carte juc(Jucator1.alegereCarte(&Jucator1));

    juc.afisare();*/ //initializare in main pentru teste


   /* Fereastra fereastra;

    fereastra.initialize("SEPTICA");

    while(true){

        fereastra.update();
        fereastra.render();

    }
*/



}
