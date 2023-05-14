#ifndef CAMERA_H
#define CAMERA_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>
#include <vector>

#include "Window.h"
#include "Transform.h"
#include "shaders/Shader.h"
#include "Input.h"

namespace Engine 
{
	class Camera
	{
	private:
		Window *m_window;

		glm::mat4 m_view = glm::mat4(1.0f);
		glm::mat4 m_projection = glm::mat4(1.0f);

		void UpdateUniforms(Engine::Shader *shader);

		float pitch;
		float yaw;
		float mouseX;


	public:
		Transform transform;

		glm::vec3 orientation = glm::vec3(0.f, 0.f, -1.f);

		float nearClipPlane;
		float farClipPlane;

		float fieldOfView;
		float sensitivity = 0.000000001f;

		Camera();

		void Create(Engine::Window *window);
		void Update(Engine::Shader *shader, float deltaTime);
		void Rotate(float xoffset, float yoffset);

	};
}


#endif // !CAMERA_H


