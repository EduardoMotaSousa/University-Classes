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
    double valor[1000], dinheiro;
    char denovo;
    std::string produto[1000];

    cout << "\n========== LOJAS TABAJARA ==========\n";

    do{
     int local{};
     double valortotal{};
    
    //Escreve nos vetores
    for(int i = 0; i < 1000; i++){ 

        cout << "Valor do produto " << i+1 << "°: ";
        cin >> valor[i];

        if(valor[i] < 0){
            cout << "Digite um valor valido!\n";
            i--;
            continue;
        }

        else if(valor[i] == 0){
            break;
        }

        cout << "Nome do produto: ";
        cin >> produto[i];

        valortotal += valor[i];
        local++;
    }

    cout << fixed << setprecision(2);

    //entrada de dinheiro
    do{ 
        cout << "\nValor total: R$" << valortotal
            << "\nValor pago? ";
        cin >> dinheiro;

        if(dinheiro < valortotal){
            cout << "Dinheiro insuficiente!\n";
        }

    }while(dinheiro < valortotal);

    cout << "\n========== LOJAS TABAJARA ==========\n";

    //Detalhas os itens
    for(int i = 0; i < local; i++){ 
        cout << produto[i] << ": R$"
            << valor[i] << endl;
    }

    //Exibe na tela
    cout << "\nO valor total: R$" << valortotal
	    << "\nDinheiro: R$" << dinheiro
        << "\nTroco: R$" << dinheiro - valortotal
	    << "\n\nProxima compra?(S para continuar)";
    cin >> denovo;

    }while(denovo == 'S' || denovo == 's');

    return 0;
}