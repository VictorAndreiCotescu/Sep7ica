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

void Joc(){

    pachet Pachet;
    jucator Jucator1;
    jucator Calculator;

    pachet::InitializarePachetvec(&Pachet);
    pachet::AmestecareVec(&Pachet);

    jucator::CompletareMana(&Pachet, &Jucator1);
    jucator::CompletareMana(&Pachet, &Calculator);


}

int main() {

    /*pachet Pachet;

    jucator Jucator1;

    pachet::InitializarePachetvec(&Pachet);

    pachet::AmestecareVec(&Pachet);

    pachet::AfisarePachetVec(Pachet);

    jucator::trageCarte(&Pachet, &Jucator1);

    std::cout << "\n\n\n dupa tragere \n\n\n";

    pachet::AfisarePachetVec(Pachet);

    std::cout << "\n\n\n cartea trasa: ";

    jucator::AfisareCarti(&Jucator1);*/



        Joc();






    //pachet::AfisarePachet(carti);






}
