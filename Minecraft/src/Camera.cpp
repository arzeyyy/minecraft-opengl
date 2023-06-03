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


    // Calculates upcoming vertical change in the Orientation




    //std::cout << "mouseX: " << mouseX << std::endl;
    //std::cout << "mouseY: " << mouseY << std::endl;



	//orientation = glm::mat3(glm::rotate(glm::mat4(1.0f), glm::radians(pitch), transform.up)) * orientation;
	//
	//transform.rotation.x = pitch;




 //   // Spherical coordinates (r=1).
 //   transform.forward.x = -sin(yaw) * cos(pitch);
 //   transform.forward.y = -sin(pitch);
 //   transform.forward.z = -cos(yaw) * cos(pitch);

 //   transform.right.x = -cos(yaw);
 //   transform.right.y = 0.0;
 //   transform.right.z = sin(yaw);

 //   transform.up = cross(transform.forward, transform.right);

 //   transform.forward = normalize(transform.forward);
 //   transform.right = normalize(transform.right);
 //   transform.up = normalize(transform.up);

	//// Convert the rotation angles from degrees to radians
	//glm::vec3 rotationRadians = glm::radians(transform.rotation);

	//// Create a rotation matrix around the x, y, and z axes
	//glm::mat4 xRotation = glm::rotate(glm::mat4(1.0f), rotationRadians.x, glm::vec3(1.0f, 0.0f, 0.0f));
	//glm::mat4 yRotation = glm::rotate(glm::mat4(1.0f), rotationRadians.y, glm::vec3(0.0f, 1.0f, 0.0f));
	//glm::mat4 zRotation = glm::rotate(glm::mat4(1.0f), rotationRadians.z, glm::vec3(0.0f, 0.0f, 1.0f));

	//// Combine the rotation matrices into a single rotation matrix
	//glm::mat4 rotationMatrix = zRotation * yRotation * xRotation;

	//// Apply the rotation to the camera orientation
	//orientation = glm::vec3(rotationMatrix * glm::vec4(orientation, 1.0f));


	UpdateUniforms(shader);
}

void Engine::Camera::Rotate(float xoffset, float yoffset)
{
	//xoffset *= sensitivity;
	//yoffset *= sensitivity;

	// Movement
	//pitch += yoffset * sensitivity * deltaTime;
	//yaw += xoffset * sensitivity * deltaTime;

	yaw -= -xoffset * sensitivity;
	pitch += yoffset * sensitivity;
	std::cout << "x: " << xoffset << std::endl;
	std::cout << "y: " << yoffset << std::endl;


	//glm::clamp(pitch, -89.f, 89.f);

	//if (yaw > 360.f || yaw < -360.f)
	//	yaw = 0.f;

	transform.forward.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
	transform.forward.y = sin(glm::radians(pitch));
	transform.forward.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));

	transform.forward = glm::normalize(transform.forward);
	transform.right = glm::normalize(glm::cross(transform.forward, glm::vec3(0.f, 1.f, 0.f)));
	transform.up = glm::normalize(glm::cross(transform.right, transform.forward));


	//glm::vec2 offset;
	//orientation = glm::mat3(glm::rotate(offset, transform.up)) * orientation;

	//glm::vec3 front;
	//front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
	//front.y = sin(glm::radians(pitch));
	//front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
	//orientation = glm::normalize(front);

	//// re-calculate the Right and Up vector, cross return perpendicular vector 
	//// normalize the vectors, because their length gets closer to 0 the more you look up or down which results in slower movement.
	//transform.right = glm::normalize(glm::cross(orientation, transform.up));  	
	//transform.up = glm::normalize(glm::cross(transform.up, orientation));



	//yaw = xoffset * sensitivity;
	//pitch = yoffset * sensitivity;



	////mouseX *= sensitivity;
	////mouseY *= sensitivity;

	////yaw += mouseX;
	////pitch += mouseY;


	//glm::clamp(pitch, -90.f, 90.f);

	//glm::vec3 front;
	//front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
	//front.y = sin(glm::radians(pitch));
	//front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
	//orientation = glm::normalize(front);
	//// also re-calculate the Right and Up vector
	//transform.right = glm::normalize(glm::cross(orientation, transform.up));  // normalize the vectors, because their length gets closer to 0 the more you look up or down which results in slower movement.
	//transform.up = glm::normalize(glm::cross(transform.up, orientation));

	//std::cout << "xpos: " << transform.position.x << std::endl;
	//std::cout << "ypos: " << transform.position.y << std::endl;
	//std::cout << "x: " << orientation.x << std::endl;
	//std::cout << "y: " << orientation.y << std::endl;
}


void Engine::Camera::UpdateUniforms(Engine::Shader *shader)
{
	shader->setMat4("view", m_view);
	shader->setMat4("projection", m_projection);
}
