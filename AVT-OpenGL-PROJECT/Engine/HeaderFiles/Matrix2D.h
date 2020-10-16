#ifndef MATRIX_2D
#define MATRIX_2D

// Matrix2D CLASS HEADER

/// Class used to represent and perform operations with 2x2 Matrices

#include<iostream>

class Vector2D;
class Matrix3D;
class Matrix4D;

class Matrix2D {
private:
	float matrix[2][2] = { {0,0}, {0,0}};
public:
	// FUNCTION DECLARATIONS
	
	 // Creates a new Matrix3 object with all cells set to 0
	  
	Matrix2D();

	
	 // Creates a new Matrix3 object with the all cells equal to the specified value

	Matrix2D(float val);

	
	 // Creates a new Matrix3 object with the cells equal to the specified array of arrays

	Matrix2D(float mat[2][2]);

	// Function used to create a Matrix2 from a Matrix3
	
	Matrix2D(Matrix3D& mat);

	// Function used to create a Matrix2 from a Matrix4
	
	Matrix2D(Matrix4D& mat);

	 // Overloading of the << operator. Prints our Matrix
	  
	friend std::ostream& operator<<(std::ostream& output, const Matrix2D& vec);

	
	 // Function used to get a specific cell of a Matrix3

	float get(int row, int col);

	
	 // Function used to set a specific cell's value

	void set(int row, int col, float val);

	
	// Overloading of the [] operator to get a row

	float* operator[](int val);

	 // Overloading of the + operator when summing two Matrix3

	Matrix2D operator+(const Matrix2D& mat);

	// Overloading of the + operator when adding a matrix and a value
	
	Matrix2D operator+(float val);
	
	 // Overloading of the - operator when subtracting two Matrix3

	Matrix2D operator-(const Matrix2D& mat);

	// Overloading of the - operator when subtracting a matrix and a value

	Matrix2D operator-(float val);

	// Overloading of the - operator when subtracting a matrix and a value

	friend Matrix2D operator-(float val, Matrix2D& mat);
	
	 // Overloading of the * operator when multiplying two Matrix3

	Matrix2D operator*(const Matrix2D& mat);

	
	 // Overloading of the * operator when multiplying a matrix and a value

	Matrix2D operator*(float val);

	
	 // Overloading of the * operator when multiplying a matrix and a value
	friend Matrix2D operator*(float val, Matrix2D& mat);

	
	 // Overloading of the * operator when multiplying a matrix and a Vector3

	Vector2D operator*(Vector2D& vec);

	
	 // Overloading of the * operator when multiplying a Vector and a matrix

	friend Vector2D operator*(Vector2D& vec, Matrix2D& mat);

	
	 // Overloading of the / operator when dividing a matrix and a value

	Matrix2D operator/(float val);

	
	 // Overloading of the / operator when dividing a matrix and a value

	friend Matrix2D operator/(float val, Matrix2D& mat);

	
	 // Overloading of the += operator. Assigns new coordinates to our matrix

	Matrix2D& operator+=(const Matrix2D& vec);

	
	 // Overloading of the -= operator. Assigns new coordinates to our matrix

	Matrix2D& operator-=(const Matrix2D& vec);

	
	 // Overloading of the *= operator. Assigns new coordinates to our matrix

	Matrix2D& operator*=(const Matrix2D& vec);

	
	 // Overloading of the *= operator. Assigns new coordinates to our matrix

	Matrix2D& operator*=(float val);

	
	 // Overloading of the * operator when multiplying a Vector and a matrix

	friend Vector2D operator*=(Vector2D& vec, Matrix2D& mat);

	
	 // Overloading of the /= operator. Assigns new coordinates to our matrix

	Matrix2D& operator/=(float val);

	
	 // Overloading of the = operator. Assigns new coordinates to our matrix

	Matrix2D& operator=(const Matrix2D& vec);

	
	 // Overloading of the = operator. Assigns new coordinates to our matrix
	 
	Matrix2D& operator=(float val);

	
	 // Overloading of the == operator. Verifies if 2 matrices have the same coordinates

	bool operator==(const Matrix2D& mat);

	
	 // Overloading of the != operator. Verifies if 2 matrices have different coordinates

	bool operator!=(const Matrix2D& mat);

	
	 // Returns the matrix transposed

	Matrix2D transposed();

	
	 // Transposes the matrix

	Matrix2D& transpose();

	
	 // Returns the matrix's determinant

	float determinant();

	
	 // Returns the adjoint matrix

	Matrix2D adjoint();

	
	 // Returns the inverse matrix or throws an error if the matrix can't be inversed

	Matrix2D inverse();

	
	 // Returns the identity matrix

	static Matrix2D identity();

	// Returns the aditive identity matrix

	static Matrix2D AditiveIdentity();

	// Returns the multiplicative identity matrix

	static Matrix2D MultiplicativeIdentity();

	// Returns the matrix in ColMajor format

	void getColMajor(float array[4]);

	// Returns the matrix in RowMajor format

	void getRowMajor(float array[4]);

};

#endif
