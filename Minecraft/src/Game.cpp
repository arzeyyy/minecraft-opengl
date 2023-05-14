#include "Game.h"

void mouseCallback(GLFWwindow *window, double xpos_in, double ypos_in);

bool firstMouse = true;
static float lastX = 1280 / 2.f;
static float lastY = 720 / 2.f;
Engine::Camera m_camera;


Game::Game() : m_window(SCREEN_WIDTH, SCREEN_HEIGHT)
{
    m_window.init();
    m_window.wireframe(false);
}

void Game::run()
{
    glfwSetCursorPosCallback(m_window.m_handle, mouseCallback);
    glfwSetInputMode(m_window.m_handle, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);

    m_shader.loadFromFile("shaders/6.3.coordinate_systems.vs", "shaders/6.3.coordinate_systems.fs");

    Engine::Texture m_grass(GRASS_BLOCK);
    if (!m_grass.loadFromFile("assets/textures/block/grass_block_side.png"))
        std::cout << "failed to load a texture" << m_grass.m_path << std::endl;


    Model mesh(cube.vertices1, cube.indices);
    mesh.SetTexture(m_grass);

    std::cout << "vertices: " << cube.vertices.size() << std::endl;

    m_camera.Create(&m_window);

    // Projection Matrix
    //glm::mat4 projection = glm::mat4(1.0f);
    //projection = glm::perspective(glm::radians(45.0f), (float)SCREEN_WIDTH / (float)SCREEN_HEIGHT, 0.1f, 100.0f);

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


        //float mouseX = Input::getAxis("mouseX");
        //float mouseY = Input::getAxis("mouseY");

        //xRotation += mouseY * m_camera.sensitivity;
        //yRotation += mouseX * m_camera.sensitivity;

        //glm::clamp(xRotation, -90.f, 90.f);

        //std::cout << "mouseX: " << mouseX << std::endl;
        //std::cout << "mouseY: " << mouseY << std::endl;

        //m_camera.transform.rotation = glm::vec3(xRotation, yRotation, 0.0f);


        if (glfwGetKey(m_window.m_handle, GLFW_KEY_W) == GLFW_PRESS)
            m_camera.transform.position += 7.f * deltaTime * m_camera.orientation;

        if (glfwGetKey(m_window.m_handle, GLFW_KEY_S) == GLFW_PRESS)
            m_camera.transform.position += 7.f * deltaTime * -m_camera.orientation;

        if (glfwGetKey(m_window.m_handle, GLFW_KEY_A) == GLFW_PRESS)
            m_camera.transform.position += 7.f * deltaTime * -glm::normalize(glm::cross(m_camera.orientation, m_camera.transform.up));

        if (glfwGetKey(m_window.m_handle, GLFW_KEY_D) == GLFW_PRESS)
            m_camera.transform.position += 7.f * deltaTime * glm::normalize(glm::cross(m_camera.orientation, m_camera.transform.up));

        if (glfwGetKey(m_window.m_handle, GLFW_KEY_SPACE) == GLFW_PRESS)
            m_camera.transform.position += 7.f * deltaTime * m_camera.transform.up;

        if (glfwGetKey(m_window.m_handle, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS)
            m_camera.transform.position += 7.f * deltaTime * -m_camera.transform.up;

        //if (glfwGetMouseButton(m_window.m_handle, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS)
        //{
        //    //glfwSetInputMode(m_window.m_handle, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);

        //    //double mouseX;
        //    //double mouseY;

        //    //glfwGetCursorPos(m_window.m_handle, &mouseX, &mouseY);

        //    //float rotX = m_camera.sensitivity * (float)mouseY - (SCREEN_HEIGHT / 2) / SCREEN_HEIGHT;
        //    //float rotY = m_camera.sensitivity * (float)mouseX - (SCREEN_HEIGHT / 2) / SCREEN_HEIGHT;

        //    //m_camera.orientation = glm::mat3(glm::rotate(-mouseX * 0.5f, m_camera.transform.up)) * m_camera.orientation;

        //    //glm::vec3 newOrientation = glm::rotate(m_camera.orientation, glm::radians(-rotX), glm::normalize(glm::cross(m_camera.orientation, m_camera.transform.up)));

        //    //if (abs(glm::angle(newOrientation, m_camera.transform.up) - glm::radians(90.0f)) <= glm::radians(85.0f))
        //    //{
        //    //    m_camera.orientation = newOrientation;
        //    //}

        //    //m_camera.orientation = glm::rotate(m_camera.orientation, glm::radians(-rotY), m_camera.transform.up);

        //    //glfwSetCursorPos(m_window.m_handle, (SCREEN_WIDTH / 2), (SCREEN_HEIGHT / 2));

        //}

        //if (glfwGetMouseButton(m_window.m_handle, GLFW_MOUSE_BUTTON_LEFT) == GLFW_RELEASE)
        //    glfwSetInputMode(m_window.m_handle, GLFW_CURSOR, GLFW_CURSOR_NORMAL);


        //double mouseX;
        //double mouseY;

        //glfwGetCursorPos(m_window.m_handle, &mouseX, &mouseY);

        //float rotX = m_camera.sensitivity * (float)mouseY - (SCREEN_HEIGHT / 2) / SCREEN_HEIGHT;
        //float rotY = m_camera.sensitivity * (float)mouseX - (SCREEN_HEIGHT / 2) / SCREEN_HEIGHT;

        //glm::clamp(m_camera.transform.rotation.x, -90.f, 90.f);

        ////m_camera.orientation = glm::rotate(m_camera.orientation, glm::radians(-rotY), m_camera.transform.up);

        //// create a quaternion that represents the rotation
        //glm::quat rotation = glm::angleAxis(glm::radians(-rotY), m_camera.transform.up);

        //// rotate the orientation vector using the quaternion
        //m_camera.orientation = rotation * m_camera.orientation;

        // Calculates upcoming vertical change in the Orientation
// 
            //glm::vec3 newOrientation = glm::rotate(newOrientation, glm::radians(-rotX), glm::normalize(glm::cross(newOrientation, m_camera.transform.up)));

            //glm::mat4 rotationMat = glm::rotate(glm::mat4(1.0f), glm::radians(45.0f), glm::vec3(0.0f, 1.0f, 0.0f));
            //glm::vec3 newOrientation = glm::vec3(rotationMat * glm::vec4(vec, 1.0f));

            //glm::vec3 newOrientation = glm::rotate(glm::mat4(1.0f), glm::radians(-rotX), glm::normalize(glm::cross(m_camera.orientation, m_camera.transform.up))) * glm::vec4(newOrientation, 1.0f);

            //    m_camera.orientation = newOrientation;
            //// Decides whether or not the next vertical Orientation is legal or not
            //if (abs(glm::angle(newOrientation, m_camera.transform.up) - glm::radians(90.0f)) <= glm::radians(85.0f))
            //{
            //}

            // Rotates the Orientation left and right

            // Sets mouse cursor to the middle of the screen so that it doesn't end up roaming around
        glfwSetCursorPos(m_window.m_handle, (SCREEN_WIDTH / 2), (SCREEN_WIDTH / 2));

        m_camera.Update(&m_shader, deltaTime);

        // transform
        //glm::mat4 model = glm::mat4(1.0f);
        //glm::mat4 view = glm::mat4(1.0f);

        //mesh.m_modelMat = glm::rotate(mesh.m_modelMat, glm::radians(-55.0f), glm::vec3(1.0f, 0.0f, 0.0f));
        //mesh.m_modelMat = glm::rotate(mesh.m_modelMat, (float)glfwGetTime() * glm::radians(55.0f), glm::vec3(0.5f, 1.0f, 0.0f));

        //view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));

        //m_shader.setMat4("view", view);
        //m_shader.setMat4("projection", projection);

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

void mouseCallback(GLFWwindow *window, double xpos_in, double ypos_in)
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
