#ifndef VERTEX_H
#define VERTEX_X

#include <glm/glm.hpp>

struct Vertex
{
	glm::vec3 position;
	glm::vec3 color;
	glm::vec3 texcoord;
	glm::vec3 normal;
};

#endif // !VERTEX_H
