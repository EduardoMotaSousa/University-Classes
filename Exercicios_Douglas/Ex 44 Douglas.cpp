#include <iostream>
#include <iomanip>

using namespace std;

// Uma fruteira está vendendo frutas com a seguinte tabela de preços:
// Até 5 Kg              | Acima de 5 Kg
// Morango: R$ 2,50/Kg   | R$ 2,20/Kg
// Maçã:    R$ 1,80/Kg   | R$ 1,50/Kg
//
// Se o cliente comprar mais de 8 Kg em frutas
// OU o valor total ultrapassar R$ 25,00,
// receberá um desconto de 10% sobre o total.

int main() {
    double kgMaca{}, kgMorango{}, kilosTotal{}, valor{};

    // Exibe tabela
    cout << "_______________________\n"
         << "    TABELA DE PREÇOS   \n"
         << "   ATÉ 5KG | ACIMA 5KG \n"
         << "        MORANGO        \n"
         << "   R$2,50  | R$2,20    \n"
         << "         MAÇÃ          \n"
         << "   R$1,80  | R$1,50    \n"
         << "_______________________\n";

    // Entrada morango
    cout << "\nQuantos Kg de morango você vai levar? ";
    cin >> kgMorango;

    if (kgMorango < 0.0) {
        cout << "Valor inválido! Digite apenas valores positivos.\n";
        return 0;
    }

    if (kgMorango <= 5.0) {
        valor = kgMorango * 2.5;
    } else {
        valor = kgMorango * 2.2;
    }

    // Entrada maçã
    cout << "Quantos Kg de maçã você vai levar? ";
    cin >> kgMaca;

    if (kgMaca < 0.0) {
        cout << "Valor inválido! Digite apenas valores positivos.\n";
        return 0;
    }

    if (kgMaca <= 5.0) {
        valor += kgMaca * 1.8;
    } else {
        valor += kgMaca * 1.5;
    }

    // Soma dos pesos
    kilosTotal = kgMaca + kgMorango;

    // Aplicação do desconto
    if (valor > 25 || kilosTotal > 8) {
        valor *= 0.9;
    }

    // Saída formatada
    cout << fixed << setprecision(2);

    cout << "\n_______________________\n"
         << "Valor total: R$ " << valor << "\n"
         << "Peso total: " << kilosTotal << " Kg\n"
         << "Morango: " << kgMorango << " Kg\n"
         << "Maçã: " << kgMaca << " Kg\n"
         << "_______________________\n";

    return 0;
}
