#include <iostream>
#include <iomanip>
using namespace std;

int main (){
    float c;

    cout << "Temperatura em Celcius: ";
    cin >> c;

    cout << "Farerint: " << (c*1.8)+32;

    return 0;
}