#include <iostream>
#include "Headers/carte.h"
#include "Headers/pachet.h"
#include "Headers/jucator.h"
#include "Headers/Calculator.h"

#define KEY_UP 72       //Up arrow character
#define KEY_DOWN 80    //Down arrow character
#define KEY_ENTER '\r'//Enter key charatcer

/*void play_music() {
    PlaySound("8bit Bossa.mp3", nullptr, SND_LOOP);
}*/

bool randulJucatorului(jucator *Jucator1, Calculator *Calculator) {

    static int inx = 1;
    int puncte = 0;

    std::cout << "Carti Calculator: \n";
    Calculator->AfisareCarti(Calculator);
    std::cout << std::endl;
    static std::vector<carte> runda;

    while (true) {
        carte juc(Jucator1->AlegereCarte(Jucator1));
        runda.push_back(juc);

        carte calc(Calculator->AlegereCarteCalculator(runda[0]));
        runda.push_back(calc);

        std::cout << "\nIn functie: juc ";
        juc.afisare();
        std::cout << " calc ";
        calc.afisare();
        std::cout << std::endl;


        if (juc != runda[0] || juc != carte(7, 0)) {

            for (int i = 0; i < inx; ++i)
                if (runda[i] == carte(1, 0) || runda[i] == carte(10, 0))
                    ++puncte;

            Calculator->AdaugarePuncte(puncte);
            return false;

        }

        if (calc != runda[0] || calc != carte(7, 0)) {

            for (int i = 0; i < inx; ++i)
                if (runda[i] == carte(1, 0) || runda[i] == carte(10, 0))
                    ++puncte;

            Jucator1->AdaugarePuncte(puncte);
            return true;

        }

        if(!Jucator1->alegerePosibila(runda[0]))
            return false;

        ++inx;
    }
}

bool randulCalculatorului(jucator *Jucator1, Calculator *Calculator) {

    int inx = 0;
    int puncte = 0;
    static std::vector<carte> runda;

    std::cout << "Carti Calculator: \n";
    Calculator->AfisareCarti(Calculator);
    std::cout << std::endl;

    while (true) {
        carte calc(Calculator->AlegereCarteCalculator());
        runda.push_back(calc);

        carte juc(Jucator1->AlegereCarte(Jucator1));
        runda.push_back(juc);

        std::cout << "\nIn functie: juc ";
        juc.afisare();
        std::cout << " calc ";
        calc.afisare();
        std::cout << std::endl;

        if (juc != runda[0] || juc != carte(7, 0)) {

            for (int i = 0; i < inx; ++i)
                if (runda[i] == carte(1, 0) || runda[i] == carte(10, 0))
                    ++puncte;

            Calculator->AdaugarePuncte(puncte);
            return true;
        }

        if (calc != runda[0] || calc != carte(7, 0)) {

            for (int i = 0; i < inx; ++i)
                if (runda[i] == carte(1, 0) || runda[i] == carte(10, 0))
                    ++puncte;

            Jucator1->AdaugarePuncte(puncte);
            return false;

        }

        if(!Calculator->alegerePosibila(runda[0]))
            return false;

        ++inx;
    }
}

void Joc() {

    pachet Pachet;
    jucator Jucator1;
    Calculator Calculator;

    pachet::InitializarePachetvec(&Pachet);
    pachet::AmestecareVec(&Pachet);

    Jucator1.CompletareMana(&Pachet, &Jucator1);
    Calculator.CompletareMana(&Pachet, &Calculator);

    bool okj = randulJucatorului(&Jucator1, &Calculator);
    bool okc = !okj;
    Jucator1.CompletareMana(&Pachet, &Jucator1);
    Calculator.CompletareMana(&Pachet, &Calculator);
    while (!Pachet.Gol()) {
        //system("cls");
        std::cout << "---------------\n";

        randulJucatorului(&Jucator1, &Calculator);

        Jucator1.CompletareMana(&Pachet, &Jucator1);
        Calculator.CompletareMana(&Pachet, &Calculator);
        if (okj) {
            okj = randulJucatorului(&Jucator1, &Calculator);
            okc = !okj;
            Jucator1.CompletareMana(&Pachet, &Jucator1);
            Calculator.CompletareMana(&Pachet, &Calculator);
        } else if (okc) {
            okc = randulCalculatorului(&Jucator1, &Calculator);
            okj = !okc;
            Jucator1.CompletareMana(&Pachet, &Jucator1);
            Calculator.CompletareMana(&Pachet, &Calculator);
        }
    }


    /* if (randulJucatorului(&Jucator1, &Calculator) && ok) {


         jucator::CompletareMana(&Pachet, &Jucator1);
         Calculator::CompletareMana(&Pachet, &Calculator);
         ok = randulJucatorului(&Jucator1, &Calculator);

     } else if (randulCalculatorului(&Jucator1, &Calculator)) {

         jucator::CompletareMana(&Pachet, &Jucator1);
         Calculator::CompletareMana(&Pachet, &Calculator);
         ok = randulCalculatorului(&Jucator1, &Calculator);
     }
 }*/


}

int main() {


    Joc();
    /*pachet Pachet;
    jucator Jucator1;

    Pachet.InitializarePachetvec(&Pachet);
    Pachet.AmestecareVec(&Pachet);

    Jucator1.CompletareMana(&Pachet, &Jucator1);
    carte joc(Jucator1.AlegereCarte(&Jucator1));

    joc.afisare();

    Jucator1.CompletareMana(&Pachet, &Jucator1);

    Jucator1.AfisareCarti(&Jucator1);

    carte juc(Jucator1.AlegereCarte(&Jucator1));

    juc.afisare();*/




    //pachet::AfisarePachet(carti);






}
