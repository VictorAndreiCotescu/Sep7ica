#ifndef SEPTICA_MOUSE_H
#define SEPTICA_MOUSE_H

#include <glfw3.h>

class MOUSE {

public:

    static void mousePosCallback(GLFWwindow *fereastra, double _x, double _y);

    static void mouseButtonCallback(GLFWwindow *fereastra, int button, int action, int mods);

    static double getMouseX();

    static double getMouseY();

    static bool buttonDown(int button);

    static bool buttonUp(int button);

    static bool button(int button);

private:

    static double xMouse;
    static double yMouse;

    static bool buttons[];
    static bool buttonsDown[];
    static bool buttonsUp[];

};


#endif //SEPTICA_MOUSE_H
