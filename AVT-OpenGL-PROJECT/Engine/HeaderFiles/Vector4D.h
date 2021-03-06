#pragma once

#include<math.h>
#include<assert.h>
#include <string>

class Vector4D
{
private:
    float x, y, z, w;

public:
    Vector4D();

    Vector4D(float _x, float _y, float _z, float _w);

    float getX();
    float getY();
    float getZ();
    float getW();
    void setX(float _x);
    void setY(float _y);
    void setZ(float _z);
    void setW(float _w);

     
    // Operador respons�vel por comparar dois vetores como iguais
     
    bool operator==(const Vector4D& component);

     
    // Operador respons�vel por igualar dois vetores
     
    Vector4D& operator=(const Vector4D& component);

     
    // Operador respons�vel por comparar dois vetores como diferentes
     
    bool operator!=(Vector4D& component);

     
    // Operador respons�vel por igual um vetor � soma dele pr�prio com um outro
     
    Vector4D& operator+=(Vector4D& component);

     
    // Operador respons�vel por somar dois vetores
     
    Vector4D operator+(Vector4D& component);

     
    // Operador respons�vel por igual um vetor � subtra��o dele pr�prio com um outro
     
    Vector4D& operator-=(Vector4D& component);


     
    // Operador respons�vel por subtrair dois vetores
     
    Vector4D operator-(Vector4D& component);


     
    // Operador respons�vel por igual um vetor � multiplica��o dele pr�prio por um escalar
     
    Vector4D& operator*=(float scalar);


     
    // Operador respons�vel por multiplicar as coordenadas de um vetor por um determinado valor
     
    Vector4D operator*(float scalar);

     
    // Operador respons�vel por igual um vetor � divisor dele pr�prio por um escalar
     
    Vector4D& operator/=(float scalar);

     
    // Operador respons�vel por dividir as coordenadas de um vetor por um determinado valor
     
    Vector4D operator/(float scalar);

     
    // Fun��o respons�vel por calcular o Dot Product entre dois vetores
     
    float dot(Vector4D& component);

     
    // Fun��o respons�vel por retornar o tamanho de um vetor
     
    double length();

     
    // Fun��o respons�vel por normalizar um vetor
     
    void normalize();

    // Fun��o normalize para quaternions

    Vector4D Normalize_Quaternions();

     
    // Fun��o respons�vel por inverter um vetor
     
    Vector4D invert();

     
    // Fun��o respons�vel por criar uma String com os dados do Vetor 
     
    std::string toString();

};
Vector4D operator*(float val, Vector4D& vec);

Vector4D operator/(float val, Vector4D& vec);

Vector4D operator-(Vector4D& vec);

