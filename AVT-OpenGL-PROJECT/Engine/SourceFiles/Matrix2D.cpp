#include "../HeaderFiles/Matrix2D.h"

#include "../HeaderFiles/Vector2D.h"

#include <cassert>

// Matrix 2 Constructors
Matrix2D::Matrix2D() {
}

Matrix2D::Matrix2D(float val) {
	for (int row = 0; row < 2; row++) {
		for (int col = 0; col < 2; col++) {
			matrix[row][col] = val;
		}
	}
}

Matrix2D::Matrix2D(float mat[2][2]) {
	for (int row = 0; row < 2; row++) {
		for (int col = 0; col < 2; col++) {
			matrix[row][col] = mat[row][col];
		}
	}
}

//Matrix2D Print
std::ostream& operator<<(std::ostream& os, const Matrix2D& matrix)
{
	os << "\n";
	for (int row = 0; row < 2; row++) {
		os << "[";

		for (int col = 0; col < 2; col++) {
			os << matrix.matrix[row][col];
			if (col != 1) {
				os << ", ";
			}
		}
		os << "]\n";
	}
	return os;
}



//Matrix2D Getters
float Matrix2D::get(int row, int col) {
	assert(row > 0 && row < 2 && col > 0 && col < 2);
	return matrix[row][col];
}

//Matrix2D Setters
void Matrix2D::set(int row, int col, float val) {
	assert(row >= 0 && row < 2 && col >= 0 && col < 2);
	matrix[row][col] = val;
}


//Matrix2D Operations
Matrix2D Matrix2D::operator+(const Matrix2D& mat)
{
	/* NEEDLESS ASSERTION
	int noRows = sizeof(mat.matrix) / sizeof(mat.matrix[0]);
	int noCols = sizeof(mat.matrix[0]) / sizeof(float);
	std::cout << noRows << "\n";
	assert(noRows == 2 && noCols == 2);
	*/

	Matrix2D matSum;
	for (int row = 0; row < 2; row++) {
		for (int col = 0; col < 2; col++) {
			matSum.matrix[row][col] = matrix[row][col] + mat.matrix[row][col];
		}
	}

	return matSum;
}

Matrix2D Matrix2D::operator-(const Matrix2D& mat)
{
	Matrix2D matSub;
	for (int row = 0; row < 2; row++) {
		for (int col = 0; col < 2; col++) {
			matSub.matrix[row][col] = matrix[row][col] - mat.matrix[row][col];
		}
	}

	return matSub;
}

Matrix2D Matrix2D::operator*(const Matrix2D& mat) {
	Matrix2D matMul;

	for (int row = 0; row < 2; row++) {
		for (int col = 0; col < 2; col++) {
			for (int i = 0; i < 2; ++i)
			{
				matMul.matrix[row][col] += matrix[row][i] * mat.matrix[i][col];
			}
		}
	}

	return matMul;
}

Matrix2D Matrix2D::operator*(float val)
{
	Matrix2D matMul;
	for (int row = 0; row < 2; row++) {
		for (int col = 0; col < 2; col++) {
			matMul.matrix[row][col] = matrix[row][col] * val;
		}
	}

	return matMul;
}

Matrix2D operator*(float val, Matrix2D& mat)
{
	Matrix2D matMul;
	for (int row = 0; row < 2; row++) {
		for (int col = 0; col < 2; col++) {
			matMul.matrix[row][col] = mat.matrix[row][col] * val;
		}
	}

	return matMul;
}

Vector2D Matrix2D::operator*(Vector2D& vec) {
	float x = matrix[0][0] * vec.getX() + matrix[0][1] * vec.getY();

	float y = matrix[1][0] * vec.getX() + matrix[1][1] * vec.getY();

	return Vector2D(x, y);
}

Vector2D operator*(Vector2D& vec, Matrix2D& mat) {
	float x = vec.getX() * mat.matrix[0][0] + vec.getY() * mat.matrix[1][0];

	float y = vec.getX() * mat.matrix[0][1] + vec.getY() * mat.matrix[1][1];

	return Vector2D(x, y);
}

