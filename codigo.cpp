#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct Departamento {
    string codigo;
    string nome;
    string palavrasChave[5];
};

int main() {
    vector<Departamento> departamentos;
    
    ifstream arquivo("dados.txt");

    if (arquivo.is_open()) {
        Departamento depto;
        while (arquivo >> depto.codigo >> depto.nome 
                       >> depto.palavrasChave[0] >> depto.palavrasChave[1] 
                       >> depto.palavrasChave[2] >> depto.palavrasChave[3] 
                       >> depto.palavrasChave[4]) {
            departamentos.push_back(depto);
        }
        arquivo.close();
    } else {
        cout << "Erro: Nao foi possivel abrir o arquivo 'dados.txt'." << endl;
        return 1;
    }

    int opcao;
    do {
        cout << "\n--- Menu de Pesquisa ---\n";
        cout << "1. Pesquisar por palavra-chave\n";
        cout << "2. Pesquisar por departamento\n";
        cout << "0. Sair\n";
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        if (opcao == 1) {
            string busca;
            cout << "Digite a palavra-chave: ";
            cin >> busca;
            bool encontrado = false;

            for (const auto& d : departamentos) {
                for (int i = 0; i < 5; i++) {
                    if (d.palavrasChave[i] == busca) {
                        cout << "-> A palavra-chave '" << busca << "' representa o departamento: " << d.nome << endl;
                        encontrado = true;
                        break; 
                    }
                }
                if (encontrado) break; 
            }
            if (!encontrado) {
                cout << "-> Palavra-chave nao encontrada." << endl;
            }

        } else if (opcao == 2) {
            string busca;
            cout << "Digite o nome do departamento: ";
            cin >> busca;
            bool encontrado = false;

            for (const auto& d : departamentos) {
                if (d.nome == busca) {
                    cout << "-> Codigo identificador: " << d.codigo << endl;
                    cout << "-> Palavras-chave: ";
                    for (int i = 0; i < 5; i++) {
                        cout << d.palavrasChave[i] << " ";
                    }
                    cout << endl;
                    encontrado = true;
                    break;
                }
            }
            if (!encontrado) {
                cout << "-> Departamento nao encontrado." << endl;
            }
        } else if (opcao != 0) {
            cout << "-> Opcao invalida." << endl;
        }

    } while (opcao != 0);

    cout << "Programa encerrado." << endl;
    return 0;
}