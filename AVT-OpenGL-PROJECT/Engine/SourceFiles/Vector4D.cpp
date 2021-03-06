#include "../HeaderFiles/Vector4D.h"
#include <cassert>

// Vector 3 Constructors
Vector4D::Vector4D() {
	x = 0;
	y = 0;
	z = 0;
	w = 0;
}

Vector4D::Vector4D(float _x, float _y, float _z, float _w) {
	x = _x;
	y = _y;
	z = _z;
	w = _w;
}

//Vector4D Getters
float Vector4D::getX() {
	return x;
}

float Vector4D::getY() {
	return y;
}

float Vector4D::getZ() {
	return z;
}

float Vector4D::getW() {
	return w;
}

//Vector4D Setters
void Vector4D::setX(float _x) {
	x = _x;
}

void Vector4D::setY(float _y) {
	y = _y;
}

void Vector4D::setZ(float _z) {
	z = _z;
}

void Vector4D::setW(float _w) {
	w = _w;
}


//Vector4D Operations

Vector4D Vector4D::operator+(Vector4D& operand)
{
	return Vector4D(x + operand.x, y + operand.y, z + operand.z, w + operand.w);
}

Vector4D Vector4D::operator-(Vector4D& operand)
{
	return Vector4D(x - operand.x, y - operand.y, z - operand.z, w - operand.w);
}

Vector4D operator-(Vector4D& operand)
{
	return Vector4D(-operand.getX(), -operand.getY(), -operand.getZ(), -operand.getW());
}

Vector4D Vector4D::operator*(float operand)
{
	return Vector4D(x * operand, y * operand, z * operand, w * operand);
}

Vector4D operator*(float val, Vector4D& operand) {
	return operand * val;
}

Vector4D Vector4D::operator/(float operand)
{
	assert(operand != 0);
	return Vector4D(x / operand, y / operand, z / operand, w / operand);
}

Vector4D operator/(float val, Vector4D& operand) {
	return operand / val;
}

//Vector4D Assignments
Vector4D& Vector4D::operator=(const Vector4D& operand)
{
	x = operand.x;
	y = operand.y;
	z = operand.z;
	w = operand.w;
	return *this;
}

Vector4D& Vector4D::operator+=(Vector4D& operand)
{
	x += operand.x;
	y += operand.y;
	z += operand.z;
	w += operand.w;
	return *this;
}

Vector4D& Vector4D::operator-=(Vector4D& operand)
{
	x -= operand.x;
	y -= operand.y;
	z -= operand.z;
	w -= operand.w;
	return *this;
}

Vector4D& Vector4D::operator*=(float operand)
{
	x *= operand;
	y *= operand;
	z *= operand;
	w *= operand;
	return *this;
}

Vector4D& Vector4D::operator/=(float operand)
{
	x /= operand;
	y /= operand;
	z /= operand;
	w /= operand;
	return *this;
}

//Vector4D Comparators
bool Vector4D::operator==(const Vector4D& vec) {
	float epsilon = 0.00005f;
	if (abs(x - vec.x) < epsilon &&
		abs(y - vec.y) < epsilon &&
		abs(z - vec.z) < epsilon &&
		abs(w - vec.w) < epsilon) {
		return true;
	}
	return false;
}

bool Vector4D::operator!=(Vector4D& vec) {
	float epsilon = 0.00005f;
	if (!(abs(x - vec.getX()) < epsilon &&
		abs(y - vec.getY()) < epsilon &&
		abs(z - vec.getZ()) < epsilon) &&
		abs(w - vec.getW()) < epsilon) {
		return false;
	}
	return true;
}

//Vector4D Methods

//Length of a Vector
double Vector4D::length() {
	return sqrt((x * x) + (y * y) + (z * z) + (w * w));
}

//Normalize
void Vector4D::normalize()
{
	double l = length();
	assert(length() != 0);
		x /= (float)l;
		y /= (float)l;
		z /= (float)l;
		w /= (float)l;
}

Vector4D Vector4D::Normalize_Quaternions()
{
	Vector4D vn;
	float s = 1 / (w * sqrt(x * x + y * y + z * z));
	vn.x = x * s;
	vn.y = y * s;
	vn.z = z * s;
	vn.w = 1.0f;
	return vn;
}

//toString
std::string Vector4D::toString() {
	std::string s = "[" + std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z) 
		+ ", " + std::to_string(w) + "]";
	return s;
}

//Dot product
float Vector4D::dot(Vector4D& component)
{
	return x * component.x + y * component.y + z * component.z + w * component.w;
}

//Invert
Vector4D Vector4D::invert()
{
	*this = -*this;
	return *this;
}