Matrix2D Matrix2D::operator/(float val)
{
	Matrix2D matMul;
	for (int row = 0; row < 2; row++) {
		for (int col = 0; col < 2; col++) {
			matMul.matrix[row][col] = matrix[row][col] / val;
		}
	}

	return matMul;
}

Matrix2D operator/(float val, Matrix2D& mat)
{
	Matrix2D matMul;
	for (int row = 0; row < 2; row++) {
		for (int col = 0; col < 2; col++) {
			matMul.matrix[row][col] = mat.matrix[row][col] / val;
		}
	}

	return matMul;
}

//Matrix2D Assignments
Matrix2D& Matrix2D::operator+=(const Matrix2D& mat) {
	for (int row = 0; row < 2; row++) {
		for (int col = 0; col < 2; col++) {
			matrix[row][col] = matrix[row][col] + mat.matrix[row][col];
		}
	}

	return *this;
}

Matrix2D& Matrix2D::operator-=(const Matrix2D& mat) {
	for (int row = 0; row < 2; row++) {
		for (int col = 0; col < 2; col++) {
			matrix[row][col] = matrix[row][col] - mat.matrix[row][col];
		}
	}

	return *this;
}

Matrix2D& Matrix2D::operator*=(const Matrix2D& mat) {
	return *this = *this * mat;
}

Matrix2D& Matrix2D::operator*=(float val) {
	for (int row = 0; row < 2; row++) {
		for (int col = 0; col < 2; col++) {
			matrix[row][col] = matrix[row][col] * val;
		}
	}

	return *this;
}

Vector2D operator*=(Vector2D& vec, Matrix2D& mat) {
	vec.setX(vec.getX() * mat.matrix[0][0] + vec.getY() * mat.matrix[1][0]);

	vec.setY(vec.getX() * mat.matrix[0][1] + vec.getY() * mat.matrix[1][1]);

	return vec;
}

Matrix2D& Matrix2D::operator/=(float val) {
	for (int row = 0; row < 2; row++) {
		for (int col = 0; col < 2; col++) {
			matrix[row][col] = matrix[row][col] / val;
		}
	}

	return *this;
}

Matrix2D& Matrix2D::operator=(const Matrix2D& mat) {
	for (int row = 0; row < 2; row++) {
		for (int col = 0; col < 2; col++) {
			matrix[row][col] = mat.matrix[row][col];
		}
	}

	return *this;
}

Matrix2D& Matrix2D::operator=(float val) {
	for (int row = 0; row < 2; row++) {
		for (int col = 0; col < 2; col++) {
			matrix[row][col] = val;
		}
	}

	return *this;
}

//Matrix2D Comparators
bool Matrix2D::operator==(const Matrix2D& mat) {
	for (int row = 0; row < 2; row++) {
		for (int col = 0; col < 2; col++) {
			if (matrix[row][col] != mat.matrix[row][col]) {
				return false;
			}
		}
	}

	return true;
}


bool Matrix2D::operator!=(const Matrix2D& mat) {
	for (int row = 0; row < 2; row++) {
		for (int col = 0; col < 2; col++) {
			if (matrix[row][col] == mat.matrix[row][col]) { 
				return false;
			}
		}
	}

	return true;
}

//Matrix2D Methods
Matrix2D Matrix2D::transposed() { 
	Matrix2D trans;
	for (int row = 0; row < 2; row++) {
		for (int col = 0; col < 2; col++) {
			trans.matrix[col][row] = matrix[row][col];
		}
	}

	return trans;
}

Matrix2D Matrix2D::convertMajorOrder() {
	Matrix2D trans = this->transposed();

	for (int row = 0; row < 2; row++) {
		for (int col = 0; col < 2; col++) {
			matrix[row][col] = trans.matrix[row][col];
		}
	}

	return *this;
}


float Matrix2D::determinant() { 
	return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
}

	Matrix2D Matrix2D::adjoint() { 
		return Matrix2D(new float[2][2]{ {matrix[1][1], -matrix[0][1]}, {-matrix[1][0], matrix[0][0]} });

	}

	Matrix2D Matrix2D::inverse() { 
		return adjoint() / determinant();
	}

	Matrix2D Matrix2D::identity() {
		return Matrix2D(new float[2][2]{ {1,0},{0,1} });
	}
