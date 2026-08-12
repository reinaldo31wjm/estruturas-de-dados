#include <iostream>
#include <locale.h>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Portuguese");
    float horasTrab, valorHora, salBruto, inss, salLiquido;

    cout << "Informe quantas horas trabalhadas: ";
    cin >> horasTrab;
    cout << "Informe o valor da hora: ";
    cin >> valorHora;

    salBruto = horasTrab * valorHora;
    inss = salBruto * 0.12;
    salLiquido = salBruto - inss;

    cout << "\nO valor do salário bruto é: R$ " << salBruto;
    cout << "\nO valor do INSS é: R$ " << inss;
    cout << "\nO valor do salário líquido é: R$ " << salLiquido << endl;

    return 0;
}

