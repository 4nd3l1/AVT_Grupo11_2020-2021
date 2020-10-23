#include "../HeaderFiles/Matrix4D.h"

#include "../HeaderFiles/Vector4D.h"
#include "../HeaderFiles/Vector3D.h"

#include <cassert>
#include "../HeaderFiles/Matrix2D.h"
#include "../HeaderFiles/Matrix3D.h"

# define PI atan(1)*4

// Matrix 4 Constructors
Matrix4D::Matrix4D() {
}

Matrix4D::Matrix4D(float val) {
	for (int row = 0; row < 4; row++) {
		for (int col = 0; col < 4; col++) {
			matrix[row][col] = val;
		}
	}
}




Matrix4D::Matrix4D(float mat[4][4]) {
	for (int row = 0; row < 4; row++) {
		for (int col = 0; col < 4; col++) {
			matrix[row][col] = mat[row][col];
		}
	}
}




Matrix4D::Matrix4D(Matrix2D& mat) {
	for (int row = 0; row < 4; row++) {
		for (int col = 0; col < 4; col++) {
			if (row >= 2 || col >= 2) {
				matrix[row][col] = 0;
			}
			else {
				matrix[row][col] = mat[row][col];
			}
		}
	}
}

Matrix4D::Matrix4D(Matrix3D& mat) {
	for (int row = 0; row < 4; row++) {
		for (int col = 0; col < 4; col++) {
			if (row == 3 || col == 3) {
				matrix[row][col] = 0;
			}
			else {
				matrix[row][col] = mat[row][col];
			}
		}
	}
}

//Matrix4D Print
std::ostream& operator<<(std::ostream& os, const Matrix4D& matrix)
{
	os << "\n";
	for (int row = 0; row < 4; row++) {
		os << "[";

		for (int col = 0; col < 4; col++) {
			os << matrix.matrix[row][col];
			if (col != 3) {
				os << ", ";
			}
		}
		os << "]\n";
	}
	return os;
}




//Matrix4D Getters
float Matrix4D::get(int row, int col) {
	assert(row > 0 && row < 4 && col > 0 && col < 4);
	return matrix[row][col];
}

//Matrix4D Setters
void Matrix4D::set(int row, int col, float val) {
	assert(row >= 0 && row < 4 && col >= 0 && col < 4);
	matrix[row][col] = val;
}

float* Matrix4D::operator[](int val) {
	return matrix[val];
}

//Matrix4D Operations
Matrix4D Matrix4D::operator+(const Matrix4D& mat)
{

	Matrix4D matSum;
	for (int row = 0; row < 4; row++) {
		for (int col = 0; col < 4; col++) {
			matSum.matrix[row][col] = matrix[row][col] + mat.matrix[row][col];
		}
	}

	return matSum;
}

Matrix4D Matrix4D::operator+(float val)
{
	Matrix4D matSum;
	for (int row = 0; row < 4; row++) {
		for (int col = 0; col < 4; col++) {
			matSum.matrix[row][col] = matrix[row][col] + val;
		}
	}

	return matSum;
}

Matrix4D operator+(float val, Matrix4D& mat)
{
	Matrix4D matSum;
	for (int row = 0; row < 4; row++) {
		for (int col = 0; col < 4; col++) {
			matSum.matrix[row][col] = mat.matrix[row][col] + val;
		}
	}

	return matSum;
}

Matrix4D Matrix4D::operator-(const Matrix4D& mat)
{
	Matrix4D matSub;
	for (int row = 0; row < 4; row++) {
		for (int col = 0; col < 4; col++) {
			matSub.matrix[row][col] = matrix[row][col] - mat.matrix[row][col];
		}
	}

	return matSub;
}

Matrix4D Matrix4D::operator-(float val)
{
	Matrix4D matSum;
	for (int row = 0; row < 4; row++) {
		for (int col = 0; col < 4; col++) {
			matSum.matrix[row][col] = matrix[row][col] - val;
		}
	}

	return matSum;
}

Matrix4D operator-(float val, Matrix4D& mat)
{
	Matrix4D matSum;
	for (int row = 0; row < 4; row++) {
		for (int col = 0; col < 4; col++) {
			matSum.matrix[row][col] = val - mat.matrix[row][col];
		}
	}

	return matSum;
}

