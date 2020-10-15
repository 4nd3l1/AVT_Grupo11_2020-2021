#include "../HeaderFiles/Matrix4D.h"

#include "../HeaderFiles/Vector4D.h"

#include <cassert>
#include "../HeaderFiles/Matrix2D.h"

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

//Matrix4D Print
std::ostream& operator<<(std::ostream& os, const Matrix4D& matrix)
{
	os << "\n";
	for (int row = 0; row < 4; row++) {
		os << "[";

		for (int col = 0; col < 4; col++) {
			os << matrix.matrix[row][col];
			if (col != 2) {
				os << ", ";
			}
		}
		os << "]\n";
	}
	return os;
}


//Clone
Matrix4D Matrix4D::clone() {
	return Matrix4D(matrix);
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


//Matrix4D Operations
Matrix4D Matrix4D::operator+(const Matrix4D& mat)
{
	/* NEEDLESS ASSERTION
	int noRows = sizeof(mat.matrix) / sizeof(mat.matrix[0]);
	int noCols = sizeof(mat.matrix[0]) / sizeof(float);
	std::cout << noRows << "\n";
	assert(noRows == 4 && noCols == 4);
	*/

	Matrix4D matSum;
	for (int row = 0; row < 4; row++) {
		for (int col = 0; col < 4; col++) {
			matSum.matrix[row][col] = matrix[row][col] + mat.matrix[row][col];
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
	for (int row = 0; row < 4; row++) {
		for (int col = 0; col < 4; col++) {
			if (matrix[row][col] != mat.matrix[row][col]) {
				return false;
			}
		}
	}

	return true;
}


bool Matrix4D::operator!=(const Matrix4D& mat) {
	for (int row = 0; row < 4; row++) {
		for (int col = 0; col < 4; col++) {
			if (matrix[row][col] == mat.matrix[row][col]) { 
				return false;
			}
		}
	}

	return true;
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

Matrix4D Matrix4D::convertMajorOrder() {

	*this = transposed();

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
		return Matrix4D(new float[4][4]{ {1,0,0},{0,1,0},{0,0,1} });
	}

	Matrix4D Matrix4D::scaling(float sx, float sy, float sz, float sw) {
		return Matrix4D(new float[4][4]{ {sx,0,0,0}, {0,sy,0,0}, {0,0,sz,0}, {0,0,0,sw} });
	}

	/* Não implementei poruqe não consigo arranjar uma forma de o fazer
	Matrix4D Matrix4D::translation(Vector4D& vec) {   

	}

	Matrix4D Matrix4D::rotation(Vector4D& vec) {

	}
	*/