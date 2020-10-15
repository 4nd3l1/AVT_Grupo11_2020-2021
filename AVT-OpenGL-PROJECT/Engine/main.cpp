
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
	std::cout << "Test compare v4(0,0) = v5(0,0) : " << v4.compare(v5) << "\n";
	std::cout << "Test compare v4(0,0) = v6(0.1f, 0.1f) : " << v4.compare(v6) << "\n";

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
	std::cout << "Test compare v4(0,0,0) = v5(0,0,0) : " << v4.compare(v5) << "\n";
	std::cout << "Test compare v4(0,0,0) = v6(0.1f, 0.1f, 0.1f) : " << v4.compare(v6) << "\n";

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
	std::cout << "Test compare v4(0,0,0,0) = v5(0,0,0,0) : " << v4.compare(v5) << "\n";
	std::cout << "Test compare v4(0,0,0) = v6(0.1f, 0.1f, 0.1f, 0.1f) : " << v4.compare(v6) << "\n";

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


int main(int argc, char* argv[])
{
	int gl_major = 4, gl_minor = 3;
	int is_fullscreen = 0;
	int is_vsync = 1;
	 //GLFWwindow* win = setup(gl_major, gl_minor, 
		//640, 480, "OpenGL Viewer (GLFW)", is_fullscreen, is_vsync);
	 //run(win);
	// vectorsMenu();

	/* Challenge #1
	std::cout << "2.1 - " << Vector3D(1.5, 3.2, 0.8).rodriguesRot(Vector3D(8, 2, 0), 24).toString() << "\n";
	std::cout << "2.2 - " << Vector3D(0.5, 1.0, 1.0).rodriguesRot(Vector3D(8, 2, 0), 0).toString() << "\n";

	Vector3D v38(1.0, 2.0, 3.0);
	Vector3D v39(0.1, 0.2, 0.3);
	Vector3D v40(0.1, 0.2, 0.3);
	Vector3D v41(1.0, 2.0, 3.0);
	Vector3D v42(1.1, 2.2, 3.3);
	Vector3D v43(0.1, 0.2, 0.3);
	Vector3D v45 = v39 * 10;	
	Vector3D v46(-0.9, -1.79, -2.7);
	std::cout << "3.1 - " << (v38 == v45) << "\n";
	std::cout << "3.2 - " << ((v40 + v41) == v42) << "\n";
	std::cout << "3.1 - " << ((v43 - v41) != v46) << "\n";
*/


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

	std::cout << "Col Major Matrix2: " << mat2.convertMajorOrder();
	std::cout << "Row Major Matrix2: " << mat2.convertMajorOrder();

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

	std::cout << "Col Major Matrix 5: " << mat5.convertMajorOrder();
	std::cout << "Row Major Matrix 5: " << mat5.convertMajorOrder();

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

	std::cout << "Col Major Matrix10: " << mat10.convertMajorOrder();
	std::cout << "Row Major Matrix10: " << mat10.convertMajorOrder();

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




	exit(EXIT_SUCCESS);

}

/////////////////////////////////////////////////////////////////////////// END

