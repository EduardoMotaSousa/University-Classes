#include <iostream>
#include <iomanip>
using namespace std;

//cálculo de uma folha de pagamento, sabendo que os descontos são do Imposto de Renda, 
//que depende do salário bruto (conforme tabela abaixo) e 10% para o INSS e que o FGTS 
//corresponde a 11% do Salário Bruto, mas não é descontado (é a empresa que deposita).

//O Salário Líquido corresponde ao Salário Bruto menos os descontos. O programa deverá 
//pedir ao usuário o valor da sua hora e a quantidade de horas trabalhadas no mês.

//Desconto do IR: Salário Bruto até 900 (inclusive) - isento Salário Bruto até 1500 
//(inclusive) - desconto de 5% Salário Bruto até 2500 (inclusive) - desconto de 10% 
//Salário Bruto acima de 2500 - desconto de 20%

//Imprima na tela as informações, dispostas conforme o exemplo abaixo. No exemplo o 
//valor da hora é 5 e a quantidade de hora é 220.

int main(){
    float sal, salh, horas, descon{};

    cout << "Horas trabalhadas: ";
    cin >>  horas;

    cout << "Salário por hora: ";
    cin >>  salh;

    sal = salh * horas;

    std::cout << std::fixed << std::setprecision(2);

    cout << "\nSalário bruto: (" << "R$" << salh << " Horas:" << horas << "): R$" << sal << endl;
    cout << "(-) IR: (5%): R$" << sal * 0.05 << endl;
    descon = descon + (sal * 0.05);

    cout << "(-) INSS: (10%): R$" << sal * 0.1 << endl;
    descon = descon + (sal * 0.1);

    cout << "FGTS: (11%): R$" << sal * 0.11 << endl;

    cout << "Total de descontos: R$" << descon << endl;
    cout << "Salário Liquido: R$" << sal - descon << endl;

    return 0;
}