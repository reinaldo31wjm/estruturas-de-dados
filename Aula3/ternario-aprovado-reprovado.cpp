#include <iostream>
#include <string>
using namespace std;

int main()
{
    int nota;

    cout << "Digite a nota do aluno: ";
    cin >> nota;

    string situacao = (nota >= 6) ? "aprovado" : "reprovado";
    cout << "O aluno foi: " << situacao << endl;

    return 0;
}
