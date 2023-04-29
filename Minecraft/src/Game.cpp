#include "Game.h"

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720



Game::Game() : m_window(SCREEN_WIDTH, SCREEN_HEIGHT) 
{
    m_window.init();
    m_window.wireframe(false);
}

void Game::init()
{

}

void Game::run()
{



    //m_vbo.create();
    //m_vao.create();
    //m_ebo.create();

    Cube cube;



    //m_vao.bind();
    //m_vbo.bind(GL_ARRAY_BUFFER, &cube.vertices[0], cube.vertices.size() * sizeof(Vertex));


    Engine::Shader m_shader("shaders/6.3.coordinate_systems.vs", "shaders/6.3.coordinate_systems.fs");
    //m_shader.use(); // activate/use the shader before setting uniforms!


    Engine::Texture m_texture("assets/textures/block/grass_block_side.png", "grass_block", GL_TEXTURE_2D);
    if (!m_texture.load())
        std::cout << "failed to load a texture" << m_texture.m_path << std::endl;

    Mesh mesh(cube.vertices, cube.indices);
    mesh.SetTexture(m_texture);

    std::cout << "vertices: " << cube.vertices.size() << std::endl;
    //Mesh test(cube.vertices, cube.indices);
    //test.SetTexture(m_texture);

    //Mesh cube(vertices, indices);

    //m_shader.setInt("grass_block", 0);


    //m_vbo.unbind(GL_ARRAY_BUFFER);
    //m_vao.unbind();

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(m_window.m_handle))
    {
        // clear
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


        mesh.Draw(&m_shader);

        //glActiveTexture(GL_TEXTURE0);
        //m_texture.bind();

   

        //m_shader.use();


        // create transformations
        //glm::mat4 model = glm::mat4(1.0f); // initialize matrix to identity matrix first
        //glm::mat4 view = glm::mat4(1.0f);
        //glm::mat4 projection = glm::mat4(1.0f);
        //model = glm::rotate(model, glm::radians(-55.0f), glm::vec3(1.0f, 0.0f, 0.0f));
        //model = glm::rotate(model, (float)glfwGetTime() * glm::radians(50.0f), glm::vec3(0.5f, 1.0f, 0.0f));

        //view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
        //projection = glm::perspective(glm::radians(45.0f), (float)SCREEN_WIDTH / (float)SCREEN_HEIGHT, 0.1f, 100.0f);
        //// retrieve the matrix uniform locations
        //unsigned int modelLoc = glGetUniformLocation(m_shader.ID, "model");
        //unsigned int viewLoc = glGetUniformLocation(m_shader.ID, "view");
        //glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
        //glUniformMatrix4fv(viewLoc, 1, GL_FALSE, &view[0][0]);

        //m_shader.setMat4("projection", projection);

        //// draw
        //m_vao.bind();
        //glDrawArrays(GL_TRIANGLES, 0, 36);

        //test.Draw(&m_shader);

        // swap
        glfwSwapBuffers(m_window.m_handle);

        /* Poll for and process events */
        glfwPollEvents();
        if (glfwGetKey(m_window.m_handle, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(m_window.m_handle, true);
    }

    //m_vbo.destroy();
    //m_vao.destroy();
}
