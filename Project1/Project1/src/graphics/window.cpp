#include "window.h"

#define CAMERA_ON (1)

namespace blackswan {
	namespace graphics {

		Window::Window(const char *title, int height, int width)
			: deltaTime (0.0f) , lastFrame(0.0f) 
		{
			this->title = title;
			this->height = height;
			this->width = width;

			if (!init())
				glfwTerminate();
		}

#if CAMERA_ON

		void Window::mouse_callback(GLFWwindow* window, double xpos, double ypos)
		{

		}


		void Window::scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
		{

		}

#else
		void Window::mouse_callback(GLFWwindow* window, double xpos, double ypos)
		{
		}

		void Window::scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
		{
		}
#endif

		bool Window::init()
		{
			if (!glfwInit())
			{
				std::cout << "Failed to init to glfw" << std::endl;
			}

			glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
			glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
			glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

			window = glfwCreateWindow(width, height, title, NULL, NULL);

			if (window == NULL)
			{
				std::cout << "Failed to create Window" << std::endl;
				return false;
			}

			glfwMakeContextCurrent(window);
			glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
			glfwSetCursorPosCallback(window, mouse_callback);
			glfwSetScrollCallback(window, scroll_callback);

			glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

			if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
			{
				std::cout << "Failed to intialize GLAD" << std::endl;
				return false;
			}

			return true;
		}

		void Window::update()
		{
			glfwSwapBuffers(window);
			glfwPollEvents();
		}

		void Window::clear() const
		{
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		}


		bool Window::isClosed()
		{
			return glfwWindowShouldClose(window);
		}


		void Window::framebuffer_size_callback(GLFWwindow* window, int width, int height)
		{
			glViewport(0, 0, width, height);
		}

		void Window::processInput()
		{

		}

		Window::~Window()
		{
			glfwTerminate();
		}

	}
}