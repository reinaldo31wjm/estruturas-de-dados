#include <iostream>
#include <locale.h>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Portuguese");
    float a, b, c;

    cout << "Digite o primeiro lado: ";
    cin >> a;
    cout << "Digite o segundo lado: ";
    cin >> b;
    cout << "Digite o terceiro lado: ";
    cin >> c;

    if (a == b && b == c)
        cout << "O triângulo é equilátero";
    else if (a == b || a == c || b == c)
        cout << "O triângulo é isósceles";
    else
        cout << "O triângulo é escaleno";

    return 0;
}
