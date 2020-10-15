#include "../HeaderFiles/Vector3D.h"
#include <cassert>

#define M_PI 3.14159265358979323846

// Vector 3 Constructors
Vector3D::Vector3D() {
	x = 0;
	y = 0;
	z = 0;
}

Vector3D::Vector3D(float _x, float _y, float _z) {
	x = _x;
	y = _y;
	z = _z;
}



//Compare
bool Vector3D::compare(Vector3D& source) {
	if (x == source.x && y == source.y && z == source.z) {
		return true;
	}
	else {
		return false;
	}
}

//Vector3D Getters
float Vector3D::getX() {
	return x;
}

float Vector3D::getY() {
	return y;
}

float Vector3D::getZ() {
	return z;
}

//Vector3D Setters
void Vector3D::setX(float _x) {
	x = _x;
}

void Vector3D::setY(float _y) {
	y = _y;
}

void Vector3D::setZ(float _z) {
	z = _z;
}


//Vector3D Operations

Vector3D Vector3D::operator+(Vector3D& operand)
{
	return Vector3D(x + operand.x, y + operand.y, z + operand.z);
}

Vector3D Vector3D::operator-(Vector3D& operand)
{
	return Vector3D(x - operand.x, y - operand.y, z - operand.z);
}

Vector3D operator-(Vector3D& operand)
{
	return Vector3D(-operand.getX(), -operand.getY(), -operand.getZ());
}

Vector3D Vector3D::operator*(float operand)
{
	return Vector3D(x * operand, y * operand, z * operand);
}

Vector3D operator*(float val, Vector3D& operand) {
	return operand * val;
}

Vector3D Vector3D::operator/(float operand)
{
	assert(operand != 0);
	return Vector3D(x / operand, y / operand, z / operand);
}

Vector3D operator/(float val, Vector3D& operand) {
	return operand / val;
}

//Vector3D Assignments
Vector3D& Vector3D::operator=(const Vector3D& operand)
{
	x = operand.x;
	y = operand.y;
	z = operand.z;
	return *this;
}

Vector3D& Vector3D::operator+=(Vector3D& operand)
{
	x += operand.x;
	y += operand.y;
	z += operand.z;
	return *this;
}

Vector3D& Vector3D::operator-=(Vector3D& operand)
{
	x -= operand.x;
	y -= operand.y;
	z -= operand.z;
	return *this;
}

Vector3D& Vector3D::operator*=(float operand)
{
	x *= operand;
	y *= operand;
	z *= operand;
	return *this;
}

Vector3D& Vector3D::operator/=(float operand)
{
	x /= operand;
	y /= operand;
	z /= operand;
	return *this;
}

//Vector3D Comparators
bool Vector3D::operator==(Vector3D& vec) {
	if (x == vec.x && y == vec.y && z == vec.z) {
		return true;
	}
	return false;
}

bool Vector3D::operator!=(Vector3D& vec) {
	if (x == vec.x && y == vec.y && z == vec.z) {
		return false;
	}
	return true;
}

//Vector3D Methods

//Length of a Vector
double Vector3D::length() {
	return sqrt((x * x) + (y * y) + (z * z));
}

//Normalize
void Vector3D::normalize()
{
	double l = length();
	assert(length() != 0);
		x /= l;
		y /= l;
		z /= l;
}

//toString
std::string Vector3D::toString() {
	std::string s = "[" + std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z) + "]";
	return s;
}

//Dot product
float Vector3D::dot(Vector3D& component)
{
	return x * component.x + y * component.y + z * component.z;
}

//Cross product
Vector3D Vector3D::cross(Vector3D& component)
{
		return Vector3D(
			y * component.z - z * component.y,
			z * component.x - x * component.z,
			x * component.y - y * component.x
		);
}

//Invert
Vector3D Vector3D::invert()
{
	*this = -*this;
	return *this;
}

Vector3D Vector3D::rodriguesRot(Vector3D k, float angle) {
	k.normalize();
	angle *= ( M_PI / 180);
	Vector3D v1 = *this * cos(angle);
	Vector3D v2 = k.cross(*this) * sin(angle);
	float v3 = k.dot(*this);
	Vector3D v4 = v3 * k * (1 - cos(angle));
	return v1 + v2 + v4;
};
