#pragma once

#include<math.h>
#include<assert.h>
#include <string>



class Vector3D
{
private:
    float x, y, z;

public:
    Vector3D();

    Vector3D(float xi, float yi, float zi);

    float getX();
    float getY();
    float getZ();
    void setX(float _x);
    void setY(float _y);
    void setZ(float _z);

    
    // Operador respons�vel por comparar dois vetores como iguais
    
    bool operator==(Vector3D& component);

    
    // Operador respons�vel por igualar dois vetores
    
    Vector3D& operator=(const Vector3D& component);

    
    // Operador respons�vel por comparar dois vetores como diferentes
    
    bool operator!=(Vector3D& component);

    
    // Operador respons�vel por igual um vetor � soma dele pr�prio com um outro
    
    Vector3D& operator+=(const Vector3D& component);

    
    // Operador respons�vel por somar dois vetores
    
    Vector3D operator+(const Vector3D& component);

    
    // Operador respons�vel por igual um vetor � subtra��o dele pr�prio com um outro
    
    Vector3D& operator-=(const Vector3D& component);


    
    // Operador respons�vel por subtrair dois vetores
    
    Vector3D operator-(Vector3D& component);


    
    // Operador respons�vel por igual um vetor � multiplica��o dele pr�prio por um escalar
    
    Vector3D& operator*=(float scalar);


    
    // Operador respons�vel por multiplicar as coordenadas de um vetor por um determinado valor
    
    Vector3D operator*(float scalar);

    
    // Operador respons�vel por igual um vetor � divisor dele pr�prio por um escalar
    
    Vector3D& operator/=(float scalar);

    
    // Operador respons�vel por dividir as coordenadas de um vetor por um determinado valor
    
    Vector3D operator/(float scalar);

    
    // Fun��o respons�vel por calcular o Cross Product entre dois vetores
    
    Vector3D cross(Vector3D& component);

    
    // Fun��o respons�vel por calcular o Dot Product entre dois vetores
    
    float dot(Vector3D& component);

    
    // Fun��o respons�vel por retornar o tamanho de um vetor
    
    double length();

    
    // Fun��o respons�vel por normalizar um vetor
    
    void normalize();

    
    // Fun��o respons�vel por inverter um vetor
    
    Vector3D invert();

    
    // Fun��o respons�vel por criar uma String com os dados do Vetor 
    
    std::string toString();

    Vector3D rodriguesRot(Vector3D k, float angle);

};
    Vector3D operator*(float val, Vector3D& vec);

    Vector3D operator/(float val, Vector3D& vec);

    Vector3D operator-(Vector3D& vec);


