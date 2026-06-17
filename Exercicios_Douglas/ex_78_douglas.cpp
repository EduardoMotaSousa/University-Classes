#include <iostream>
using namespace std;

// Uma academia deseja fazer um senso entre seus clientes para descobrir o mais alto, o mais baixo, a mais gordo e o mais magro, 
// para isto você deve fazer um programa que exige a cada um dos clientes da academia seu código, sua altura e seu peso.

// O final da digitação de dados deve ser dado quando o usuário digita 0 (zero) no campo código.

// Ao encerrar o programa também deve ser informado os códigos e valores do clente mais alto, do mais baixo, do mais gordo e do mais magro, 
// além da média das alturas e dos pesos dos clientes.

int main() {
    int gordo{}, magro{}, alto{}, baixo{}, local{}, codigo[100];
    double mediapeso{}, mediaaltura{}, peso[100] = {0.0}, altura[100] = {0.0};
    
    //Entra dados
    while(true){
        if(local >= 100){
            cout << "Limite de clientes atingido!";
            break;
        }

        //Entra codigo
        cout << "Qual seu codigo?(Digite '0' para cancelar): ";
        cin >> codigo[local];

        //Valida o codigo
        if(codigo[local] == 0){
            break;
        }

        if(codigo[local] < 0){
            cout << "Digite um valor valido!";
            continue;
        }

        //Entra altura
        do{
            cout << "Qual sua altura? ";
            cin >> altura[local];
        }while(altura[local] < 0);

        //Operações da altura
        mediaaltura += altura[local];

        if(altura[local] > altura[alto]){
            alto = local;
        }

        if(altura[local] < altura[baixo]){
            baixo = local;
        }

        //Entra peso
        do{
            cout << "Qual seu peso? ";
            cin >> peso[local];
        }while(peso[local] < 0);

        //Operações da peso
        mediapeso += peso[local];

        if(peso[local] > peso[gordo]){
            gordo = local;
        }

        if(peso[local] < peso[magro]){
            magro = local;
        }

        local++;
    }

    mediapeso /= local;
    mediaaltura/= local;

    //Escreve dados
    cout << "\nMais alto: " << codigo[alto]
	 << "\nAltura: " << altura[alto]
	 << "\nPeso: " << peso[alto];

    cout << "\nMais baixo: " << codigo[baixo]
	 << "\nAltura: " << altura[baixo]
	 << "\nPeso: " << peso[baixo];

    cout << "\nMais magro: " << codigo[magro]
	 << "\nAltura: " << altura[magro]
	 << "\nPeso: " << peso[magro];

    cout << "\nMais gordo: " << codigo[gordo]
	 << "\nAltura: " << altura[gordo]
	 << "\nPeso: " << peso[gordo];

    cout << "\nMedia altura: " << mediaaltura
	 << "\nMedia peso: " << mediapeso;
  
    return 0;
}