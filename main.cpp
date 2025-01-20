#include "Uteis.h"

#include "Biblioteca.h"

#include "LivroFiccao.h"
#include "LivroCientifico.h"
#include "LivroEducativo.h"
#include "LivroRevista.h"
#include "LivroJornal.h"

#include "LeitorEstudante.h"
#include "LeitorProfessor.h"
#include "LeitorSenior.h"
#include "LeitorComum.h"


void exibirMenu() {
    system("cls");
    cout << "___________________________________________________\n";
    cout << "|               Sistema de Biblioteca             |\n";
    cout << "___________________________________________________\n";
    cout << "|                     Livro                       |\n";
    cout << "| 1. Registrar Livro                              |\n";
    cout << "| 2. Exibir Livros                                |\n";
    cout << "| 3. Relatorio dos Livros por Categoria           |\n";
    cout << "| 4. Editar Livro                                 |\n";
    cout << "___________________________________________________\n";
    cout << "|                    Leitor                       |\n";
    cout << "| 5. Registrar Leitor                             |\n";
    cout << "| 6. Exibir Leitores                              |\n";
    cout << "| 7. Exibir Leitores por Categoria                |\n";
    cout << "| 8. Editar Leitor                                |\n";
    cout << "___________________________________________________\n";
    cout << "|                  Emprestimo                     |\n";
    cout << "| 9.  Realizar Emprestimo                         |\n";
    cout << "| 10. Exibir Emprestimos                          |\n";
    cout << "| 11. Exibir Emprestimo por Status                |\n";
    cout << "| 12. Relatorio Emprestimo                        |\n";
    cout << "| 13. Devolucao                                   |\n";
    cout << "| 14. Prorrogar Devolucao                         |\n";
    cout << "___________________________________________________\n";
    cout << "| 0. Sair                                         |\n";
    cout << "___________________________________________________\n";
    cout << "Escolha uma opcao: ";
}

int main() {
    Biblioteca biblioteca;
    int opcao;
    do {
        exibirMenu();
        cin >> opcao;
        cin.ignore();

        switch (opcao) {
            case 1: {
                biblioteca.registrarLivro();
                system("pause");
                break;
            }

            case 2: {
                biblioteca.exibirLivros();
                system("pause");
                break;
            }

            case 3: {
                biblioteca.exibirLivrosPorCategoria();
                system("pause");
                break;
            }

            case 4: {
                biblioteca.editarLivro();
                system("pause");
                break;
            }

            case 5: {
                biblioteca.registrarLeitor();
                system("pause");
                break;
            }

            case 6: {
                biblioteca.exibirLeitor();
                system("pause");
                break;
            }

            case 7: {
                biblioteca.exibirLeitorPorTipo();
                system("pause");
                break;
            }

            case 8: {
                biblioteca.editarLeitor();
                system("pause");
                break;
            }

            case 9: {
                biblioteca.registrarEmprestimo();
                system("pause");
                break;
            }

            case 10: {
                biblioteca.exibirEmprestimo();
                system("pause");
                break;
            }

            case 11: {
                biblioteca.exibirEmprestimoPorStatus();
                system("pause");
                break;
            }

            case 12: {
                biblioteca.relatorioEmprestimo();
                system("pause");
                break;
            }

            case 13: {
                biblioteca.devolucao();
                system("pause");
                break;
            }

            case 0:
                system("cls");
                cout<<"Obrigado por usar o sistema! Ate logo!";
                break;
            default:
                cout << "Opcao inválida. Tente novamente.\n";
                break;
        }

        if (opcao != 0) {
            cout << "Pressione Enter para continuar...";
            cin.get();
        }
    } while (opcao != 0);

    return 0;
}
