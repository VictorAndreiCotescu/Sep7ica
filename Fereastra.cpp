#include "Headers/Fereastra.h"
#include "IO/MOUSE.h"
#include <iostream>

int Fereastra::REZ_WID = 1280;
int Fereastra::REZ_HGT = 1024;

GLFWwindow *Fereastra::fereastra = nullptr;

Fereastra::Fereastra() = default;

bool Fereastra::initialize(const char *titlu) {

    try {
        if (!glfwInit())
            throw "glfwInit esuat";
    } catch (const char &ex) {
        std::cerr << "[GLFW ERROR]: " << ex << std::endl;
        return false;
    }

    try {

        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
        fereastra = glfwCreateWindow(REZ_WID, REZ_HGT, titlu, nullptr, nullptr);

        if (fereastra == nullptr) {
            throw "Initializare fereastra esuata";
        }
    } catch (const char &ex) {
        std::cerr << "[GLFW ERROR]: " << ex << std::endl;
        return false;
    }

    glfwMakeContextCurrent(fereastra);
    int wid, hgt;
    glfwGetFramebufferSize(fereastra, &wid, &hgt);
    glfwSwapInterval(1);

    glfwSetCursorPosCallback(fereastra, MOUSE::mousePosCallback);
    glfwSetMouseButtonCallback(fereastra, reinterpret_cast<GLFWmousebuttonfun>(MOUSE::mouseButtonCallback));

    const GLFWvidmode *mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
    int xPos = (mode->width - REZ_WID) / 2;
    int yPos = (mode->height - REZ_HGT) / 2;
    glfwSetWindowPos(fereastra, xPos, yPos);

    glViewport(0, 0, wid, hgt);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, wid, 0, hgt, -10, 10);
    glDepthRange(-10, 10);
    glMatrixMode(GL_MODELVIEW);

    glEnable(GL_ALPHA_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    return true;
}

Fereastra::~Fereastra() = default;

void Fereastra::update() {
    glfwPollEvents();
}

void Fereastra::beginRender() {

    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Fereastra::endRender() {
    glfwSwapBuffers(fereastra);
}

