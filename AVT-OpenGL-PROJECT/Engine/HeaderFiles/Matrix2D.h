#ifndef MATRIX_2
#define MATRIX_2

// Matrix2D CLASS HEADER

/// Class used to represent and perform operations with 2x2 Matrices

#include<iostream>

class Vector2D;

class Matrix2D {
private:
	float matrix[2][2] = { {0,0}, {0,0}};
public:
	// FUNCTION DECLARATIONS
	/********************************************/ /**
	 * Creates a new Matrix3 object with all cells set to 0
	 ***********************************************/
	Matrix2D();

	/********************************************/ /**
	 * Creates a new Matrix3 object with the all cells equal to the specified value
	 *
	 * @param val The value of all cells
	 ***********************************************/
	Matrix2D(float val);

	/********************************************/ /**
	 * Creates a new Matrix3 object with the cells equal to the specified array of arrays
	 *
	 * @param mat The array of arrays that specify our matrix cell's values
	 ***********************************************/
	Matrix2D(float mat[2][2]);

	/********************************************/ /**
	 * Overloading of the << operator. Prints our Matrix
	 ***********************************************/
	friend std::ostream& operator<<(std::ostream& output, const Matrix2D& vec);

	/********************************************/ /**
	 * Used to create a clone of the matrix (that is still a different object)
	 *
	 ***********************************************/
	Matrix2D clone();

	/********************************************/ /**
	 * Function used to get a specific cell of a Matrix3
	 *
	 * @param row The row of the cell
	 * @param col The column of the cell
	 * @return cel The matrix3 cell at given coordinates
	 ***********************************************/
	float get(int row, int col);

	/********************************************/ /**
	 * Function used to set a specific cell's value
	 *
	 * @param row The row of the cell
	 * @param col The column of the cell
	 * @return val The value we want to set the cell to
	 ***********************************************/
	void set(int row, int col, float val);

	/********************************************/ /**
	 * Overloading of the + operator when summing two Matrix3
	 *
	 * @param mat The matrix3 we want to sum with
	 * @return matSum The sum of the two matrices
	 ***********************************************/
	Matrix2D operator+(const Matrix2D& mat);

	/********************************************/ /**
	 * Overloading of the - operator when subtracting two Matrix3
	 *
	 * @param mat The matrix3 we want to sub with
	 * @return matSub The sub of the two matrices
	 ***********************************************/
	Matrix2D operator-(const Matrix2D& mat);

	/********************************************/ /**
	 * Overloading of the * operator when multiplying two Matrix3
	 *
	 * @param mat The matrix3 we want to multiply with
	 * @return matMult The multiplication of the two matrices
	 ***********************************************/
	Matrix2D operator*(const Matrix2D& mat);

	/********************************************/ /**
	 * Overloading of the * operator when multiplying a matrix and a value
	 *
	 * @param val The value we want to multiply with
	 * @return matMult The multiplication of the two matrices
	 ***********************************************/
	Matrix2D operator*(float val);

	/********************************************/ /**
	 * Overloading of the * operator when multiplying a matrix and a value
	 *
	 * @param val The value we want to multiply with
	 * @return matMult The multiplication of the two matrices
	 ***********************************************/
	friend Matrix2D operator*(float val, Matrix2D& mat);

	/********************************************/ /**
	 * Overloading of the * operator when multiplying a matrix and a Vector3
	 *
	 * @param vec The vector we want to multiply with
	 * @return Vector3 The multiplication of the two matrices
	 ***********************************************/
	Vector2D operator*(Vector2D& vec);

	/********************************************/ /**
	 * Overloading of the * operator when multiplying a Vector and a matrix
	 *
	 * @param val The value we want to multiply with
	 * @return matMult The multiplication of the the vector and the matrix
	 ***********************************************/
	friend Vector2D operator*(Vector2D& vec, Matrix2D& mat);

