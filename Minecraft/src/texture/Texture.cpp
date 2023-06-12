#define STB_IMAGE_IMPLEMENTATION

#include "Texture.h"

Engine::Texture::Texture(GLuint id, GLenum target)
	: m_data(0), m_path(0), m_id(id), m_target(target)
	, m_width(0), m_height(0), m_bpp(0)
{
}

bool Engine::Texture::loadFromFile(const char *path)
{
	m_path = path;

	stbi_set_flip_vertically_on_load(0);


	unsigned char *data = stbi_load(path, &m_width, &m_height, &m_bpp, 0);

	if (!data)
	{
		std::cout << "Can't load data from" << path << stbi_failure_reason() << std::endl;
		exit(0);
	}

	std::cout << "width: " << m_width << " height: " << m_height << " bits per pixel: " << m_bpp << std::endl;

	glGenBuffers(1, &m_id);
	glBindTexture(m_target, m_id);
	if(m_target == GL_TEXTURE_2D){
		glTexImage2D(m_target, 0, GL_RGBA, m_width, m_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
	} else{
		std::cout << "support for the texture target " << m_target << "is not implemented" << std::endl;
		exit(1);
	}

	glTexParameterf(m_target, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameterf(m_target, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameterf(m_target, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameterf(m_target, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);


	glBindTexture(m_target, 0);

	stbi_image_free(data);

	return true;
}

void Engine::Texture::bind()
{
	glBindTexture(m_target, m_id);
}

int Engine::Texture::getWidth()
{
	return m_width;
}

int Engine::Texture::getHeight()
{
	return m_height;
}

const void *Engine::Texture::getData() const
{
	return m_data;
}

GLuint Engine::Texture::getID() 
{
	return m_id;
}

const char Engine::Texture::getPath() 
{
	return *m_path;
}
