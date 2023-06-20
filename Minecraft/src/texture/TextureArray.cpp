#include "TextureArray.h"

Engine::TextureArray::TextureArray(GLenum target, int width, int height)
    : m_id(0), m_layerCount(0), m_target(target)
    , m_width(width), m_height(height)
{
    glGenTextures(1, &m_id);
    glBindTexture(m_target, m_id);
}

bool Engine::TextureArray::loadFromFiles(const std::vector<const char *> &paths)
{
    // m_layerCount assigned the number of elements in the paths vector
    m_layerCount = static_cast<int>(paths.size());

    glTexStorage3D(m_target, 1, GL_RGBA8, m_width, m_height, m_layerCount);

    for (int i = 0; i < m_layerCount; ++i)
    {
        Texture texture(0, m_target);
        if (!texture.loadFromFile(paths[i]))
        {
            return false;
        }

        glTexSubImage3D(m_target, 0, 0, 0, i, texture.getWidth(), texture.getHeight(), 1, GL_RGBA, GL_UNSIGNED_BYTE, texture.getData());
    }

    glBindTexture(m_target, 0);

    return true;
}
void Engine::TextureArray::generateMipmaps()
{
    glBindTexture(m_target, m_id);
    glGenerateMipmap(m_target);
    glBindTexture(m_target, 0);
}


//void Engine::TextureArray::generate(GLuint width, GLuint height, unsigned char *data)
//{
//    m_width = width;
//    m_height = height;
//
//    glBindTexture(GL_TEXTURE_2D_ARRAY, m_id);
//
//    // I cannot decide what the texture array layer (depth) should be (I put here is 1 for layer number)
//    //Can anyone explain to me how to decide the texture layer here? 
//    glTexImage3D(GL_TEXTURE_2D_ARRAY, 1, this->Internal_Format, m_width, m_height, 0, 1, this->Image_Format, GL_UNSIGNED_BYTE, data);
//
//    glTexParameteri(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_WRAP_S, this->Wrap_S);
//    glTexParameteri(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_WRAP_T, this->Wrap_T);
//    glTexParameteri(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_WRAP_R, this->Wrap_R);
//
//    glTexParameteri(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_MIN_FILTER, this->Filter_Min);
//    glTexParameteri(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_MIN_FILTER, this->Filter_Max);
//
//    //unbind this texture for another creating texture
//    glBindTexture(GL_TEXTURE_2D_ARRAY, 0);
//}



//void Engine::TextureArray::bind() const
//{
//    glBindTexture(m_target, m_id);
//}
//
//void Engine::TextureArray::unbind() const
//{
//    glBindTexture(m_target, 0);
//}