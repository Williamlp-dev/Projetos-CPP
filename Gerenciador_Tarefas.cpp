#include <iostream>
#include <string>
#include <vector>
#include <windows.h> // Para SetConsoleOutputCP

using namespace std;

// Estrutura que representa uma tarefa
struct Tarefa
{
    string titulo;
    string descricao;
    bool concluida;

    Tarefa(string t, string desc) : titulo(t), descricao(desc), concluida(false) {}
};

// Função para adicionar uma nova tarefa
void adicionarTarefa(vector<Tarefa> &tarefas)
{
    string titulo, descricao;
    cout << "Título da tarefa: ";
    getline(cin >> ws, titulo); // ws ignora espaços em branco
    cout << "Descrição da tarefa: ";
    getline(cin, descricao);
    tarefas.push_back(Tarefa(titulo, descricao));
    cout << "Tarefa adicionada: " << titulo << endl;
}

// Função para remover uma tarefa
void removerTarefa(vector<Tarefa> &tarefas)
{
    string titulo;
    cout << "Título da tarefa a remover: ";
    getline(cin >> ws, titulo);

    for (size_t i = 0; i < tarefas.size(); i++)
    {
        if (tarefas[i].titulo == titulo)
        {
            tarefas.erase(tarefas.begin() + i);
            cout << "Tarefa removida: " << titulo << endl;
            return;
        }
    }
    cout << "Tarefa não encontrada: " << titulo << endl;
}

// Função para marcar uma tarefa como concluída
void concluirTarefa(vector<Tarefa> &tarefas)
{
    string titulo;
    cout << "Título da tarefa a concluir: ";
    getline(cin >> ws, titulo);

    for (auto &tarefa : tarefas)
    {
        if (tarefa.titulo == titulo)
        {
            tarefa.concluida = true;
            cout << "Tarefa concluída: " << titulo << endl;
            return;
        }
    }
    cout << "Tarefa não encontrada: " << titulo << endl;
}

// Função para exibir todas as tarefas
void exibirTarefas(const vector<Tarefa> &tarefas)
{
    if (tarefas.empty())
    {
        cout << "Nenhuma tarefa disponível." << endl;
        return;
    }
    cout << "Tarefas:" << endl;
    for (const auto &tarefa : tarefas)
    {
        cout << (tarefa.concluida ? "[X] " : "[ ] ") << tarefa.titulo << ": " << tarefa.descricao << endl;
    }
}

int main()
{
    // Configura a saída do console para UTF-8
    SetConsoleOutputCP(CP_UTF8);

    vector<Tarefa> tarefas; // Vetor para armazenar as tarefas
    int escolha;

    while (true)
    {
        cout << "\nGerenciador de Tarefas:\n";
        cout << "1. Adicionar tarefa\n";
        cout << "2. Remover tarefa\n";
        cout << "3. Marcar tarefa como concluída\n";
        cout << "4. Exibir tarefas\n";
        cout << "5. Sair\n";
        cout << "Escolha uma opção: ";
        cin >> escolha;

        switch (escolha)
        {
        case 1:
            adicionarTarefa(tarefas);
            break;
        case 2:
            removerTarefa(tarefas);
            break;
        case 3:
            concluirTarefa(tarefas);
            break;
        case 4:
            exibirTarefas(tarefas);
            break;
        case 5:
            return 0;
        default:
            cout << "Opção inválida. Tente novamente." << endl;
        }
    }
    return 0;
}
