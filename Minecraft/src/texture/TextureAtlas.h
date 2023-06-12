#ifndef TEXTURE_ATLAS_H
#define TEXTURE_ATLAS_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <iostream>

#include "stb_image.h"
#include <array>

class TextureAtlas
{	
public:
    TextureAtlas(const std::string &textureFileName);
    std::array<GLfloat, 8> getTexture(const glm::ivec2 &coords);

private:
    int m_imageSize;
    int m_individualTextureSize;
};

#endif // !TEXTURE_ATLAS_H
