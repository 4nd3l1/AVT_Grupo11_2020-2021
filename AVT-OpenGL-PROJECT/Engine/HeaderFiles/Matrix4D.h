#ifndef MATRIX_4
#define MATRIX_4

// Matrix4D CLASS HEADER

/// Class used to represent and perform operations with 4x4 Matrices

#include<iostream>

class Vector4D;

class Matrix4D {
private:
	float matrix[4][4] = { {0,0,0,0}, {0,0,0,0}, {0,0,0,0}, {0,0,0,0} };
public:
	// FUNCTION DECLARATIONS
	/********************************************/ /**
	 * Creates a new Matrix4D object with all cells set to 0
	 ***********************************************/
	Matrix4D();

	/********************************************/ /**
	 * Creates a new Matrix4D object with the all cells equal to the specified value
	 *
	 * @param val The value of all cells
	 ***********************************************/
	Matrix4D(float val);

	/********************************************/ /**
	 * Creates a new Matrix4D object with the cells equal to the specified array of arrays
	 *
	 * @param mat The array of arrays that specify our matrix cell's values
	 ***********************************************/
	Matrix4D(float mat[4][4]);

	/********************************************/ /**
	 * Overloading of the << operator. Prints our Matrix
	 ***********************************************/
	friend std::ostream& operator<<(std::ostream& output, const Matrix4D& vec);

	/********************************************/ /**
	 * Used to create a clone of the matrix (that is still a different object)
	 *
	 ***********************************************/
	Matrix4D clone();

	/********************************************/ /**
	 * Function used to get a specific cell of a Matrix4D
	 *
	 * @param row The row of the cell
	 * @param col The column of the cell
	 * @return cel The Matrix4D cell at given coordinates
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
	 * Overloading of the + operator when summing two Matrix4D
	 *
	 * @param mat The Matrix4D we want to sum with
	 * @return matSum The sum of the two matrices
	 ***********************************************/
	Matrix4D operator+(const Matrix4D& mat);

	/********************************************/ /**
	 * Overloading of the - operator when subtracting two Matrix4D
	 *
	 * @param mat The Matrix4D we want to sub with
	 * @return matSub The sub of the two matrices
	 ***********************************************/
	Matrix4D operator-(const Matrix4D& mat);

	/********************************************/ /**
	 * Overloading of the * operator when multiplying two Matrix4D
	 *
	 * @param mat The Matrix4D we want to multiply with
	 * @return matMult The multiplication of the two matrices
	 ***********************************************/
	Matrix4D operator*(const Matrix4D& mat);

	/********************************************/ /**
	 * Overloading of the * operator when multiplying a matrix and a value
	 *
	 * @param val The value we want to multiply with
	 * @return matMult The multiplication of the two matrices
	 ***********************************************/
	Matrix4D operator*(float val);

	/********************************************/ /**
	 * Overloading of the * operator when multiplying a matrix and a value
	 *
	 * @param val The value we want to multiply with
	 * @return matMult The multiplication of the two matrices
	 ***********************************************/
	friend Matrix4D operator*(float val, Matrix4D& mat);

	/********************************************/ /**
	 * Overloading of the * operator when multiplying a matrix and a Vector4D
	 *
	 * @param vec The vector we want to multiply with
	 * @return Vector4D The multiplication of the two matrices
	 ***********************************************/
	Vector4D operator*(Vector4D& vec);

	/********************************************/ /**
	 * Overloading of the * operator when multiplying a Vector and a matrix
	 *
	 * @param val The value we want to multiply with
	 * @return matMult The multiplication of the the vector and the matrix
	 ***********************************************/
	friend Vector4D operator*(Vector4D& vec, Matrix4D& mat);

	/********************************************/ /**
	 * Overloading of the / operator when dividing a matrix and a value
	 *
	 * @param val The value we want to multiply with
	 * @return matDiv The division of the two matrices
	 ***********************************************/
	Matrix4D operator/(float val);

	/********************************************/ /**
	 * Overloading of the / operator when dividing a matrix and a value
	 *
	 * @param val The value we want to multiply with
	 * @return matDiv The division of the two matrices
	 ***********************************************/
	friend Matrix4D operator/(float val, Matrix4D& mat);

