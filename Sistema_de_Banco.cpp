#include <iostream>
#include <string>
#include <vector>
#include <iomanip> 
#include <windows.h> 

using namespace std;


class Conta
{
private:
    string titular;
    int numero;
    double saldo;

public:
    Conta(string t, int n) : titular(t), numero(n), saldo(0.0) {}

    string getTitular() const { return titular; }
    int getNumero() const { return numero; }
    double getSaldo() const { return saldo; }

    void depositar(double valor)
    {
        if (valor > 0)
        {
            saldo += valor;
            cout << "Depósito de R$ " << valor << " realizado com sucesso!" << endl;
        }
        else
        {
            cout << "Valor inválido para depósito!" << endl;
        }
    }

    void sacar(double valor)
    {
        if (valor > 0 && valor <= saldo)
        {
            saldo -= valor;
            cout << "Saque de R$ " << valor << " realizado com sucesso!" << endl;
        }
        else
        {
            cout << "Saque inválido! Verifique o valor e seu saldo." << endl;
        }
    }

    void transferir(double valor, Conta &destino)
    {
        if (valor > 0 && valor <= saldo)
        {
            sacar(valor);
            destino.depositar(valor);
            cout << "Transferência de R$ " << valor << " para a conta " << destino.getNumero() << " realizada com sucesso!" << endl;
        }
        else
        {
            cout << "Transferência inválida! Verifique o valor e seu saldo." << endl;
        }
    }
};

class Banco
{
private:
    vector<Conta> contas;

public:
    void criarConta(string titular, int numero)
    {
        contas.emplace_back(titular, numero);
        cout << "Conta criada com sucesso para " << titular << "!" << endl;
    }

    Conta *encontrarConta(int numero)
    {
        for (auto &conta : contas)
        {
            if (conta.getNumero() == numero)
            {
                return &conta;
            }
        }
        return nullptr;
    }

    void removerConta(int numero)
    {
        for (size_t i = 0; i < contas.size(); i++)
        {
            if (contas[i].getNumero() == numero)
            {
                contas.erase(contas.begin() + i);
                cout << "Conta número " << numero << " removida com sucesso!" << endl;
                return;
            }
        }
        cout << "Conta não encontrada: " << numero << endl;
    }

    void listarContas() const
    {
        cout << "Contas no Banco:" << endl;
        for (const auto &conta : contas)
        {
            cout << "Titular: " << conta.getTitular() << ", Número: " << conta.getNumero() << ", Saldo: R$ " << fixed << setprecision(2) << conta.getSaldo() << endl;
        }
    }
};

int main()
{
    SetConsoleOutputCP(CP_UTF8);

    Banco banco;
    int opcao;

    while (true)
    {
        cout << "\nSimulador de Banco\n";
        cout << "1. Criar Conta\n";
        cout << "2. Depositar\n";
        cout << "3. Sacar\n";
        cout << "4. Transferir\n";
        cout << "5. Listar Contas\n";
        cout << "6. Remover Conta\n";
        cout << "7. Sair\n";
        cout << "Escolha uma opção: ";
        cin >> opcao;
        cin.ignore();

        switch (opcao)
        {
        case 1:
        {
            string titular;
            int numero;
            cout << "Nome do Titular: ";
            getline(cin, titular);
            cout << "Número da Conta: ";
            cin >> numero;
            banco.criarConta(titular, numero);
            break;
        }
        case 2:
        {
            int numero;
            double valor;
            cout << "Número da Conta: ";
            cin >> numero;
            Conta *conta = banco.encontrarConta(numero);
            if (conta)
            {
                cout << "Valor a Depositar: R$ ";
                cin >> valor;
                conta->depositar(valor);
            }
            else
            {
                cout << "Conta não encontrada!" << endl;
            }
            break;
        }
        case 3:
        {
            int numero;
            double valor;
            cout << "Número da Conta: ";
            cin >> numero;
            Conta *conta = banco.encontrarConta(numero);
            if (conta)
            {
                cout << "Valor a Sacar: R$ ";
                cin >> valor;
                conta->sacar(valor);
            }
            else
            {
                cout << "Conta não encontrada!" << endl;
            }
            break;
        }
        case 4:
        {
            int numeroOrigem, numeroDestino;
            double valor;
            cout << "Número da Conta Origem: ";
            cin >> numeroOrigem;
            cout << "Número da Conta Destino: ";
            cin >> numeroDestino;
            Conta *contaOrigem = banco.encontrarConta(numeroOrigem);
            Conta *contaDestino = banco.encontrarConta(numeroDestino);
            if (contaOrigem && contaDestino)
            {
                cout << "Valor a Transferir: R$ ";
                cin >> valor;
                contaOrigem->transferir(valor, *contaDestino);
            }
            else
            {
                cout << "Uma ou ambas as contas não foram encontradas!" << endl;
            }
            break;
        }
        case 5:
            banco.listarContas();
            break;
        case 6:
        {
            int numero;
            cout << "Número da Conta a remover: ";
            cin >> numero;
            banco.removerConta(numero);
            break;
        }
        case 7:
            return 0;
        default:
            cout << "Opção inválida. Tente novamente." << endl;
        }
    }
    return 0;
}
