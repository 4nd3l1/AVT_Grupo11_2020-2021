#pragma once

#include<math.h>
#include<assert.h>
#include <string>

class Vector2D
{
private:
    float x, y;

public:
    Vector2D();

    Vector2D(float _x, float _y);

    float getX();
    float getY();
    void setX(float _x);
    void setY(float _y);


     
    // Operador respons�vel por comparar dois vetores como iguais
     
    bool operator==(Vector2D& component);

     
    // Operador respons�vel por igualar dois vetores
     
    Vector2D& operator=(const Vector2D& component);

     
    // Operador respons�vel por comparar dois vetores como diferentes
     
    bool operator!=(Vector2D& component);

     
    // Operador respons�vel por igual um vetor � soma dele pr�prio com um outro
     
    Vector2D& operator+=(Vector2D& component);

     
    // Operador respons�vel por somar dois vetores
     
    Vector2D operator+(Vector2D& component);

     
    // Operador respons�vel por igual um vetor � subtra��o dele pr�prio com um outro
     
    Vector2D& operator-=(Vector2D& component);


     
    // Operador respons�vel por subtrair dois vetores
     
    Vector2D operator-(Vector2D& component);


     
    // Operador respons�vel por igual um vetor � multiplica��o dele pr�prio por um escalar
     
    Vector2D& operator*=(float scalar);


     
    // Operador respons�vel por multiplicar as coordenadas de um vetor por um determinado valor
     
    Vector2D operator*(float scalar);

     
    // Operador respons�vel por igual um vetor � divis�o dele pr�prio por um escalar
     
    Vector2D& operator/=(float scalar);

     
    // Operador respons�vel por dividir as coordenadas de um vetor por um determinado valor
     
    Vector2D operator/(float scalar);

     
    // Fun��o respons�vel por calcular o Dot Product entre dois vetores
     
    float dot(Vector2D& component);

     
    // Fun��o respons�vel por verificar se um vetor � igual a outro
     
    bool compare(Vector2D& component);

     
    // Fun��o respons�vel por retornar o tamanho de um vetor
     
    double length();

     
    // Fun��o respons�vel por normalizar um vetor
     
    void normalize();

     
    // Fun��o respons�vel por inverter um vetor
     
    Vector2D invert();

     
    // Fun��o respons�vel por criar uma String com os dados do Vetor 
     
    std::string toString();

};
Vector2D operator*(float val, Vector2D& vec);

Vector2D operator/(float val, Vector2D& vec);

Vector2D operator-(Vector2D& vec);

