#include "vec2.h"
#include <iostream>

namespace kevin{
	namespace maths {

		vec2::vec2()
		{
			x = 0.0f;
			y = 0.0f;
		}

		vec2::vec2(const float &x, const float &y)
		{
			this->x = x;
			this->y = y;
		}

// Vector - vector operation

		vec2& vec2::add(const vec2 &other)
		{
			x += other.x;
			y += other.y;
			return *this;
		}

		vec2& vec2::sub(const vec2 &other)
		{
			x -= other.x;
			y -= other.y;
			return *this;
		}

		float vec2::dotProduct(const vec2 &other)
		{
			x *= other.x;
			y *= other.y;
			return x + y;
		}

// Vector - scalar operation

		vec2& vec2::scalarAdd(const float &other)
		{
			x += other;
			y += other;
			return *this;
		}

		vec2& vec2::scalarSub(const float &other)
		{
			x -= other;
			y -= other;
			return *this;
		}

		vec2& vec2::scalarMul(const float &other)
		{
			x *= other;
			y *= other;
			return *this;
		}

		vec2& vec2::scalarDiv(const float &other)
		{
			x /= other;
			y /= other;
			return *this;
		}

		float vec2 :: magnititude()
		{
			return x + y;
		}

//Operator overloads

		vec2& operator + (vec2 left , const vec2& right)
		{
			return left.add(right);
		}

		vec2& operator - (vec2 left, const vec2& right)
		{
			return left.sub(right);
		}

		vec2& operator + (vec2 left, const float& right)
		{
			return left.scalarAdd(right);
		}

		vec2& operator - (vec2 left, const float& right)
		{
			return left.scalarSub(right);
		}

		vec2& operator * (vec2 left, const float& right)
		{
			return left.scalarMul(right);
		}

		vec2& operator / (vec2 left, const float& right)
		{
			return left.scalarDiv(right);
		}

//output stream 

		std::ostream& operator << (std::ostream& stream, const vec2& vector)
		{
			stream << "vec2 : ( " << vector.x << "," << vector.y << ")";
			return stream;
		}

	
	}
}