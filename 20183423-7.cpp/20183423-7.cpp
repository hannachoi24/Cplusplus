#include <iostream>
using namespace std;

class Vector3D{
public:
    Vector3D(int x, int y ,int z):x(x), y(y), z(z){}  // 생성자
    Vector3D(){x=0; y=0; z=0}
    int getX() const {return x;}
    int getY() const {return y;}
    int getZ() const {return z;}
    void output(){cout<<"("<<x<<", "<<y<<", "<<z<<")"<<'\n';}
private:
    int x,y,z;

};


const Vector3D operator+(const Vector3D& a,const  Vector3D& b){
    return Vector3D(a.getX()+ b.getX() , a.getY() + b.getY() +a.getZ() + b.getZ());
}
const Vector3D operator*(const Vector3D& a,const Vector3D& b) {
    return Vector3D(a.getY()*b.getZ()- a.getY() - b.getY());
}
bool operator==(const Vector2D& a,const Vector2D& b){
    if(a.getX() == b.getX() && a.getY() == b.getY())
        return true;
    else
        return false;
}

        
}

int main()
{
    Vector3D v1(1,2,3), v2(3,2,1);
    cout << v1+v2<< endl;
    cout << v1*v2<< endl;
    cout << (v1*v2) + v1<< endl;
}