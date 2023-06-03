#include "Game.h"


void mouse_callback(GLFWwindow *window, double xpos_in, double ypos_in);

Engine::Camera m_camera;

float lastX = 1280 / 2;
float lastY = 720 / 2;

bool firstMouse = true;


Game::Game() : m_window(SCREEN_WIDTH, SCREEN_HEIGHT)
{
    m_window.init();
    m_window.wireframe(false);
}

void Game::run()
{
    glfwSetInputMode(m_window.m_handle, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    glfwSetCursorPosCallback(m_window.m_handle, mouse_callback);
    //updateMouseEvents();

    m_shader.loadFromFile("shaders/6.3.coordinate_systems.vs", "shaders/6.3.coordinate_systems.fs");

    Engine::Texture m_grass(GRASS_BLOCK);
    if (!m_grass.loadFromFile("assets/textures/block/grass_block_side.png"))
        std::cout << "failed to load a texture" << m_grass.m_path << std::endl;


    Model mesh(cube.vertices1, cube.indices);
    mesh.SetTexture(m_grass);

    std::cout << "vertices: " << cube.vertices.size() << std::endl;

    m_camera.Create(&m_window);

    float old_time = 0;
    bool constrainPitch = true;

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(m_window.m_handle))
    {
        float time = (float)glfwGetTime();
        float deltaTime = (time - old_time);
        old_time = time;

        // clear
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


        if (glfwGetKey(m_window.m_handle, GLFW_KEY_W) == GLFW_PRESS)
            m_camera.transform.position += 7.f * deltaTime * m_camera.transform.forward;

        if (glfwGetKey(m_window.m_handle, GLFW_KEY_S) == GLFW_PRESS)
            m_camera.transform.position += 7.f * deltaTime * -m_camera.transform.forward;

        if (glfwGetKey(m_window.m_handle, GLFW_KEY_A) == GLFW_PRESS)
            m_camera.transform.position += 7.f * deltaTime * -m_camera.transform.right;

        if (glfwGetKey(m_window.m_handle, GLFW_KEY_D) == GLFW_PRESS)
            m_camera.transform.position += 7.f * deltaTime * m_camera.transform.right;

        if (glfwGetKey(m_window.m_handle, GLFW_KEY_SPACE) == GLFW_PRESS)
            m_camera.transform.position += 7.f * deltaTime * m_camera.transform.up;

        if (glfwGetKey(m_window.m_handle, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS)
            m_camera.transform.position += 7.f * deltaTime * -m_camera.transform.up;

        m_camera.Update(&m_shader, deltaTime);

        // Draw
        mesh.Draw(&m_shader);

        // swap
        glfwSwapBuffers(m_window.m_handle);

        /* Poll for and process events */
        glfwPollEvents();
        if (glfwGetKey(m_window.m_handle, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(m_window.m_handle, true);
    }

    mesh.Destroy();
}

void mouse_callback(GLFWwindow *window, double xpos_in, double ypos_in)
{

    float xpos = static_cast<float>(xpos_in);
    float ypos = static_cast<float>(ypos_in);

    if (firstMouse)
    {
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
    }

    float xoffset = xpos - lastX;
    float yoffset = lastY - ypos; // reversed since y-coordinates go from bottom to top

    //std::cout << "xoffset: " << xoffset << std::endl;

    lastX = xpos;
    lastY = ypos;

    m_camera.Rotate(xoffset, yoffset);
}
