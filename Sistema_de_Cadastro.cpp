#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <windows.h>

using namespace std;

class Cliente
{
private:
    string nome;
    string email;
    string telefone;

public:
    Cliente(string n, string e, string t) : nome(n), email(e), telefone(t) {}

    string getNome() const { return nome; }
    string getEmail() const { return email; }
    string getTelefone() const { return telefone; }

    void exibir() const
    {
        cout << "Nome: " << nome << ", Email: " << email << ", Telefone: " << telefone << endl;
    }

    string toFileFormat() const
    {
        return nome + "," + email + "," + telefone;
    }

    static Cliente fromFileFormat(const string &line)
    {
        size_t pos1 = line.find(',');
        size_t pos2 = line.find(',', pos1 + 1);
        string nome = line.substr(0, pos1);
        string email = line.substr(pos1 + 1, pos2 - pos1 - 1);
        string telefone = line.substr(pos2 + 1);
        return Cliente(nome, email, telefone);
    }
};

class GerenciadorDeClientes
{
private:
    vector<Cliente> clientes;
    const string arquivo = "clientes.txt";

    void carregarClientes()
    {
        ifstream inputFile(arquivo);
        string linha;
        while (getline(inputFile, linha))
        {
            clientes.push_back(Cliente::fromFileFormat(linha));
        }
        inputFile.close();
    }

    void salvarClientes()
    {
        ofstream outputFile(arquivo);
        for (const auto &cliente : clientes)
        {
            outputFile << cliente.toFileFormat() << endl;
        }
        outputFile.close();
    }

public:
    GerenciadorDeClientes()
    {
        carregarClientes();
    }

    void cadastrarCliente(const string &nome, const string &email, const string &telefone)
    {
        Cliente novoCliente(nome, email, telefone);
        clientes.push_back(novoCliente);
        salvarClientes();
        cout << "Cliente cadastrado com sucesso!" << endl;
    }

    void removerCliente(const string &nome)
    {
        for (size_t i = 0; i < clientes.size(); i++)
        {
            if (clientes[i].getNome() == nome)
            {
                clientes.erase(clientes.begin() + i);
                salvarClientes();
                cout << "Cliente removido com sucesso!" << endl;
                return;
            }
        }
        cout << "Cliente não encontrado: " << nome << endl;
    }

    void listarClientes() const
    {
        cout << "Lista de Clientes:" << endl;
        for (const auto &cliente : clientes)
        {
            cliente.exibir();
        }
    }
};

int main()
{

    SetConsoleOutputCP(CP_UTF8);

    GerenciadorDeClientes gerenciador;
    int opcao;
    string nome, email, telefone;

    while (true)
    {
        cout << "\nSistema de Cadastro de Clientes\n";
        cout << "1. Cadastrar Cliente\n";
        cout << "2. Listar Clientes\n";
        cout << "3. Remover Cliente\n";
        cout << "4. Sair\n";
        cout << "Escolha uma opção: ";
        cin >> opcao;
        cin.ignore();

        switch (opcao)
        {
        case 1:
            cout << "Nome do Cliente: ";
            getline(cin, nome);
            cout << "Email do Cliente: ";
            getline(cin, email);
            cout << "Telefone do Cliente: ";
            getline(cin, telefone);
            gerenciador.cadastrarCliente(nome, email, telefone);
            break;
        case 2:
            gerenciador.listarClientes();
            break;
        case 3:
            cout << "Nome do Cliente a remover: ";
            getline(cin, nome);
            gerenciador.removerCliente(nome);
            break;
        case 4:
            return 0;
        default:
            cout << "Opção inválida. Tente novamente." << endl;
        }
    }
    return 0;
}
