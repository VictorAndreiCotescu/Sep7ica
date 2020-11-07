#include "Joc.h"

Joc::Joc() {

}

void Joc::initializareJoc() {

    fereastra.initialize("Sep7ica");

    Pachet::initializarePachetVec(&pachet);
    Pachet::amestecareVec(&pachet);

    Jucator::completareMana(&pachet, &jucator);
    Calculator::completareMana(&pachet, &jucator);

    std::vector<Sprite> spriteCarteJucator;
    std::vector<Sprite> spriteCarteCalculator;

    for(int i = 0; jucator.getManaSize(); ++i){

        spriteCarteJucator[i] = Sprite(jucator.getCarteTexPath(i), (float)(i+1)*100, 100);

    }


    while(true){

        fereastra.update();

        fereastra.beginRender();

        fereastra.endRender();

    }
}