Matrix4D Matrix4D::operator*(const Matrix4D& mat) {
	Matrix4D matMul;

	for (int row = 0; row < 4; row++) {
		for (int col = 0; col < 4; col++) {
			for (int i = 0; i < 4; ++i)
			{
				matMul.matrix[row][col] += matrix[row][i] * mat.matrix[i][col];
			}
		}
	}

	return matMul;
}

Matrix4D Matrix4D::operator*(float val)
{
	Matrix4D matMul;
	for (int row = 0; row < 4; row++) {
		for (int col = 0; col < 4; col++) {
			matMul.matrix[row][col] = matrix[row][col] * val;
		}
	}

	return matMul;
}

Matrix4D operator*(float val, Matrix4D& mat)
{
	Matrix4D matMul;
	for (int row = 0; row < 4; row++) {
		for (int col = 0; col < 4; col++) {
			matMul.matrix[row][col] = mat.matrix[row][col] * val;
		}
	}

	return matMul;
}

Vector4D Matrix4D::operator*(Vector4D& vec) {
	float x = matrix[0][0] * vec.getX() + matrix[0][1] * vec.getY() + matrix[0][2] * vec.getZ() + matrix[0][3] * vec.getW();

	float y = matrix[1][0] * vec.getX() + matrix[1][1] * vec.getY() + matrix[1][2] * vec.getZ() + matrix[1][3] * vec.getW();

	float z = matrix[2][0] * vec.getX() + matrix[2][1] * vec.getY() + matrix[2][2] * vec.getZ() + matrix[2][3] * vec.getW();

	float w = matrix[3][0] * vec.getX() + matrix[3][1] * vec.getY() + matrix[3][2] * vec.getZ() + matrix[3][3] * vec.getW();

	return Vector4D(x, y, z, w);
}

Vector4D operator*(Vector4D& vec, Matrix4D& mat) {
	float x = vec.getX() * mat.matrix[0][0] + vec.getY() * mat.matrix[1][0] + vec.getZ() * mat.matrix[2][0] + vec.getZ() * mat.matrix[3][0];

	float y = vec.getX() * mat.matrix[0][1] + vec.getY() * mat.matrix[1][1] + vec.getZ() * mat.matrix[2][1] + vec.getZ() * mat.matrix[3][1];

	float z = vec.getX() * mat.matrix[0][2] + vec.getY() * mat.matrix[1][2] + vec.getZ() * mat.matrix[2][2] + vec.getZ() * mat.matrix[3][2];

	float w = vec.getX() * mat.matrix[0][3] + vec.getY() * mat.matrix[1][3] + vec.getZ() * mat.matrix[2][3] + vec.getZ() * mat.matrix[3][3];

	return Vector4D(x, y, z, w);
}

Matrix4D Matrix4D::operator/(float val)
{
	Matrix4D matMul;
	for (int row = 0; row < 4; row++) {
		for (int col = 0; col < 4; col++) {
			matMul.matrix[row][col] = matrix[row][col] / val;
		}
	}

	return matMul;
}

Matrix4D operator/(float val, Matrix4D& mat)
{
	Matrix4D matMul;
	for (int row = 0; row < 4; row++) {
		for (int col = 0; col < 4; col++) {
			matMul.matrix[row][col] = mat.matrix[row][col] / val;
		}
	}

	return matMul;
}

//Matrix4D Assignments
Matrix4D& Matrix4D::operator+=(const Matrix4D& mat) {
	for (int row = 0; row < 4; row++) {
		for (int col = 0; col < 4; col++) {
			matrix[row][col] = matrix[row][col] + mat.matrix[row][col];
		}
	}

	return *this;
}

Matrix4D& Matrix4D::operator-=(const Matrix4D& mat) {
	for (int row = 0; row < 4; row++) {
		for (int col = 0; col < 4; col++) {
			matrix[row][col] = matrix[row][col] - mat.matrix[row][col];
		}
	}

	return *this;
}

Matrix4D& Matrix4D::operator*=(const Matrix4D& mat) {
	return *this = *this *mat;
}

Matrix4D& Matrix4D::operator*=(float val) {
	for (int row = 0; row < 4; row++) {
		for (int col = 0; col < 4; col++) {
			matrix[row][col] = matrix[row][col] * val;
		}
	}

	return *this;
}

