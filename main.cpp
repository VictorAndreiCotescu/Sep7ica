#include <iostream>
#include "carte.h"
#include "pachet.h"

int main() {

    auto *carti = new carte[28];
    //carte pachet[52];
    pachet Pachet;

    pachet::InitializarePachet(carti);
    pachet::Amestecare(carti);
    //pachet::AfisarePachet(carti);






}
