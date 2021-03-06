#include "../HeaderFiles/Vector2D.h"
#include <cassert>

// Vector 3 Constructors
Vector2D::Vector2D() {
	x = 0;
	y = 0;
}

Vector2D::Vector2D(float _x, float _y) {
	x = _x;
	y = _y;
}

//Vector2D Getters
float Vector2D::getX() {
	return x;
}

float Vector2D::getY() {
	return y;
}

//Vector2D Setters
void Vector2D::setX(float _x) {
	x = _x;
}

void Vector2D::setY(float _y) {
	y = _y;
}

//Vector2D Operations

Vector2D Vector2D::operator+(Vector2D& operand)
{
	return Vector2D(x + operand.x, y + operand.y);
}

Vector2D Vector2D::operator-(Vector2D& operand)
{
	return Vector2D(x - operand.x, y - operand.y);
}

Vector2D operator-(Vector2D& operand)
{
	return Vector2D(-operand.getX(), -operand.getY());
}

Vector2D Vector2D::operator*(float operand)
{
	return Vector2D(x * operand, y * operand);
}

Vector2D operator*(float val, Vector2D& operand) {
	return operand * val;
}

Vector2D Vector2D::operator/(float operand)
{
	assert(operand != 0);
	return Vector2D(x / operand, y / operand);
}

Vector2D operator/(float val, Vector2D& operand) {
	return operand / val;
}

//Vector2D Assignments
Vector2D& Vector2D::operator=(const Vector2D& operand)
{
	x = operand.x;
	y = operand.y;
	return *this;
}

Vector2D& Vector2D::operator+=(Vector2D& operand)
{
	x += operand.x;
	y += operand.y;
	return *this;
}

Vector2D& Vector2D::operator-=(Vector2D& operand)
{
	x -= operand.x;
	y -= operand.y;
	return *this;
}

Vector2D& Vector2D::operator*=(float operand)
{
	x *= operand;
	y *= operand;
	return *this;
}

Vector2D& Vector2D::operator/=(float operand)
{
	x /= operand;
	y /= operand;
	return *this;
}

//Vector2D Comparators
bool Vector2D::operator==(Vector2D& vec) {
	float epsilon = 0.00005f;
	if (abs( x - vec.getX()) < epsilon && abs(y - vec.getY()) < epsilon) {
		return true;
	}
	return false;
}

bool Vector2D::operator!=(Vector2D& vec) {
	float epsilon = 0.00005f;
	if (!(abs(x - vec.getX()) < epsilon && abs(y - vec.getY()) < epsilon)) {
		return false;
	}
	return true;
}

//Vector2D Methods

//Length of a Vector
double Vector2D::length() {
	return sqrt((x * x) + (y * y));
}

//Normalize
void Vector2D::normalize()
{

	double l = length();
	assert(length() != 0);
		x /= (float)l;
		y /= (float)l;
}

//toString
std::string Vector2D::toString() {
	std::string s = "[" + std::to_string(x) + ", " + std::to_string(y) + "]";
	return s;
}

//Dot product
float Vector2D::dot(Vector2D& component)
{
	return x * component.x + y * component.y;
}

//Invert
Vector2D Vector2D::invert()
{
	*this = -*this;
	return *this;
}
