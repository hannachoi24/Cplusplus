#include <iostream>
using namespace std;

class Vector2D
{
public:
    Vector2D(int x, int y):x(x), y(y){} // 생성자
    Vector2D(){x=0; y=0;}
    void output(){cout<<"("<<x<<", "<<y<<")"<<'\n';}
    int operator * (const Vector2D& a){
        int num1, num2;
        num1 = x * a.x;
        num2 = y * a.y;
        return num1+num2;
    }

    friend const Vector2D operator * (int k, const Vector2D& a) {
        Vector2D V;
        V.x = k*a.x;
        V.y = k*a.y;
        return V;
    }
private:
    int x,y;

};

int main()
{
    Vector2D v0, v1(2,2), v2(3,3), v3;
    int k = 2;

    v3 = k*v1;
    v3.output();
    cout << v1 * v2 << endl;
}
