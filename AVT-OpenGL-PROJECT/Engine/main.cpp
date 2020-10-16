
#include <iostream>
#include <sstream>
#include <iomanip>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "HeaderFiles/Vector2D.h"
#include "HeaderFiles/Vector3D.h"
#include "HeaderFiles/Vector4D.h"
#include "HeaderFiles/Matrix2D.h"
#include "HeaderFiles/Matrix3D.h"
#include "HeaderFiles/Matrix4D.h"


////////////////////////////////////////////////////////////////////////// MAIN

void test2D() {
	Vector2D v1;
	Vector2D v2(0.1f, 0.2f);

	std::cout << "Test constructor #1: " << v1.toString() << "\n";
	std::cout << "Test constructor #2: " << v2.toString() << "\n";



	std::cout << "Test operator v1 += v2: " << (v1 += v2).toString() << "\n";

	std::cout << "Test operator v1 + v2: " << (v1 + v2).toString() << "\n";

	std::cout << "Test operator v1 -= v2: " << (v1 -= v2).toString() << "\n";

	std::cout << "Test operator v1 - v2: " << (v1 - v2).toString() << "\n";

	std::cout << "Test operator v2 *= 2.0f: " << (v2 *= 2.0f).toString() << "\n";

	std::cout << "Test operator v2 * 2.0f: " << (v2 * 2.0f).toString() << "\n";

	std::cout << "Test operator float 2.0f * v2 : " << (2.0f * v2).toString() << "\n";

	std::cout << "Test operator v2 /= 2.0f: " << (v2 /= 2.0f).toString() << "\n";

	std::cout << "Test operator v2 / 2.0f: " << (v2 / 2.0f).toString() << "\n";

	std::cout << "Test operator 2.0f / v2: " << (2.0f / v1).toString() << "\n";

	std::cout << "Test v1 dot v2: " << v1.dot(v2) << "\n";

	std::cout << "Test -v2: " << (-v2).toString() << "\n";

	Vector2D v4;
	Vector2D v5;
	Vector2D v6(0.1f, 0.1f);
	std::cout << "Test compare v4(0,0) = v5(0,0) : " << (v4 == v5) << "\n";
	std::cout << "Test compare v4(0,0) = v6(0.1f, 0.1f) : " << (v4 == v6) << "\n";

	std::cout << "Test lenght v1: " << v1.length() << "\n";

	v2.normalize();
	std::cout << "Test normalize v2: " << v2.toString() << "\n";

}


void test3D() {

	Vector3D v1;
	Vector3D v2 (0.1f, 0.2f, 0.3f);

	std::cout << "Test constructor #1: " << v1.toString() << "\n";
	std::cout << "Test constructor #2: " << v2.toString() << "\n";


	std::cout << "Test operator v1 += v2: " << (v1 += v2).toString() << "\n";

	std::cout << "Test operator v1 + v2: " << (v1 + v2).toString() << "\n";

	std::cout << "Test operator v1 -= v2: " << (v1 -= v2).toString() << "\n";

	std::cout << "Test operator v1 - v2: " << (v1 - v2).toString() << "\n";

	std::cout << "Test operator v2 *= 2.0f: " << (v2 *= 2.0f).toString() << "\n";

	std::cout << "Test operator v2 * 2.0f: " << (v2 * 2.0f).toString() << "\n";

	std::cout << "Test operator float 2.0f * v2 : " << (2.0f * v2).toString() << "\n";

	std::cout << "Test operator v2 /= 2.0f: " << (v2 /= 2.0f).toString() << "\n";

	std::cout << "Test operator v2 / 2.0f: " << (v2 / 2.0f).toString() << "\n";

	std::cout << "Test operator 2.0f / v2: " << (2.0f / v1).toString() << "\n";

	std::cout << "Test v1 cross v2: " << v1.cross(v2).toString() << "\n";

	std::cout << "Test v1 dot v2: " << v1.dot(v2) << "\n";

	std::cout << "Test -v2: " << (-v2).toString() << "\n";

	Vector3D v4;
	Vector3D v5;
	Vector3D v6 (0.1f, 0.1f, 0.1f);
	std::cout << "Test compare v4(0,0,0) = v5(0,0,0) : " << (v4 == v5) << "\n";
	std::cout << "Test compare v4(0,0,0) = v6(0.1f, 0.1f, 0.1f) : " << (v4 == v6) << "\n";

	std::cout << "Test lenght v1: " << v1.length() << "\n";

	v2.normalize();
	std::cout << "Test normalize v2: " << v2.toString() << "\n";
}


