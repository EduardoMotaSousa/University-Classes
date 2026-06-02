#include <iostream>
#include <iomanip>

using namespace std;

//Até 5 Kg           Acima de 5 Kg
//File Duplo R$ 4,90 por Kg R$ 5,80 
//Alcatra R$ 5,90 por Kg R$ 6,80 
//Picanha R$ 6,90 por Kg R$ 7,80 

///Para atender a todos os clientes, cada cliente poderá levar apenas um dos tipos de carne da promoção, 
//porém não há limites para a quantidade de carne por cliente.

//Se compra for feita no cartão Tabajara o cliente receberá ainda um desconto de 5% sobre o total da compra.

//Escreva um programa que peça o tipo e a quantidade de carne comprada pelo usuário e gere um cupom fiscal, 
//contendo as informações da compra: tipo de carne quantidade de carne preço total tipo de pagamento valor do desconto valor a pagar.

int main() {
    double valor{}, kilos{}, valordesconto{};
    char carne, cartao;
    std::string desconto, tipocarne;

    // Exibe tabela
    cout << "_______________________\n"
         << "    TABELA DE PREÇOS   \n"
         << "   ATÉ 5KG | ACIMA 5KG \n"
         << "      FILE DUPLO       \n"
         << "   R$4,90  | R$5,80    \n"
         << "        ALCATRA        \n"
         << "   R$5,90  | R$6,80    \n"
         << "        PICANHA        \n"
         << "   R$6,90  | R$7,80    \n"
         << "_______________________\n";

    // Entrada de dados
    cout << "\nQual tipo de carne você vai levar?"
         << "\n(F-File / A-Alcatra / P-Picanha): ";

    cin >> carne;

    cout << "Quantos kilos de carne: ";
    cin >> kilos;

    if(kilos < 0.0){
        cout << "Somente valores positivos!";
        return 0;
    }

    cout << "O pagamento será com o cartão da loja? (S/N): ";
    cin >> cartao;

    //tipo carne
    switch (carne){
        case 'F':
        case 'f':
            if(kilos <= 5.0){
                valor = kilos * 4.9;
            }
            else{
                valor = kilos * 5.8;
            }
            tipocarne = "File Duplo";
            break;

        case 'A':
        case 'a':
            if(kilos <= 5.0){
                valor = kilos * 5.9;
            }
            else{
                valor = kilos * 6.8;
            }
            tipocarne = "Alcatra";
            break;

        case 'P':
        case 'p':
            if(kilos <= 5.0){
                valor = kilos * 6.9;
            }
            else{
                valor = kilos * 7.8;
            }
            tipocarne = "Picanha";
            break;

        default:
            cout << "Opção invalida";
            return 0;
    }

    //cartão
    switch (cartao)
    {
        case 'S':
        case 's':
            valordesconto = valor * 0.05;
            desconto = "Sim! 5%";
            break;
        case 'N':
        case 'n':
            desconto = "Não, você não usou nosso cartão da loja";
            break;

        default:
            cout << "Opção invalida";
            return 0;
    }



    // Saída formatada
    cout << fixed << setprecision(2);

    cout << "\n_______________________\n"
         << "Valor total: R$ " << valor  - valordesconto<< "\n"
         << "Valor do desconto: R$ " << valordesconto<< "\n"
         << "Peso total: " << kilos << " Kg\n"
         << "Tipo de carne: " << tipocarne
         << "\nDesconto: " << desconto
         << "\n_______________________\n";

    return 0;
}
