#pragma once

#pragma once
#include <iostream>

namespace kevin {
	namespace maths
	{
		struct vec4
		{
			float x, y, z , w;

			vec4();

			vec4(const float &x, const float &y, const float &z , const float &w);

			vec4& add(const vec4 &other);

			vec4& sub(const vec4 &other);

			vec4& scalarAdd(const float &other);

			vec4& scalarSub(const float &other);

			vec4& scalarMul(const float &other);

			vec4& scalarDiv(const float &other);

			float dotProduct(const vec4 &other);

			//vec4& crossProduct(const vec4 &other);

			friend vec4& operator + (vec4 left, const vec4& right);

			friend vec4& operator - (vec4 left, const vec4& right);

			friend vec4& operator + (vec4 left, const float& right);

			friend vec4& operator - (vec4 left, const float& right);

			friend vec4& operator * (vec4 left, const float& right);

			friend vec4& operator / (vec4 left, const float& right);

			friend std::ostream& operator << (std::ostream& stream, const vec4& vector);

		};
	}
}
