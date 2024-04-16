#include <stdio.h>
#include <stdlib.h>

#include "Lista.h"
#include "Hashing.h"
#include "Biblioteca.h"

extern int LerInteiro(char *txt);
//-----------------------------------------
void Exemplo_Hashing()
{
    HASHING *Has = CriarHashing();
    PESSOA *X = CriarPessoa(1234, "Jose", "CAT-A");
    AddHashing(Has, X);
    X = CriarPessoa(567, "Pedro", "CAT-A");
    AddHashing(Has, X);
    X = CriarPessoa(456, "Luis", "CAT-A");
    AddHashing(Has, X);
    X = CriarPessoa(56, "Miguel", "CAT-B");
    AddHashing(Has, X);
    X = CriarPessoa(5690, "James Bond", "CAT-Z");
    AddHashing(Has, X);
    ShowHashing(Has);

    DestruirHashing(Has);
}

char Menu()
{
    limparTerminal();


    printf("\n #----------------------------------------------------------------#");
    printf("\n |                      Bem Vindo ao BSoft!                       |");
    printf("\n |------------------------ Menu  Inicial -------------------------|");
    printf("\n |                                                                |");
    printf("\n | [1] Menu de Requisitantes                                      |");// Requisitantes
    printf("\n | [2] Menu de Livros                                             |");// Livros
    printf("\n | [3] Menu de Emprestimos                                        |");// Requisições
    printf("\n | [4] Listar Biblioteca                                          |");
    printf("\n | [5] Load Biblioteca                                            |");
    printf("\n |                                                                |");
    printf("\n |----------------------------------------------------------------|");
    printf("\n | [0] Sair                                                       |");
    printf("\n #----------------------------------------------------------------#");

    char op;
    printf("\n Selecione sua opcao: ");
    op = getchar();
    return op;
}


int main()
3
    printf("Projecto-Biblioteca-Versao-Base!\n");
    //Exemplo_Hashing();
    BIBLIOTECA *Bib;
    Bib = CriarBiblioteca("Biblioteca-ESTGV", "log.txt");
    char OP;
    do
    {
        OP = Menu();
        switch(OP)
        {
            case '1': system("pause"); break;
            case '2': system("pause"); break;
            case '3': system("pause"); break;
            case '4': LoadFicheiroBiblioteca(Bib); break;
            case '5': ShowBiblioteca(Bib); break;
            default:
                printf("Opcao nao implementada\n"); break;
        }

    }while (OP != '0');
    DestruirBiblioteca(Bib);
    return EXIT_SUCCESS; // ou EXIT_FAILURE
}
