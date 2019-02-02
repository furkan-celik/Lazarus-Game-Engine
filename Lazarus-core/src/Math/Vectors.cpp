#include "Vectors.h"

//Author: Furkan Celik Date: 20.12.2018
//All vectors has the same functions which serves the same functionality and extended implementation, therefore only Vec2d commented

namespace Lazarus { namespace Math {

#pragma region Vec2d

	Vec2d Vec2d::operator+(const Vec2d &rhs) { //adds rhs's x and y to this's x and y and assigns them to result to return
		Vec2d result;
		result.x = x + rhs.x;
		result.y = y + rhs.y;
		return result;
	}

	Vec2d Vec2d::operator-(const Vec2d &rhs) { //subtracts rhs's x and y from this's x and y and assigns them to result to return
		Vec2d result;
		result.x = x - rhs.x;
		result.y = y - rhs.y;
		return result;
	}

	Vec2d Vec2d::operator/(const Vec2d &rhs) { //divides rhs's x and y from this's x and y and assigns them to result to return
		Vec2d result;
		result.x = x / rhs.x;
		result.y = y / rhs.y;
		return result;
	}

	Vec2d Vec2d::operator*(const Vec2d &rhs) { //multiplies rhs's x and y with this's x and y and assigns them to result to return
		Vec2d result;
		result.x = x * rhs.x;
		result.y = y * rhs.y;
		return result;
	}

	Vec2d& Vec2d::operator+=(const Vec2d &rhs) { //adds rhs's x and y to this's x and y. Does not call operator + for saving memory (operator+ will create a new vec2d which will allocate memory). Returning reference will also save from memory for operation with equality
		x += rhs.x;
		y += rhs.y;
		return (*this);
	}

	Vec2d& Vec2d::operator-=(const Vec2d &rhs) { //subtracts rhs's x and y to this's x and y. Does not call operator + for saving memory (operator- will create a new vec2d which will allocate memory)
		x -= rhs.x;
		y -= rhs.y;
		return (*this);
	}

	Vec2d& Vec2d::operator/=(const Vec2d &rhs) { //divides rhs's x and y to this's x and y. Does not call operator + for saving memory (operator/ will create a new vec2d which will allocate memory)
		x /= rhs.x;
		y /= rhs.y;
		return (*this);
	}

	Vec2d& Vec2d::operator*=(const Vec2d &rhs) { //multiplies rhs's x and y to this's x and y. Does not call operator + for saving memory (operator* will create a new vec2d which will allocate memory)
		x *= rhs.x;
		y *= rhs.y;
		return (*this);
	}

	Vec2d& Vec2d::operator=(const Vec2d &rhs) { //assigns rhs's x and y values to this's ones
		x = rhs.x;
		y = rhs.y;
		return (*this);
	}

	bool Vec2d::operator==(const Vec2d & rhs) //returns if both x and y of both this and rhs is equals or not
	{
		return x == rhs.x && y == rhs.y;
	}

	bool Vec2d::operator<(const Vec2d & rhs) //returns if both x and y of this is smaller than rhs's ones
	{
		return x < rhs.x && y < rhs.y;
	}

	bool Vec2d::operator>(const Vec2d & rhs) //returns if both x and y of this is greater than rhs's ones
	{
		return x > rhs.x && y > rhs.y;
	}

	bool Vec2d::operator<=(const Vec2d & rhs) //returns if this is not greater than rhs since this will be this is smaller or equal to rhs. This done to reduce code duplication
	{
		return !((*this) > rhs);
	}

	bool Vec2d::operator>=(const Vec2d & rhs) //returns if this is not smaller than rhs since this will be this is greater or equal to rhs. This done to reduce code duplication
	{
		return !((*this) < rhs);
	}

	bool Vec2d::operator!=(const Vec2d & rhs) //returns if this is not equal to rhs since this will be this is not equal to rhs. This done to reduce code duplication
	{
		return !((*this) == rhs);
	}

#pragma endregion

#pragma region Vec3d

	Vec3d Vec3d::operator+(const Vec3d &rhs) {
		Vec3d result;
		result.x = x + rhs.x;
		result.y = y + rhs.y;
		result.z = z + rhs.z;
		return result;
	}

	Vec3d Vec3d::operator-(const Vec3d &rhs) {
		Vec3d result;
		result.x = x - rhs.x;
		result.y = y - rhs.y;
		result.z = z - rhs.z;
		return result;
	}

	Vec3d Vec3d::operator/(const Vec3d &rhs) {
		Vec3d result;
		result.x = x / rhs.x;
		result.y = y / rhs.y;
		result.z = z / rhs.z;
		return result;
	}

	Vec3d Vec3d::operator*(const Vec3d &rhs) {
		Vec3d result;
		result.x = x * rhs.x;
		result.y = y * rhs.y;
		result.z = z * rhs.z;
		return result;
	}

	Vec3d& Vec3d::operator+=(const Vec3d &rhs) {
		x += rhs.x;
		y += rhs.y;
		z += rhs.z;
		return (*this);
	}

	Vec3d& Vec3d::operator-=(const Vec3d &rhs) {
		x -= rhs.x;
		y -= rhs.y;
		z -= rhs.z;
		return (*this);
	}

