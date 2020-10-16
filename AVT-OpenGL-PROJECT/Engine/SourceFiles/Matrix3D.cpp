#include "../HeaderFiles/Matrix3D.h"
#include "../HeaderFiles/Matrix4D.h"

#include "../HeaderFiles/Vector3D.h"

#include <cassert>
#include "../HeaderFiles/Matrix2D.h"

// Matrix 3 Constructors
Matrix3D::Matrix3D() {
}

Matrix3D::Matrix3D(float val) {
	for (int row = 0; row < 3; row++) {
		for (int col = 0; col < 3; col++) {
			matrix[row][col] = val;
		}
	}
}

Matrix3D::Matrix3D(float mat[3][3]) {
	for (int row = 0; row < 3; row++) {
		for (int col = 0; col < 3; col++) {
			matrix[row][col] = mat[row][col];
		}
	}
}

Matrix3D::Matrix3D(Matrix2D& mat) {
	for (int row = 0; row < 3; row++) {
		for (int col = 0; col < 3; col++) {
			if (row == 2 || col == 2) {
				matrix[row][col] = 0;
			}
			else {
				matrix[row][col] = mat[row][col];

			}
		}
	}
}

Matrix3D::Matrix3D(Matrix4D& mat) {
	for (int row = 0; row < 3; row++) {
		for (int col = 0; col < 3; col++) {
			matrix[row][col] = mat[row][col];
		}
	}
}

//Matrix3D Print
std::ostream& operator<<(std::ostream& os, const Matrix3D& matrix)
{
	os << "\n";
	for (int row = 0; row < 3; row++) {
		os << "[";

		for (int col = 0; col < 3; col++) {
			os << matrix.matrix[row][col];
			if (col != 2) {
				os << ", ";
			}
		}
		os << "]\n";
	}
	return os;
}




//Matrix3D Getters
float Matrix3D::get(int row, int col) {
	assert(row > 0 && row < 3 && col > 0 && col < 3);
	return matrix[row][col];
}

//Matrix3D Setters
void Matrix3D::set(int row, int col, float val) {
	assert(row >= 0 && row < 3 && col >= 0 && col < 3);
	matrix[row][col] = val;
}

float* Matrix3D::operator[](int val) {
	return matrix[val];
}

//Matrix3D Operations
Matrix3D Matrix3D::operator+(const Matrix3D& mat)
{
	Matrix3D matSum;
	for (int row = 0; row < 3; row++) {
		for (int col = 0; col < 3; col++) {
			matSum.matrix[row][col] = matrix[row][col] + mat.matrix[row][col];
		}
	}

	return matSum;
}

Matrix3D Matrix3D::operator+(float val)
{
	Matrix3D matSum;
	for (int row = 0; row < 3; row++) {
		for (int col = 0; col < 3; col++) {
			matSum.matrix[row][col] = matrix[row][col] + val;
		}
	}

	return matSum;
}

Matrix3D operator+(float val, Matrix3D& mat)
{
	Matrix3D matSum;
	for (int row = 0; row < 3; row++) {
		for (int col = 0; col < 3; col++) {
			matSum.matrix[row][col] = mat.matrix[row][col] + val;
		}
	}

	return matSum;
}

Matrix3D Matrix3D::operator-(const Matrix3D& mat)
{
	Matrix3D matSub;
	for (int row = 0; row < 3; row++) {
		for (int col = 0; col < 3; col++) {
			matSub.matrix[row][col] = matrix[row][col] - mat.matrix[row][col];
		}
	}

	return matSub;
}

Matrix3D Matrix3D::operator-(float val)
{
	Matrix3D matSum;
	for (int row = 0; row < 3; row++) {
		for (int col = 0; col < 3; col++) {
			matSum.matrix[row][col] = matrix[row][col] - val;
		}
	}

	return matSum;
}