	/********************************************/ /**
	 * Overloading of the / operator when dividing a matrix and a value
	 *
	 * @param val The value we want to multiply with
	 * @return matDiv The division of the two matrices
	 ***********************************************/
	Matrix2D operator/(float val);

	/********************************************/ /**
	 * Overloading of the / operator when dividing a matrix and a value
	 *
	 * @param val The value we want to multiply with
	 * @return matDiv The division of the two matrices
	 ***********************************************/
	friend Matrix2D operator/(float val, Matrix2D& mat);

	/********************************************/ /**
	 * Overloading of the += operator. Assigns new coordinates to our matrix
	 *
	 * @param mat The Matrix we want to sum to our Matrix
	 ***********************************************/
	Matrix2D& operator+=(const Matrix2D& vec);

	/********************************************/ /**
	 * Overloading of the -= operator. Assigns new coordinates to our matrix
	 *
	 * @param mat The Matrix we want to sub to our Matrix
	 ***********************************************/
	Matrix2D& operator-=(const Matrix2D& vec);

	/********************************************/ /**
	 * Overloading of the *= operator. Assigns new coordinates to our matrix
	 *
	 * @param mat The Matrix we want to multiply to our Matrix
	 ***********************************************/
	Matrix2D& operator*=(const Matrix2D& vec);

	/********************************************/ /**
	 * Overloading of the *= operator. Assigns new coordinates to our matrix
	 *
	 * @param val The value we want to multiply by
	 ***********************************************/
	Matrix2D& operator*=(float val);

	/********************************************/ /**
	 * Overloading of the * operator when multiplying a Vector and a matrix
	 *
	 * @param mat The matrix we want to use to multiply
	 ***********************************************/
	friend Vector2D operator*=(Vector2D& vec, Matrix2D& mat);

	/********************************************/ /**
	 * Overloading of the /= operator. Assigns new coordinates to our matrix
	 *
	 * @param val The value we want to multiply by
	 ***********************************************/
	Matrix2D& operator/=(float val);

	/********************************************/ /**
	 * Overloading of the = operator. Assigns new coordinates to our matrix
	 *
	 * @param mat The matrix with the coordenates to be copied
	 ***********************************************/
	Matrix2D& operator=(const Matrix2D& vec);

	/********************************************/ /**
	 * Overloading of the = operator. Assigns new coordinates to our matrix
	 *
	 * @param val The value we want our matrix cells to have
	 ***********************************************/
	Matrix2D& operator=(float val);

	/********************************************/ /**
	 * Overloading of the == operator. Verifies if 2 matrices have the same coordinates
	 *
	 * @return eq True if they have the same cells, false otherwise
	 ***********************************************/
	bool operator==(const Matrix2D& mat);

	/********************************************/ /**
	 * Overloading of the != operator. Verifies if 2 matrices have different coordinates
	 *
	 * @return eq True if they have the different coordinates, false otherwise
	 ***********************************************/
	bool operator!=(const Matrix2D& mat);

	/********************************************/ /**
	 * Returns the matrix transposed
	 *
	 * @return mat The transposed equivalent of the matrix
	 ***********************************************/
	Matrix2D transposed();

	/********************************************/ /**
	 * Converts a row major to column major and column major to row major (respectively)
	 *
	 * @return The converted matrix
	 ***********************************************/
	Matrix2D convertMajorOrder();

	/********************************************/ /**
	 * Returns the matrix's determinant
	 *
	 * @return det The determinant of the matrix
	 ***********************************************/
	float determinant();

	/********************************************/ /**
	 * Returns the adjoint matrix
	 *
	 * @return adj The adjoint of the matrix
	 ***********************************************/
	Matrix2D adjoint();

	/********************************************/ /**
	 * Returns the inverse matrix or throws an error if the matrix can't be inversed
	 *
	 * @return mat The inversed matrix
	 ***********************************************/
	Matrix2D inverse();

	/********************************************/ /**
	 * Returns the identity matrix
	 *
	 * @return mat The 3x3 identity matrix
	 ***********************************************/
	static Matrix2D identity();

};

#endif
