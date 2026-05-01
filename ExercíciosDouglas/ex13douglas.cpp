#include <iomanip>
#include <iostream>
using namespace std;

int main(){
    float h;

    cout << "Qual sua altura em metros? ";
    cin >> h;

    cout << "Seu peso ideal:\nSe você for homem: " << (72.7*h)-58 << "\nSe você for mulher: " << (62.1*h)-44.7 << endl;

    return 0;
}