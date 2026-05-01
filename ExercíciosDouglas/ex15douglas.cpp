#include <iomanip>
#include <iostream>
using namespace std;

int main(){
    float horas, money, salario;

    cout << "Quanto ganha por hora: ";
    cin >> money;
    cout << "Quantos horas tabalha: ";
    cin >> horas;

    salario = horas * money;

    float ir = salario * 0.11;
    float inss = salario * 0.08;
    float sindicato = salario * 0.05;
    float sa_liq = salario - (ir + inss + sindicato);

    std::cout << std::fixed << std::setprecision(2);

    cout << "Salário bruto: R$" << salario << "\nIR: R$" << ir << "\nINSS: R$" << inss << "\nSindicato: R$" << sindicato << "\nSalário Liquido: R$" << sa_liq << endl;
    
    return 0;
}