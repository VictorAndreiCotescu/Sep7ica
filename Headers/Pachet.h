#ifndef SEPTICA_PACHET_H
#define SEPTICA_PACHET_H

#include "Carte.h"
#include <vector>

class Pachet {


public:
    Pachet(): pachet() {}

    Pachet(const Pachet &p): pachet(p.pachet) {}

    Pachet& operator=(const Pachet &p);


    static void initializarePachetVec(Pachet &Pachet);

    static void afisarePachetVec(const Pachet &pachet);

    static void amestecareVec(Pachet &Pachet);

    int getSize();

    bool Gol() const;


    ~Pachet();


protected:

    std::vector<Carte> pachet;

private:

    friend class Jucator;

    // fara std::vector
    static void InitializarePachet(Carte pachet[]);

    static void Amestecare(Carte *pachet);

    static void AfisarePachet(Carte pachet[]);

};


#endif //SEPTICA_PACHET_H
