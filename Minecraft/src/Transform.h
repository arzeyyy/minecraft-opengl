#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <glm/glm.hpp>

struct Transform
{
	glm::vec3 position = glm::vec3(0.f);
	glm::vec3 rotation = glm::vec3(0.f);
	glm::vec3 localScale = glm::vec3(0.f);

	glm::vec3 up = glm::vec3(0.f, 1.f, 0.f);
	glm::vec3 forward = glm::vec3(0.f, 0.f, -1.f);
	glm::vec3 right = glm::vec3(1.f, 0.f, 0.f);
};

#endif // !TRANSFORM_H

