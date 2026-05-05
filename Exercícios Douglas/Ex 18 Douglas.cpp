#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main(){
    double mb, link;

    cout <<  "Tamanho do arquivo em MB: ";
    cin >> mb;

    
    cout <<  "Velocidade do link em MBs: ";
    cin >> link;

    cout << "Demorará: " << ceil(mb / link) << " Segundo \n";

    return 0;
}