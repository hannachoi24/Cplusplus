#include <iostream>
using namespace std;

class NComplex {
private:
    double real;      // 실수부
    double image;     // 허수부
public:
    NComplex() {real=0; image=0;}
    NComplex(double r,double i){  // 생성자
        real = r;
        image = i;
    }
    friend ostream& operator<<(ostream &cout, const NComplex &C);
    
    NComplex operator+(NComplex C); // 복소수 + 복소수
    NComplex operator+(double k);   // 복소수 + 실수
    friend NComplex operator+(double k, NComplex C);   // 실수 + 복소수
    
    NComplex operator-(NComplex C); // 복소수 - 복소수
    NComplex operator-(double k);   // 복소수 - 실수
    friend NComplex operator-(double k, NComplex C);   // 실수 - 복소수
    
    NComplex operator*(NComplex C); // 복소수 x 복소수
    NComplex operator*(double k);   // 복소수 x 실수
    friend NComplex operator*(double k, NComplex C);   // 실수 x 복소수
    
    NComplex operator/(NComplex C); // 복소수 / 복소수 (유리화 필요)
    NComplex operator/(double k);   // 복소수 / 실수
    friend NComplex operator/(double k, NComplex C);   // 실수 / 복소수 (유리화 필요)
    
};
// 객체 출력에 필요한 오버로딩.
ostream& operator<<(ostream &cout, const NComplex &C){
    cout.setf(ios::fixed);
    cout.precision(1);
    if(C.real!=0 && C.image!=0){    //만약 실수부와 허수부 둘다 0이 아닌 경우
        if(C.image > 0)
            cout<<C.real<<" + "<<C.image<<'i';
        else if(C.image < 0)
            cout<<C.real<<C.image<<'i'; //허수부가 음수라면 '-'가 저절로 앞에 붙기 때문에 문자 -는 굳이 추가 안함.
    }
    else if(C.real==0 && C.image!=0)   //실수부가 0인경우 0을 출력하지 않아도 되므로 허수부만 출력
        cout<<C.image<<'i';
    else if(C.real!=0 && C.image==0)   //허수부가 0인경우 0을 출력하지 않아도 되므로 실수부만 출력
        cout<<C.real;
    
    return cout;
}

// 복소수 덧셈 연산
NComplex NComplex::operator+(NComplex C){   //복소수 + 복소수
    NComplex T;
    T.real = real + C.real;
    T.image = image + C.image;
    return T;
}
NComplex NComplex::operator+(double k){     //복소수 + 실수
    NComplex T;
    T.real = real+k;
    T.image = image;
    return T;
}
NComplex operator+(double k, NComplex C){      //실수 + 복소수
    NComplex T;
    T.real = k+C.real;
    T.image = C.image;
    return T;
}


// 복소수 뺄셈 연산
NComplex NComplex::operator-(NComplex C){   //복소수 - 복소수
    NComplex T;
    T.real = real - C.real;
    T.image = image - C.image;
    return T;
}
NComplex NComplex::operator-(double k){     //복소수 - 실수
    NComplex T;
    T.real = real-k;
    T.image = image;
    return T;
}
NComplex operator-(double k, NComplex C){   //실수 - 복소수
    NComplex T;
    T.real = k-C.real;
    T.image = C.image;
    return T;
}



// 복소수 곱셈 연산
NComplex NComplex::operator*(NComplex C){   //복소수 * 복소수
    NComplex T;
    T.real = real*C.real - (image*C.image);
    T.image = real*C.image + C.real*image;
    return T;
}
NComplex NComplex::operator*(double k){     //복소수 * 실수
    NComplex T;
    T.real = k*real;
    T.image = k*image;
    return T;
}
/*
 (복소수) x (상수)
 (상수) x (복소수)
 (1+i) x 2  = 2+2i -> (real=1, image=1 , 문자 i) x 상수
 2 x (1+i)  = 2+2i -> 상수 x (real=1, image=1 , 문자 i)
 
 */
NComplex operator*(double k, NComplex C){   //실수 * 복소수
    NComplex T;
    T.real = k*C.real;
    T.image = k*C.image;
    return T;
}

// 복소수 나눗셈 연산
NComplex NComplex::operator/(NComplex C){   //복소수 / 복소수 (유리화 필요)
    NComplex T;
    if(C.real*C.real + C.image*C.image == 0){
        cout<<"Error: divide by zero"<<endl;
        exit(0);
    }
    else{
        //(a+bi)/(c+di) == 1/(c^2 + d^2){(ac+bd) - (ad-bc)i}
        // (a+bi)(c-di) == ac + bd - (ad - bc)i  // 분자
        //유리화
        T.real = (real*C.real + image*C.image) / (C.real*C.real + C.image*C.image);
        T.image = (-real*C.image + C.real*image) / (C.real*C.real + C.image*C.image);
    }
    return T;
}
NComplex NComplex::operator/(double k){     // 복소수/실수
    NComplex T;
    T.real = real/k;
    T.image = image/k;
    return T;
}
NComplex operator/(double k, NComplex C){  // 실수/복소수   (유리화 필요)
    //예시.  k / (2+3i) = k(2-3i)/(2^2 - (3i)^2)
    NComplex T;
    T.real = k*(C.real)/(C.real*C.real + C.image*C.image);
    T.image = k*(C.image)/(C.real*C.real + C.image*C.image);
    return T;
}



int main(){
    NComplex n1(5.1, 2.2), n2(2.0, 2.0), n3;
    double d1 = 3.0;
    
    cout<<"n1+n2: "<<n1+n2<<endl;
    cout<<"n1*n2: "<<n1*n2<<endl;
    cout<<"n1-d1: "<<n1-d1<<endl;
    cout<<"d1*n2: "<<d1*n2<<endl;
    cout<<"n1/n3: "<<n1/n3<<endl;
}