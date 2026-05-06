#include <iostream>
#include <iomanip>
using namespace std;

//Faça um Programa que verifique se uma letra digitada é "F" ou "M". 
//Conforme a letra escrever: F - Feminino, M - Masculino, Sexo Inválido.

int main(){
    char gen;

    cout << "Qual seu genero(F ou M): ";
    cin >> gen;

    if(gen == 'F'){
        cout << "Feminino\n";
    }
    else if(gen == 'M'){
        cout << "Masculino\n";
    }
    else{
        cout << "Sexo inválido\n";
    }
    return 0;
}