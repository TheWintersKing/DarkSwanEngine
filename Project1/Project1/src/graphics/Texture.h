#pragma once

#include "render.h"
#include "../External/stb/stb_image.h"

namespace blackswan {
	namespace graphics {
		class Texture
		{
		private:
			GLuint RenderID;
			//std::string FilePath;
			unsigned char* localBuffer;
			int width, height, BPP;

		public:
			Texture(const std::string& FilePath);
			~Texture();

			void bind(unsigned int slot = 0) const;
			void unbind() const;


			inline int getWidth() const { return width; }
			inline int getHeight() const { return height; }
		};

	}
}