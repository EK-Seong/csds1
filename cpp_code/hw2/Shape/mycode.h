#pragma once

// Fill in
class Shape{
    protected:
    float length;

    public:
    Shape();
    Shape(float aLength);

    virtual float area(void);
    void print(void);
};

class Square : public Shape {

    public:
    Square();
    Square(float aLength);

    float area(void);
    void print(void);
};

class Equilateral : public Shape {

    public:
    Equilateral();
    Equilateral(float aLength);

    float area(void);
    void print(void);
};