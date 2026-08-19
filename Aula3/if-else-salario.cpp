#include <iostream>
#include <locale.h>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Portuguese");
    float sal, liq;

    cout << "Informe o salario anual: ";
    cin >> sal;

    if (sal > 20000 && sal <= 50000){
        liq = sal - (sal * 0.10);
        cout << "O colaborador recebe: " << liq;
    } else if (sal > 50000){
        liq = sal - (sal * 0.20);
        cout << "O colaborador recebe: " << liq;
    } else {
        cout << "O colaborador esta isento";
    }

    return 0;
}
