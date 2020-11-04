#ifndef SEPTICA_CARTE_H
#define SEPTICA_CARTE_H

#include <cstring>
#include <string>
#include <utility>

class Carte {

public:
    Carte();

    explicit Carte(int numar_ = 1, int culoare_ = 1) : numar(numar_), culoare(culoare_) {}

    Carte(const Carte &c);

    Carte operator=(const Carte &c);

    void afisare() const;

    bool operator==(const Carte &c) const;

    bool operator!=(const Carte &c) const;

    ~Carte();


protected:

    int culoare;
    int numar;

private:

    friend class Pachet;

    friend class Jucator;

    friend class Calculator;

};


#endif //SEPTICA_CARTE_H
