#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    int peso; //Escolhi fazer com int ao invés de float por conta que a questão não expecifica a multa por gramas excedentes

    cout << "Kilos de peixe: ";
    cin >> peso;

    if(peso > 50){
        cout << "Passou do limite por: " << peso - 50 << "\nMulta de: R$" << (peso - 50)*4 << ",00\n";
    }
    else{
        cout << "Dentro do limite" << endl;
    }
    return 0;
}