Vector4D operator*=(Vector4D& vec, Matrix4D& mat) {
	vec.setX(vec.getX() * mat.matrix[0][0] + vec.getY() * mat.matrix[1][0] + vec.getZ() * mat.matrix[2][0] + vec.getW() * mat.matrix[3][0]);

	vec.setY(vec.getX() * mat.matrix[0][1] + vec.getY() * mat.matrix[1][1] + vec.getZ() * mat.matrix[2][1] + vec.getW() * mat.matrix[3][1]);

	vec.setZ(vec.getX() * mat.matrix[0][2] + vec.getY() * mat.matrix[1][2] + vec.getZ() * mat.matrix[2][2] + vec.getW() * mat.matrix[3][2]);

	vec.setW(vec.getW() * mat.matrix[0][3] + vec.getY() * mat.matrix[1][3] + vec.getZ() * mat.matrix[2][3] + vec.getW() * mat.matrix[3][2]);

	return vec;
}

Matrix4D& Matrix4D::operator/=(float val) {
	for (int row = 0; row < 4; row++) {
		for (int col = 0; col < 4; col++) {
			matrix[row][col] = matrix[row][col] / val;
		}
	}

	return *this;
}

Matrix4D& Matrix4D::operator=(const Matrix4D& mat) {
	for (int row = 0; row < 4; row++) {
		for (int col = 0; col < 4; col++) {
			matrix[row][col] = mat.matrix[row][col];
		}
	}

	return *this;
}

Matrix4D& Matrix4D::operator=(float val) {
	for (int row = 0; row < 4; row++) {
		for (int col = 0; col < 4; col++) {
			matrix[row][col] = val;
		}
	}

	return *this;
}

//Matrix4D Comparators
bool Matrix4D::operator==(const Matrix4D& mat) {
	float epsilon = 0.00005f;
	for (int row = 0; row < 4; row++) {
		for (int col = 0; col < 4; col++) {
			if (!(abs(matrix[row][col] - mat.matrix[row][col]) < epsilon)) {
				return false;
			}
		}
	}

	return true;
}


bool Matrix4D::operator!=(const Matrix4D& mat) {
	float epsilon = 0.00005f;
	int count = 0;
	for (int row = 0; row < 4; row++) {
		for (int col = 0; col < 4; col++) {
			if (abs(matrix[row][col] - mat.matrix[row][col]) < epsilon) {
				count++;
			}
		}
	}
	if (count == 16) {
		return false;
	}
	else {
		return true;
	}
}

//Matrix4D Methods
Matrix4D Matrix4D::transposed() {
	Matrix4D trans;
	for (int row = 0; row < 4; row++) {
		for (int col = 0; col < 4; col++) {
			trans.matrix[col][row] = matrix[row][col];
		}
	}

	return trans;
}

Matrix4D& Matrix4D::transpose() {
	*this = this->transposed();
	return *this;
}

