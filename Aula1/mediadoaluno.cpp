#include <iostream>
using namespace std;

int main()
{
    float p1, p2, p3, p4, soma, media;

    cout << "Informe a nota 1 do aluno: ";
    cin >> p1;
    cout << "Informe a nota 2 do aluno: ";
    cin >> p2;
    cout << "Informe a nota 3 do aluno: ";
    cin >> p3;
    cout << "Informe a nota 4 do aluno: ";
    cin >> p4;

    soma = p1 + p2 + p3 + p4;
    media = soma / 4;

    cout << "\nA media do aluno e: " << media;

    return 0;
}

