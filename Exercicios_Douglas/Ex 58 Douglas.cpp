#include <iostream>

using namespace std;

//programa que peça dois números, base e expoente, calcule e mostre o primeiro número elevado ao segundo número. Não utilize a função de potência da linguagem.

int main() {
    int num1, num2, resultado{};

    //entra dados
    cout << "Base: ";
    cin >> num1;
    
    cout << "Expoente: ";
    cin >> num2;

    resultado = 1;

    for(int i = 0; i < num2; i++){ 
        resultado *= num1;
    }

    cout << "Resultado: " << resultado;
  
    return 0;
}