#include <iostream>
using namespace std;

//Uma fruteira está vendendo frutas com a seguinte tabela de preços:

//Até 5 Kg           Acima de 5 Kg
//Morango R$ 2,50 por Kg R$ 2,20 por Kg Maçã R$ 1,80 por Kg R$ 1,50 por Kg

//Se o cliente comprar mais de 8 Kg em frutas ou o valor total da compra ultrapassar R$ 25,00, receberá ainda um desconto de 10% sobre este total.

//Escreva um algoritmo para ler a quantidade (em Kg) de morangos e a quantidade (em Kg) de maças adquiridas e escreva o valor a ser pago pelo cliente.

int main(){
    float maca, moran, valor;

    //escreve a tabela na tela
    cout << "_______________________\n"  
         << "    TABELA DE PREÇOS   \n"
         << " ATÉ 5KG:   ACIMA 5KG: \n"
         << "        MORANGO        \n"
         << "  R$2,50       R$2,20  \n"
         << "          MAÇÃ         \n"
         << "  R$1,80       R$1,50  \n"
         << "_______________________\n";

     
    cout << "Quantos KGs de morango você vai levar?";
    cin >> moran;

    if(moran < 0.0){
        cout << "Valor invalido! Somente valores positivos.";
        return 0;
    }
    else if(moran <= 5.0){
        valor = moran * 2.5;
    }

    cout << "Quantos KGs de maça você vai levar?";
    cin >> maca;

    
    return 0;
}