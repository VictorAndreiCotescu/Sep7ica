#ifndef SEPTICA_PACHET_H
#define SEPTICA_PACHET_H

#include "carte.h"

class pachet {

public:
    pachet();

    static void InitializarePachet(carte pachet[]);

    static void AfisarePachet(carte pachet[]);

    static void Amestecare(carte *pachet);

private:


};


#endif //SEPTICA_PACHET_H
