#include <iostream>
#include <iomanip>
using namespace std;

// Recebe o salário de um colaborador

// até R$ 280,00 : aumento de 20% 
// entre R$ 280,00 e R$ 700,00 : aumento de 15% 
// entre R$ 700,00 e R$ 1500,00 : aumento de 10% 
// de R$ 1500,00 em diante : aumento de 5% 

// informe na tela: salário antes do reajuste; o percentual de 
// aumento aplicado; o valor do aumento; o novo salário, após o aumento.

int main(){
    double sal, sal_aumento;
    int porcen;

    std::cout << std::fixed << std::setprecision(2);

    cout << "Salário: ";
    cin >> sal;
    
    if(sal <= 280){
        sal_aumento = sal*1.2;
        porcen = 20;
    }

    else if(sal <= 700){
        sal_aumento = sal*1.15;
        porcen = 15;
    }

    else if(sal <= 1500){
        sal_aumento = sal*1.1;
        porcen = 10;
    }

    else{
        sal_aumento = sal*1.05;
        porcen = 5;
    }
    cout << "Salário antigo: R$" << sal << "\nAumento percentual: " << porcen << "%\nAumento real: R$" << sal_aumento - sal << "\nSalário atual: R$" << sal_aumento << endl;

    return 0;
}