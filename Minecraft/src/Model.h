#ifndef MODEL_H
#define MODEL_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>
#include <vector>

#include "shaders/Shader.h"
#include "texture/Texture.h"
#include "Mesh.h"
#include "Transform.h"

class Model
{
private:
	void SetBuffers();
	void InitTransform();
	void UpdateUniforms(Engine::Shader *shader);

public:
	// trasnforms
	Transform transform;
	glm::mat4 m_modelMat;

	// render data
	unsigned int VAO, VBO, EBO;

	// mesh data
	std::vector<Vertex> m_vertices;
	std::vector<unsigned int> m_indices;

	Model(std::vector<Vertex> &vertices, std::vector<unsigned int> &indices);
	void Draw(Engine::Shader *shader);
	void SetTexture(Engine::Texture &texture);
	void Destroy();
};

#endif // !MODE_H
