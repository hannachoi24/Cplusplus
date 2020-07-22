#include <iostream>
using namespace std;

class Vector2D
{
public:
    Vector2D(int x, int y):x(x), y(y){} // 생성자
    Vector2D(){x=0; y=0;}
    void output(){cout<<"("<<x<<", "<<y<<")"<<'\n';}
    friend ostream& operator << (ostream& outputstream, const Vector2D& a);
    Vector2D operator + (const Vector2D& a){
    Vector2D V;
    V.x = x+a.x;
    V.y = y+a.y;
    return V;
    }
    
private:
    int x,y;

};

ostream& operator << (ostream& outputstream, const Vector2D& a){
    outputstream<<"("<<a.x<<", "<<a.y<<")"<<endl;
    return outputstream;
}


int main()
{
    Vector2D v0, v1(2,2), v2(3,3), v3;
    cout << v1 << endl;
    cout << v1 + v2 << endl;
}
