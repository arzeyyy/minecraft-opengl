#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#include "Texture.h"


Engine::Texture::Texture(GLuint id, GLenum target)
{
	m_data = 0;
	m_id = id;
	m_target = target;
}

bool Engine::Texture::loadFromFile(const char *path)
{
	m_path = path;

	stbi_set_flip_vertically_on_load(0);

	int width = 0, height = 0, bpp = 0;

	unsigned char *data = stbi_load(path, &width, &height, &bpp, 0);

	if (!data)
	{
		std::cout << "Can't load data from" << path << stbi_failure_reason() << std::endl;
		exit(0);
	}

	std::cout << "width: " << width << " height: " << height << " bits per pixel: " << bpp << std::endl;

	glGenBuffers(1, &m_id);
	glBindTexture(m_target, m_id);
	if(m_target == GL_TEXTURE_2D){
		glTexImage2D(m_target, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
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
