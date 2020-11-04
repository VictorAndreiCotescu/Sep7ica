#ifndef SEPTICA_PACHET_H
#define SEPTICA_PACHET_H

#include "carte.h"
#include <vector>

class pachet {

    friend class jucator;

public:
    pachet();

    pachet(const pachet &p);

    pachet operator=(const pachet &p);

    // cu std::vector
    static void InitializarePachetvec(pachet *Pachet);

    static void AfisarePachetVec(const pachet &pachet);

    static void AmestecareVec(pachet *Pachet);

    bool Gol() const;


    ~pachet();


protected:

    std::vector<carte> Pachet;

private:
    // fara std::vector
    static void InitializarePachet(carte pachet[]);

    static void Amestecare(carte *pachet);

    static void AfisarePachet(carte pachet[]);

};


#endif //SEPTICA_PACHET_H
