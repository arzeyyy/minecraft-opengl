#ifndef TEXTURE_H
#define TEXTURE_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>


namespace Engine
{
	class Texture
	{
	private:
		GLenum m_target;
		unsigned char *m_data;
		//unsigned char *data;
		//int width;
		//int height;
		//int nrChannels;
		//unsigned int texture;

	public:
		//Texture(const char *path, GLint type, GLint mmLevel = 0);
		////void set(const char *path, GLint type, GLint mmLevel = 0);
		//void bind(GLint type);
		Texture(const char *path, const char *name, GLenum target);
		bool load();
		void bind();
		void free();


		GLuint m_id;
		const char *m_path;
		const char *m_name;
	};
}


#endif // !TEXTURE_H

