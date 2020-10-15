#ifndef MATRIX_3D
#define MATRIX_3D

// Matrix3D CLASS HEADER

/// Class used to represent and perform operations with 3x3 Matrices

#include<iostream>

class Vector3D;
class Matrix2D;
class Matrix4D;

class Matrix3D {
	private:
		float matrix[3][3] = { {0,0,0}, {0,0,0}, {0,0,0} };
	public:
		// FUNCTION DECLARATIONS
		
		 // Creates a new Matrix3D object with all cells set to 0
		  
		Matrix3D();

		
		 // Creates a new Matrix3D object with the all cells equal to the specified value

		Matrix3D(float val);

		
		 // Creates a new Matrix3D object with the cells equal to the specified array of arrays

		Matrix3D(float mat[3][3]);

		// Function used to create a Matrix3 from a Matrix2
		
		Matrix3D(Matrix2D& mat);

		// Function used to create a Matrix3 from a Matrix4
		
		Matrix3D(Matrix4D& mat);

		
		 // Overloading of the << operator. Prints our Matrix
		  
		friend std::ostream& operator<<(std::ostream& output, const Matrix3D& vec);

	
		
		 // Function used to get a specific cell of a Matrix3D

		float get(int row, int col);

		
		 // Function used to set a specific cell's value

		void set(int row, int col, float val);

		// Overloading of the [] operator to get a row
	
		float* operator[](int val);
		
		 // Overloading of the + operator when summing two Matrix3D

		Matrix3D operator+(const Matrix3D& mat);

		// Overloading of the + operator when adding a matrix and a value
		
		Matrix3D operator+(float val);

		// Overloading of the + operator when adding a matrix and a value
		
		friend Matrix3D operator+(float val, Matrix3D& mat);
		
		 // Overloading of the - operator when subtracting two Matrix3D

		Matrix3D operator-(const Matrix3D& mat);

		// Overloading of the - operator when subtracting a matrix and a value
		
		Matrix3D operator-(float val);

		// Overloading of the - operator when subtracting a matrix and a value
		
		friend Matrix3D operator-(float val, Matrix3D& mat);
		
		 // Overloading of the * operator when multiplying two Matrix3D

		Matrix3D operator*(const Matrix3D& mat);

		
		 // Overloading of the * operator when multiplying a matrix and a value

		Matrix3D operator*(float val);

		
		 // Overloading of the * operator when multiplying a matrix and a value

		friend Matrix3D operator*(float val, Matrix3D& mat);

		
		 // Overloading of the * operator when multiplying a matrix and a Vector3D

		Vector3D operator*(Vector3D& vec);

		
		 // Overloading of the * operator when multiplying a Vector and a matrix

		friend Vector3D operator*(Vector3D& vec, Matrix3D& mat);

		
		 // Overloading of the / operator when dividing a matrix and a value

		Matrix3D operator/(float val);

		
		 // Overloading of the / operator when dividing a matrix and a value

		friend Matrix3D operator/(float val, Matrix3D& mat);

		
		 // Overloading of the += operator. Assigns new coordinates to our matrix

		Matrix3D& operator+=(const Matrix3D& vec);

		
		 // Overloading of the -= operator. Assigns new coordinates to our matrix
  
		Matrix3D& operator-=(const Matrix3D& vec);

		
		 // Overloading of the *= operator. Assigns new coordinates to our matrix

		Matrix3D& operator*=(const Matrix3D& vec);

		
		 // Overloading of the *= operator. Assigns new coordinates to our matrix

		Matrix3D& operator*=(float val);

		
		 // Overloading of the * operator when multiplying a Vector and a matrix

		friend Vector3D operator*=(Vector3D& vec, Matrix3D& mat);

		
		 // Overloading of the /= operator. Assigns new coordinates to our matrix

		Matrix3D& operator/=(float val);

		
		 // Overloading of the = operator. Assigns new coordinates to our matrix

		Matrix3D& operator=(const Matrix3D& vec);

		
		 // Overloading of the = operator. Assigns new coordinates to our matrix

		Matrix3D& operator=(float val);

		
		 // Overloading of the == operator. Verifies if 2 matrices have the same coordinates

		bool operator==(const Matrix3D& mat);

		
		 // Overloading of the != operator. Verifies if 2 matrices have different coordinates

		bool operator!=(const Matrix3D& mat);

		
		 // Returns the matrix transposed

		Matrix3D transposed();

		
		 // Converts a row major to column major and column major to row major (respectively)

		Matrix3D convertMajorOrder();

		
		 // Returns the matrix's determinant

		float determinant();

		
		 // Returns the adjoint matrix

		Matrix3D adjoint();

		
		 // Returns the inverse matrix or throws an error if the matrix can't be inversed

		Matrix3D inverse();

		
		 // Returns the identity matrix

		static Matrix3D identity();

		
		 // Returns the dual matrix according to the given vector

		static Matrix3D dual(Vector3D& vec);
};



#endif