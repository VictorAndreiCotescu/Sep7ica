#ifndef SEPTICA_PACHET_H
#define SEPTICA_PACHET_H

#include "Carte.h"
#include <vector>

class Pachet {


public:
    Pachet() : pachet() {}

    Pachet(const Pachet &p) = default;

    Pachet &operator=(const Pachet &p);


    static void initializarePachetVec(Pachet &Pachet);

    static void amestecareVec(Pachet &Pachet);

    int getSize();

    bool Gol() const;


    ~Pachet();


protected:

    std::vector<Carte> pachet;

private:

    friend class Jucator;
};


#endif //SEPTICA_PACHET_H
