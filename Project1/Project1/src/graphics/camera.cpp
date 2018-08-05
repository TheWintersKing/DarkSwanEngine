#include "camera.h"

namespace blackswan {
	namespace graphics {

		Camera::Camera(glm::vec3 cameraPos, glm::vec3 cameraFront, glm::vec3 cameraUp , float Yaw, float Pitch)
			: MovementSpeed(2.5f), MouseSensitivity(0.1f), Zoom(45.0f)
		{
			this->cameraPos = cameraPos;
			this->cameraFront = cameraFront;
			this->cameraUp = cameraUp;
			this->Yaw = Yaw;
			this->Pitch = Pitch;
			updateCameraVectors();
		}

		glm::mat4 Camera::GetViewMatrix()
		{
			return glm::lookAt(cameraPos , cameraFront + cameraPos , cameraUp);
		}

		void Camera::ProcessKeyboard(camera_movement direction, float deltaTime)
		{
			float velocity = MovementSpeed * deltaTime;
			if (direction == FORWARD)
				cameraPos += cameraFront * velocity;
			if (direction == BACKWARD)
				cameraPos -= cameraFront * velocity;
			if (direction == LEFT)
				cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * velocity;
			if (direction == RIGHT)
				cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * velocity;
		}

		void Camera::ProcessMouseMovement(float xoffset, float yoffset, GLboolean constrainPitch)
		{
			xoffset *= MouseSensitivity;
			yoffset *= MouseSensitivity;

			Yaw += xoffset;
			Pitch += yoffset;

			if (constrainPitch)
			{
				if (Pitch > 89.0f)
					Pitch = 89.0f;
				if (Pitch < -89.0f)
					Pitch = -89.0f;
			}

			updateCameraVectors();

		}

		void Camera::ProcessMouseScroll(float yoffset)
		{
			if (Zoom >= 1.0f && Zoom <= 45.0f)
				Zoom -= yoffset;
			if (Zoom <= 1.0f)
				Zoom = 1.0f;
			if (Zoom >= 45.0f)
				Zoom = 45.0f;
		}

		void Camera::updateCameraVectors()
		{
			glm::vec3 front;
			front.x = cos(glm::radians(Yaw)) * cos(glm::radians(Pitch));
			front.y = sin(glm::radians(Pitch));
			front.z = sin(glm::radians(Yaw)) * cos(glm::radians(Pitch));
			cameraFront = glm::normalize(front);

		}

		Camera::~Camera()
		{
		}

	}
}