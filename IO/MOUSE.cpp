#include "MOUSE.h"

double MOUSE::xMouse = 0;
double MOUSE::yMouse = 0;

bool MOUSE::buttons[GLFW_MOUSE_BUTTON_LAST] = { 0 };
bool MOUSE::buttonsDown[GLFW_MOUSE_BUTTON_LAST] = { 0 };
bool MOUSE::buttonsUp[GLFW_MOUSE_BUTTON_LAST] = { 0 };

void MOUSE::mousePosCallback(GLFWwindow *fereastra, double _x, double _y) {

    int wid, hgt;
    glfwGetFramebufferSize(fereastra, &wid, &hgt);

    xMouse = _x;
    yMouse = _y;


}

void MOUSE::mouseButtonCallback(GLFWwindow *fereastra, int button, int action, int mods) {
    mods = 1;
    if(mods) {
        if (fereastra != nullptr) {

            if (button < 0)
                return;

            if (action != GLFW_RELEASE && !buttons[button]) {
                buttonsDown[button] = true;
                buttonsUp[button] = false;
            }

            if (action == GLFW_RELEASE && !buttons[button]) {
                buttonsDown[button] = false;
                buttonsUp[button] = true;
            }

            buttons[button] = action != GLFW_RELEASE;
        }
    }

}

double MOUSE::getMouseX() {
    return xMouse;
}

double MOUSE::getMouseY() {
    return yMouse;
}

bool MOUSE::buttonDown(int button) {
    bool x = buttonsDown[button];
    buttonsDown[button] = false;
    return x;
}

bool MOUSE::buttonUp(int button) {
    bool x = buttonsUp[button];
    buttonsUp[button] = false;
    return x;
}

bool MOUSE::button(int button) {
    return buttons[button];
}
