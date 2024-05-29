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
    printf("\n | [1] Adicionar                                                  |");
    printf("\n | [2] Remover                                                    |");
    printf("\n | [3] Listar                                                     |");
    printf("\n |                                                                |");
    printf("\n |----------------------------------------------------------------|");
    printf("\n | [0] Sair                                                       |");
    printf("\n | [9] Fechar Programa                                            |");
    printf("\n #----------------------------------------------------------------#");

    char op;
    printf("\n Selecione sua opcao: ");
    op = getchar();
    return op;
}

int main()
{

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
            case '1': printf("ADICIONAR");system("pause"); break;
            case '2': printf("LISTAR");system("pause"); break;
            case '3': printf("REMOVER");system("pause"); break;
            default:
                printf("Opcao nao implementada\n");
                system("pause");
                setbuf (stdin, 0);
                break;
        }

    }while (OP != '0');
    DestruirBiblioteca(Bib);
    return EXIT_SUCCESS; // ou EXIT_FAILURE
}
