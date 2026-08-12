#include <iostream>
#include <locale.h>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int idade;

    cout << "Digite a sua idade: ";
    cin >> idade;

    if (idade < 18) {
    	cout << "Voce e menor de idade." << endl;
    }else {
        cout << "Voce e maior de idade." << endl;
    }

    return 0;
}