void test4D() {
	Vector4D v1;
	Vector4D v2(0.1f, 0.2f, 0.3f, 0.4f);

	std::cout << "Test constructor #1: " << v1.toString() << "\n";
	std::cout << "Test constructor #2: " << v2.toString() << "\n";


	std::cout << "Test operator v1 += v2: " << (v1 += v2).toString() << "\n";

	std::cout << "Test operator v1 + v2: " << (v1 + v2).toString() << "\n";

	std::cout << "Test operator v1 -= v2: " << (v1 -= v2).toString() << "\n";

	std::cout << "Test operator v1 - v2: " << (v1 - v2).toString() << "\n";

	std::cout << "Test operator v2 *= 2.0f: " << (v2 *= 2.0f).toString() << "\n";

	std::cout << "Test operator v2 * 2.0f: " << (v2 * 2.0f).toString() << "\n";

	std::cout << "Test operator float 2.0f * v2 : " << (2.0f * v2).toString() << "\n";

	std::cout << "Test operator v2 /= 2.0f: " << (v2 /= 2.0f).toString() << "\n";

	std::cout << "Test operator v2 / 2.0f: " << (v2 / 2.0f).toString() << "\n";

	std::cout << "Test operator 2.0f / v2: " << (2.0f / v1).toString() << "\n";

	std::cout << "Test v1 dot v2: " << v1.dot(v2) << "\n";

	std::cout << "Test -v2: " << (-v2).toString() << "\n";

	Vector4D v4;
	Vector4D v5;
	Vector4D v6(0.1f, 0.1f, 0.1f, 0.1f);
	std::cout << "Test compare v4(0,0,0,0) = v5(0,0,0,0) : " << (v4 == v5) << "\n";
	std::cout << "Test compare v4(0,0,0) = v6(0.1f, 0.1f, 0.1f, 0.1f) : " << (v4 == v6) << "\n";

	std::cout << "Test lenght v1: " << v1.length() << "\n";

	v2.normalize();
	std::cout << "Test normalize v2: " << v2.toString() << "\n";
}

void testVectors() {
	int choice;
	std::cout << "Select '2', '3' or '4' if you want to test 2D, 3D or 4D vectors respectively: \n";
	std::cin >> choice;
	switch (choice) {
		case(2):
		{
			test2D();
			break;
		}	

		case(3):
		{
			test3D();
			break;
		}

		default:
		{
			test4D();
			break;
		}
	}
}

void createVector() {
	std::cout << "Select '2', '3' or '4' if you want to create a 2D, 3D or 4D vectors respectively \n";
	int choice;
	std::cin >> choice;
	float x, y, z, w;
	switch (choice) {
		case(2):
		{
			std::cout << "Please enter the coordinates for the vector with a space as interval: \n";
			std::cin >> x;
			std::cin >> y;
			Vector2D vec2 (x, y);
			std::cout << "Vector successfully created! - " << vec2.toString() << " \n";
			break;
		}
		
		case(3):
		{
			std::cout << "Please enter the coordinates for the vector with a space as interval: \n";
			std::cin >> x;
			std::cin >> y;
			std::cin >> z;
			Vector3D vec3 (x, y, z);
			std::cout << "Vector successfully created! - " << vec3.toString() << " \n";
			break;
		}
		
		default:
		{
			std::cout << "Please enter the coordinates for the vector with a space as interval: \n";
			std::cin >> x;
			std::cin >> y;
			std::cin >> z;
			std::cin >> w;
			Vector4D vec4 (x, y, z, w);
			std::cout << "Vector successfully created! - " << vec4.toString() << " \n";
			break;
		}	
	}
}

void vectorsMenu() {
	while (true) {
		std::cout << "Please enter '1' to create a vector, '2' to test vector related methods, or '3' to exit: \n";
		int choice;
		std::cin >> choice;
		switch (choice) {
			case 1:
				createVector();
				break;
			case 2:
				testVectors();
				break;
			default:
				break;
		}
		if (choice == 3) {
			break;
		}
	}
	
}


// CHALLENGE

