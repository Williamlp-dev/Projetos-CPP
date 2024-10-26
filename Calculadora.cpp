#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
    setlocale(LC_ALL, "portuguese");

    int escolha_Usuario;
    float numero_1, numero_2;
    char continuar;

    do
    {
        cout << "Digite a opção desejada:" << endl;
        cout << "1. Somar" << endl;
        cout << "2. Subtrair" << endl;
        cout << "3. Multiplicar" << endl;
        cout << "4. Dividir" << endl;
        cin >> escolha_Usuario;

        if (escolha_Usuario < 1 || escolha_Usuario > 4)
        {
            cout << "Apenas opções válidas são permitidas!" << endl;
        }
        else
        {
            cout << "Digite o primeiro número: ";
            cin >> numero_1;

            cout << "Digite o segundo número: ";
            cin >> numero_2;

            switch (escolha_Usuario)
            {
            case 1:
                cout << "Resultado: " << numero_1 + numero_2 << endl;
                break;
            case 2:
                cout << "Resultado: " << numero_1 - numero_2 << endl;
                break;
            case 3:
                cout << "Resultado: " << numero_1 * numero_2 << endl;
                break;
            case 4:
                if (numero_2 == 0)
                {
                    cout << "Não tem divisor!" << endl;
                }
                else
                {
                    cout << "Resultado: " << numero_1 / numero_2 << endl;
                }
                break;
            }
        }

        cout << "Você deseja fazer outro cálculo? (s/n): ";
        cin >> continuar;

    } while (continuar == 's' || continuar == 'S');

    cout << "Obrigado por usar a calculadora!" << endl;
    system("pause");

    return 0;
}
