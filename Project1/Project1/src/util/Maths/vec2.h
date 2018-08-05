#pragma once
#include <iostream>

namespace kevin {
	namespace maths
	{
		struct vec2
		{
			float x, y;

			vec2();

			vec2(const float &x , const float &y);

			vec2& add(const vec2 &other);

			vec2& sub(const vec2 &other);

			vec2& scalarAdd(const float &other);

			vec2& scalarSub(const float &other);

			vec2& scalarMul(const float &other);

			vec2& scalarDiv(const float &other);

			float dotProduct(const vec2 &other);

			float magnititude();

			//vec2& crossProduct(const vec2 &other);

			friend vec2& operator + (vec2 left, const vec2& right);

			friend vec2& operator - (vec2 left, const vec2& right);

			friend vec2& operator + (vec2 left, const float& right);

			friend vec2& operator - (vec2 left, const float& right);
			
			friend vec2& operator * (vec2 left, const float& right);

			friend vec2& operator / (vec2 left, const float& right);

			friend std::ostream& operator << (std::ostream& stream, const vec2& vector);

		};
	}
}
