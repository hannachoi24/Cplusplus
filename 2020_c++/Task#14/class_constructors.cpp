#include <iostream>
#include <string>
using namespace std;

class DayOfYear{
private:
    string month;
    int day;
    void testDate(){
        if(month == "Jan") month = "January";
        else if(month == "Feb") month = "Febuary";
        else if(month == "Mar") month = "March";
        else if(month == "Apr") month = "April";
        else if(month == "May") month = "May";
        else if(month == "Jun") month = "June";
        else if(month == "Jul") month = "July";
        else if(month == "Aug") month = "August";
        else if(month == "Sep") month = "September";
        else if(month == "Oct") month = "October";
        else if(month == "Nov") month = "November";
        else if(month == "Dec") month = "December";
    }
public:
    //DayOfYear():month("Jan"), day(1){}   //Default Constructor
    DayOfYear(string monthValue):month(monthValue), day(1){}    // date1에 대한 생성자
    DayOfYear(string monthValue, int dayValue):month(monthValue), day(dayValue){testDate();}  // date2에 대한 생성자
    void output(){
        if(month.size() > 3)
            cout<<month<<' '<<day<<'\n';
    }
};

int main(){
    string sMonth;
    int day;
    cout<<"Put an abbreviation of a month (3 chars) and a day (number):";   //Feb 4
    cin>>sMonth>>day; // Feb 4 입력
    DayOfYear date1(sMonth), date2(sMonth, day);        //date1(Feb) date2(Feb, 4)
    date1.output();
    date2.output();
   
    return 0;
}