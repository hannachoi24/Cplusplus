#include <iostream>
using namespace std;

class Figure{
public:
    virtual void draw() = 0;
}

class Point{
public:
    point():x(0),y(0){}
      
}
int main()
{
    Point p1(0,0), p2(2,2);
    Rectangle r1 (p1, p2);
    Circle c1 (p1, 2);
    draw2figure(r1, c1);

}