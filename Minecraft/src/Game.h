#ifndef GAME_H
#define GAME_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>

#include "Window.h"
#include "Shader.h"
#include "Texture.h"
#include "VBO.h"
#include "VAO.h"
#include "EBO.h"

#include "models/Cube.h"

class Game
{
private:
	Engine::Window m_window;
	Engine::VBO m_vbo;
	Engine::VAO m_vao;
	Engine::EBO m_ebo;

	//Engine::Shader *m_shader;
	Engine::Texture *m_texture;

public:
	Game();
	void init();
	void run();
};


#endif // !GAME_H


