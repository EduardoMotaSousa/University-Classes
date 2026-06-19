#include <iostream>
#include <iomanip>
using namespace std;

// Faça um programa que calcule o valor total investido por um colecionador em sua coleção de CDs e o valor médio gasto em cada um deles. 
// O usuário deverá informar a quantidade de CDs e o valor para em cada um.

int main() {
    int cds;
    double valortotal{}, valoruni;

    do{ 
	cout << "Quantos CDs você tem? ";
	cin >> cds;
    }while(cds<=0);

    for(int i = 1; i <= cds; i++){
	cout << "Quanto custou o " << i << "° CD?";
	cin >> valoruni;

	if(valoruni > 0){
	    valortotal += valoruni;
	}
	
	else{
	    cout << "Digite um valor valido!\n";
	    i--;
	}
    }   

    cout << fixed << setprecision(2);

    cout << "Você tem uma coleção de: " << cds
	<<  "\nNo valor total de: " << valortotal
	<< "\nOvalor medio dos CDs é: " << valortotal/cds;

    return 0;
}