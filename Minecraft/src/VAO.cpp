#include "VAO.h"

void Engine::VAO::create()
{
	glGenVertexArrays(1, &VAO);
}

void Engine::VAO::bind()
{
	glBindVertexArray(VAO);
}

void Engine::VAO::unbind()
{
	glBindVertexArray(NULL);
}

void Engine::VAO::destroy()
{
	glDeleteVertexArrays(1, &VAO);
}
