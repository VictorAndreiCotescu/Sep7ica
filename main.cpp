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

void Joc(){

    pachet Pachet;
    jucator Jucator1;
    Calculator Calculator;

    pachet::InitializarePachetvec(&Pachet);
    pachet::AmestecareVec(&Pachet);

    jucator::CompletareMana(&Pachet, &Jucator1);
    jucator::CompletareMana(&Pachet, &Calculator);

    //Jucator1.AfisareCarti(&Jucator1);
    int puncteJos = 0;

    carte c(3,4);


    Calculator.AlegereCarteCalculator(c);

    Calculator.AfisareCarti(&Calculator);


}

int main() {


    Joc();






    //pachet::AfisarePachet(carti);






}
