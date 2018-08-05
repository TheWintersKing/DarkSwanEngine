#pragma once

#pragma once
#include <iostream>

namespace kevin {
	namespace maths
	{
		struct vec3
		{
			float x, y ,z;

			vec3();

			vec3(const float &x, const float &y , const float &z);

			vec3& add(const vec3 &other);

			vec3& sub(const vec3 &other);

			vec3& scalarAdd(const float &other);

			vec3& scalarSub(const float &other);

			vec3& scalarMul(const float &other);

			vec3& scalarDiv(const float &other);

			float dotProduct(const vec3 &other);

			//vec3& crossProduct(const vec3 &other);

			friend vec3& operator + (vec3 left, const vec3& right);

			friend vec3& operator - (vec3 left, const vec3& right);

			friend vec3& operator + (vec3 left, const float& right);

			friend vec3& operator - (vec3 left, const float& right);

			friend vec3& operator * (vec3 left, const float& right);

			friend vec3& operator / (vec3 left, const float& right);

			friend std::ostream& operator << (std::ostream& stream, const vec3& vector);

		};
	}
}
