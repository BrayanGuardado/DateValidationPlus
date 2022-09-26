#include "Program.h"
#include "DateValidationP.h"

void Program::run() {

    string inputDate;
    string date[3] = {"","",""};
   DateValidationP data(inputDate, &date[3]);

    data.mainDate();
    data.yearValidation();
    data.monthValidation();
    data.dayValidation();
    data.operator++();

}