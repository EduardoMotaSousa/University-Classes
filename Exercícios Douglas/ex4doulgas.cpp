#include <iostream>
#include <iomanip>   
using namespace std;

int main(){
    float n1, n2, n3, n4;

    cout << "Informe as 4 notas dos alunos em sequência: :";
    cin >> n1 >> n2 >> n3 >> n4;


    cout << "Nota média:" << (n1+n2+n3+n4)/4;

    return 0;
}