#pragma once
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace blackswan {
	namespace graphics {

		enum camera_movement
		{
			FORWARD,
			BACKWARD,
			LEFT,
			RIGHT
		};
			
		class Camera
		{
		private :
			
			glm::vec3 cameraPos;
			glm::vec3 cameraFront;
			glm::vec3 cameraUp;

			float Yaw;
			float Pitch;

			float MovementSpeed;
			float MouseSensitivity;
			float Zoom;

		public :
			
			
			Camera(glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 3.0f) ,glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f), glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f) , float yaw = -90.0f, float pitch = 0.0f);
			
			void ProcessKeyboard(camera_movement direction, float deltaTime);
			void ProcessMouseMovement(float xoffset, float yoffset, GLboolean constrainPitch = true);
			void ProcessMouseScroll(float yoffset);

			inline float getZoom() { return Zoom; }
			inline float getMouseSensitivity() { return MouseSensitivity; }
			inline float getMovementSpeed() { return MovementSpeed; }

			glm::mat4 GetViewMatrix();
			
			~Camera();

		private :

			void updateCameraVectors();
		};
	}
}