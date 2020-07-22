#include <iostream>
#include <string>
using namespace std;

template<typename T>
class Quadtemplate
{
public:
    Quadtemplate(){}
    Quadtemplate(T x, T y, T z, T w)
    :qx(x), qy(y), qz(z), qw(w){}
    template <typename U> //오버로딩전에도 선언해줘야함
    friend ostream& operator<<(ostream& cout, const Quadtemplate<U>& A); //연산자오버로딩 함수선언
private:
    T qx, qy, qz, qw;
};
template<typename T>
ostream& operator << (ostream& cout, const Quadtemplate<T>& A){      //연산자오버로딩 함수구현
    cout<< "Elements are: < " << A.qx <<", "<< A.qy<<", "<<A.qz<<", "<<A.qw<<" > "<<'\n';
    return cout;
}
int main(void)
{
    Quadtemplate<int> qi (5, 6, 7, 8);
    Quadtemplate<string> qs ("hello", "C++", "programming", "language");
    Quadtemplate<double> qd (1.1, 2.2, 3.3, 4.4);


    cout << qi << endl;
    cout << qs << endl;
    cout << qd << endl;
    
    return 0;
}