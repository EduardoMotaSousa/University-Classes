#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    float altura;

    cout << "Sua altura em metros: ";
    cin >> altura;

    cout << "Peso ideal: " << (72.7*altura)-58;

    return 0;
}