	Vec3d& Vec3d::operator/=(const Vec3d &rhs) {
		x /= rhs.x;
		y /= rhs.y;
		z /= rhs.z;
		return (*this);
	}

	Vec3d& Vec3d::operator*=(const Vec3d &rhs) {
		x *= rhs.x;
		y *= rhs.y;
		z *= rhs.z;
		return (*this);
	}

	Vec3d& Vec3d::operator=(const Vec3d &rhs) {
		x = rhs.x;
		y = rhs.y;
		z = rhs.z;
		return (*this);
	}

	bool Vec3d::operator==(const Vec3d & rhs)
	{
		return x == rhs.x && y == rhs.y && z == rhs.z;
	}

	bool Vec3d::operator<(const Vec3d & rhs)
	{
		return x < rhs.x && y < rhs.y && z < rhs.z;
	}

	bool Vec3d::operator>(const Vec3d & rhs)
	{
		return x > rhs.x && y > rhs.y && z > rhs.z;
	}

	bool Vec3d::operator<=(const Vec3d & rhs)
	{
		return !((*this) > rhs);
	}

	bool Vec3d::operator>=(const Vec3d & rhs)
	{
		return !((*this) < rhs);
	}

	bool Vec3d::operator!=(const Vec3d & rhs)
	{
		return !((*this) == rhs);
	}

#pragma endregion

#pragma region Ved4d
	Vec4d Vec4d::operator+(const Vec4d &rhs) {
		Vec4d result;
		result.x = x + rhs.x;
		result.y = y + rhs.y;
		result.z = z + rhs.z;
		result.w = w + rhs.w;
		return result;
	}

	Vec4d Vec4d::operator-(const Vec4d &rhs) {
		Vec4d result;
		result.x = x - rhs.x;
		result.y = y - rhs.y;
		result.z = z - rhs.z;
		result.w = w - rhs.w;
		return result;
	}

	Vec4d Vec4d::operator/(const Vec4d &rhs) {
		Vec4d result;
		result.x = x / rhs.x;
		result.y = y / rhs.y;
		result.z = z / rhs.z;
		result.w = w / rhs.w;
		return result;
	}

	Vec4d Vec4d::operator*(const Vec4d &rhs) {
		Vec4d result;
		result.x = x * rhs.x;
		result.y = y * rhs.y;
		result.z = z * rhs.z;
		result.w = w * rhs.w;
		return result;
	}

	Vec4d& Vec4d::operator+=(const Vec4d &rhs) {
		x += rhs.x;
		y += rhs.y;
		z += rhs.z;
		w += rhs.w;
		return (*this);
	}

	Vec4d& Vec4d::operator-=(const Vec4d &rhs) {
		x -= rhs.x;
		y -= rhs.y;
		z -= rhs.z;
		w -= rhs.w;
		return (*this);
	}

	Vec4d& Vec4d::operator/=(const Vec4d &rhs) {
		x /= rhs.x;
		y /= rhs.y;
		z /= rhs.z;
		w /= rhs.w;
		return (*this);
	}

	Vec4d& Vec4d::operator*=(const Vec4d &rhs) {
		x *= rhs.x;
		y *= rhs.y;
		z *= rhs.z;
		w *= rhs.w;
		return (*this);
	}

	Vec4d& Vec4d::operator=(const Vec4d &rhs) {
		x = rhs.x;
		y = rhs.y;
		z = rhs.z;
		w = rhs.w;
		return (*this);
	}

	bool Vec4d::operator==(const Vec4d & rhs)
	{
		return x == rhs.x && y == rhs.y && z == rhs.z && w == rhs.w;
	}

	bool Vec4d::operator<(const Vec4d & rhs)
	{
		return x < rhs.x && y < rhs.y && z < rhs.z && w < rhs.w;
	}

	bool Vec4d::operator>(const Vec4d & rhs)
	{
		return x > rhs.x && y > rhs.y && z > rhs.z && w > rhs.w;
	}

	bool Vec4d::operator<=(const Vec4d & rhs)
	{
		return !((*this) > rhs);
	}

	bool Vec4d::operator>=(const Vec4d & rhs)
	{
		return !((*this) < rhs);
	}


	bool Vec4d::operator!=(const Vec4d & rhs)
	{
		return !((*this) != rhs);
	}

#pragma endregion

#pragma region FREE_FUNCTIONS

	std::ostream & operator<<(std::ostream & os, const Vec2d &rhs)
	{
		os << "X: " << rhs.x;
		os << " Y: " << rhs.y;
		return os;
	}

	std::ostream & operator<<(std::ostream & os, const Vec3d &rhs)
	{
		os << "X: " << rhs.x;
		os << " Y: " << rhs.y;
		os << " Z: " << rhs.z;
		return os;
	}

	std::ostream & operator<<(std::ostream & os, const Vec4d &rhs)
	{
		os << "X: " << rhs.x;
		os << " Y: " << rhs.y;
		os << " Z: " << rhs.z;
		os << " W: " << rhs.w;
		return os;
	}

#pragma endregion

} }