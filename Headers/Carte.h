#ifndef SEPTICA_CARTE_H
#define SEPTICA_CARTE_H

#include <cstring>
#include <string>
#include <utility>

class Carte {

public:
    Carte();

    explicit Carte(int numar_ = 1, int culoare_ = 1, std::string _tex = "--") : numar(numar_),
                                                                                culoare(culoare_),
                                                                                texPath(std::move(_tex)) {}

    Carte(const Carte &c);

    Carte operator=(const Carte &c);


    void afisare() const;

    bool operator==(const Carte &c) const;

    bool operator!=(const Carte &c) const;


    //~Carte();

    void setTexPath(const std::string &texPath);

    static std::string genTexPath(Carte &c);

    const std::string &getTexPath();

    int getCuloare() const;

    int getNumar() const;

protected:

    int culoare;
    int numar;
    std::string texPath;

private:

    friend class Pachet;

    friend class Jucator;

    friend class Calculator;

};


#endif //SEPTICA_CARTE_H
