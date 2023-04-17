#ifndef MODEL_H
#define MODEL_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <vector>

#include "Mesh.h"
#include "Shader.h"


class Model
{
private:

public:
	std::vector<Mesh> m_meshes;


	Model();
	void Init();
	void Draw(Engine::Shader shader);
	void Destroy();
};


#endif // !MODEL_H