Matrix3D operator-(float val, Matrix3D& mat)
{
	Matrix3D matSum;
	for (int row = 0; row < 3; row++) {
		for (int col = 0; col < 3; col++) {
			matSum.matrix[row][col] = val - mat.matrix[row][col];
		}
	}

	return matSum;
}

Matrix3D Matrix3D::operator*(const Matrix3D& mat) {
	Matrix3D matMul;

	for (int row = 0; row < 3; row++) {
		for (int col = 0; col < 3; col++) {
			for (int i = 0; i < 3; ++i)
			{
				matMul.matrix[row][col] += matrix[row][i] * mat.matrix[i][col];
			}
		}
	}

	return matMul;
}

Matrix3D Matrix3D::operator*(float val)
{
	Matrix3D matMul;
	for (int row = 0; row < 3; row++) {
		for (int col = 0; col < 3; col++) {
			matMul.matrix[row][col] = matrix[row][col] * val;
		}
	}

	return matMul;
}

Matrix3D operator*(float val, Matrix3D& mat)
{
	Matrix3D matMul;
	for (int row = 0; row < 3; row++) {
		for (int col = 0; col < 3; col++) {
			matMul.matrix[row][col] = mat.matrix[row][col] * val;
		}
	}

	return matMul;
}

Vector3D Matrix3D::operator*(Vector3D& vec) {
	float x = matrix[0][0] * vec.getX() + matrix[0][1] * vec.getY() + matrix[0][2] * vec.getZ();

	float y = matrix[1][0] * vec.getX() + matrix[1][1] * vec.getY() + matrix[1][2] * vec.getZ();

	float z = matrix[2][0] * vec.getX() + matrix[2][1] * vec.getY() + matrix[2][2] * vec.getZ();

	return Vector3D(x, y, z);
}

Vector3D operator*(Vector3D& vec, Matrix3D& mat) {
	float x = vec.getX() * mat.matrix[0][0] + vec.getY() * mat.matrix[1][0] + vec.getZ() * mat.matrix[2][0];

	float y = vec.getX() * mat.matrix[0][1] + vec.getY() * mat.matrix[1][1] + vec.getZ() * mat.matrix[2][1];

	float z = vec.getX() * mat.matrix[0][2] + vec.getY() * mat.matrix[1][2] + vec.getZ() * mat.matrix[2][2];

	return Vector3D(x, y, z);
}

Matrix3D Matrix3D::operator/(float val)
{
	Matrix3D matMul;
	for (int row = 0; row < 3; row++) {
		for (int col = 0; col < 3; col++) {
			matMul.matrix[row][col] = matrix[row][col] / val;
		}
	}

	return matMul;
}

Matrix3D operator/(float val, Matrix3D& mat)
{
	Matrix3D matMul;
	for (int row = 0; row < 3; row++) {
		for (int col = 0; col < 3; col++) {
			matMul.matrix[row][col] = mat.matrix[row][col] / val;
		}
	}

	return matMul;
}

//Matrix3D Assignments
Matrix3D& Matrix3D::operator+=(const Matrix3D& mat) {
	for (int row = 0; row < 3; row++) {
		for (int col = 0; col < 3; col++) {
			matrix[row][col] = matrix[row][col] + mat.matrix[row][col];
		}
	}

	return *this;
}

Matrix3D& Matrix3D::operator-=(const Matrix3D& mat) {
	for (int row = 0; row < 3; row++) {
		for (int col = 0; col < 3; col++) {
			matrix[row][col] = matrix[row][col] - mat.matrix[row][col];
		}
	}

	return *this;
}

Matrix3D& Matrix3D::operator*=(const Matrix3D& mat) {
	return *this = *this * mat;

}

Matrix3D& Matrix3D::operator*=(float val) {
	for (int row = 0; row < 3; row++) {
		for (int col = 0; col < 3; col++) {
			matrix[row][col] = matrix[row][col] * val;
		}
	}

	return *this;
}

