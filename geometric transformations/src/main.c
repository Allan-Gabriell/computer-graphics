#include <stdio.h>
#include "../include/geometric.h"

int main(){
    Point2D initial = {1.0, 2.0};
    Point2D end = {4.0, 6.0};
    Point2D vectorResult = vector2D(initial, end);
    printf("Vetor resultante 2D: (%f, %f)\n", vectorResult.x, vectorResult.y);

    Point3D initial3D = {1.0, 2.0, 3.0};
    Point3D end3D = {4.0, 6.0, 8.0};
    Point3D vectorResult3D = vector3D(initial3D, end3D);
    printf("Vetor resultante 3D: (%f, %f, %f)\n", vectorResult3D.x, vectorResult3D.y, vectorResult3D.z);

    printf("------------------------------------------------\n");

    Point2D point = {3.0, 5.0};
    float norm = norm2D(point);
    printf("A norma do vetor é: %f\n", norm);

    Point3D pointNorm3D = {3.0, 5.0, 2.0};
    float normm = norm3D(pointNorm3D);
    printf("A norma do vetor é: %f\n", normm);

    printf("------------------------------------------------\n");

    Point2D point2D = {3.0, 5.0};
    Point2D vector2D = {8.0, 9.0};
    Point2D displacement2D = PointOffset2D(point2D, vector2D, "sum");

    printf("O Deslocamento de ponto através de vetor é: %f, %f \n", displacement2D.x, displacement2D.y);

    Point3D point3D = {3.0, 5.0, 7.0};
    Point3D vector3D = {8.0, 9.0, 11.0};
    Point3D displacement3D = PointOffset3D(point3D, vector3D, "subtracion");

    printf("O Deslocamento de ponto através de vetor é: %f, %f, %f \n", displacement3D.x, displacement3D.y, displacement3D.z);

    printf("------------------------------------------------\n");

    Point2D vector1 = { 2.0, -5.0};
    Point2D vector2 = { 2.0, 4.0};
    Point2D sum2D = vectorSum2D(vector1, vector2);
    Point2D subtracion2D = vectorSubtracion2D(vector1, vector2);

    printf("A soma dos dois vetores é: %f, %f \n", sum2D.x, sum2D.y);
    printf("A subtração dos dois vetores é: %f, %f \n", subtracion2D.x, subtracion2D.y);

    Point3D vector1_3D = { 3.0, 5.0, -6.0};
    Point3D vector2_3D = { -3.0, 2.0, -3.0};
    Point3D sum3D = vectorSum3D(vector1_3D, vector2_3D);
    Point3D subtracion3D = vectorSubtracion3D(vector1_3D, vector2_3D);

    printf("A soma dos dois vetores é: %f, %f, %f \n", sum3D.x, sum3D.y, sum3D.z);
    printf("A subtração dos dois vetores é: %f, %f, %f \n", subtracion3D.x, subtracion3D.y, subtracion3D.z);

    printf("------------------------------------------------\n");

    Point2D vector_2D = { 2, 4};
    Point3D vector_3D = { 1, 7, 5};

    Point2D multiplication2D = multiplicationByScalar2D(3, vector_2D);
    Point3D multiplication3D = multiplicationByScalar3D(-5, vector_3D);

    printf("A multiplicação por escalar deu o vector 2D: %f, %f \n", multiplication2D.x, multiplication2D.y);
    printf("A multiplicação por escalar deu o vector 3D: %f, %f, %f \n", multiplication3D.x, multiplication3D.y, multiplication3D.z);

    printf("------------------------------------------------\n");

    Point2D vectorToNormalize2D = {12.0, 3.0};
    Point2D vectorUnit2D = unitVector2D(vectorToNormalize2D);

    Point3D vectorToNormalize3D = {-3, 4, -5};
    Point3D vectorUnit3D = unitVector3D(vectorToNormalize3D);

    printf("A normalização gerou o vetor unitário 2D: %f, %f\n", vectorUnit2D.x, vectorUnit2D.y);
    printf("A normalização gerou o vetor unitário 3D: %f, %f, %f\n", vectorUnit3D.x, vectorUnit3D.y, vectorUnit3D.z);

    printf("------------------------------------------------\n");

    Point2D vectorA1 = {2, -4};
    Point2D vectorB1 = {5, 3};
    Point3D vectorA2 = {1, 7, 5};
    Point3D vectorB2 = {2, 4, 5};
    float inner2D = innerProduct2D(vectorA1, vectorB1);
    float inner3D = innerProduct3D(vectorA2, vectorB2);

    printf("O valor do produto interno dos dois vetores 2D é: %f\n", inner2D);
    printf("O valor do produto interno dos dois vetores 3D é: %f\n", inner3D);

    return 0;
}