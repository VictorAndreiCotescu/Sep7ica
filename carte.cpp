#include "Headers/carte.h"

//carte::carte() = default;

carte::carte(const carte &c){
    numar = c.numar;
    culoare = c.culoare;
}
