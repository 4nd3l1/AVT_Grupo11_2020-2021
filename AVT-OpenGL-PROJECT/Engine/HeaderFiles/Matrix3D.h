#ifndef MATRIX_3
#define MATRIX_3

// Matrix3D CLASS HEADER

/// Class used to represent and perform operations with 3x3 Matrices

#include<iostream>

class Vector3D;

class Matrix3D {
	private:
		float matrix[3][3] = { {0,0,0}, {0,0,0}, {0,0,0} };
	public:
		// FUNCTION DECLARATIONS
		/********************************************/ /**
		 * Creates a new Matrix3D object with all cells set to 0
		 ***********************************************/
		Matrix3D();

		/********************************************/ /**
		 * Creates a new Matrix3D object with the all cells equal to the specified value
		 *
		 * @param val The value of all cells
		 ***********************************************/
		Matrix3D(float val);

		/********************************************/ /**
		 * Creates a new Matrix3D object with the cells equal to the specified array of arrays
		 * 
		 * @param mat The array of arrays that specify our matrix cell's values
		 ***********************************************/
		Matrix3D(float mat[3][3]);

		/********************************************/ /**
		 * Overloading of the << operator. Prints our Matrix
		 ***********************************************/
		friend std::ostream& operator<<(std::ostream& output, const Matrix3D& vec);

		/********************************************/ /**
		 * Used to create a clone of the matrix (that is still a different object)
		 *
		 ***********************************************/
		Matrix3D clone();

		/********************************************/ /**
		 * Function used to get a specific cell of a Matrix3D
		 *
		 * @param row The row of the cell
		 * @param col The column of the cell
		 * @return cel The Matrix3D cell at given coordinates
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
		 * Overloading of the + operator when summing two Matrix3D
		 *
		 * @param mat The Matrix3D we want to sum with
		 * @return matSum The sum of the two matrices
		 ***********************************************/
		Matrix3D operator+(const Matrix3D& mat);

		/********************************************/ /**
		 * Overloading of the - operator when subtracting two Matrix3D
		 *
		 * @param mat The Matrix3D we want to sub with
		 * @return matSub The sub of the two matrices
		 ***********************************************/
		Matrix3D operator-(const Matrix3D& mat);

		/********************************************/ /**
		 * Overloading of the * operator when multiplying two Matrix3D
		 *
		 * @param mat The Matrix3D we want to multiply with
		 * @return matMult The multiplication of the two matrices
		 ***********************************************/
		Matrix3D operator*(const Matrix3D& mat);

		/********************************************/ /**
		 * Overloading of the * operator when multiplying a matrix and a value
		 *
		 * @param val The value we want to multiply with
		 * @return matMult The multiplication of the two matrices
		 ***********************************************/
		Matrix3D operator*(float val);

		/********************************************/ /**
		 * Overloading of the * operator when multiplying a matrix and a value
		 *
		 * @param val The value we want to multiply with
		 * @return matMult The multiplication of the two matrices
		 ***********************************************/
		friend Matrix3D operator*(float val, Matrix3D& mat);

		/********************************************/ /**
		 * Overloading of the * operator when multiplying a matrix and a Vector3D
		 *
		 * @param vec The vector we want to multiply with
		 * @return Vector3D The multiplication of the two matrices
		 ***********************************************/
		Vector3D operator*(Vector3D& vec);

		/********************************************/ /**
		 * Overloading of the * operator when multiplying a Vector and a matrix
		 *
		 * @param val The value we want to multiply with
		 * @return matMult The multiplication of the the vector and the matrix
		 ***********************************************/
		friend Vector3D operator*(Vector3D& vec, Matrix3D& mat);

		/********************************************/ /**
		 * Overloading of the / operator when dividing a matrix and a value
		 *
		 * @param val The value we want to multiply with
		 * @return matDiv The division of the two matrices
		 ***********************************************/
		Matrix3D operator/(float val);

		/********************************************/ /**
		 * Overloading of the / operator when dividing a matrix and a value
		 *
		 * @param val The value we want to multiply with
		 * @return matDiv The division of the two matrices
		 ***********************************************/
		friend Matrix3D operator/(float val, Matrix3D& mat);

		/********************************************/ /**
		 * Overloading of the += operator. Assigns new coordinates to our matrix
		 *
		 * @param mat The Matrix we want to sum to our Matrix
		 ***********************************************/
		Matrix3D& operator+=(const Matrix3D& vec);

		/********************************************/ /**
		 * Overloading of the -= operator. Assigns new coordinates to our matrix
		 *
		 * @param mat The Matrix we want to sub to our Matrix
		 ***********************************************/
		Matrix3D& operator-=(const Matrix3D& vec);

		/********************************************/ /**
		 * Overloading of the *= operator. Assigns new coordinates to our matrix
		 *
		 * @param mat The Matrix we want to multiply to our Matrix
		 ***********************************************/
		Matrix3D& operator*=(const Matrix3D& vec);

		/********************************************/ /**
		 * Overloading of the *= operator. Assigns new coordinates to our matrix
		 *
		 * @param val The value we want to multiply by
		 ***********************************************/
		Matrix3D& operator*=(float val);

		/********************************************/ /**
		 * Overloading of the * operator when multiplying a Vector and a matrix
		 *
		 * @param mat The matrix we want to use to multiply
		 ***********************************************/
		friend Vector3D operator*=(Vector3D& vec, Matrix3D& mat);

		/********************************************/ /**
		 * Overloading of the /= operator. Assigns new coordinates to our matrix
		 *
		 * @param val The value we want to multiply by
		 ***********************************************/
		Matrix3D& operator/=(float val);

		/********************************************/ /**
		 * Overloading of the = operator. Assigns new coordinates to our matrix
		 *
		 * @param mat The matrix with the coordenates to be copied
		 ***********************************************/
		Matrix3D& operator=(const Matrix3D& vec);

		/********************************************/ /**
		 * Overloading of the = operator. Assigns new coordinates to our matrix
		 *
		 * @param val The value we want our matrix cells to have
		 ***********************************************/
		Matrix3D& operator=(float val);

		/********************************************/ /**
		 * Overloading of the == operator. Verifies if 2 matrices have the same coordinates
		 *
		 * @return eq True if they have the same cells, false otherwise
		 ***********************************************/
		bool operator==(const Matrix3D& mat);

		/********************************************/ /**
		 * Overloading of the != operator. Verifies if 2 matrices have different coordinates
		 *
		 * @return eq True if they have the different coordinates, false otherwise
		 ***********************************************/
		bool operator!=(const Matrix3D& mat);

		/********************************************/ /**
		 * Returns the matrix transposed
		 *
		 * @return mat The transposed equivalent of the matrix
		 ***********************************************/
		Matrix3D transposed();

		/********************************************/ /**
		 * Converts a row major to column major and column major to row major (respectively)
		 *
		 * @return The converted matrix
		 ***********************************************/
		Matrix3D convertMajorOrder();

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
		Matrix3D adjoint();

		/********************************************/ /**
		 * Returns the inverse matrix or throws an error if the matrix can't be inversed
		 *
		 * @return mat The inversed matrix
		 ***********************************************/
		Matrix3D inverse();

		/********************************************/ /**
		 * Returns the identity matrix
		 *
		 * @return mat The 3x3 identity matrix
		 ***********************************************/
		static Matrix3D identity();

		/********************************************/ /**
		 * Returns the dual matrix according to the given vector
		 *
		 * @param vec The vector to build the dual matrix with
		 * @return mat The 3x3 dual matrix
		 ***********************************************/
		static Matrix3D dual(Vector3D& vec);
};



#endif