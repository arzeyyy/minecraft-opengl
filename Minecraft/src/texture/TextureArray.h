#ifndef TEXTURE_ARRAY_H
#define TEXTURE_ARRAY_H

#include <vector>

#include "Texture.h"
#include "stb_image.h"

namespace Engine 
{
	class TextureArray
	{
	public:
		TextureArray(GLenum target);

		bool loadFromFiles(const std::vector<const char *> &paths);
		void bind() const;
		void unbind() const;
	
	private:
		GLuint m_id;
		GLenum m_target;
		int m_layerCount;
	};
};

#endif // !TEXTURE_ARRAY_H