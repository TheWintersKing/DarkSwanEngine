#include "Texture.h"

namespace blackswan {
	namespace graphics {
		
		Texture::Texture(const std::string& FilePath)
			:localBuffer(nullptr)
		{
			stbi_set_flip_vertically_on_load(true);
			localBuffer = stbi_load(FilePath.c_str() , &width , &height , &BPP , 4);

			glGenTextures(1, &RenderID);
			glBindTexture(GL_TEXTURE_2D , RenderID);

			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S , GL_CLAMP_TO_BORDER);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);

			glTexImage2D(GL_TEXTURE_2D, 0 , GL_RGBA8, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE , localBuffer);
			glGenerateMipmap(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, 0);

			if (!localBuffer)
			{
				stbi_image_free(localBuffer);
			}


		}

		Texture::~Texture()
		{
			glDeleteTextures(1, &RenderID);
		}

		void Texture::bind(unsigned int slot /*=0*/) const
		{
			glActiveTexture(GL_TEXTURE0 + slot);
			glBindTexture(GL_TEXTURE_2D, RenderID);
		}

		void Texture::unbind() const
		{
			glBindTexture(GL_TEXTURE_2D, 0);
		}
	}
}