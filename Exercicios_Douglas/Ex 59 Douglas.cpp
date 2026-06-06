#include <iostream>

using namespace std;

//eça 10 números inteiros, calcule e mostre a quantidade de números pares e a quantidade de números impares.

int main() {
    int vet[10], pares{}, impares{};

    //entra dados no vetor + calculo
    for(int i{}; i < 10; i++){
        vet[i] = i;

        if(vet[i] % 2 == 0){
            pares++;
        }
        else{
            impares++;
        }
    }

    //mostra na tela
    cout << "Pares: " << pares
        << "\nImpares: " << impares << endl;    
  
    return 0;
}