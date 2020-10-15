#ifndef MATRIX_4
#define MATRIX_4

// Matrix4D CLASS HEADER

// Class used to represent and perform operations with 4x4 Matrices

#include<iostream>

class Vector4D;

class Matrix4D {
private:
	float matrix[4][4] = { {0,0,0,0}, {0,0,0,0}, {0,0,0,0}, {0,0,0,0} };
public:
	// FUNCTION DECLARATIONS
	
	 // Creates a new Matrix4D object with all cells set to 0
	  
	Matrix4D();

	
	 // Creates a new Matrix4D object with the all cells equal to the specified value
	  
	Matrix4D(float val);

	
	 // Creates a new Matrix4D object with the cells equal to the specified array of arrays

	Matrix4D(float mat[4][4]);

	friend std::ostream& operator<<(std::ostream& output, const Matrix4D& vec);

	

	 // Function used to get a specific cell of a Matrix4D
 
	float get(int row, int col);

	
	 // Function used to set a specific cell's value

	void set(int row, int col, float val);

	
	 // Overloading of the + operator when summing two Matrix4D

	Matrix4D operator+(const Matrix4D& mat);

	
	 // Overloading of the - operator when subtracting two Matrix4D

	Matrix4D operator-(const Matrix4D& mat);

	
	 // Overloading of the * operator when multiplying two Matrix4D

	Matrix4D operator*(const Matrix4D& mat);

	
	 // Overloading of the * operator when multiplying a matrix and a value

	Matrix4D operator*(float val);

	
	 // Overloading of the * operator when multiplying a matrix and a value

	friend Matrix4D operator*(float val, Matrix4D& mat);

	
	 // Overloading of the * operator when multiplying a matrix and a Vector4D

	Vector4D operator*(Vector4D& vec);

	
	 // Overloading of the * operator when multiplying a Vector and a matrix

	friend Vector4D operator*(Vector4D& vec, Matrix4D& mat);

	
	 // Overloading of the / operator when dividing a matrix and a value

	Matrix4D operator/(float val);

	
	 // Overloading of the / operator when dividing a matrix and a value

	friend Matrix4D operator/(float val, Matrix4D& mat);

	
	 // Overloading of the += operator. Assigns new coordinates to our matrix

	Matrix4D& operator+=(const Matrix4D& vec);

	
	 // Overloading of the -= operator. Assigns new coordinates to our matrix

	Matrix4D& operator-=(const Matrix4D& vec);

	
	 // Overloading of the *= operator. Assigns new coordinates to our matrix

	Matrix4D& operator*=(const Matrix4D& vec);

	
	 // Overloading of the *= operator. Assigns new coordinates to our matrix

	Matrix4D& operator*=(float val);

	
	 // Overloading of the * operator when multiplying a Vector and a matrix

	friend Vector4D operator*=(Vector4D& vec, Matrix4D& mat);

	
	 // Overloading of the /= operator. Assigns new coordinates to our matrix

	Matrix4D& operator/=(float val);

	
	 // Overloading of the = operator. Assigns new coordinates to our matrix

	Matrix4D& operator=(const Matrix4D& vec);

	
	 // Overloading of the = operator. Assigns new coordinates to our matrix

	Matrix4D& operator=(float val);

	
	 // Overloading of the == operator. Verifies if 2 matrices have the same coordinates

	bool operator==(const Matrix4D& mat);

	
	 // Overloading of the != operator. Verifies if 2 matrices have different coordinates

	bool operator!=(const Matrix4D& mat);

	
	 // Returns the matrix transposed

	Matrix4D transposed();

	
	 // Converts a row major to column major and column major to row major (respectively)

	Matrix4D convertMajorOrder();

	
	 // Returns the matrix's determinant

	float determinant();

	
	 // Returns the adjoint matrix

	Matrix4D adjoint();

	
	 // Returns the inverse matrix or throws an error if the matrix can't be inversed

	Matrix4D inverse();

	
	 // Returns the identity matrix

	static Matrix4D identity();

	
	 // Returns the scaling matrix according to the given parameters

	static Matrix4D scaling(float sx, float sy, float sz, float sw);


	
	 // Returns the rotation matrix according to the given parameters

	static Matrix4D rotation(Vector4D& vec);


	
	 // Returns the translation matrix according to the given parameters

	static Matrix4D translation(Vector4D& vec);
};



#endif