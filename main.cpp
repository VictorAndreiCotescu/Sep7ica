#include <iostream>
#include <conio.h>
#include <windows.h>
#include <thread>
#include "Headers/carte.h"
#include "Headers/pachet.h"
#include "Headers/jucator.h"

#define KEY_UP 72       //Up arrow character
#define KEY_DOWN 80    //Down arrow character
#define KEY_ENTER '\r'//Enter key charatcer

/*void play_music() {
    PlaySound("8bit Bossa.mp3", nullptr, SND_LOOP);
}*/

[[noreturn]] void Joc(){

    pachet Pachet;
    jucator Jucator1;
    jucator Calculator;

    pachet::InitializarePachetvec(&Pachet);
    pachet::AmestecareVec(&Pachet);

    jucator::CompletareMana(&Pachet, &Jucator1);
    jucator::CompletareMana(&Pachet, &Calculator);

    Jucator1.AfisareCarti(&Jucator1);
    carte carteJucator(1,1);
    carte carteCalculator(1,1);
    int puncteJos = 0;

    while(true){


        carteJucator.operator=(Jucator1.AlegereCarte(&Jucator1));



    }




}

int main() {

        Joc();






    //pachet::AfisarePachet(carti);






}
