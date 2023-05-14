#ifndef VBO_H
#define VBO_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

namespace Engine 
{
	class VBO
	{
	private:
		unsigned int VBO;
	public:
		void create();
		void bind(GLint type, void *data, size_t size);
		void unbind(GLint type);
		void destroy();
	};

}


#endif // !VBO_H
