#ifndef MATRIX_4D
#define MATRIX_4D

// Matrix4D CLASS HEADER

// Class used to represent and perform operations with 4x4 Matrices

#include<iostream>

#include "../HeaderFiles/Vector3D.h"

class Vector4D;
class Vector3D;
class Matrix2D;
class Matrix3D;

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

	//Function used to create a Matrix4 from a Matrix2
	
	Matrix4D(Matrix2D& mat);

	// Function used to create a Matrix4 from a Matrix3
	
	Matrix4D(Matrix3D& mat);

	// Overflow do operador >>

	friend std::ostream& operator<<(std::ostream& output, const Matrix4D& vec);

	 // Function used to get a specific cell of a Matrix4D
 
	float get(int row, int col);

	
	 // Function used to set a specific cell's value

	void set(int row, int col, float val);

	// Overloading of the [] operator to get a row

	float* operator[](int val);
	
	 // Overloading of the + operator when summing two Matrix4D

	Matrix4D operator+(const Matrix4D& mat);

	// Overloading of the + operator when adding a matrix and a value
	
	Matrix4D operator+(float val);

	// Overloading of the + operator when adding a matrix and a value

	friend Matrix4D operator+(float val, Matrix4D& mat);
	
	 // Overloading of the - operator when subtracting two Matrix4D

	Matrix4D operator-(const Matrix4D& mat);

	// Overloading of the - operator when subtracting a matrix and a value

	Matrix4D operator-(float val);

	// Overloading of the - operator when subtracting a matrix and a value

	friend Matrix4D operator-(float val, Matrix4D& mat);
	
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

	
	// Transposes the matrix

	Matrix4D& transpose();

	
	 // Returns the adjoint matrix

	Matrix4D adjoint();


	
	 // Returns the identity matrix

	static Matrix4D identity();

	static Matrix4D scaling(float sx, float sy, float sz);

	// Returns the scaling matrix according to the given parameters (vector)

	static Matrix4D scaling(Vector3D& vec);

	// Returns the rotation matrix according to the given parameters

	static Matrix4D rotation(float rx, float ry, float rz, bool radians = true, bool round = false);

	// Returns the rotation matrix according to the given parameters (vector)

	static Matrix4D rotation(Vector3D& vec, bool radians = true, bool round = false);

	// Returns the rotation matrix over the X axis
	 
	static Matrix4D rotationX(float ang, bool radians = true, bool round = false);

	// Returns the rotation matrix over the Y axis
	
	static Matrix4D rotationY(float ang, bool radians = true, bool round = false);

	// Returns the rotation matrix over the Z axis
	 
	static Matrix4D rotationZ(float ang, bool radians = true, bool round = false);

	// Returns the translation matrix according to the given parameters
	 
	static Matrix4D translation(float tx, float ty, float tz);

	// Returns the translation matrix according to the given parameters (vector)
	 
	static Matrix4D translation(Vector3D& vec);

	// Returns the matrix in ColMajor format

	void getColMajor(float array[16]);

	// Returns the matrix in RowMajor format

	void getRowMajor(float array[16]);
};



#endif