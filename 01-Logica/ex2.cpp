// ============================================================
//  EXERCÍCIO 2 — Calculadora de média escolar
//  Semana 03 | Tipos de dado: int e double
// ============================================================
//
//  QUAL A DIFERENÇA ENTRE int E double?
//
//    int    -> guarda números INTEIROS (sem vírgula)
//              exemplos: 1, 5, 100, -3
//              uso típico: contagens, quantidades, notas inteiras
//
//    double -> guarda números REAIS (com vírgula)
//              exemplos: 7.5, 9.0, 3.14, -0.5
//              uso típico: médias, preços, medidas
//
//  OPERADORES ARITMÉTICOS:
//    +   soma          ex: 7 + 3  = 10
//    -   subtração     ex: 7 - 3  = 4
//    *   multiplicação ex: 7 * 3  = 21
//    /   divisão       ex: 7.0 / 2 = 3.5
//
//  ATENÇÃO: se dividir dois int, o resultado é truncado!
//    7 / 2 = 3   (errado para média)
//    7.0 / 2 = 3.5  (correto — use double)
//
// ------------------------------------------------------------
//  ENUNCIADO:
//  Crie um programa que leia as 3 notas de um aluno
//  (cada nota pode ter decimal, ex: 7.5) e mostre:
//    1) A média das três notas.
//    2) Uma mensagem: "Aprovado" se a média >= 6.0
//                 ou "Reprovado" se a média < 6.0.
//
// ------------------------------------------------------------
//  EXEMPLO DE SAÍDA ESPERADA:
//
//  === Calculadora de Média ===
//  Digite a nota 1: 8.0
//  Digite a nota 2: 6.5
//  Digite a nota 3: 7.0
//  Média: 7.17
//  Resultado: Aprovado
//
// ------------------------------------------------------------
//  EXEMPLO DE SAÍDA ESPERADA (outro caso):
//
//  === Calculadora de Média ===
//  Digite a nota 1: 4.0
//  Digite a nota 2: 5.5
//  Digite a nota 3: 3.0
//  Média: 4.17
//  Resultado: Reprovado
//
// ============================================================
//  DESENVOLVA NO CÓDIGO ABAIXO:
// ============================================================

#include <iostream>
#include <iomanip>   // necessário para usar setprecision
using namespace std;

int main() {

    float n1, n2, n3;

    float nota_media;

    cout << "Nota 1:";
    cin >> n1;

    cout << "Nota 2:";
    cin >> n2;

    cout << "Nota 3:";
    cin >> n3;

    nota_media = (n1+n2+n3)/3;

    cout << "Nota media:" << nota_media << endl;

    if(nota_media >= 6){
        cout << "Resultado: Aprovado" << endl;
    }

    else{
        cout << "Resultado: Reprovado" << endl;
    }
    return 0;
}