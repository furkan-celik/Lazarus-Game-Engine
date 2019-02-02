#pragma once
#include <iostream>

//Author: Furkan Celik Date: 20.12.2018
//this header contains every type of vectors by using inheritance. Single templated class would be harder to implement

namespace Lazarus { namespace Math {

	struct Vec2d //a 2d vector with all operators
	{
		float x, y;

		Vec2d() { x = 0, y = 0; };
		Vec2d(float _x, float _y) : x(_x), y(_y) {};

		Vec2d operator+(const Vec2d &rhs);
		Vec2d operator-(const Vec2d &rhs);
		Vec2d operator/(const Vec2d &rhs);
		Vec2d operator*(const Vec2d &rhs);

		Vec2d& operator+=(const Vec2d &rhs);
		Vec2d& operator-=(const Vec2d &rhs);
		Vec2d& operator/=(const Vec2d &rhs);
		Vec2d& operator*=(const Vec2d &rhs);

		Vec2d& operator=(const Vec2d &rhs);

		bool operator==(const Vec2d &rhs);
		bool operator<(const Vec2d &rhs);
		bool operator>(const Vec2d &rhs);
		bool operator<=(const Vec2d &rhs);
		bool operator>=(const Vec2d &rhs);
		bool operator!=(const Vec2d &rhs);

		friend std::ostream & operator<<(std::ostream & os, const Vec2d &rhs);
	};

	struct Vec3d : Vec2d //a 3d vector inherited from 2d vector with all operators
	{
		float z;

		Vec3d() : Vec2d() { z = 0; };
		Vec3d(float _x, float _y, float _z) : Vec2d(_x, _y), z(_z) {};

		Vec3d operator+(const Vec3d &rhs);
		Vec3d operator-(const Vec3d &rhs);
		Vec3d operator/(const Vec3d &rhs);
		Vec3d operator*(const Vec3d &rhs);

		Vec3d& operator+=(const Vec3d &rhs);
		Vec3d& operator-=(const Vec3d &rhs);
		Vec3d& operator/=(const Vec3d &rhs);
		Vec3d& operator*=(const Vec3d &rhs);

		Vec3d& operator=(const Vec3d &rhs);

		bool operator==(const Vec3d &rhs);
		bool operator<(const Vec3d &rhs);
		bool operator>(const Vec3d &rhs);
		bool operator<=(const Vec3d &rhs);
		bool operator>=(const Vec3d &rhs);
		bool operator!=(const Vec3d &rhs);

		friend std::ostream & operator<<(std::ostream & os, const Vec3d &rhs);
	};

	struct Vec4d : Vec3d //a 4d vector inherited from 3d vector with all operators
	{
		float w;

		Vec4d() : Vec3d() { w = 0; };
		Vec4d(float _x, float _y, float _z, float _w) : Vec3d(_x, _y, _z), w(_w) {};

		Vec4d operator+(const Vec4d &rhs);
		Vec4d operator-(const Vec4d &rhs);
		Vec4d operator/(const Vec4d &rhs);
		Vec4d operator*(const Vec4d &rhs);

		Vec4d& operator+=(const Vec4d &rhs);
		Vec4d& operator-=(const Vec4d &rhs);
		Vec4d& operator/=(const Vec4d &rhs);
		Vec4d& operator*=(const Vec4d &rhs);

		Vec4d& operator=(const Vec4d &rhs);

		bool operator==(const Vec4d &rhs);
		bool operator<(const Vec4d &rhs);
		bool operator>(const Vec4d &rhs);
		bool operator<=(const Vec4d &rhs);
		bool operator>=(const Vec4d &rhs);
		bool operator!=(const Vec4d &rhs);

		friend std::ostream & operator<<(std::ostream & os, const Vec4d &rhs);
	};

} }