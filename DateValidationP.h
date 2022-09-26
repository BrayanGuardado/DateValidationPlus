#include<cstring>
#include<iostream>
using namespace std;
class DateValidationP {
private:
    string inputDate;
    string date[3] = {"","",""};
public:
    DateValidationP(string _inputDate, string _date[]){
        inputDate = _inputDate;
        date[3] = _date[3];
    }
    void mainDate();
    void yearValidation();
    void monthValidation();
    void dayValidation();
    DateValidationP& operator++();
};

