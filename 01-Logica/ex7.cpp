#include <iomanip>
#include <iostream>
using namespace std;


int main(){
    float peso, altura, imc;


    cout <<  "Peso em kilos e altura em metros: ";
    cin >> peso >> altura;


    imc = peso/(altura*altura);

    cout << setprecision(4);
    cout << "IMC: " << imc << endl;


    if(imc<18.5){
        cout << "Abaixo do peso\n";
    }

    else if(imc<25){
        cout << "Peso normal\n";
    }

    else if(imc<30){
        cout << "Sobrepeso\n";
    }
    
    else if(imc<35){
        cout << "Obesidade Grau I\n";
    }

    else if(imc<40){
        cout << "Obesidade Grau II\n";
    }
    else{
        cout << "Obesidade Grau III (Mórbida)\n";
    }

    return 0;
}
