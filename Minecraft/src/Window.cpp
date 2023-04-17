#include "Window.h"

Engine::Window::Window(int screen_width, int screen_height)
{
    m_handle = NULL;
    m_width = screen_width;
    m_height = screen_height;
}

int Engine::Window::init()
{
    /* Create a windowed mode window and its OpenGL context */
    m_handle = glfwCreateWindow(m_width, m_height, "Minecraft", NULL, NULL);
    if (!m_handle)
    {
        std::cout << "Failed to create glfw window" << std::endl;
        glfwTerminate();
        return -1;
    }

    //glViewport(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
    glfwMakeContextCurrent(m_handle);
    glEnable(GL_DEPTH_TEST);

    return 0;
}

void Engine::Window::wireframe(bool is_wireframe)
{
    if(is_wireframe)
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    else
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); 
}
