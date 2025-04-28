#include "../include/geometric.h"

Point2D vector2D(Point2D initial, Point2D end) {
    Point2D vector;
    vector.x = (end.x - initial.x);
    vector.y = (end.y - initial.y);
    return vector;
}

Point3D vector3D(Point3D initial, Point3D end) {
    Point3D vector;
    vector.x = (end.x - initial.x); 
    vector.y = (end.y - initial.y);
    vector.z = (end.z - initial.z);
    return vector;
}

float norm2D(Point2D point) {
    return sqrt((point.x * point.x) + (point.y * point.y));
}

float norm3D(Point3D point) {
    return sqrt((point.x * point.x) + (point.y * point.y) + (point.z * point.z));
}

Point2D PointOffset2D(Point2D point, Point2D vector, char *operation) {
    Point2D displacement;
    if (strcmp(operation, "sum") == 0 || strcmp(operation, "Sum") == 0) {
        displacement.x = (point.x + vector.x);
        displacement.y = (point.y + vector.y);
    } else if (strcmp(operation, "subtracion") == 0 || strcmp(operation, "Subtracion") == 0) {
        displacement.x = (point.x - vector.x);
        displacement.y = (point.y - vector.y);
    }
    return displacement;
}

Point3D PointOffset3D(Point3D point, Point3D vector, char *operation) {
    Point3D displacement;
    if (strcmp(operation, "sum") == 0 || strcmp(operation, "Sum") == 0) {
        displacement.x = (point.x + vector.x);
        displacement.y = (point.y + vector.y);
        displacement.z = (point.z + vector.z);
    } else if (strcmp(operation, "subtracion") == 0 || strcmp(operation, "Subtracion") == 0) {
        displacement.x = (point.x - vector.x);
        displacement.y = (point.y - vector.y);
        displacement.z = (point.z - vector.z);
    }
    return displacement;
}

Point2D vectorSum2D(Point2D vector1, Point2D vector2) {
    Point2D sum2D;
    sum2D.x = (vector1.x + vector2.x);
    sum2D.y = (vector1.y + vector2.y);
    return sum2D;
}

Point3D vectorSum3D(Point3D vector1, Point3D vector2) {
    Point3D sum3D;
    sum3D.x = (vector1.x + vector2.x);
    sum3D.y = (vector1.y + vector2.y);
    sum3D.z = (vector1.z + vector2.z);
    return sum3D;
}

Point2D vectorSubtracion2D(Point2D vector1, Point2D vector2) {
    Point2D sub2D; 
    sub2D.x = (vector1.x - vector2.x);
    sub2D.y = (vector1.y - vector2.y);
    return sub2D;
}

Point3D vectorSubtracion3D(Point3D vector1, Point3D vector2) {
    Point3D sub3D; 
    sub3D.x = (vector1.x - vector2.x);
    sub3D.y = (vector1.y - vector2.y);
    sub3D.z = (vector1.z - vector2.z);
    return sub3D;
}

Point2D multiplicationByScalar2D(int scalar, Point2D vector) {
    Point2D vectorByScalar;
    vectorByScalar.x = (scalar * vector.x);
    vectorByScalar.y = (scalar * vector.y);
    return vectorByScalar;
}

Point3D multiplicationByScalar3D(int scalar, Point3D vector) {
    Point3D vectorByScalar;
    vectorByScalar.x = (scalar * vector.x);
    vectorByScalar.y = (scalar * vector.y);
    vectorByScalar.z = (scalar * vector.z);
    return vectorByScalar;
}

Point2D unitVector2D(Point2D vector) { 
    float norm = norm2D(vector);
    Point2D newVector;
    if (norm == 0) {
        newVector.x = 0;
        newVector.y = 0;
    } else {
        newVector.x = (vector.x / norm);
        newVector.y = (vector.y / norm);
    }
    return newVector;
}

Point3D unitVector3D(Point3D vector) {
    float norm = norm3D(vector);
    Point3D newVector;
    if (norm == 0) {
        newVector.x = 0;
        newVector.y = 0;
        newVector.z = 0;
    } else {
        newVector.x = (vector.x / norm);
        newVector.y = (vector.y / norm);
        newVector.z = (vector.z / norm);
    }
    return newVector;
}

float innerProduct2D(Point2D vector1, Point2D vector2) {
    float product = ((vector1.x * vector2.x) + (vector1.y * vector2.y));
    return product;
}

float innerProduct3D(Point3D vector1, Point3D vector2) {
    float product = ((vector1.x * vector2.x) + (vector1.y * vector2.y) + (vector1.z * vector2.z));
    return product;
}

Point3D vectorProduct(Point3D vector1, Point3D vector2) {
    Point3D vectorFinal;
    vectorFinal.x = ((vector1.y * vector2.z) - (vector1.z * vector2.y));
    vectorFinal.y = ((vector1.z * vector2.x) - (vector1.x * vector2.z));
    vectorFinal.z = ((vector1.x * vector2.y) - (vector1.y * vector2.x));

    return vectorFinal;
}