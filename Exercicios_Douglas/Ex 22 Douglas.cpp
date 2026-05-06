#include <iostream>
#include <iomanip>
using namespace std;

//Faça um Programa que verifique se uma letra digitada é vogal ou consoante.

int main(){
    char letra;
    char vogal[6] = {'a', 'e', 'i', 'o', 'u', '\0'};

    cout << "Escreva uma letra minuscula: ";
    cin >> letra;

    for(int i = 0; i < 5; i++){
        if(letra == vogal[i]){
            cout << letra << " É vogal\n";
            return 0;
        }
    }
    cout << letra << " Não é vogal\n";

    return 0;
}