	/********************************************/ /**
	 * Overloading of the += operator. Assigns new coordinates to our matrix
	 *
	 * @param mat The Matrix we want to sum to our Matrix
	 ***********************************************/
	Matrix4D& operator+=(const Matrix4D& vec);

	/********************************************/ /**
	 * Overloading of the -= operator. Assigns new coordinates to our matrix
	 *
	 * @param mat The Matrix we want to sub to our Matrix
	 ***********************************************/
	Matrix4D& operator-=(const Matrix4D& vec);

	/********************************************/ /**
	 * Overloading of the *= operator. Assigns new coordinates to our matrix
	 *
	 * @param mat The Matrix we want to multiply to our Matrix
	 ***********************************************/
	Matrix4D& operator*=(const Matrix4D& vec);

	/********************************************/ /**
	 * Overloading of the *= operator. Assigns new coordinates to our matrix
	 *
	 * @param val The value we want to multiply by
	 ***********************************************/
	Matrix4D& operator*=(float val);

	/********************************************/ /**
	 * Overloading of the * operator when multiplying a Vector and a matrix
	 *
	 * @param mat The matrix we want to use to multiply
	 ***********************************************/
	friend Vector4D operator*=(Vector4D& vec, Matrix4D& mat);

	/********************************************/ /**
	 * Overloading of the /= operator. Assigns new coordinates to our matrix
	 *
	 * @param val The value we want to multiply by
	 ***********************************************/
	Matrix4D& operator/=(float val);

	/********************************************/ /**
	 * Overloading of the = operator. Assigns new coordinates to our matrix
	 *
	 * @param mat The matrix with the coordenates to be copied
	 ***********************************************/
	Matrix4D& operator=(const Matrix4D& vec);

	/********************************************/ /**
	 * Overloading of the = operator. Assigns new coordinates to our matrix
	 *
	 * @param val The value we want our matrix cells to have
	 ***********************************************/
	Matrix4D& operator=(float val);

	/********************************************/ /**
	 * Overloading of the == operator. Verifies if 2 matrices have the same coordinates
	 *
	 * @return eq True if they have the same cells, false otherwise
	 ***********************************************/
	bool operator==(const Matrix4D& mat);

	/********************************************/ /**
	 * Overloading of the != operator. Verifies if 2 matrices have different coordinates
	 *
	 * @return eq True if they have the different coordinates, false otherwise
	 ***********************************************/
	bool operator!=(const Matrix4D& mat);

	/********************************************/ /**
	 * Returns the matrix transposed
	 *
	 * @return mat The transposed equivalent of the matrix
	 ***********************************************/
	Matrix4D transposed();

	/********************************************/ /**
	 * Converts a row major to column major and column major to row major (respectively)
	 *
	 * @return The converted matrix
	 ***********************************************/
	Matrix4D convertMajorOrder();

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
	Matrix4D adjoint();

	/********************************************/ /**
	 * Returns the inverse matrix or throws an error if the matrix can't be inversed
	 *
	 * @return mat The inversed matrix
	 ***********************************************/
	Matrix4D inverse();

	/********************************************/ /**
	 * Returns the identity matrix
	 *
	 * @return mat The 4x4 identity matrix
	 ***********************************************/
	static Matrix4D identity();

	/********************************************/ /**
	 * Returns the scaling matrix according to the given parameters
	 *
	 * @param sx The x value to use on the scaling
	 * @param sy The y value to use on the scaling
	 * @param sz The z value to use on the scaling
	 * @param sw The w value to use on the scaling
	 * @return mat The 4x4 dual matrix
	 ***********************************************/
	static Matrix4D scaling(float sx, float sy, float sz, float sw);


	/********************************************/ /**
	 * Returns the rotation matrix according to the given parameters
	 *
	 * @param vec The parameters to use on the scaling
	 * @return mat The 4x4 dual matrix
	 ***********************************************/
	static Matrix4D rotation(Vector4D& vec);


	/********************************************/ /**
	 * Returns the translation matrix according to the given parameters
	 *
	 * @param vec The parameters to use on the scaling
	 * @return mat The 4x4 dual matrix
	 ***********************************************/
	static Matrix4D translation(Vector4D& vec);
};



#endif