#ifndef GEOMETRIC_H
#define GEOMETRIC_H
#include <math.h>
#include <string.h>

typedef struct {
    float x;
    float y;
} Point2D;

typedef struct {
    float x;
    float y;
    float z;
} Point3D;

//Faz o cálculo de um vetor 2D
Point2D vector2D(Point2D initial, Point2D end);
//Faz o cálculo de um vetor 3D
Point3D vector3D(Point3D initial, Point3D end);
//Faz o cálculo da norma de um vetor 2D
float norm2D(Point2D point);
//Faz o cálculo da norma de um vetor 3D
float norm3D(Point3D point);
//Faz o cálculo do deslocamento de ponto no espaço através de um vetor 2D
Point2D PointOffset2D(Point2D point, Point2D vector, char *operation);
//Faz o cálculo do deslocamento de ponto no espaço através de um vetor 3D
Point3D PointOffset3D(Point3D point, Point3D vector, char *operation);
//Faz o cálculo da soma de dois vetores 2D
Point2D vectorSum2D(Point2D vector1, Point2D vector2);
//Faz o cálculo da soma de dois vetores 3D
Point3D vectorSum3D(Point3D vector1, Point3D vector2);
//Faz o cálculo da subtração de dois vetores 2D
Point2D vectorSubtracion2D(Point2D vector1, Point2D vector2);
//Faz o cálculo da subtração de dois vetores 3D
Point3D vectorSubtracion3D(Point3D vector1, Point3D vector2);
//Faz o cálculo de um vetor por um escalar 2D
Point2D multiplicationByScalar2D(int scalar, Point2D vector);
//Faz o cálculo de um vetor por um escalar 3D
Point3D multiplicationByScalar3D(int scalar, Point3D vector);
//Faz o cálculo que torna um vetor 2D em unitário
Point2D unitVector2D(Point2D vector);
//Faz o cálculo que torna um vetor 3D em unitário
Point3D unitVector3D(Point3D vector);
//Faz o cálculo do produto escalar de dois vetores 2D
float innerProduct2D(Point2D vector1, Point2D vector2);
//Faz o cálculo do produto escalar de dois vetores 3D
float innerProduct3D(Point3D vector1, Point3D vector2);
//Faz o cálculo do produto vetorial de dois vetores 3D
Point3D vectorProduct(Point3D vector1, Point3D vector2);

#endif