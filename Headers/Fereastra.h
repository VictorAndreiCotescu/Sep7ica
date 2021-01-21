#ifndef SEPTICA_FEREASTRA_H
#define SEPTICA_FEREASTRA_H

#include <glfw3.h>
#include <SOIL.h>

class Fereastra {

public:
    static int REZ_WID;
    static int REZ_HGT;

    Fereastra();

    ~Fereastra();

    static bool initialize(const char *Titlu);

    static void update();

    static void beginRender();

    static void endRender();

    static GLFWwindow *fereastra;
};


#endif //SEPTICA_FEREASTRA_H
