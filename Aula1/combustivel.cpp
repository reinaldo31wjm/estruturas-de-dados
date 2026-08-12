#include <iostream>
#include <locale.h>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Portuguese");
    float valor, km, consumo, gasto, total;

    cout << "Informe o valor do litro do combustível: ";
    cin >> valor;
    cout << "Informe a distância percorrida (km): ";
    cin >> km;
    cout << "Informe o consumo do veículo (km/L): ";
    cin >> consumo;

    gasto = km / consumo;
    total = gasto * valor;

    cout << "\nO total de litros consumidos foi: " << gasto;
    cout << "\nO valor total gasto é: R$ " << total;

    return 0;
}

