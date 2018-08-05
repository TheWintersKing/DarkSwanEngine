#pragma once
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>
#include "camera.h"

namespace blackswan {
	namespace graphics {


		class Window {
		
		private :
			
			GLFWwindow * window;
			int height, width;
			const char *title;

			float deltaTime;
			float lastFrame;

		public :

			Window(const char *title , int height , int width);

			~Window();

			void update();

			bool isClosed();

			void clear() const;

			void processInput();

			inline int getHeight() { return height; }

			inline int getWidth() { return width; }

			static void mouse_callback(GLFWwindow* window, double xpos, double ypos);
			static void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
			static void framebuffer_size_callback(GLFWwindow* window, int width, int height);
		
		private :

			bool init();

		};
	}
}