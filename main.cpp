#include <iostream>
#include <conio.h>
#include <windows.h>
#include <thread>
#include "Headers/carte.h"
#include "Headers/pachet.h"

#define KEY_UP 72       //Up arrow character
#define KEY_DOWN 80    //Down arrow character
#define KEY_ENTER '\r'//Enter key charatcer

/*void play_music() {
    PlaySound("8bit Bossa.mp3", nullptr, SND_LOOP);
}*/

void Joc(carte *carti) {

    std::cout << "1. Start Joc" << std::endl;
    std::cout << "2. Exit";

e:
        char c = getch();
        switch (c) {

            case '1':
                pachet::InitializarePachet(carti);
                pachet::Amestecare(carti);
                pachet::AfisarePachet(carti);
                goto e;
                break;
            case '2':
                exit(0);

            case '\r':
                Beep(300, 200);

            default:

                Beep(300, 200);
                goto e;

                break;
        }



}


int main() {

    auto *carti = new carte[28];

    pachet Pachet;
    //Joc(carti);

    pachet::InitializarePachetvec(&Pachet);

    int j = 0;
    for(auto & i : Pachet.Pachet){

           // std::cout << 'k';
            std::cout << i.numar << " " << i.culoare << std::endl;
    }



    //pachet::AfisarePachet(carti);






}
