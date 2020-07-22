#include <iostream>
using namespace std;

class Vector2D
{
public:
    Vector2D(int x, int y):x(x), y(y){}  // 생성자
    Vector2D(){x=0; y=0;}
    int getX() const {return x;}
    int getY() const {return y;}
    void output(){cout<<"("<<x<<", "<<y<<")"<<'\n';}
private:
    int x,y;

};


const Vector2D operator+(const Vector2D& a,const  Vector2D& b) {
    return Vector2D(a.getX()+ b.getX(), a.getY() + b.getY());
}
const Vector2D operator-(const Vector2D& a,const Vector2D& b) {
    return Vector2D(a.getX()- b.getX(), a.getY() - b.getY());
}
bool operator==(const Vector2D& a,const Vector2D& b){
    if(a.getX() == b.getX() && a.getY() == b.getY())
        return true;
    else
        return false;
}


int main()
{
    Vector2D v0, v1(2,2), v2(3,3), v3;
    
    v3 = v1 + v2;
    v3.output();

    v3 = v2 - v2;
    v3.output();
    if (v3 == v0)
       cout << "Operator - works!"<<'\n';

}