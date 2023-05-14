#ifndef VAO_H
#define VAO_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

namespace Engine
{
	class VAO
	{
	private:
		unsigned int VAO;
	public:
		void create();
		void bind();
		void unbind();
		void destroy();
	};
}


#endif // !VAO_H


