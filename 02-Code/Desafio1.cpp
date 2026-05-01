#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    float c;

    cout << "Celsius: ";
    cin >> c;

    cout << c << "°C = " << c*9/5 + 32 << "°F";

    return 0;
}