void challenge() {
	
	float randomBetween; 
	float matrix4[4][4] = { {0,0,0,0}, {0,0,0,0}, {0,0,0,0}, {0,0,0,0} };
	float matrix3[3][3] = { {0,0,0}, {0,0,0}, {0,0,0} };
	float matrix2[2][2] = { {0,0}, {0,0} };
	
	Matrix2D mat21;
	Matrix2D mat22;
	Matrix3D mat31;
	Matrix3D mat32;
	Matrix4D mat41;
	Matrix4D mat42;

	// EXERCICIO 1
	std::cout << "Exercico 1 " << "\n";
	for (int row = 0; row < 4; row++) {
		for (int col = 0; col < 4; col++) {
			randomBetween = rand() % (10 - (-10)) + 10;
			matrix4[row][col] = randomBetween;
		}
	}

	mat41 = matrix4;

	for (int row = 0; row < 3; row++) {
		for (int col = 0; col < 3; col++) {
			randomBetween = rand() % (10 - (-10)) + 10;
			matrix3[row][col] = randomBetween;
		}
	}

	mat31 = matrix3;

	for (int row = 0; row < 2; row++) {
		for (int col = 0; col < 2; col++) {
			randomBetween = rand() % (10 - (-10)) + 10;
			matrix2[row][col] = randomBetween;
		}
	}

	mat21 = matrix2;

	for (int row = 0; row < 4; row++) {
		for (int col = 0; col < 4; col++) {
			randomBetween = rand() % (10 - (-10)) + 10;
			matrix4[row][col] = randomBetween;
		}
	}

	mat42 = matrix4;

	for (int row = 0; row < 3; row++) {
		for (int col = 0; col < 3; col++) {
			randomBetween = rand() % (10 - (-10)) + 10;
			matrix3[row][col] = randomBetween;
		}
	}

	mat32 = matrix3;

	for (int row = 0; row < 2; row++) {
		for (int col = 0; col < 2; col++) {
			randomBetween = rand() % (10 - (-10)) + 10;
			matrix2[row][col] = randomBetween;
		}
	}

	mat22 = matrix2;

	std::cout << "Matrix2D A: " << mat21 << "\n";
	std::cout << "Matrix2D B: " << mat22 << "\n";

	std::cout << "Matrix3D A: " << mat31 << "\n";
	std::cout << "Matrix3D B: " << mat32 << "\n";

	std::cout << "Matrix4D A: " << mat41 << "\n";
	std::cout << "Matrix4D B: " << mat42 << "\n";


	std::cout << "Matrix2D:   (A*B)T = BT*AT :       " << (((mat21 * mat22).transposed()) == ((mat22.transposed()) * (mat21.transposed()))) << "\n";
	std::cout << "Matrix2D:   (A*B)-1 = ((B)-1)*((A)-1) :       " << (((mat21 * mat22).inverse()) == ((mat22.inverse()) * (mat21.inverse()))) << "\n";

	std::cout << "Matrix3D:   (A*B)T = BT*AT :       " << (((mat31 * mat32).transposed()) == ((mat32.transposed()) * (mat31.transposed()))) << "\n";
	std::cout << "Matrix3D:   (A*B)-1 = ((B)-1)*((A)-1) :       " << (((mat31 * mat32).inverse()) == ((mat32.inverse()) * (mat31.inverse()))) << "\n";

	std::cout << "Matrix4D:   (A*B)T = BT*AT :       " << (((mat41 * mat42).transposed()) == ((mat42.transposed()) * (mat41.transposed()))) << "\n";




	// EXERCICIO 2

	std::cout << "\n\n" << "Exercico 2 " << "\n";
	Matrix3D M (new float[3][3] { {2,3,1}, {3,4,1}, {3,7,2} });
	Matrix3D N (new float[3][3]{ {1,0,0}, {0,0,-2}, {-5,0,9} });

	std::cout << "(M)T :    " << (M.transposed()) << "\n";

	std::cout << "(N)T :    " << (N.transposed()) << "\n";

	std::cout << "|M| :    " << (M.determinant()) << "\n";

	std::cout << "|N| :    " << (N.determinant()) << "\n";


	std::cout << "(M)-1 :   " << (M.inverse()) << "\n";

	std::cout << "(N)-1 :   " << (N.inverse()) << "\n";


	float arrayM[9];
	std::cout << (arrayM) << "\n";
	M.getColMajor(arrayM);

	


	//for (int i = 0; i < 9; i++)
	//	std::cout << arrayM[i] << " ";
	//std::cout << "\n";

	//float arrayN[9];
	//M.getColMajor(arrayN);

	//for (int i = 0; i < 9; i++)
	//	std::cout << arrayN[i] << " ";
	//std::cout << "\n";



	// EXERCICIO 3

	std::cout << "\n\n" << "Exercico 3 " << "\n";
	float PI = atan(1) * 4;
	Matrix4D T = Matrix4D::translation(4, 5, 6);
	Matrix4D S = Matrix4D::scaling(4, 5, 6);
	Matrix4D R = Matrix4D::rotationZ(34, false);
	Matrix4D Tr(new float[4][4]{ {1,0,0,4}, { 0,1,0,5 }, { 0,0,1,6 }, { 0,0,0,1 } });
	Matrix4D Sr(new float[4][4]{ {4,0,0,0}, { 0,5,0,0 }, { 0,0,6,0 }, { 0,0,0,1 } });
	Matrix4D Rr(new float[4][4]{ {cos(34 * (PI / 180)),-sin(34 * (PI / 180)),0,0}, { sin(34 * (PI / 180)),cos(34 * (PI / 180)),0,0 }, { 0,0,1,0 }, { 0,0,0,1 } });
	std::cout << "T: " << T << "\n";
	std::cout << "S: " << S << "\n";
	std::cout << "R: " << R << "\n";
	std::cout << "Tr: " << Tr << "\n";
	std::cout << "Sr: " << Sr << "\n";
	std::cout << "Rr: " << Rr << "\n";
	std::cout << "T == Tr: " << (T == Tr) << "\n";
	std::cout << "S == Sr: " << (S == Sr) << "\n";
	std::cout << "R == Rr: " << (R == Rr) << "\n";
}


