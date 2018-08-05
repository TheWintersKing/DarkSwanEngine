#pragma once
#include "vec3.h"
#include "vec4.h"
#include <iostream>

namespace kevin {
	namespace maths {
		struct mat4 {

			union {
				float element[16];
				vec4 columns[4];
			};
			

			mat4();

			mat4(float diagonal);

			static mat4 identity();

			void mul(const mat4& other);

			static mat4 orthogaphics(float left, float right, float up, float down ,float near ,float far);

			static mat4 prespective(float fov , float aspectratio , float near ,float far);

			static mat4 translation(const vec3&	translate);

			static mat4 rotation(float angle , const vec3& axis);

			static mat4 scale(const vec3& scale);

			friend mat4 operator * (mat4 left,const mat4& right);

			friend std::ostream& operator << (std::ostream& stream, const mat4& matrix);

			~mat4();
		};
	}
}
