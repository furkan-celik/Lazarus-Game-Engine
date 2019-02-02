#include "mat4.h"

//Author: Furkan Celik Date: 21.12.2018

namespace Lazarus { namespace Math {

	Mat4::Mat4() {
		for (int i = 0; i < 16; i++) { //initializing every element of elements array to 0. Used for loop instead of memset for simplicity
			elements[i] = 0;
		}
	}

	Mat4::Mat4(float diagonal) { //initializing every element of elements array to 0 and then assigning diagonal value to diagonal elements of elements matrix
		for (int i = 0; i < 16; i++) {
			elements[i] = 0.0f;
		}
		elements[0 + 0 * 4] = diagonal; //opengl uses matrix as column based matrices so numbering elements will be higher by going down. Visualization is bellow
		elements[1 + 1 * 4] = diagonal; //format is y + x * 4 for reaching correct element of matrix. This rule will be used to determine correct element
		elements[2 + 2 * 4] = diagonal;
		elements[3 + 3 * 4] = diagonal;
		//x0	x4	x8		x12
		//x1	x5	x9		x13
		//x2	x6	x10		x14
		//x3	x7	x11		x15
	}

	Mat4 Mat4::identity() //returning diagonal constructor with 1.0f since this is identity matrix
	{
		return Mat4(1.0f);
	}

	Mat4 Mat4::operator*(const Mat4 & rhs) //mutiplies every element of this elements array with rhs's elements array by multiplication of matrices rule
	{
		Mat4 result(0.0f);
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				float sum = 0.0f;
				for (int e = 0; e < 4; e++) {
					sum += elements[j + e * 4] * rhs.elements[e + i * 4];
				}
				result.elements[j + i * 4] = sum;
			}
		}
		return result;
	}

	Mat4& Mat4::operator*=(const Mat4 & rhs) //calling operator * by multipliying this with rhs and assigning to this
	{
		return (*this) = (*this) * rhs;
	}

	Mat4 & Mat4::operator=(const Mat4 & rhs) //I don't want to operation equality to be controlled by default constructor so I decleared my own operator which iterates through both matrices and assigns value
	{
		// TODO: insert return statement here
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				elements[j + i * 4] = rhs.elements[j + i * 4];
			}
		}
		return (*this);
	}

	Mat4 Mat4::orthographic(float _left, float _right, float _bottom, float _top, float _near, float _far) //creating orthographic matrix by impliying rule
	{
		Mat4 result(1.0f);
		
		result.elements[0 + 0 * 4] = 2.0f / (_right - _left);

		result.elements[1 + 1 * 4] = 2.0f / (_top - _bottom);

		result.elements[2 + 2 * 4] = 2.0f / (_near - _far);

		result.elements[0 + 3 * 4] = (_left + _right) / (_left - _right);

		result.elements[1 + 3 * 4] = (_bottom + _top) / (_bottom - _top);

		result.elements[2 + 3 * 4] = (_far + _near) / (_far - _near);

		return result;
	}

	Mat4 Mat4::perspective(float _fov, float _aspectRatio, float _near, float _far) //creating perspective matrix by impliying rule
	{
		Mat4 result(1.0f);

		float q = 1.0f / tan(toRadians(0.5f * _fov)), a = q / _aspectRatio, b = (_near + _far) / (_near - _far), c = (2.0f * _near * _far) / (_near - _far);

		result.elements[0 + 0 * 4] = a;
		result.elements[1 + 1 * 4] = q;
		result.elements[2 + 2 * 4] = b;
		result.elements[3 + 2 * 4] = -1.0f;
		result.elements[2 + 3 * 4] = c;

		return result;
	}

	Mat4 Mat4::translation(const Vec3d & _translation) //creating translation matrix by impliying rule
	{
		Mat4 result(1.0f);

		result.elements[0 + 3 * 4] = _translation.x;
		result.elements[1 + 3 * 4] = _translation.y;
		result.elements[2 + 3 * 4] = _translation.z;

		return result;
	}

	Mat4 Mat4::rotation(float _angle, const Vec3d & _axis) //creating rotation matrix by impliying rule
	{
		Mat4 result(1.0f);

		float r = toRadians(_angle), c = cos(r), s = sin(r), omc = 1.0f - c;
		float x = _axis.x, y = _axis.y, z = _axis.z;

		result.elements[0 + 0 * 4] = x * omc + c;
		result.elements[1 + 0 * 4] = y * x * omc + z * s;
		result.elements[2 + 0 * 4] = z * x * omc - y * s;

		result.elements[0 + 1 * 4] = y * x * omc - z * s;
		result.elements[1 + 1 * 4] = y * omc + c;
		result.elements[2 + 1 * 4] = y * z * omc + x * s;

		result.elements[0 + 2 * 4] = z * x * omc + y * s;
		result.elements[1 + 2 * 4] = y * z * omc - x * s;
		result.elements[2 + 2 * 4] = z * omc + c;

		return result;
	}

	Mat4 Mat4::scale(const Vec3d & _scale) //creating scale matrix by impliying rule
	{
		Mat4 result(1.0f);

		result.elements[0 + 0 * 4] = _scale.x;
		result.elements[1 + 1 * 4] = _scale.y;
		result.elements[2 + 2 * 4] = _scale.z;

		return result;
	}

	float toRadians(float degrees) { //multiplying degrees to pi/180.0f since this value will be equivalent value of degree in radians
		return degrees * (M_PI / 180.0f);
	}

} }