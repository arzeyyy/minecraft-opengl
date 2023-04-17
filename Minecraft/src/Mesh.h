#ifndef MESH_H
#define MESH_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>
#include <vector>

#include "Shader.h"
#include "Texture.h"


struct Vertex
{
	glm::vec3 position;
	glm::vec3 color;
	glm::vec2 texCoords;
	glm::vec3 normal;

};

struct Transform
{
	glm::vec3 position;
	glm::vec3 origin;
	glm::vec3 rotation;
	glm::vec3 scale;
};



//struct Texture
//{
//	unsigned int id;
//	std::string type;
//};


class Mesh
{
private:
	glm::mat4 m_modelMatrix;


	void SetBuffers();
	void InitTransform();
	void UpdateUniforms(Engine::Shader *shader);


public:
	Transform m_transform;


	//  render data
	unsigned int VAO, VBO, EBO;

	// mesh data
	std::vector<Vertex> m_vertices;
	//std::vector<Engine::Texture> m_textures;
	std::vector<unsigned int> m_indices;

	Mesh(std::vector<Vertex> &vertices, std::vector<unsigned int> &indices);
	void Draw(Engine::Shader *shader);
	void SetTexture(Engine::Texture &texture);
	void Destroy();

};


#endif // !MESH_H
