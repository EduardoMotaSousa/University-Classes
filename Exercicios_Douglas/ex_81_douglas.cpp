#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Foi feita uma estatística em cinco cidades brasileiras para coletar dados sobre acidentes de trânsito.

//Foram obtidos os seguintes dados: Código da cidade; Número de veículos de passeio (em 1999); Número de acidentes de trânsito com vítimas (em 1999).

//Deseja-se saber: Qual o maior e menor índice de acidentes de trânsito e a que cidade pertence; Qual a média de veículos nas cinco cidades juntas; 
//Qual a média de acidentes de trânsito nas cidades com menos de 2.000 veículos de passeio.

int main() {
    std::string cidades[5] = {"Curitiba", "São Paulo", "Londrina", "Rio De Janeiro", "Cuiaba"};
    int veiculos[5] = {0}, mediaveiculos{}, mediaacidentes{}, maior, menor, numacidentes{};
    double acidentes[5] = {0.0}; //Double para futuramente calcular o indice 

    //Escreve nos vetores
    for(int i = 0; i < 5; i++){
	    //Escreve veiculos[i]
        do{
            cout << "\n==========" << cidades[i] << "=========="
                << "\nQual a quantidade de veiculos da cidade? ";
            cin >> veiculos[i];
        }while(veiculos[i] <= 0);

        mediaveiculos += veiculos[i];
        
        //Escreve acidentes[i]
        do{
            cout << "Qual a quantidade de acidentes da cidade? ";
            cin >> acidentes[i];
        }while(acidentes[i] < 0);
        
        if(i == 0){
            maior = menor = i;
        }
        
        //Se menor que 2mil add
        if(veiculos[i] < 2000){
            mediaacidentes += acidentes[i];
            numacidentes++;
        }

        //transforma o total em indice
        acidentes[i] /= veiculos[i];

        //valida maior e menor
        if(acidentes[i] >= acidentes[maior]){
            maior = i;
        }

        if(acidentes[i] <= acidentes[menor]){
            menor = i;
        }
    }

    cout << fixed << setprecision(4);

    cout << "\n========Estatística========"
        << "\nMaior indice de acidentes: " << acidentes[maior] << " em: " << cidades[maior]
        << "\nMenor indice de acidentes: " << acidentes[menor] << " em: " << cidades[menor]
        << "\nMedia de veiculos das cidades: " << mediaveiculos / 5
        << "\nMedia de acidentes em cidades com menos de 2k de veiculos: " << mediaacidentes / numacidentes;
        
    return 0;
}