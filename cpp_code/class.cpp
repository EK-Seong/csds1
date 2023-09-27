#include <iostream>
#include <cmath>

class Triangle{
    double sideA;
    double sideB;
    double sideC;

    public:
    Triangle(double a,double b,double c);
    double area();
    double perimeter();
};

Triangle::Triangle(double a = 5, double b = 4, double c = 3){
    // 이거는 argument initialization이고
    // : sideA(5) 는 sideA에 대한 initialization이다
    sideA = a;
    sideB = b;
    sideC = c;
}

double Triangle::perimeter(){
    return sideA + sideB + sideC;
}

double Triangle::area(){
    double s = perimeter() / 2;

    // Heron's Formula
    return sqrt(s*(s-sideA)*(s-sideB)*(s-sideC));
}

using namespace std;
int main(void){
    Triangle t1(6,5,4);
    double p1;
    p1 = t1.perimeter();
    double p2 = t1.area();
    cout << "perimeter is: " << p1 << ", " << "area is: " << p2 << "." << endl;
    return 0;
}