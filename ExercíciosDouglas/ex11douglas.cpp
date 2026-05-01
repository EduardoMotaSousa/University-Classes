#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main(){
    int a, b;
    float c;

    cout << "Em sequência, escreva dois números inteiros e um número com virgula: ";
    cin >> a >> b >> c;

    cout << "Soma do dobro do primeiro com a metade do segundo: " << a*2 + b/2 << endl;
    cout << "Soma do triplo do primeiro com o terceiro: " << a*3 + c <<  endl;
    cout << "Terceiro ao cubo: " << std::pow(c, 3) << endl;

    return 0;
}