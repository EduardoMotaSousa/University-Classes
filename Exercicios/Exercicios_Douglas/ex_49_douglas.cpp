#include <iostream>

using namespace std;

//a população de um país A seja da ordem de 80000 habitantes com uma taxa anual de crescimento de 3% e que a população de B seja 200000 habitantes 
//com uma taxa de crescimento de 1.5%.

//Faça um programa que calcule e escreva o número de anos necessários para que a população do país A ultrapasse ou iguale a população do 
//país B, mantidas as taxas de crescimento.

int main() {
    int anos{}, paisa = 80000, paisb = 200000;

    while(paisa < paisb){
        paisa *= 1.03;
        paisb *= 1.015;
        anos++;
    }
    
    cout << "O país A vai demorar " <<  anos << " anos para ultrapaçar o pais B"
        << "\nA: " << paisa << "\nB: " << paisb << endl; 

    return 0;
}