Matrix4D Matrix4D::adjoint() {  
	Matrix4D trans = transposed();
	Matrix4D adj;

	for (int row = 0; row < 4; row++) {
		for (int col = 0; col < 4; col++) {
			float temp[4] = { 0,0,0,0 };
			int index = 0;

			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					if (i == row || j == col) continue;
					temp[index++] = trans.matrix[i][j];
				}
			}

			adj.matrix[row][col] = Matrix2D(new float[2][2]{ {temp[0],temp[1]}, {temp[2],temp[3]} }).determinant();

			if ((row + col) % 2 != 0) adj.matrix[row][col] = -adj.matrix[row][col];
		}
	}

	return adj;
	}

	Matrix4D Matrix4D::identity() {
		return Matrix4D(new float[4][4]{ {1,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,1} });
	}

	Matrix4D Matrix4D::scaling(float sx, float sy, float sz) {
		return Matrix4D(new float[4][4]{ {sx,0,0,0}, {0,sy,0,0}, {0,0,sz,0}, {0,0,0,1} });
	}

	Matrix4D Matrix4D::scaling(Vector3D& vec) {
		return Matrix4D(new float[4][4]{ {vec.getX(),0,0,0}, {0,vec.getY(),0,0}, {0,0,vec.getZ(),0}, {0,0,0,1} });
	}

	Matrix4D Matrix4D::translation(float sx, float sy, float sz) {
		return Matrix4D(new float[4][4]{ {1,0,0,sx}, {0,1,0,sy}, {0,0,1,sz}, {0,0,0,1} });
	}

	Matrix4D Matrix4D::translation(Vector3D& vec) {
		return Matrix4D(new float[4][4]{ {1,0,0,vec.getX()}, {0,1,0,vec.getY()}, {0,0,1,vec.getZ()}, {0,0,0,1} });
	}

	Matrix4D Matrix4D::rotation(float sx, float sy, float sz, bool radians, bool round) {
		if (!radians) { // Convert to radians
			sx = sx * (float)PI / 180.0f;
			sy = sy * (float)PI / 180.0f;
			sz = sz * (float)PI / 180.0f;
		}

		float cosG = cos(sx);
		float cosB = cos(sy);
		float cosA = cos(sz);

		float sinG = sin(sx);
		float sinB = sin(sy);
		float sinA = sin(sz);

		// Round - Useful for angles like PI/2 
		if (round) {
			cosG = roundf(cosG * 10000000) / 10000000;
			cosB = roundf(cosB * 10000000) / 10000000;
			cosA = roundf(cosA * 10000000) / 10000000;

			sinG = roundf(sinG * 10000000) / 10000000;
			sinB = roundf(sinB * 10000000) / 10000000;
			sinA = roundf(sinA * 10000000) / 10000000;
		}

		return Matrix4D(
			new float[4][4]{
				{cosA * cosB, cosA * sinB * sinG - sinA * cosG, cosA * sinB * cosG + sinA * sinG,0},
				{sinA * cosB, sinA * sinB * sinG + cosA * cosG, sinA * sinB * cosG - cosA * sinG, 0},
				{-sinB, cosB * sinG, cosB * cosG, 0},
				{0,0,0,1}
			}
		);
	}

	Matrix4D Matrix4D::rotation(Vector3D& vec, bool radians, bool round) {
		float sx = vec.getX();
		float sy = vec.getY();
		float sz = vec.getZ();

		return rotation(sx, sy, sz, radians, round);
	}

	Matrix4D Matrix4D::rotationX(float ang, bool radians, bool round) {
		if (!radians) { // Convert to radians
			ang = ang * (float)PI / 180.0f;
		}

		float cosAng = cos(ang);
		float sinAng = sin(ang);

		// Round - Useful for angles like PI/2 
		if (round) {
			cosAng = roundf(cosAng * 10000000) / 10000000;
			sinAng = roundf(sinAng * 10000000) / 10000000;
		}

		return Matrix4D(
			new float[4][4]{
				{1, 0, 0, 0},
				{0, cosAng, -sinAng, 0},
				{0, sinAng, cosAng, 0},
				{0,0,0,1}
			}
		);
	}

	Matrix4D Matrix4D::rotationY(float ang, bool radians, bool round) {
		if (!radians) { // Convert to radians
			ang = ang * (float)PI / 180.0f;
		}

		float cosAng = cos(ang);
		float sinAng = sin(ang);

		// Round - Useful for angles like PI/2 
		if (round) {
			cosAng = roundf(cosAng * 10000000) / 10000000;
			sinAng = roundf(sinAng * 10000000) / 10000000;
		}

		return Matrix4D(
			new float[4][4]{
				{cosAng, 0, sinAng, 0},
				{0, 1, 0, 0},
				{-sinAng, 0, cosAng, 0},
				{0,0,0,1}
			}
		);
	}

	Matrix4D Matrix4D::rotationZ(float ang, bool radians, bool round) {
		if (!radians) { // Convert to radians
			ang = ang * (float)PI / 180.0f;
		}
		float cosAng = cos(ang);
		float sinAng = sin(ang);

		// Round - Useful for angles like PI/2 
		if (round) {
			cosAng = roundf(cosAng * 10000000) / 10000000;
			sinAng = roundf(sinAng * 10000000) / 10000000;
		}

		return Matrix4D(
			new float[4][4]{
				{cosAng, -sinAng, 0, 0},
				{sinAng, cosAng, 0, 0},
				{0, 0, 1, 0},
				{0,0,0,1}
			}
		);
	}

	void Matrix4D::getColMajor(float array[16]) {
		int i = 0;
		for (int col = 0; col < 4; col++) {
			for (int row = 0; row < 4; row++) {
				array[i++] = matrix[row][col];
			}
		}
	}

	void Matrix4D::getRowMajor(float array[16]) {
		int i = 0;
		for (int row = 0; row < 4; row++) {
			for (int col = 0; col < 4; col++) {
				array[i++] = matrix[row][col];
			}
		}
	}

	Matrix4D Matrix4D::AditiveIdentity() {
		float f = 0;
		return Matrix4D(f);
	}

	Matrix4D Matrix4D::MultiplicativeIdentity() {
		float f = 1;
		return Matrix4D(f);
	}
	