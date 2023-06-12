#ifndef ENTITY_H
#define ENTITY_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <vector>

#include "Transform.h"
#include "shaders/Shader.h"

class Entity
{
public:
	Entity() {
		velocity = glm::vec3(0.f);
		transform.position = glm::vec3(0.f);
		transform.rotation = glm::vec3(0.f);
	}

	Entity(const glm::vec3 &pos) {
		velocity = glm::vec3(0.f);
		transform.position = pos;
		transform.rotation = glm::vec3(0.f);
	}

	Entity(const glm::vec3 &pos, const glm::vec3 &rot) {
		velocity = glm::vec3(0.f);
		transform.position = pos;
		transform.rotation = rot;
	}

	//virtual void UpdateUniforms(Engine::Shader *shader);

	Transform transform;
	glm::vec3 velocity;

};

#endif // !ENTITY_H
