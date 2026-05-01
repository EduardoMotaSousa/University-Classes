#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main(){
    float m2, tinta;

    cout << "Área em m² para pintar: ";
    cin >> m2;

    tinta = ceil(m2/54); // Cada lata de tinta pinta no total 54m²

    if(tinta <= 1){
        cout << "Será necessário somente uma lata de tinta de 18 Litros\nValor total R$80,00 reais\n";
    } 

    else{
        cout << "Latas de tinta necessárias: " << tinta << "\nValor total: R$" << 80*tinta << ",00\n";
    }

    return 0;
}