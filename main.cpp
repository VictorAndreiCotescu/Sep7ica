#include <iostream>
#include "Headers/Carte.h"
#include "Headers/Pachet.h"
#include "Headers/Jucator.h"
#include "Headers/Calculator.h"
#include "Headers/Fereastra.h"
#include "Grafica/Sprite.h"
#include "IO/MOUSE.h"
#include "Joc.h"

Joc *Joc::instance = nullptr;

int main() {
    Joc *joc = Joc::getInstance();
    joc->initializareJoc();

}
