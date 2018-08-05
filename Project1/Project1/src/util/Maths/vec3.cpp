#include "vec3.h"
#include <iostream>

namespace kevin {
	namespace maths {

		vec3::vec3()
		{
			x = 0.0f;
			y = 0.0f;
			z = 0.0f;
		}

		vec3::vec3(const float &x, const float &y , const float &z)
		{
			this->x = x;
			this->y = y;
			this->z = z;
		}

		// Vector - vector operation

		vec3& vec3::add(const vec3 &other)
		{
			x += other.x;
			y += other.y;
			z += other.z;
			return *this;
		}

		vec3& vec3::sub(const vec3 &other)
		{
			x -= other.x;
			y -= other.y;
			z -= other.z;
			return *this;
		}

		float vec3::dotProduct(const vec3 &other)
		{
			x *= other.x;
			y *= other.y;
			z *= other.z;
			return x + y;
		}

	// Vector - scalar operation

		vec3& vec3::scalarAdd(const float &other)
		{
			x += other;
			y += other;
			z += other;
			return *this;
		}

		vec3& vec3::scalarSub(const float &other)
		{
			x -= other;
			y -= other;
			z -= other;
			return *this;
		}

		vec3& vec3::scalarMul(const float &other)
		{
			x *= other;
			y *= other;
			z *= other;
			return *this;
		}

		vec3& vec3::scalarDiv(const float &other)
		{
			x /= other;
			y /= other;
			z /= other;
			return *this;
		}

	//Operator overloads

		vec3& operator + (vec3 left, const vec3& right)
		{
			return left.add(right);
		}

		vec3& operator - (vec3 left, const vec3& right)
		{
			return left.sub(right);
		}

		vec3& operator + (vec3 left, const float& right)
		{
			return left.scalarAdd(right);
		}

		vec3& operator - (vec3 left, const float& right)
		{
			return left.scalarSub(right);
		}

		vec3& operator * (vec3 left, const float& right)
		{
			return left.scalarMul(right);
		}

		vec3& operator / (vec3 left, const float& right)
		{
			return left.scalarDiv(right);
		}

		//output stream 

		std::ostream& operator << (std::ostream& stream, const vec3& vector)
		{
			stream << "vec3 : ( " << vector.x << "," << vector.y << "," << vector.z << ")";
			return stream;
		}


	}
}