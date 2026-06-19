#include <iostream>
using namespace std;

//Um posto está vendendo combustíveis com a seguinte tabela de descontos:
//Álcool: até 20L, desconto de 3%. Acima de  20L, 5%.

//Gasolina: até 20 litros, desconto de 4%. Acima de  20L, 6%.

//Escreva um algoritmo que leia o número de litros vendidos, o tipo 
//de combustível (codificado da seguinte forma: A-álcool, G-gasolina)

//Calcule e imprima o valor a ser pago pelo cliente sabendo-se que o 
//preço do litro da gasolina é R$ 2,50 o preço do litro do álcool é 
//R$ 1,90.

int main(){
    float litros, valor;
    char combus;
    int desconto;

    //lê as informações
    cout << "Qual tipo de combustivel (A-álcool, G-gasolina): ";
    cin >> combus;

    cout << "Quantos litros? ";
    cin >> litros;
    
    if(litros < 0){
        cout << "Valor invalido\n";
        return 0;
    }

    //Valida o tipo de combustivel + calcula o valor
    if(combus == 'A' || combus == 'a'){
        if(litros <= 20){
            valor = (litros*1.9)*0.97;
            desconto = 3;
        }
        else{
            valor = (litros*1.9)*0.95;  
            desconto = 5; 
        }
    }

    else if(combus == 'G' || combus == 'g'){
        if(litros <= 20){
            valor = (litros*2.5)*0.96;
            desconto = 4;
        }
        else{
            valor = (litros*2.5)*0.94;
            desconto = 6;   
        }
    }   

    else{
        cout << "Tipo de combustivel invalido, marque apenas A ou G\n";
        return 0;
    }

    //escreve o resultado
    cout << "\nVocê ganhou um desconto de: " << desconto << "%"
         << "\nValor: R$" <<  valor << endl;

    return 0;
}