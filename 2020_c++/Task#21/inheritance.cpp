#include <iostream>
#include <string>
using namespace std;

class Employee
{
public:
    Employee();
    Employee(const string& theName, const string& theSsn); //멤버변수인 netpay를 생성자에 넣지 않는 이유는 클래스 내에서 계산을 따로 해주고 할당하기 때문에
    string getName() const;
    string getSsn() const;
    double getNetPay() const;
    void setName(const string& newName);
    void setSsn(const string& newSsn); 
    void setNetPay(double newNetPay);
    void printCheck() const;
private:
    string name;
    string ssn;
    double netPay;
};

Employee::Employee():name("No name yet"), ssn("No number yet"), netPay(0){}
Employee::Employee(const string& theName, const string& theSsn):name(theName), ssn(theSsn){}
string Employee::getName() const { return name; }
string Employee::getSsn() const {return ssn;}
double Employee::getNetPay() const {return netPay;}
void Employee::setName(const string &newName){name = newName;}
void Employee::setSsn(const string &newSsn){ssn = newSsn;}
void Employee::setNetPay(double newNetPay){netPay = newNetPay;}
void Employee::printCheck() const{
    cout<<"\nERROR: printCheck FUNCTION CALLED FOR AN \n"
    <<"UNDIFFERENT EMPLOYEE. Aborting the program.\n"
    <<"Check with the author of the program about this pug.\n";
    exit(1);
}
class HourlyEmployee : public Employee
{
    public:
        HourlyEmployee();
        HourlyEmployee(const string& theName, const string& theNumber, double theWageRate, double theHours);
        void setRate(double newWageRate);
        double getRate() const;
        void setHours(double hoursWorked);
        double getHours() const;
        void printCheck();
    private:
         double wageRate;
         double hours;        
};

HourlyEmployee::HourlyEmployee() : Employee(), wageRate(0), hours(0)
{

}

HourlyEmployee::HourlyEmployee(const string& theName, const string& theNumber, double theWageRate, double theHours)
          : Employee(theName, theNumber), wageRate(theWageRate), hours(theHours)
            //위에 Employee 클래스에서 생성자함수에 parameter 두개 선언해주었기 때문에( , )
      
{

}          

void HourlyEmployee::setRate(double newWageRate)
{
    wageRate = newWageRate;
}

double HourlyEmployee::getRate() const
{
    return wageRate;
}

void HourlyEmployee::setHours(double hoursWorked)
{
    hours = hoursWorked;
}

double HourlyEmployee::getHours() const
{
    return hours;
}
void HourlyEmployee::printCheck()
{
    setNetPay(hours * wageRate);

    cout << "\n______________________________________\n";
    cout << "Pay to the order of " << getName() << endl;
    cout << "The sum of " << getNetPay() << " Dollars\n";
    cout << "______________________________________\n";
    cout << "Check Stub: NOT NEGOTIABLE\n";
    cout << "Employ Number: " << getSsn() << endl;
    cout << "Hourly Employee. \nHours worked: " << hours
    << " Rate: " << wageRate << " Pay: " << getNetPay()<< endl;
    cout << "______________________________________\n";

}

class UnivHourlyEmployee : public HourlyEmployee
{
public:
    UnivHourlyEmployee();
    UnivHourlyEmployee(const string& theName, const string& theNumber, const string& theUniv, double theWageRate, double theHours);
    void setUniv(double newUniv);
    string getUniv() const;
    void printInfo();
private:
    string univName;
};

UnivHourlyEmployee::UnivHourlyEmployee():HourlyEmployee(), univName("No Univ yet"){}
UnivHourlyEmployee::UnivHourlyEmployee(const string& theName, const string& theNumber, const string& theUniv, double theWageRate, double theHours):HourlyEmployee(theName, theNumber, theWageRate, theHours), univName(theUniv){}
void UnivHourlyEmployee::setUniv(double newUniv){
    univName = newUniv;
}
string UnivHourlyEmployee::getUniv() const{
    return univName;
}
void UnivHourlyEmployee::printInfo()
{
    cout << "Employee name: "<< getName() << ", Affliation: " << getUniv();
    printCheck();
}

int main()
{
    UnivHourlyEmployee jhon("JohnDoe", "123456", "SSU", 10, 40);
    jhon.printInfo();
}