#include "mat4.h"
#include <math.h>
#include <iostream>

#define PI 3.14f


namespace kevin {
	namespace maths {

		inline float toRadians(float x) { return x * PI / 180.0f; }

		mat4::mat4()
		{
			for (int i = 0; i <= 4 * 4; i++)
				element[i] = 0.0f;
		}

		mat4::mat4(float diagonal)
		{
			for (int i = 0; i < 4 * 4; i++)
			{
				if (i == 0 || i == 5 || i == 10 || i == 15)
				{
					element[i] = diagonal;
				}
				
				else
				{
					element[i] = 0.0f;
				}
			}
		}

		mat4 mat4::identity()
		{
			return mat4(1.0f);
		}

		void mat4::mul(const mat4& other)
		{	

			float sum;
			for (int i = 0; i < 4; i++)
			{
				
				for (int j = 0; j < 4; j++)
				{
					sum = 0.0f;

					for (int k = 0; k < 4; k++)
					{
						sum = sum + (this->element[i+k*4] * other.element[k+j*4]);
					}

					this->element[i + j * 4] = sum;
				}

				
			}
			
		}

		mat4 operator * (mat4 left, const mat4& right)
		{
			left.mul(right);
			return left;
		}

		mat4 mat4::orthogaphics(float left, float right, float up, float down, float near, float far)
		{
			mat4 result(1.0f);

			result.element[0] = 2.0f / (right - left);

			result.element[5] = 2.0f / (up - down);

			result.element[10] = 2.0f / (near - far);

			result.element[12] = (right + left) / (left - right);

			result.element[13] = (down + up) / (down - up);

			result.element[14] = (far + near) / (far -near);

			return result;

		}

		mat4 mat4::prespective(float fov, float aspectratio, float near, float far)
		{
			mat4 result(1.0f);

			float q = 1.0f / tan(toRadians(0.5f * fov));
			float a = q / aspectratio;

			float b = (near + far) / (near - far);

			float c = (2.0f * near * far) / (near - far);
				
			result.element[0] = a;
			result.element[5] = q;
			result.element[10] = b;
			result.element[11] = c;
			result.element[14] = -1.0f;

			return result;

		}


		mat4 mat4::translation(const vec3&	translate)
		{
			mat4 result(1.0f);
			result.element[12] =  translate.x;
			result.element[13] = translate.y;
			result.element[14] = translate.z;
			return result;
		}

		mat4 mat4::scale(const vec3& scale)
		{
			mat4 result(1.0f);
			result.element[0] = scale.x;
			result.element[0] = scale.y;
			result.element[0] = scale.z;
			return result;
		}

		mat4 mat4::rotation(float angle, const vec3& axis)
		{
			mat4 result(1.0f);
			float r = toRadians(angle);
			float s = sin(r);
			float c = cos(r);
			float omc = 1 - c;

			result.element[0] = axis.x * omc + c;
			result.element[1] = axis.x * axis.y * omc + axis.z * s;
			result.element[2] = axis.x * axis.z * omc - axis.y * s;

			result.element[5] = axis.y * omc + c;
			result.element[4] = axis.x * axis.y * omc - axis.z * s;
			result.element[6] = axis.y * axis.z * omc + axis.x * s;

			result.element[10] = axis.z * omc + c;
			result.element[9] = axis.z * axis.y * omc - axis.x * s;
			result.element[8] = axis.x * axis.z * omc + axis.y * s;

			return result;
		}

		mat4::~mat4()
		{

		}

		std::ostream& operator << (std::ostream& stream, const mat4& matrix)
		{	
			stream << "Matrix \n";
			for (int j = 0; j < 4 ; j++)
			{
				stream << matrix.element[0 + 4 * j] << "\t" << matrix.element[1 + 4 * j] << "\t" << matrix.element[2 + 4 * j] << "\t" << matrix.element[3 + 4 * j] <<"\n";

			}
			return stream;
		}

	}
}