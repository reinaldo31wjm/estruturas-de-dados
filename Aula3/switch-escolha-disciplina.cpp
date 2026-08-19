#include <iostream>
#include <locale.h>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int materia;

    cout << "Digite o número da sua disciplina (1-9): ";
    cin >> materia;

    switch (materia)
    {
        case 1:
            cout << "Visão Computacional" << endl;
            break;
        case 2:
            cout << "Redes Neurais" << endl;
            break;
        case 3:
            cout << "Engenharia de Software" << endl;
            break;
        case 4:
            cout << "Front End" << endl;
            break;
        case 5:
            cout << "Back End" << endl;
            break;
        case 6:
            cout << "Banco de Dados" << endl;
            break;
        case 7:
            cout << "Qualidade de Software" << endl;
            break;
        case 8:
            cout << "Inteligência Artificial" << endl;
            break;
        case 9:
            cout << "Realidade Aumentada" << endl;
            break;
        default:
            cout << "Opção inválida!" << endl;
    }

    return 0;
}
