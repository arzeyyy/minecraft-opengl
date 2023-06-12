#ifndef TEXTURE_H
#define TEXTURE_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "stb_image.h"

namespace Engine
{
	class Texture
	{
	public:
		Texture(GLuint id, GLenum target = GL_TEXTURE_2D);
		bool loadFromFile(const char *path);
		void bind();
		void free();
		int getWidth();
		int getHeight();
		const void *getData() const;
		const char getPath();
		GLuint getID();

	private:
		GLuint m_id;
		GLenum m_target;
		const char *m_path;
		unsigned char *m_data;
		int m_width, m_height, m_bpp;
	};
}

#endif // !TEXTURE_H

