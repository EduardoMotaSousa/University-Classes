#include <iostream>
using namespace std;

//O Departamento Estadual de Meteorologia contratou para desenvolver um programa que leia como um conjunto indeterminado de temperaturas, 
//e informe ao final a menor e a maior temperatura informada, bem como a média das temperaturas.

int main() {
    double temp, tmax, tmin, tmedia{};
    int dias{};

    while (true){

    cout << "Qual a temperatura de hoje °C?(Digite '-500' para sair): ";
    cin >> temp;

    //Finaliza
    if(temp == -500){
	    break;
    }    

    //Valida a temperatura
    if(temp < -90 || temp > 60){
	    cout << "Digite uma temperatura valida!\n";
	    continue;
    }

    //Preenche Max e Min
    if(dias == 0){
	    tmax = temp;
	    tmin = temp;
    }

    //Se passou, faz as operações
    dias++;
    tmedia += temp;

    if(temp > tmax){
	    tmax = temp;
    }

    if(temp < tmin){
	    tmin = temp;
    }

    }

    //exibe na tela
    if(dias > 0){
    	cout << "|Departamento Estadual de Meteorologia|"
		<< "\nTemperatura Média: " << tmedia / dias
		<< "\nTemperatura minima: " << tmin
		<< "\nTemperatura maxima: " << tmax;
    }

    else{
    	cout << "Nenhuma temperatura digitada";
    }

    return 0;
}