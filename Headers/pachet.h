#ifndef SEPTICA_PACHET_H
#define SEPTICA_PACHET_H

#include "carte.h"
#include <vector>

class pachet {

public:
    pachet();

    static void InitializarePachet(carte pachet[]);


    static void InitializarePachetvec(pachet *Pachet);



    static void AfisarePachet(carte pachet[]);

    static void Amestecare(carte *pachet);

    std::vector<carte> Pachet;

private:




};


#endif //SEPTICA_PACHET_H
