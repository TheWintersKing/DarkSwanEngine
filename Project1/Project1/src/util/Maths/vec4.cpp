#include "vec4.h"
#include <iostream>

namespace kevin {
	namespace maths {

		vec4::vec4()
		{
			x = 0.0f;
			y = 0.0f;
			z = 0.0f;
			w = 0.0f;
		}

		vec4::vec4(const float &x, const float &y, const float &z ,const float &w)
		{
			this->x = x;
			this->y = y;
			this->z = z;
			this->w = w;
		}

		// Vector - vector operation

		vec4& vec4::add(const vec4 &other)
		{
			x += other.x;
			y += other.y;
			z += other.z;
			w += other.w;
			return *this;
		}

		vec4& vec4::sub(const vec4 &other)
		{
			x -= other.x;
			y -= other.y;
			z -= other.z;
			w -= other.w;
			return *this;
		}

		float vec4::dotProduct(const vec4 &other)
		{
			x *= other.x;
			y *= other.y;
			z *= other.z;
			w *= other.w;
			return x + y;
		}

		// Vector - scalar operation

		vec4& vec4::scalarAdd(const float &other)
		{
			x += other;
			y += other;
			z += other;
			w += other;
			return *this;
		}

		vec4& vec4::scalarSub(const float &other)
		{
			x -= other;
			y -= other;
			z -= other;
			w -= other;
			return *this;
		}

		vec4& vec4::scalarMul(const float &other)
		{
			x *= other;
			y *= other;
			z *= other;
			w *= other;
			return *this;
		}

		vec4& vec4::scalarDiv(const float &other)
		{
			x /= other;
			y /= other;
			z /= other;
			w /= other;
			return *this;
		}

		//Operator overloads

		vec4& operator + (vec4 left, const vec4& right)
		{
			return left.add(right);
		}

		vec4& operator - (vec4 left, const vec4& right)
		{
			return left.sub(right);
		}

		vec4& operator + (vec4 left, const float& right)
		{
			return left.scalarAdd(right);
		}

		vec4& operator - (vec4 left, const float& right)
		{
			return left.scalarSub(right);
		}

		vec4& operator * (vec4 left, const float& right)
		{
			return left.scalarMul(right);
		}

		vec4& operator / (vec4 left, const float& right)
		{
			return left.scalarDiv(right);
		}

		//output stream 

		std::ostream& operator << (std::ostream& stream, const vec4& vector)
		{
			stream << "vec4 : ( " << vector.x << "," << vector.y << "," << vector.z << "," << vector.w << ")";
			return stream;
		}


	}
}