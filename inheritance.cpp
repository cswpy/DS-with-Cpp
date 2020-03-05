//Inheritance of classes in C++
#include<iostream>

using namespace std;

class Point{
    protected :
    int x;
    int y;
    public :
    Point(int a, int b);
    void display();
    void setCoord(int x, int y);
};

Point::Point(int a=0, int b=0){
    this->x = a;
    this->y = b;
}

void Point::display(){
    cout<<"x: "<<this->x<<endl<<"y: "<<this->y;
}

void Point::setCoord(int x, int y){
    this->x = x;
    this->y = y;
}

class ColorPoint: public Point{
    private :
    int color;
    public :
    ColorPoint(int a, int b, int c);
    ColorPoint(ColorPoint const &cp);
    void display();
    void operator= (ColorPoint const &cp);
};

ColorPoint::ColorPoint(int a, int b, int c): Point(a,b){
    this->color = c;
}

ColorPoint::ColorPoint(ColorPoint const &cp){
    this->x = cp.x;
    this->y = cp.y;
    this->color = cp.color;
}

void ColorPoint::display(){
    Point::display();
    cout<<endl<<"Color: "<<this->color<<endl;
}

void ColorPoint::operator= (ColorPoint const &cp){
    this->x = cp.x;
    this->y = cp.y;
    this->color = cp.color;
}

class Circle{
    protected :
    Point center;
    int r;
    public :
    Circle(int x, int y, int r);
    Circle(Circle const &ci);
    void display();
    void operator= (Circle const &ci);
};

Circle::Circle(int x, int y, int r){
    center.setCoord(x,y);
    this->r = r;
}

Circle::Circle(Circle const &ci){
    this->center = ci.center;
    this->r = ci.r;
}

void Circle::display(){
    cout<< "lol" <<endl;
}


int main(){
    Point p1;
    p1 = Point(2,3);
    p1.display();
    ColorPoint cp1(4,9,10);
    ColorPoint cp2(cp1);
    ColorPoint cp3 = cp2;
    cp1.display();
    cp2.display();
    cp3.display();
    return EXIT_SUCCESS;
}