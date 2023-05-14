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


	public:
		GLFWwindow *m_handle;

		int m_width;
		int m_height;

		Window(int screen_width, int screen_height);
		int init();
		void wireframe(bool is_wireframe);

	};
}

#endif // !GAME_H




