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
#include "Texture.h"

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

public:
	Game();
	void run();
};

#endif // !GAME_H


