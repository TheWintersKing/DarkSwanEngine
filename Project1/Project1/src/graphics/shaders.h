#pragma once
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>
#include <fstream>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace blackswan {
	namespace graphics {

		class Shader {
		
		private :

			GLuint ProgramID;

		public :

			Shader(const std::string& vertpath, const std ::string& fragpath);
			~Shader();

			void setUniform3f(const std::string& name, float v1, float v2, float v3);
			void setUniform4f(const std::string& name, float v1, float v2, float v3, float v4);
			void setUniform1i(const std::string& name, int value);
			void setUniformMAT4f(const std::string& name, const glm::mat4 &mat);


			int getUniformLocation(const std::string& name);

			void enable() const;
			void disable() const;

		private :

			static GLuint CompileShader(GLenum type, const std::string& source);
			static std::string PraserShader(const std::string& filepath);

		};
	}
}