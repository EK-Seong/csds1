#include "mycode.h"
#include <cstdlib>
#include <iostream>
#include <math.h>
#include <iomanip>

// Fill in

using namespace std;

Shape::Shape(){}
Shape::Shape(float aLength){
    length = aLength;
}

float Shape::area(void){
    return 0.0;
}

void Shape::print(void){
    cout << "This is Shape. Area is " << area() << endl;
}


Square::Square(){}
Square::Square(float aLength){
    length = aLength;
}

float Square::area(void){
    float area = pow(length,2);
    return area;
}

void Square::print(void){
    float Area = area();
    Area *= 1000000;
    Area = round(Area);
    Area /= 1000000;
    cout << "This is Square. Area is " << fixed << setprecision(6) << area() << endl;
}


Equilateral::Equilateral(){}
Equilateral::Equilateral(float aLength){
    length = aLength;
}

float Equilateral::area(void){
    float area = sqrt(pow(length,2)-pow(length/2,2)) * length / 2;
    return area;
}

void Equilateral::print(void){
    float Area = area();
    Area *= 1000000;
    Area = round(Area);
    Area /= 1000000;
    cout << "This is Equilateral. Area is " << fixed << setprecision(6) << area() << endl;
}
