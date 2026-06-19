#include <iostream>
using namespace std;

// Faça um programa que leia dez conjuntos de dois valores, o primeiro representando o número do aluno e o segundo representando a sua altura em centímetros.

// Encontre o aluno mais alto e o mais baixo.

// Mostre o número do aluno mais alto e o número do aluno mais baixo, junto com suas alturas.

int main() {
    int i{}, codigo{}, baixo, alto, aluno[10], alturacm[10] = {0};

    do{
        cout << "Qual o codigo do aluno? ";
        cin >> codigo;

        //Valida
        if(codigo <= 0){
            cout << "Valor invalido!\n";
            break;
        }

        //Entra a altura
        do{
            cout << "Qual a altura em CMs do aluno N° " << codigo << ": ";
            cin >> alturacm[i];

            //Valida
            if(alturacm[i] > 250 || alturacm[i] < 20){
                cout << "Valor invalido!\n";
            }

        }while(alturacm[i] > 250 || alturacm[i] < 20);

        aluno[i] = codigo; 

        if(i == 0){
            baixo = alto = 0;
        }

        //Descobre o mais alto e mais baixo
        if(alturacm[i] > alturacm[alto]){
            alto = i;
        }

        if(alturacm[i] < alturacm[baixo]){
            baixo = i;
        }
        i++;
    } while(i < 10);

    //escreve na tela
    cout << "===Aluno mais alto==="
	 << "\nCodigo: " << aluno[alto]
	 << "\nAltura(CMs): " << alturacm[alto] << endl;

    cout << "\n===Aluno mais baixo==="
	 << "\nCodigo: " << aluno[baixo]
	 << "\nAltura(CMs): " << alturacm[baixo] << endl;

    return 0;
}