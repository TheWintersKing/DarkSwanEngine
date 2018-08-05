#include "src/graphics/window.h"
#include "src/graphics/shaders.h" 
#include "src/graphics/buffers/Buffer.h"
#include "src/graphics/buffers/Indexbuffer.h"
#include "src/graphics/buffers/VertexArray.h"
#include "src/graphics/render.h"
#include "src/graphics/Texture.h"
#include <cmath>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>



int main(void)
{
	using namespace blackswan;
	using namespace graphics;

	GLfloat vertices[] = {

		// front
		-1.0f, -1.0f,  1.0f, 0.0f, 0.0f,
		1.0f, -1.0f,  1.0f, 1.0f, 0.0f,
		1.0f,  1.0f,  1.0f, 1.0f, 1.0f,
		-1.0f,  1.0f,  1.0f, 0.0f, 1.0f,

		// back
		-1.0f, -1.0f, -1.0f, 0.0f, 0.0f,
		1.0f, -1.0f, -1.0f, 1.0f, 0.0f,
		1.0f,  1.0f, -1.0f, 1.0f, 1.0f,
		-1.0f,  1.0f, -1.0f, 0.0f, 1.0f
	};

	GLfloat texcoords[] = {
		// front
		0.0f, 0.0f
	};

	GLuint indices[] = 
	{
		// front
		0, 1, 2,
		2, 3, 0,
		// right
		1, 5, 6,
		6, 2, 1,
		// back
		7, 6, 5,
		5, 4, 7,
		// left
		4, 0, 3,
		3, 7, 4,
		// bottom
		4, 5, 1,
		1, 0, 4,
		// top
		3, 2, 6,
		6, 7, 3,
	};

	
	Window window( "Test" , 600 , 800 );

	Camera camera;

	Render render;

	VertexArray vao;
	
	Buffer vbo(vertices , 8 * 5 * sizeof(GLfloat));
	
	VertexLayout layout;

	layout.Push<GLfloat>(3);
	layout.Push<GLfloat>(2);
	
	vao.addBuffers(vbo, layout);

	IndexBuffer ibo(indices, 3 * 12);

	Shader shade("res/shaders/basic.vert", "res/shaders/basic.frag");

	Texture texture1("res/textures/img.jpg");
	Texture texture2("res/textures/img.png");

	vbo.unbind();
	ibo.unbind();
	vao.unbind();

	while (!window.isClosed()) 
	{
		auto timeValue = glfwGetTime();
		auto greenValue = sin(timeValue) / 2.0f + 1.0f;
		window.clear();
		render.Draw(vao, shade ,ibo);

		texture1.bind(0);
		texture2.bind(1);

		shade.setUniform1i("ourTex1", 0);
		shade.setUniform1i("ourTex2", 1);
		shade.setUniform4f("ourColor", greenValue + 0.2f, greenValue - 0.1f , greenValue + 0.0f, 1.0f);
		
		glm::mat4 model;
		glm::mat4 view;
		glm::mat4 projection;
		
		model = glm::rotate(model, (float)glfwGetTime(), glm::vec3(0.5f, 1.0f, 0.0f));
		view = glm::translate(view, glm::vec3(0.0f, 0.0f, -10.0f));
		projection = glm::perspective(glm::radians(45.0f), (float)window.getHeight() / (float)window.getWidth(), 0.1f, 100.0f);

		shade.setUniformMAT4f("model" , model);
		shade.setUniformMAT4f("view", view);
		shade.setUniformMAT4f("projection", projection);

		window.update();
	}

	shade.disable();
}

