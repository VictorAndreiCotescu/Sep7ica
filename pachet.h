#ifndef SEPTICA_PACHET_H
#define SEPTICA_PACHET_H

#include "carte.h"

class pachet {

public:
    int j = -1;

    pachet(){

        for(int i = 0; i < 13; ++i){

            carte Carte1(i+1, "inima rosie");
            carte Carte2(i+1, "inima neagra");
            carte Carte3(i+1, "romb");
            carte Carte4(i+1, "trefla");

            Carti[j++] = Carte1;
            Carti[j++] = Carte2;
            Carti[j++] = Carte3;
            Carti[j++] = Carte4;

        }

    }

    void amestecare(){


            

    }

private:
    carte Carti[];

};


#endif //SEPTICA_PACHET_H
