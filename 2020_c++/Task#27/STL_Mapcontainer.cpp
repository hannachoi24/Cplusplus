#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
    map<int, string> login;
    map<int, string>::iterator iter;
    

    while(1){
        int idnum;
        string idName;
        cout << "Enter the ID number: ";
        cin>>idnum;
        
        if (idnum != 0){
            cout << "Enter the student name: ";
            cin>>idName;
            login[idnum] = idName;
        }
        else{
            int sNum;
            cout<<"Enter the searching ID number: ";
            cin>>sNum;
            
            int cnt=0; //나중에 True/False의 용도로 쓰기 위해..
            for(iter=login.begin(); iter!=login.end(); iter++){
                if(iter->first == sNum)
                    cnt++;  //만약 해당학번이 존재하면 
            }
            if(cnt){    //1이상은 True니까
                cout<<"The student name is "<<login[sNum]<<'\n'; // login[idnum] = idName 선언문 때문에 [snum]이 이름으로 값도출
                break;
            }
            else
                cout<<"존재하지 않는 학번입니다."<<'\n';
            
        }
    }
    
}