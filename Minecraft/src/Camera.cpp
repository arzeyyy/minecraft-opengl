#include "Camera.h"

Engine::Camera::Camera() 
{
	fieldOfView = 45.f;
	nearClipPlane = 0.1f;
	farClipPlane = 100.0f;
	transform.position = glm::vec3(0.f, 0.f, 0.f);
	transform.position = glm::vec3(0.f, 0.f, 0.f);
}

void Engine::Camera::Create(Engine::Window *window)
{
    m_window = window;
	transform.position = glm::vec3(0.0f, 0.0f, 3.0f);
}

void Engine::Camera::Update(Engine::Shader *shader, float deltaTime)
{
	m_view = glm::lookAt(transform.position, transform.position + transform.forward, transform.up);
	m_projection = glm::perspective(glm::radians(fieldOfView), (float)m_window->m_width / (float)m_window->m_height, nearClipPlane, farClipPlane);

	UpdateUniforms(shader);
}

void Engine::Camera::Rotate(float xoffset, float yoffset)
{
	// Movement
	m_yaw -= -xoffset * sensitivity;
	m_pitch += yoffset * sensitivity;

	std::cout << "x: " << xoffset << std::endl;
	std::cout << "y: " << yoffset << std::endl;

	glm::clamp(m_pitch, -89.f, 89.f);

	//if (yaw > 360.f || yaw < -360.f)
	//	yaw = 0.f;

	transform.forward.x = cos(glm::radians(m_yaw)) * cos(glm::radians(m_pitch));
	transform.forward.y = sin(glm::radians(m_pitch));
	transform.forward.z = sin(glm::radians(m_yaw)) * cos(glm::radians(m_pitch));

	transform.forward = glm::normalize(transform.forward);
	transform.right = glm::normalize(glm::cross(transform.forward, glm::vec3(0.f, 1.f, 0.f)));
	transform.up = glm::normalize(glm::cross(transform.right, transform.forward));
}


void Engine::Camera::UpdateUniforms(Engine::Shader *shader) 
{
	shader->setMat4("view", m_view);
	shader->setMat4("projection", m_projection);
}
