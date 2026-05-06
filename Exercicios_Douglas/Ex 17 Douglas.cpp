#include <iomanip>
#include <iostream>
#include <cmath>
using namespace std;

int main(){
    //Pede área a ser pintada
    double m2{};
    int l, g;
     
    cout << "Metros quadrados: ";
    cin >> m2;

    m2 *= 1.1; 

    //Apenas latas
    l = ceil(m2 / 108);

    cout << "Apenas latas: " << l << " R$: " << l * 80 << ",00 \n";

    //Apenas galões
    g = ceil(m2 / 21.6);

    cout << "Apenas galões: " << g << " R$: " << g * 25 << ",00 \n";

    //Mistura
    l = floor(m2 / 97.2);
    g = ceil((m2 - (97.2 * l)) / 19.44);

    cout << "\nMistura de latas e galões:\nlatas: " << l << "\nGalçoes: " << g << endl;
    cout << "Valor total: R$" << (l * 80) + (g * 25) << ",00";

    return 0;
}