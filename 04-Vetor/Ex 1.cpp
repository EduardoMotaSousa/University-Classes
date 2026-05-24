#include <iostream>
using namespace std;

int main(){
    int menor, maior, num[10], indice[2];

    //le os numeros 
    for(int i = 0; i < 30; i++){
        cin >> num[i];
    }

    menor = num[0];
    maior = num[0];


    // determina menor e maior
    for (int i = 0; i < 30; i++)
    {
        if(num[i] > maior){
            maior = num[i];
            indice[0] = i;
        }

        if(num[i] < menor){
            menor = num[i];
            indice[1] = i;
        }
    }

    //exibe
    cout << "O maior numero é: " << maior << " e esta no indice: " << indice[0] 
         << "\nO menor numero é: " << menor << " e esta no indice: " << indice[1] << endl;
    
    return 0;
}