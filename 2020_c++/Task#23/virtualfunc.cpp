#include <iostream>
using namespace std;

class Figure{
public:
    virtual void draw() = 0;
};

class Point{
public:
    Point():x(0), y(0){} //생성자
    Point(int _x):x(_x){} //원
    Point(int _x, int _y):x(_x), y(_y){} //직사각형
    virtual void draw(){                 //순수가상함수(구현필요x)
        cout<<"("<<x<<", "<<y<<")";
    }
private:    
    int x;
    int y;
};

class Rectangle:public Figure{
public:
    Rectangle(Point _a, Point _b):a(_a), b(_b){} //(자식클래스에서)생성자 따로 만들어야함
    void draw(){                                 //자식클래스에서는(재정의 할 때) "virtual" 않써도됨
        cout<<"A rectangle from ";
        a.draw();
        cout<<" to ";
        b.draw();
        cout<<'\n';
    }
private:
    Point a;
    Point b;
};
class Circle:public Figure{
public:
    Circle(Point _a, int _r):a(_a), r(_r){}
    void draw(){
        cout<<"A circle with the center of ";
        a.draw();
        cout<<" and the radius of "<<r<<'\n';
        
    }
private:
    Point a;
    int r;
};

void draw2figure (Figure& f1, Figure& f2){  //함수호출부분
    cout << "First figure is: ";
    f1.draw();
    cout << "Second figure is: ";
    f2.draw();
}

int main()
{
    Point p1(0,0), p2(2,2);
    Rectangle r1 (p1, p2);
    Circle c1 (p1, 2);
    draw2figure(r1, c1);

}