#include "render.h"

namespace blackswan {
	namespace graphics {

		Render::Render()
		{
			glEnable(GL_BLEND);
			glEnable(GL_DEPTH_TEST);
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
			glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		}

		Render::~Render()
		{
			glDisable(GL_BLEND);
			glDisable(GL_DEPTH_TEST);
		}


		void Render::Draw(const VertexArray& va, const Shader& shader , IndexBuffer& ib) const
		{
			shader.enable();
			va.bind();
			ib.bind();
			glDrawElements(GL_TRIANGLES, ib.getCount() , GL_UNSIGNED_INT, NULL);
		}

		
	}
}