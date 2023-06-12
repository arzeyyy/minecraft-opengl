#include "TextureArray.h"

Engine::TextureArray::TextureArray(GLenum target)
    : m_id(0), m_target(target), m_layerCount(0)
{
    glGenTextures(1, &m_id);
    glBindTexture(m_target, m_id);
}

bool Engine::TextureArray::loadFromFiles(const std::vector<const char *> &paths)
{
    m_layerCount = static_cast<int>(paths.size());

    glTexStorage3D(m_target, 1, GL_RGBA8, 256, 256, m_layerCount);

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

void Engine::TextureArray::bind() const
{
    glBindTexture(m_target, m_id);
}

void Engine::TextureArray::unbind() const
{
    glBindTexture(m_target, 0);
}