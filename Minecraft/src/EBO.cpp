#include "EBO.h"

void Engine::EBO::create()
{
	glGenBuffers(1, &EBO);
}

void Engine::EBO::bind(GLint type, void *indices, size_t size)
{
	glBindBuffer(type, EBO);
	glBufferData(type, size, indices, GL_STATIC_DRAW);
}

void Engine::EBO::destroy()
{
	glDeleteBuffers(1, &EBO);
}