int main(int argc, char* argv[])
{
	int gl_major = 4, gl_minor = 3;
	int is_fullscreen = 0;
	int is_vsync = 1;

	// Challenge 2
	challenge();



/*


	std::cout << "=====================MATRIX 3x3=====================\n";

	std::cout << "=======CONSTRUCTORS, SETTERS & GETTERS=======\n";

	Matrix3D mat1;
	std::cout << "Matrix 1: " << mat1 << "\n";

	Matrix3D mat2(new float[3][3]{ {1,2,3},{4,5,6},{7,8,9} });
	std::cout << "Matrix 2: " << mat2 << "\n";

	std::cout << "Matrix 2 [2][2]: " << mat2.get(2, 2) << "\n";

	mat2.set(2, 2, 10);
	std::cout << "Matrix 2 [2][2] after Set: " << mat2.get(2, 2) << "\n\n";

	Matrix3D mat3(1);
	std::cout << "Matrix 3: " << mat3 << "\n";


	std::cout << "\n=======MATRIX-MATRIX OPERATORS=======\n";
	std::cout << "Matrix 1: " << mat1 << "\n";
	std::cout << "Matrix 2: " << mat2 << "\n";
	std::cout << "Matrix3: " << mat3 << "\n";

	std::cout << "Matrix1 + Matrix2 = " << mat1 + mat2 << "\n";
	std::cout << "Matrix2 - Matrix1 = " << mat1 - mat2 << "\n";

	std::cout << "Matrix3 * Matrix2 = " << mat3 * mat2 << "\n";
	std::cout << "Matrix2 * Matrix3 = " << mat2 * mat3 << "\n";


	std::cout << "\n=======MATRIX-SCALAR OPERATORS=======\n";
	std::cout << "Matrix3: " << mat3 << "\n";

	std::cout << "Matrix3 * 2 = " << mat3 * 2 << "\n";
	std::cout << "1/2.0f * Matrix3 = " << 1 / 2.0f * mat3 << "\n";

	std::cout << "Matrix3 / 4 = " << mat3 / 4 << "\n";
	std::cout << "4.0f / Matrix3 = " << 4.0f / mat3 << "\n";

	std::cout << "\n=======MATRIX-VECTOR OPERATORS=======\n";
	std::cout << "Matrix3: " << mat3;

	Vector3D vec1(1, 2, 3);
	std::cout << "Vector1: " << vec1.toString() << "\n";

	std::cout << "Matrix3 * Vector1 = " << (mat3 * vec1).toString() << "\n";
	std::cout << "Vector1 * Matrix3 = " << (vec1 * mat3).toString() << "\n\n";

	std::cout << "Matrix2: " << mat2;
	std::cout << "Vector1: " << vec1.toString() << "\n";

	std::cout << "Matrix2 * Vector1 = " << (mat2 * vec1).toString() << "\n";
	std::cout << "Vector1 * Matrix2 = " << (vec1 * mat2).toString() << "\n";

	std::cout << "\n=======ASSIGNMENTS=======\n";
	std::cout << "Matrix3: " << mat3;

	vec1.setX(1);
	vec1.setY(2);
	vec1.setZ(3);
	std::cout << "Vector1: " << vec1.toString() << "\n";

	Matrix3D mat4;
	std::cout << "Matrix4: " << mat4;

	mat4 = mat3;
	std::cout << "Matrix4 = Matrix3: " << mat4;

	mat4 += mat3;
	std::cout << "Matrix4 += Matrix3: " << mat4;

	mat4 -= mat3;
	std::cout << "Matrix4 -= Matrix3: " << mat4;

	mat4 += 1;
	std::cout << "Matrix4 += 1: " << mat4;

	mat4 -= 1;
	std::cout << "Matrix4 -= 1: " << mat4;

	mat4 = 1;
	std::cout << "Matrix4 = 1: " << mat4;

	mat4 *= mat3;
	std::cout << "Matrix4 *= Matrix3: " << mat4;

	mat4 *= 2;
	std::cout << "Matrix4 *= 2: " << mat4;

	mat4 /= 2;
	std::cout << "Matrix4 /= 2: " << mat4;

	vec1 *= mat4;
	std::cout << "Vector1 /= Matrix4: " << vec1.toString();

	std::cout << "\n=======COMPARISSONS=======\n";
	std::cout << "Matrix1: " << mat1;
	std::cout << "Matrix2: " << mat2;

	mat3 = mat2;
	std::cout << "Matrix3: " << mat3;

	std::cout << "Matrix1 == Matrix2 : " << (mat1 == mat2) << "\n";
	std::cout << "Matrix1 != Matrix2 : " << (mat1 != mat2) << "\n";

	std::cout << "Matrix3 == Matrix2 : " << (mat3 == mat2) << "\n";
	std::cout << "Matrix2 != Matrix3 : " << (mat2 != mat3) << "\n";

	std::cout << "\n=======MATRIX METHODS=======\n";
	std::cout << "Matrix1: " << mat1;
	mat2 = Matrix3D(new float[3][3]{ {1,2,3},{0,1,4},{5,6,0} });
	std::cout << "Matrix2: " << mat2 << "\n";

	std::cout << "Transposed Matrix1: " << mat1.transposed();
	std::cout << "Transposed Matrix2: " << mat2.transposed();

	std::cout << "Transpose Matrix1: " << mat1.transpose();
	std::cout << "Transpose Matrix2: " << mat2.transpose();

	std::cout << "Determinant Matrix1: " << mat1.determinant() << "\n";
	std::cout << "Determinant Matrix2: " << mat2.determinant() << "\n";

	std::cout << "Adjoint Matrix1: " << mat1.adjoint() << "\n";
	std::cout << "Adjoint Matrix2: " << mat2.adjoint() << "\n";

	std::cout << "Inverse Matrix2: " << mat2.inverse() << "\n";

	std::cout << "Identity Matrix: " << Matrix3D::identity();

	vec1.setX(1);
	vec1.setY(2);
	vec1.setZ(3);
	std::cout << "Dual Matrix (Vector (1,2,3)): " << Matrix3D::dual(vec1);

	std::cout << "\n=======CONVERSIONS=======\n";
	Matrix4D matC(1);
	Matrix3D matA(matC);
	std::cout << "Matrix3 from Matrix4: " << matA;

	Matrix2D matB(1);
	matA = matB;
	std::cout << "Matrix3 from Matrix2: " << matA;

	std::cout << "=====================MATRIX 3x3=====================\n\n\n";

	std::cout << "=====================MATRIX 2x2=====================\n";

	std::cout << "=======CONSTRUCTORS, SETTERS & GETTERS=======\n";

	Matrix2D mat8;
	std::cout << "Matrix 8: " << mat8 << "\n";

	Matrix2D mat5(new float[2][2]{ {1,2},{3,4} });
	std::cout << "Matrix 5: " << mat5 << "\n";

	std::cout << "Matrix 5 [1][1]: " << mat5.get(1, 1) << "\n";

	mat5.set(1, 1, 10);
	std::cout << "Matrix 5 [1][1] after Set: " << mat5.get(1, 1) << "\n\n";

	Matrix2D mat6(1);
	std::cout << "Matrix 6: " << mat6 << "\n";


	std::cout << "\n=======MATRIX-MATRIX OPERATORS=======\n";
	std::cout << "Matrix 8: " << mat8 << "\n";
	std::cout << "Matrix 5: " << mat5 << "\n";
	std::cout << "Matrix 6: " << mat6 << "\n";

	std::cout << "Matrix 8 + Matrix 5 = " << mat8 + mat5 << "\n";
	std::cout << "Matrix 5 - Matrix 8 = " << mat5 - mat8 << "\n";

	std::cout << "Matrix 6 * Matrix 5 = " << mat6 * mat5 << "\n";
	std::cout << "Matrix 5 * Matrix 6 = " << mat5 * mat6 << "\n";


	std::cout << "\n=======MATRIX-SCALAR OPERATORS=======\n";
	std::cout << "Matrix 6: " << mat6 << "\n";

	std::cout << "Matrix 6 * 2 = " << mat6 * 2 << "\n";
	std::cout << "1/2.0f * Matrix 6 = " << 1 / 2.0f * mat6 << "\n";

	std::cout << "Matrix 6 / 4 = " << mat6 / 4 << "\n";
	std::cout << "4.0f / Matrix 6 = " << 4.0f / mat6 << "\n";

	std::cout << "\n=======MATRIX-VECTOR OPERATORS=======\n";
	std::cout << "Matrix 6: " << mat6;

	Vector2D vec2(1, 2);
	std::cout << "Vector1: " << vec1.toString() << "\n";

	std::cout << "Matrix 6 * Vector 2 = " << (mat6 * vec2).toString() << "\n";
	std::cout << "Vector 2 * Matrix 6 = " << (vec2 * mat6).toString() << "\n\n";

	std::cout << "Matrix 5: " << mat5;
	std::cout << "Vector 2: " << vec2.toString() << "\n";

	std::cout << "Matrix 5 * Vector 2 = " << (mat5 * vec2).toString() << "\n";
	std::cout << "Vector 2 * Matrix 5 = " << (vec2 * mat5).toString() << "\n";

	std::cout << "\n=======ASSIGNMENTS=======\n";
	std::cout << "Matrix 6: " << mat6;

	vec2.setX(1);
	vec2.setY(2);
	std::cout << "Vector 2: " << vec2.toString() << "\n";

	Matrix2D mat7;
	std::cout << "Matrix 7: " << mat7;

	mat7 = mat6;
	std::cout << "Matrix 7 = Matrix 6: " << mat7;

	mat7 += mat6;
	std::cout << "Matrix 7 += Matrix 6: " << mat7;

	mat7 -= mat6;
	std::cout << "Matrix 7 -= Matrix 6: " << mat7;

	mat7 += 1;
	std::cout << "Matrix 7 += 1: " << mat7;

	mat7 -= 1;
	std::cout << "Matrix 7 -= 1: " << mat7;

	mat7 = 1;
	std::cout << "Matrix 7 = 1: " << mat7;

	mat7 *= mat6;
	std::cout << "Matrix 7 *= Matrix 6: " << mat7;

	mat7 *= 2;
	std::cout << "Matrix 7 *= 2: " << mat7;

	mat7 /= 2;
	std::cout << "Matrix 7 /= 2: " << mat7;

	vec2 *= mat7;
	std::cout << "Vector 2 /= Matrix 7: " << vec2.toString();

	std::cout << "\n=======COMPARISSONS=======\n";
	std::cout << "Matrix 8: " << mat8;
	std::cout << "Matrix 5: " << mat5;

	mat6 = mat5;
	std::cout << "Matrix 6: " << mat6;

	std::cout << "Matrix 8 == Matrix 5 : " << (mat8 == mat5) << "\n";
	std::cout << "Matrix 8 != Matrix 5 : " << (mat8 != mat5) << "\n";

	std::cout << "Matrix 6 == Matrix 5 : " << (mat6 == mat5) << "\n";
	std::cout << "Matrix 5 != Matrix 6 : " << (mat5 != mat6) << "\n";

	std::cout << "\n=======MATRIX METHODS=======\n";
	std::cout << "Matrix 8: " << mat8;
	mat5 = Matrix2D(new float[2][2]{ {1,2},{0,1} });
	std::cout << "Matrix 5: " << mat5 << "\n";

	std::cout << "Transposed Matrix 8: " << mat8.transposed();
	std::cout << "Transposed Matrix 5: " << mat5.transposed();

	std::cout << "Transpose Matrix 8: " << mat8.transpose();
	std::cout << "Transpose Matrix 5: " << mat5.transpose();

	std::cout << "Determinant Matrix 8: " << mat8.determinant() << "\n";
	std::cout << "Determinant Matrix 5: " << mat5.determinant() << "\n";

	std::cout << "Adjoint Matrix 8: " << mat8.adjoint() << "\n";
	std::cout << "Adjoint Matrix 5: " << mat5.adjoint() << "\n";

	std::cout << "Inverse Matrix 5: " << mat5.inverse() << "\n";

	std::cout << "Identity Matrix: " << Matrix2D::identity();

	std::cout << "\n=======CONVERSIONS=======\n";

	matA = Matrix3D(1);
	matB = matA;
	std::cout << "Matrix2 from Matrix3: " << matB;

	matC = Matrix4D(1);
	matB = matC;
	std::cout << "Matrix2 from Matrix4: " << matB;

	std::cout << "=====================MATRIX 2x2=====================\n\n\n";

	std::cout << "=====================MATRIX 4x4=====================\n";

	std::cout << "=======CONSTRUCTORS, SETTERS & GETTERS=======\n";

	Matrix4D mat9;
	std::cout << "Matrix 9: " << mat9 << "\n";

	Matrix4D mat10(new float[4][4]{ {1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16} });
	std::cout << "Matrix 10: " << mat10 << "\n";

	std::cout << "Matrix 10 [2][2]: " << mat10.get(2, 2) << "\n";

	mat10.set(2, 2, 10);
	std::cout << "Matrix 10 [2][2] after Set: " << mat10.get(2, 2) << "\n\n";

	Matrix4D mat11(1);
	std::cout << "Matrix 11: " << mat11 << "\n";


	std::cout << "\n=======MATRIX-MATRIX OPERATORS=======\n";
	std::cout << "Matrix 9: " << mat9 << "\n";
	std::cout << "Matrix 10: " << mat10 << "\n";
	std::cout << "Matrix 11: " << mat11 << "\n";

	std::cout << "Matrix9 + Matrix10 = " << mat9 + mat10 << "\n";
	std::cout << "Matrix9 - Matrix10 = " << mat9 - mat10 << "\n";

	std::cout << "Matrix11 * Matrix10 = " << mat11 * mat10 << "\n";
	std::cout << "Matrix10 * Matrix11 = " << mat10 * mat11 << "\n";

	std::cout << "\n=======MATRIX-SCALAR OPERATORS=======\n";
	std::cout << "Matrix11: " << mat11 << "\n";

	std::cout << "Matrix11 * 2 = " << mat11 * 2 << "\n";
	std::cout << "1/2.0f * Matrix11 = " << 1 / 2.0f * mat11 << "\n";

	std::cout << "Matrix11 + 2 = " << mat11 + 2 << "\n";
	std::cout << "Matrix11 - 2 = " << mat11 - 2 << "\n";
	std::cout << "2 + Matrix11 = " << 2 + mat11 << "\n";
	std::cout << "2 - Matrix11 = " << 2 - mat11 << "\n";

	std::cout << "Matrix11 / 4 = " << mat11 / 4 << "\n";
	std::cout << "4.0f / Matrix11 = " << 4.0f / mat11 << "\n";

	std::cout << "\n=======MATRIX-VECTOR OPERATORS=======\n";
	std::cout << "Matrix11: " << mat11;

	Vector4D vec3(1, 2, 3, 4);
	std::cout << "Vector3: " << vec3.toString() << "\n";

	std::cout << "Matrix11 * Vector3 = " << (mat11 * vec3).toString() << "\n";
	std::cout << "Vector3 * Matrix11 = " << (vec3 * mat11).toString() << "\n\n";

	std::cout << "Matrix10: " << mat10;
	std::cout << "Vector3: " << vec3.toString() << "\n";

	std::cout << "Matrix10 * Vector3 = " << (mat10 * vec3).toString() << "\n";
	std::cout << "Vector3 * Matrix10 = " << (vec3 * mat10).toString() << "\n";

	std::cout << "\n=======ASSIGNMENTS=======\n";
	std::cout << "Matrix11: " << mat11;

	vec3.setX(1);
	vec3.setY(2);
	vec3.setZ(3);
	vec3.setW(4);
	std::cout << "Vector3: " << vec3.toString() << "\n";

	Matrix4D mat12;
	std::cout << "Matrix12: " << mat12;

	mat12 = mat11;
	std::cout << "Matrix12 = Matrix11: " << mat12;

	mat12 += mat11;
	std::cout << "Matrix12 += Matrix11: " << mat12;

	mat12 -= mat11;
	std::cout << "Matrix12 -= Matrix11: " << mat12;

	mat12 += 1;
	std::cout << "Matrix12 += 1: " << mat12;

	mat12 -= 1;
	std::cout << "Matrix12 -= 1: " << mat12;

	mat12 = 1;
	std::cout << "Matrix12 = 1: " << mat12;

	mat12 *= mat11;
	std::cout << "Matrix12 *= Matrix11: " << mat12;

	mat12 *= 2;
	std::cout << "Matrix12 *= 2: " << mat12;

	mat12 /= 2;
	std::cout << "Matrix12 /= 2: " << mat12;

	vec3 *= mat12;
	std::cout << "Vector3 /= Matrix12: " << vec3.toString();

	std::cout << "\n=======COMPARISSONS=======\n";
	std::cout << "Matrix9: " << mat9;
	std::cout << "Matrix10: " << mat10;

	mat11 = mat10;
	std::cout << "Matrix11 = Matrix 10: " << mat11;

	std::cout << "Matrix9 == Matrix10 : " << (mat9 == mat10) << "\n";
	std::cout << "Matrix9 != Matrix10 : " << (mat9 != mat10) << "\n";

	std::cout << "Matrix11 == Matrix10 : " << (mat11 == mat10) << "\n";
	std::cout << "Matrix10 != Matrix11 : " << (mat10 != mat11) << "\n";

	std::cout << "\n=======MATRIX METHODS=======\n";
	float PI = atan(1) * 4;

	std::cout << "Matrix9: " << mat9;
	mat10 = Matrix4D(new float[4][4]{ {1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16} });
	std::cout << "Matrix10: " << mat10 << "\n";

	std::cout << "Transposed Matrix9: " << mat9.transposed();
	std::cout << "Transposed Matrix10: " << mat10.transposed();

	std::cout << "Transpose Matrix9: " << mat9.transpose();
	std::cout << "Transpose Matrix10: " << mat10.transpose();

	std::cout << "Identity Matrix: " << Matrix3D::identity();

	vec1.setX(1);
	vec1.setY(2);
	vec1.setZ(3);
	std::cout << "Scaling Matrix (Vector (1,2,3)): " << Matrix4D::scaling(vec1) << "\n";
	std::cout << "Scaling Matrix values (1,2,3)): " << Matrix4D::scaling(1, 2, 3) << "\n\n";

	std::cout << "Transition Matrix (Vector (1,2,3)): " << Matrix4D::translation(vec1) << "\n";
	std::cout << "Transition Matrix values (1,2,3)): " << Matrix4D::translation(1, 2, 3) << "\n\n";

	std::cout << "Rotation Matrix (Vector (1,2,3)): " << Matrix4D::rotation(vec1) << "\n";
	std::cout << "Rotation Matrix radians (1,2,3)): " << Matrix4D::rotation(1, 2, 3) << "\n\n";

	std::cout << "Rotation Matrix degrees (90,0,0)): " << Matrix4D::rotation(90, 0, 0, false, true) << "\n";
	std::cout << "RotationX Matrix 90 degrees: " << Matrix4D::rotationX(90, false, true) << "\n";
	std::cout << "RotationX Matrix 90 degrees == Rotation Matrix (90,0,0): " << (Matrix4D::rotationX(90, false, true) == Matrix4D::rotation(90, 0, 0, false, true)) << "\n\n";

	std::cout << "Rotation Matrix degrees (0,90,0)): " << Matrix4D::rotation(0, 90, 0, false, true) << "\n";
	std::cout << "RotationY Matrix PI/2 radians: " << Matrix4D::rotationY(PI / 2, true, true) << "\n";
	std::cout << "RotationY Matrix 90 degrees == Rotation Matrix (0,90,0): " << (Matrix4D::rotationY(90, false, true) == Matrix4D::rotation(0, 90, 0, false, true)) << "\n\n";

	std::cout << "Rotation Matrix degrees (0,0,90)): " << Matrix4D::rotation(0, 0, 90, false, true) << "\n";
	std::cout << "RotationZ Matrix 90 degrees: " << Matrix4D::rotationZ(90, false, true) << "\n";
	std::cout << "RotationY Matrix 90 degrees == Rotation Matrix (0,0,90): " << (Matrix4D::rotationZ(90, false, true) == Matrix4D::rotation(0, 0, 90, false, true)) << "\n\n";

	std::cout << "\n=======CONVERSIONS=======\n";
	matA = Matrix3D(1);
	matC = matA;
	std::cout << "Matrix4 from Matrix3: " << mat3;

	matB = Matrix2D(1);
	matC = matB;
	std::cout << "Matrix4 from Matrix2: " << mat3 << "\n";

	Matrix4D matD = Matrix4D::rotationX(90, false, true);
	std::cout << "3D RotationX Matrix 90 degrees: " << Matrix3D(matD) << "\n";

	matD = Matrix4D::rotationY(PI / 2, true, true);
	std::cout << "3D RotationY Matrix PI/2 radians: " << Matrix3D(matD) << "\n";

	matD = Matrix4D::rotationZ(90, false, true);
	std::cout << "3D RotationZ Matrix 90 degrees: " << Matrix3D(matD) << "\n";
	std::cout << "=====================MATRIX 4x4=====================\n\n\n";



	*/


	exit(EXIT_SUCCESS);

}

/////////////////////////////////////////////////////////////////////////// END

