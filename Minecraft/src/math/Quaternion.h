#ifndef QUATERNION_H
#define QUATERNION_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>
#include <vector>


class Quaternion
{
public:
	void axisAngle(glm::vec3 axis, float angle);
	void euler(float pitch, float yaw, float roll);


public:
	float x, y, z, w;
};


#endif // !QUATERNION_H
