#include <iostream>
#include <iomanip>
using namespace std;

// Faça um programa que receba: O Valor de uma dívida. E mostre uma tabela com os seguintes dados: 
// Valor da dívida, Valor dos juros, Quantidade de parcelas e Valor da parcela.

// Os juros e a quantidade de parcelas seguem a tabela abaixo: Quantidade de Parcelas % de Juros sobre o valor inicial da dívida:
// 1x = 0% 
// 3x = 10% 
// 6x = 15% 
// 9x = 20% 
// 12x = 25%

// Exemplo de saída do programa: Valor da Dívida, Valor dos Juros, Quantidade de Parcelas, Valor da Parcela 
// R$ 1.000,00 | Juros: R$0,00 | 1xR$ 1.000,00 
// R$ 1.100,00 | Juros: R$100,00 | 3xR$ 366,00 
// R$ 1.150,00 | Juros: R$150,00 | 6xR$ 191,67

int main() {
    double divida, dividaatt, jurosValor{},  juros[5] = {0, 10, 15, 20, 25};
    int quantidadeParcelas[5] = {1, 3, 6, 9, 12};

    cout << fixed << setprecision(2);

    //Entra divida e valida
    do{
        cout << "Qual o valor da divida(Maior do que R$10,00): ";
        cin >> divida;
    }while(divida <= 10);

    //calcula
    for(int i = 0; i < 5; i++){
        dividaatt = divida;

        if(i > 0){
            jurosValor = divida * juros[i] / 100;
            dividaatt += jurosValor;
        }

        cout << "R$" << dividaatt
             << " | Juros: R$" << jurosValor << " | "
             << quantidadeParcelas[i] << "xR$" << dividaatt / quantidadeParcelas[i] << endl;

    }
        
    return 0;
}