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


     
    // Operador responsável por comparar dois vetores como iguais
     
    bool operator==(Vector2D& component);

     
    // Operador responsável por igualar dois vetores
     
    Vector2D& operator=(const Vector2D& component);

     
    // Operador responsável por comparar dois vetores como diferentes
     
    bool operator!=(Vector2D& component);

     
    // Operador responsável por igual um vetor à soma dele próprio com um outro
     
    Vector2D& operator+=(Vector2D& component);

     
    // Operador responsável por somar dois vetores
     
    Vector2D operator+(Vector2D& component);

     
    // Operador responsável por igual um vetor à subtração dele próprio com um outro
     
    Vector2D& operator-=(Vector2D& component);


     
    // Operador responsável por subtrair dois vetores
     
    Vector2D operator-(Vector2D& component);


     
    // Operador responsável por igual um vetor à multiplicação dele próprio por um escalar
     
    Vector2D& operator*=(float scalar);


     
    // Operador responsável por multiplicar as coordenadas de um vetor por um determinado valor
     
    Vector2D operator*(float scalar);

     
    // Operador responsável por igual um vetor à divisão dele próprio por um escalar
     
    Vector2D& operator/=(float scalar);

     
    // Operador responsável por dividir as coordenadas de um vetor por um determinado valor
     
    Vector2D operator/(float scalar);

     
    // Função responsável por calcular o Dot Product entre dois vetores
     
    float dot(Vector2D& component);

     
    // Função responsável por verificar se um vetor é igual a outro
     
    bool compare(Vector2D& component);

     
    // Função responsável por retornar o tamanho de um vetor
     
    double length();

     
    // Função responsável por normalizar um vetor
     
    void normalize();

     
    // Função responsável por inverter um vetor
     
    Vector2D invert();

     
    // Função responsável por criar uma String com os dados do Vetor 
     
    std::string toString();

};
Vector2D operator*(float val, Vector2D& vec);

Vector2D operator/(float val, Vector2D& vec);

Vector2D operator-(Vector2D& vec);

