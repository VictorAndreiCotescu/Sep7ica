#include <iostream>
#include <conio.h>
#include <windows.h>
#include <thread>
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

    static std::vector<carte> runda;

    carte juc(jucator::AlegereCarte(Jucator1));
    runda.push_back(juc);

    carte calc = Calculator->AlegereCarteCalculator(juc);
    runda.push_back(calc);


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
}

bool randulCalculatorului(jucator *Jucator1, Calculator *Calculator) {

    static int inx = 0;
    static std::vector<carte> runda;
    carte calc = Calculator->AlegereCarteCalculator();
    runda.push_back(calc);
    carte juc = Jucator1->AlegereCarte(Jucator1);
    runda.push_back(juc);

    static int puncte = 0;

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
}

void Joc() {

    pachet Pachet;
    jucator Jucator1;
    Calculator Calculator;

    pachet::InitializarePachetvec(&Pachet);
    pachet::AmestecareVec(&Pachet);

    jucator::CompletareMana(&Pachet, &Jucator1);
    Calculator::CompletareMana(&Pachet, &Calculator);

    while (!Pachet.Gol()) {

        static bool ok = true;

        if (randulJucatorului(&Jucator1, &Calculator) && ok) {


            jucator::CompletareMana(&Pachet, &Jucator1);
            Calculator::CompletareMana(&Pachet, &Calculator);
            ok = randulJucatorului(&Jucator1, &Calculator);

        } else if (randulCalculatorului(&Jucator1, &Calculator)) {

            jucator::CompletareMana(&Pachet, &Jucator1);
            Calculator::CompletareMana(&Pachet, &Calculator);
            ok = randulCalculatorului(&Jucator1, &Calculator);
        }


    }
}

int main() {


    Joc();
    /*pachet Pachet;
    jucator Jucator1;

    Pachet.InitializarePachetvec(&Pachet);
    Pachet.AmestecareVec(&Pachet);

    Jucator1.CompletareMana(&Pachet, &Jucator1);
    carte joc(Jucator1.AlegereCarte(&Jucator1));

    joc.afisare();*/




    //pachet::AfisarePachet(carti);






}
