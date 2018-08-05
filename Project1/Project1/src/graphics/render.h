#pragma once
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>
#include "buffers/VertexArray.h"
#include "buffers/Buffer.h"
#include "buffers/Indexbuffer.h"
#include "buffers/VertexLayout.h"
#include "shaders.h"
#include "Texture.h"

namespace blackswan {
	namespace graphics {

		class Render
		{
		private :

		public :

			Render();
			~Render();

			void Draw(const VertexArray& va , const Shader& shader, IndexBuffer& ib) const;

		};
	
	}
}