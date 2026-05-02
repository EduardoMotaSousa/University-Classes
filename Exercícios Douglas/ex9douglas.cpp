#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    float c, f;

    cout << "Temperatura em Farenheit:";
    cin >> f;

    c = 5*(f-32)/9;

    cout << "Temperatura em Celcius: " << c << endl;

    return 0;
}