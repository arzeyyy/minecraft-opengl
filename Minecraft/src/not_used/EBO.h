#ifndef EBO_H
#define EBO_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

namespace Engine 
{
	class EBO
	{
	private:
		unsigned int EBO;

	public:
		void create();
		void bind(GLint type, void *indices, size_t size);
		void destroy();
	};

}


#endif // !EBO_H
