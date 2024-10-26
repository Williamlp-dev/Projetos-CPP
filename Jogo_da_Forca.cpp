#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>
#include <string>
#include <set>

using namespace std;

void mudarCor(int cor)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), cor);
}

void jogar()
{
    string palavra, lacuna, dica;
    char letra;
    int vida = 7, cont, venceu = 0, pontos = 0;
    set<char> letrasTentadas;

    cout << "Digite a palavra secreta: ";
    getline(cin, palavra);
    cout << "Digite a dica: ";
    getline(cin, dica);

    for (size_t i = 0; i < palavra.length(); i++)
    {
        if (palavra[i] == ' ')
            lacuna.push_back(' ');
        else
            lacuna.push_back('_');
    }

    while (vida > 0 && venceu == 0)
    {
        system("cls");

        cout << "Dica: " << dica << endl;
        cout << "Quantidade de letras: " << palavra.length() << endl;
        cout << "Vidas: " << vida << "\n\n";
        cout << lacuna << endl
             << endl;

        cout << "Letras tentadas: ";
        for (char l : letrasTentadas)
        {
            cout << l << " ";
        }
        cout << endl;

        cout << "Digite uma letra: ";
        letra = getch();
        cout << letra << endl;

        if (!isalpha(letra) || letrasTentadas.count(letra))
        {
            cout << "Entrada inválida ou letra já tentada!" << endl;
            Sleep(500);
            continue;
        }

        letrasTentadas.insert(letra);
        cont = 0;

        for (size_t i = 0; i < palavra.length(); i++)
        {
            if (palavra[i] == letra)
            {
                lacuna[i] = letra;
                cont++;
                pontos += 2;
            }
        }

        cout << "-------------------------------------" << endl;
        if (cont == 0)
        {
            mudarCor(12);
            cout << "Você errou uma letra!" << endl;
            mudarCor(7);
            vida--;
        }
        else
        {
            mudarCor(10);
            cout << "Você acertou uma letra!" << endl;
            mudarCor(7);
        }
        cout << "-------------------------------------" << endl;
        Sleep(1000);

        if (palavra == lacuna)
            venceu = 1;
    }

    cout << endl;
    if (venceu == 1)
    {
        cout << "Parabéns, Você venceu! A palavra era: " << palavra << endl;
        cout << "Fez " << pontos << " pontos.\n\n";
    }
    else
    {
        cout << "Você perdeu. A palavra era: " << palavra << endl;
        cout << "Fez " << pontos << " pontos.\n\n";
    }
}

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    char opcao;
    do
    {
        jogar();
        cout << "Deseja jogar novamente? (s/n): ";
        cin >> opcao;
        cin.ignore();
    } while (opcao == 's' || opcao == 'S');

    cout << "Obrigado por jogar! Pressione qualquer tecla para sair...";
    getch();
    return 0;
}
