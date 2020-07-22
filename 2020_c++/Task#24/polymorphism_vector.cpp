#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Figure{
public:
    Figure(){}
    virtual void draw() = 0;
    ~Figure(){}
};

class Point{
public:
    Point():x(0), y(0){}
    Point(int _x):x(_x){} //원
    Point(int _x, int _y):x(_x), y(_y){}
    virtual void draw(){
        cout<<"("<<x<<", "<<y<<")";
    }
    ~Point(){}

    int x;
    int y;
};

class Rectangle:public Figure{
public:
    Rectangle(){}
    Rectangle(Point _a, Point _b):a(_a), b(_b){}
    virtual void draw(){
        cout<<"A rectangle from ";
        a.draw();
        cout<<" to ";
        b.draw();
        cout<<'\n';
    }
    ~Rectangle(){}
private:
    Point a;
    Point b;
};
class Circle:public Figure{
public:
    Circle(){}
    Circle(Point _a, int _r):a(_a), r(_r){}
    virtual void draw(){
        cout<<"A circle with the center of ";
        a.draw();
        cout<<" and the radius of "<<r<<'\n';
    }
    ~Circle(){}
private:
    Point a;
    int r;
};

int main(){
    string select;
    vector<Figure*> v;
    while(1){
        cout<<"Enter figure type or draw: ";
        cin>>select;
        if(select == "rectangle" || select == "Rectangle"){
            int x1, y1;
            int x2, y2;
            cout<<"Enter x, y coordinates of P1: ";
            cin>>x1>>y1;
            cout<<"Enter x, y coordinates of P2: ";
            cin>>x2>>y2;
            Point p1(x1, y1), p2(x2, y2);
            Figure * pFigure; //포인터 생성
            pFigure = new Rectangle(p1, p2); //포인터의 또다른 공간생성
            v.push_back(pFigure);
        }
        else if(select == "circle" || select == "Circle"){
            int x, y, r;
            cout<<"Enter x, y coordinates of the center: ";
            cin>>x>>y;
            cout<<"Enter the radius: ";
            cin>>r;
            Point p1(x, y);
            Figure * pFigure;
            pFigure = new Circle(p1, r);
            v.push_back(pFigure);
        }
        else if(select == "draw"){
            for(unsigned i=0; i<v.size(); i++){
                v.at(i)->draw();
            }
            break;
        }
        else{
            cout<<"Please Enter type or draw!"<<endl;
        }
    }
    return 0;
}