#ifndef GAME_H
#define GAME_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>
#include <vector>

#include "Window.h"
#include "shaders/Shader.h"
#include "texture/Texture.h"

#include "Model.h"
#include "Camera.h"
#include "models/Cube.h"
#include "Input.h"


#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720

enum AssetID
{
	GRASS_BLOCK,
};

class Game
{
private:
	Engine::Window m_window;
	Engine::Shader m_shader;
	Cube cube;

	float xRotation;
	float yRotation;

	//double m_mouseX;
	//double m_mouseY;

	//float m_xoffset;
	//float m_yoffset;
	//float m_lastX;
	//float m_lastY;

	//bool m_firstMouse = true;

public:
	Game();
	void run();
	//void mouse_callback(GLFWwindow *window, double xpos_in, double ypos_in);
	//void updateMouseEvents();
};

#endif // !GAME_H


