#include <iostream>
#include <iomanip>
using namespace std;

//peça uma data no formato dd/mm/aaaa e determine se a mesma é uma data válida.

int main(){
    int day, month, year;

    cout << "Enter day: ";
    cin >> day;
    
    if (day > 31 || day < 0){
        cout << "Day invalid";
        return 0;
    }

    cout << "Enter month: ";
    cin >> month;
    
    if (month > 12 || month < 0){
        cout << "Month invalid";
        return 0;
    }

    cout << "Enter year D.C.: ";
    cin >> year;
    
    cout << day << "/" << month << "/" << year << endl;
    
    return 0;
}