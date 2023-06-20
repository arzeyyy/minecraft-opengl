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
		TextureArray(GLenum target, int width, int height);

		bool loadFromFiles(const std::vector<const char *> &paths);
		void generateMipmaps();
		void generate(int width, int height);
		void bind() const;
		void unbind() const;
	
	private:
		GLuint m_id;
		GLenum m_target;
		int m_layerCount;
		int m_width, m_height;
	};
};

#endif // !TEXTURE_ARRAY_H