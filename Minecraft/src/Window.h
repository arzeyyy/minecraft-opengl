#ifndef WINDOW_H
#define WINDOW_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

namespace Engine
{
	class Window
	{
	private:
		int m_width;
		int m_height;

	public:
		Window(int screen_width, int screen_height);
		int init();
		void wireframe(bool is_wireframe);


		GLFWwindow *m_handle;
	};
}



#endif // !GAME_H




