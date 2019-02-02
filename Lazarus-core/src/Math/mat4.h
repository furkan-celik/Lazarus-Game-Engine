#pragma once
#define _USE_MATH_DEFINES
#include "../Math/Vectors.h"
#include <math.h>

//Author: Furkan Celik Date: 21.12.2018

namespace Lazarus { namespace Math {

	struct Mat4 //this class will hold 4x4 matrices
	{
		union //using union so we can reach elements of matrix by using both float array and Vec4d class. Since both will have 16 bytes, union is not hard to do
		{
			float elements[4 * 4];
			Vec4d columns[4];
		};

		Mat4();
		Mat4(float diagonal); //to assign diagonal elements to given value

		static Mat4 identity(); //returning identity matrix. This function is static because I want to create an identity matrix without initializing any Mat4 object

		Mat4 operator*(const Mat4& rhs); //operator * for 2 Mat4 object
		Mat4& operator*=(const Mat4& rhs); //operator * for 2 Mat4 object. Simply calls operator * to reduce code duplication
		Mat4& operator=(const Mat4& rhs); //assigns valuse of rhs to lhs (this)

		static Mat4 orthographic(float _left, float _right, float _bottom, float _top, float _near, float _far); //creating orthographic matrix. This will be handy in camera creation
		static Mat4 perspective(float _fov, float _aspectRatio, float _near, float _far); //creating perespective matrix. This will be handy in camera creation

		static Mat4 translation(const Vec3d& _translation); //creating translation matrix for Vec3d objects. This will return moved version of given Vec3d as Mat4
		static Mat4 rotation(float _angle, const Vec3d& _axis); //creating rotation matrix for given angle for Vec3d object. This will return rotated version of given Vec3d as Mat4
		static Mat4 scale(const Vec3d& _scale); //scaling matrix of given Vec3d
	};

	float toRadians(float degrees); //this free function will be used in translation and rotation functions to convert degrees to radians. This will reduce code duplication since conversion will be used multiple time
} }