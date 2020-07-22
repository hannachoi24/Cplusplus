#include <iostream>
#include <string>
using namespace std;

class HotDogStand{
public:
    HotDogStand(string getname); //생성자
    void justSold(int hotDogs); // 핫도그 판매 메소드
    static int getTotalNumSold();   //전체 핫도그 판매 매소드
    int getNumSold();   //각 객체마다 몇개의 핫도를 판매했는지
    string getName();   //핫도그 판매처의 이름
private:
    static int sales; //핫도그 판매량 멤버 변수 설정(sales)
    int hotDog;       
    string name;      //가맹점 이름
};

int HotDogStand::sales = 0; //static은 클래스 밖에서 초기화해줘야 함

int main()
{
    HotDogStand h1("ssu-1"), h2("ssu-2"), h3("cau-1");
    h1.justSold(20);
    h2.justSold(50);
    h3.justSold(1);

    cout << h1.getName() << " has sold " << h1.getNumSold() << " hotdogs." << endl;
    cout << h2.getName() << " has sold " << h2.getNumSold() << " hotdogs." << endl;
    cout << h3.getName() << " has sold " << h3.getNumSold() << " hotdogs." << endl;
    cout << "Total sales are: " << HotDogStand::getTotalNumSold() << endl;

}

HotDogStand::HotDogStand(string getname):name(getname){}
void HotDogStand::justSold(int hotDogs){
    sales += hotDogs; //멤버변수(데이터) = 
    hotDog = hotDogs; //멤버변수(데이터) =
}
int HotDogStand::getTotalNumSold(){
    return sales;
}
int HotDogStand::getNumSold(){
    return hotDog;
}
string HotDogStand::getName(){
    return name;
}