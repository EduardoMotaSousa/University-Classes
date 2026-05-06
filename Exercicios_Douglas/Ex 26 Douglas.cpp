#include <iostream>
#include <iomanip>
using namespace std;

//Faça um programa que pergunte o preço de três produtos e informe qual 
//produto você deve comprar, sabendo que a decisão é sempre pelo mais barato.

int main(){
    float preco[3] = {0.0, 0.0, 0.0};
    std::string nome[3] = {"", "", ""};

    for(int i =0; i < 3; i++){
        cout << "Digite o nome do produto: ";
        cin >> nome[i];

        cout << "Digite o valor do produto: ";
        cin >> preco[i];

        if(preco[0] > preco[i]){
            preco[0] = preco[i];
            nome[0] = nome[i];
        }
    }
    cout << nome[0] << " É o produto mais barato custando: R$" << preco[0] << endl;

    return 0;
}