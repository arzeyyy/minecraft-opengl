#include "TextureAtlas.h"

TextureAtlas::TextureAtlas(const std::string &textureFileName)
{
	const char *path = ("Res/Textures/" + textureFileName + ".png").c_str();

	stbi_set_flip_vertically_on_load(0);

	int width = 0, height = 0, bpp = 0;

	unsigned char *data = stbi_load(path, &width, &height, &bpp, 0);

	if (!data)
	{
		std::cout << "Can't load data from" << path << stbi_failure_reason() << std::endl;
		exit(0);
	}

	m_imageSize = 256;
	m_individualTextureSize = 16;
}

std::array<GLfloat, 8> TextureAtlas::getTexture(const glm::ivec2 &coords)
{
	static const GLfloat TEX_PER_ROW =
		(GLfloat)m_imageSize / (GLfloat)m_individualTextureSize;
	static const GLfloat INDV_TEX_SIZE = 1.0f / TEX_PER_ROW;
	static const GLfloat PIXEL_SIZE = 1.0f / (float)m_imageSize;

	GLfloat xMin = (coords.x * INDV_TEX_SIZE) + 0.5f * PIXEL_SIZE;
	GLfloat yMin = (coords.y * INDV_TEX_SIZE) + 0.5f * PIXEL_SIZE;

	GLfloat xMax = (xMin + INDV_TEX_SIZE) - PIXEL_SIZE;
	GLfloat yMax = (yMin + INDV_TEX_SIZE) - PIXEL_SIZE;

	return { xMax, yMax, xMin, yMax, xMin, yMin, xMax, yMin };
}