Vector3D operator*=(Vector3D& vec, Matrix3D& mat) {
	vec.setX(vec.getX() * mat.matrix[0][0] + vec.getY() * mat.matrix[1][0] + vec.getZ() * mat.matrix[2][0]);

	vec.setY(vec.getX() * mat.matrix[0][1] + vec.getY() * mat.matrix[1][1] + vec.getZ() * mat.matrix[2][1]);

	vec.setZ(vec.getX() * mat.matrix[0][2] + vec.getY() * mat.matrix[1][2] + vec.getZ() * mat.matrix[2][2]);

	return vec;
}

Matrix3D& Matrix3D::operator/=(float val) {
	for (int row = 0; row < 3; row++) {
		for (int col = 0; col < 3; col++) {
			matrix[row][col] = matrix[row][col] / val;
		}
	}

	return *this;
}

Matrix3D& Matrix3D::operator=(const Matrix3D& mat) {
	for (int row = 0; row < 3; row++) {
		for (int col = 0; col < 3; col++) {
			matrix[row][col] = mat.matrix[row][col];
		}
	}

	return *this;
}

Matrix3D& Matrix3D::operator=(float val) {
	for (int row = 0; row < 3; row++) {
		for (int col = 0; col < 3; col++) {
			matrix[row][col] = val;
		}
	}

	return *this;
}

//Matrix3D Comparators
bool Matrix3D::operator==(const Matrix3D& mat) {
	float epsilon = 0.00005f;
	for (int row = 0; row < 3; row++) {
		for (int col = 0; col < 3; col++) {
			if (!(abs(matrix[row][col] - mat.matrix[row][col]) < epsilon)) {
				return false;
			}
		}
	}

	return true;
}


bool Matrix3D::operator!=(const Matrix3D& mat) {
	float epsilon = 0.00005f;
	int count = 0;
	for (int row = 0; row < 3; row++) {
		for (int col = 0; col < 3; col++) {
			if (abs(matrix[row][col] - mat.matrix[row][col]) < epsilon) {
				count++;
			}
		}
	}
	if (count == 9){
		return false;
	}
	else {
		return true;
	}
}

//Matrix3D Methods
Matrix3D Matrix3D::transposed() {
	Matrix3D trans;
	for (int row = 0; row < 3; row++) {
		for (int col = 0; col < 3; col++) {
			trans.matrix[col][row] = matrix[row][col];
		}
	}

	return trans;
}

Matrix3D& Matrix3D::transpose() {
	*this = this->transposed();
	return *this;
}

float Matrix3D::determinant() { 
	float det = matrix[0][0]*(matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1]);

	det -= matrix[0][1] * (matrix[1][0] * matrix[2][2] - matrix[2][0] * matrix[1][2]);

	det += matrix[0][2] * (matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0]);

	return det;
}


Matrix3D Matrix3D::adjoint() { 
	Matrix3D trans = transposed();
	Matrix3D adj;

	for (int row = 0; row < 3; row++) {
		for (int col = 0; col < 3; col++) {
			float temp[4] = { 0,0,0,0 };
			int index = 0;

			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
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

Matrix3D Matrix3D::inverse() {
	float det = determinant();
	assert(det != 0);

	return adjoint() / determinant();
}

Matrix3D Matrix3D::identity() {
	return Matrix3D(new float[3][3]{ {1,0,0},{0,1,0},{0,0,1} });
}

Matrix3D Matrix3D::dual(Vector3D& vec) {
	return Matrix3D(new float[3][3]{ {0,-vec.getZ(),vec.getY()},{vec.getZ(),0,-vec.getX()},{-vec.getY(),vec.getX(),0} });
}

void Matrix3D::getColMajor(float array[9]) {
	int i = 0;
	for (int col = 0; col < 3; col++) {
		for (int row = 0; row < 3; row++) {
			array[i++] = matrix[row][col];
		}
	}
}

void Matrix3D::getRowMajor(float array[9]) {
	int i = 0;
	for (int row = 0; row < 3; row++) {
		for (int col = 0; col < 3; col++) {
			array[i++] = matrix[row][col];
		}
	}
}