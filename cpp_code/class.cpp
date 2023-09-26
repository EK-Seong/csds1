class Triangle{
    double sideA;
    double sideB;
    double sideC;

    public:
    double area();
    double perimeter();
};

double Triangle::perimeter(){
    return sideA + sideB + sideC;
}

double Triangle::area(){
    double s = perimeter() / 2;

    // Heron's Fourmula
    return sqrt(s*(s-sideA)*(s-sideB)*(s-sideC));
}