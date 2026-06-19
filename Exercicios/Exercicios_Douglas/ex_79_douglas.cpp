#include <iostream>
#include <iomanip>
using namespace std;

//Um funcionário de uma empresa recebe aumento salarial anualmente.

//Sabe-se que: Esse funcionário foi contratado em 1995, com salário inicial de R$ 1.000,00; Em 1996 recebeu aumento de 1,5% sobre seu salário inicial; 
//A partir de 1997 (inclusive), os aumentos salariais sempre correspondem ao dobro do percentual do ano anterior.

//Faça um programa que determine o salário atual desse funcionário. Após concluir isto, altere o programa permitindo que o usuário digite o salário 
//inicial do funcionário.



int main() {
    int anoatual;
    double salario = 1000, aumento = 1.5;

    while(true){
    	cout << "Ano: ";
    	cin >> anoatual;

        if(anoatual > 1995){
            break;
        }

        cout << "Ano invalido!\n";
    }

    int anoi = anoatual - 1995; 

    salario *= 1 + aumento / 100;

    for(int i = 1; i < anoi; i++){
	    aumento *= 2;
    	salario *= 1 + aumento / 100;
    }

    cout << fixed << setprecision(2);

    cout << "Salario em " << anoi << " R$ " << salario;

    return 0;
}