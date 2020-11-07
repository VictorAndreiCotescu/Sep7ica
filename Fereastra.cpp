#include "Headers/Fereastra.h"
#include "IO/MOUSE.h"
#include <iostream>

int Fereastra::REZ_WID = 1280;
int Fereastra::REZ_HGT = 1024;

GLFWwindow *Fereastra::fereastra = nullptr;

Fereastra::Fereastra() {
}

bool Fereastra::initialize(const char *titlu) {

    if (!glfwInit()) {
        std::cerr << "Eroare initializare GLFW" << std::endl;
        return false;
    }

    fereastra = glfwCreateWindow(REZ_WID, REZ_HGT, titlu, nullptr, nullptr);

    if (fereastra == nullptr) {
        std::cerr << "Eroare initializare fereastra" << std::endl;
        return false;
    }

    glfwMakeContextCurrent(fereastra);
    int wid, hgt;
    glfwGetFramebufferSize(fereastra, &wid, &hgt);
    glfwSwapInterval(1);

    glfwSetCursorPosCallback(fereastra, MOUSE::mousePosCallback);
    glfwSetMouseButtonCallback(fereastra, MOUSE::mouseButtonCallback);

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
};

void Fereastra::beginRender() {

    glClearColor(1, 1, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Fereastra::endRender() {
    glfwSwapBuffers(fereastra);

}

