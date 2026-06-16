#include <iostream>
#include <iomanip>
using namespace std;

//O Sr. Manoel Joaquim expandiu seus negócios para além dos negócios de 1,99 e agora possui uma loja de conveniências.

//Faça um programa que implemente uma caixa registradora rudimentar.

//O programa deverá receber um número desconhecido de valores referentes aos preços das mercadorias.

//Um valor zero deve ser informado pelo operador para indicar o final da compra.

//O programa deve então mostrar o total da compra e perguntar o valor em dinheiro que o cliente forneceu, para então calcular e mostrar o valor do troco.

//Após esta operação, o programa deverá voltar ao ponto inicial, para registrar a próxima compra.

//A saída deve ser conforme o exemplo abaixo: Lojas Tabajara Produto 1: R$ 2.20 Produto 2: R$ 5.80 Produto 3: R$ 0 Total: R$ 9.00 Dinheiro: R$ 20.00 Troco: R$ 11.00

int main() {
    int local{};
    double valor[1000], valortotal{}, dinheiro;
    std::string produto[1000];

    for(int i = 0; i < 1000; i++){ 
        cout << "Nome do produto: ";
        cin >> produto[i];

        cout << "Valor do " << produto[i] << ": ";
        cin >> valor[i];

        if(valor[1] < 0){
            cout << "Digite um valor valido!\n";
            i--;
            continue;
        }

        else if(valor[i] == 0){
            local--;
            break;
        }

        valortotal += valor[i];
        local++;
    }

    cout << fixed << setprecision(2);

    do{ 
        cout << "Valor total: R$" << valortotal
            << "\nValor pago? ";
        cin >> dinheiro;

        if(dinheiro<valortotal){
            cout << "Dinheiro insuficiente!\n";
        }

    }while(dinheiro < valortotal);

    while(local >= 0){
        cout << produto[local] << ": R$"
            << valor[local] << endl;
        local--;
    }
    cout << "O valor total: " << valortotal
        << "Troco: " << valortotal - dinheiro;

    return 0;
}