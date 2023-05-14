#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "Game.h"

int main(void)
{
    if (!glfwInit())
    {
        std::cout << "Failed to init glfw" << std::endl;
        return -1;
    }

    Game game;

    if (glewInit() != GLEW_OK)
    {
        std::cout << "Failed to init glew" << std::endl;
        return -1;
    }
    std::cout << glGetString(GL_VERSION) << std::endl;


    game.run();

    glfwTerminate();

    return 0;
}