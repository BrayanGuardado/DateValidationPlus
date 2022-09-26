#include"DateValidationP.h"
#include<cstring>
#include<iostream>
using namespace std;

int convertStringToInt(string);

void DateValidationP::mainDate() {

    cout<<"Type the date with the format yyyy/mm/dd: ";
    cin>>inputDate;

    char charDate[inputDate.length() + 1];
    strcpy(charDate, inputDate.c_str());

    int auxCounter = 0;
    for(int i = 0; i<inputDate.length(); i++){
        if(charDate[i] != '/'){
            date[auxCounter] += charDate[i];
        }else{
            auxCounter++;
        }
    }

    cout<<"Date: "<<date[0]<<"/"<<date[1]<<"/"<<date[2];

}

void DateValidationP::yearValidation() {
    if(convertStringToInt(date[0]) < 1){
        cout<<"\nThe year is not correct";
    }else{
        cout<<"\nThe year is correct";
    }
}

void DateValidationP::monthValidation() {
    if (convertStringToInt(date[1]) >= 1 && convertStringToInt(date[1]) <= 12)
        cout << "\nThe month is correct";
    else {
        cout << "\nThe month is not correct";
    }
}

void DateValidationP::dayValidation() {

    if(convertStringToInt(date[1]) == 1 || convertStringToInt(date[1]) == 3 || convertStringToInt(date[1]) == 5 || convertStringToInt(date[1]) == 7 ||
        convertStringToInt(date[1]) == 8 || convertStringToInt(date[1]) == 10 || convertStringToInt(date[1]) == 12){
        if(convertStringToInt(date[2]) >= 1 && convertStringToInt(date[2]) <= 31) {
            cout << "\nThe day is correct";
        }
        else{
            cout<<"\nThe day is not correct";
        }
    }
    else if(convertStringToInt(date[1]) == 2){
        if(convertStringToInt(date[0]) % 4 == 0 && convertStringToInt(date[0]) % 100 != 0 || convertStringToInt(date[0]) % 400 == 0) {
            if (convertStringToInt(date[2]) >= 1 && convertStringToInt(date[2]) <= 29) {
                cout << "\nThe day in the leap year is correct";
            }
            else{
                cout << "\nThe day in the leap year is not correct";
            }
        }
        else if(convertStringToInt(date[2]) >= 1 && convertStringToInt(date[2]) <= 28){
            cout << "\nThe day is correct";
        }else{
            cout << "\nThe day is not correct";
        }
    }
    else if(convertStringToInt(date[1]) == 4 || convertStringToInt(date[1]) == 6 || convertStringToInt(date[1]) == 9 || convertStringToInt(date[1]) == 11){
        if(convertStringToInt(date[2]) > 1 && convertStringToInt(date[2]) < 30){
            cout<<"\nThe day is correct";
        }else{
            cout<<"\nThe day is not correct";
        }
    }
    else cout<<"\nThe day is not correct or the month don't exist";

}

DateValidationP &DateValidationP::operator++() {

    int year = 0, month = 0, day = 0;
    year = convertStringToInt(date[0]);
    month = convertStringToInt(date[1]);
    day = convertStringToInt(date[2]);

    ++day;
    if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12){
        if(day > 31){
            day = 1;
            month++;
            if(year > 12){
                month = 1;
                year++;
            }
        }
    }
    else if(month == 4 || month == 6 || month == 9 || month == 11){
        if(day > 30){
            day = 1;
            month++;
            if(month > 12){
                month = 1;
                year++;
            }
        }
    }
    else if(month == 2){
        if(year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
            if(day > 29){
                day = 1;
                month++;
                if(month > 12){
                    month = 1;
                    year++;
                }
            }
        }
        else if(day > 28){
            day = 1;
            month++;
            if(month > 12){
                month = 1;
                year++;
            }
        }
    }

    cout<<"\n\nThe nex date: "<<endl;
    cout<<year<<"/"<<month<<"/"<<day;

    return *this;
}

int convertStringToInt(const string text){
    return stoi(text);
}