#include <stdio.h>
#include <stdlib.h>

#include "Lista.h"
#include "Hashing.h"
#include "Biblioteca.h"

#include "Pessoa.h"

extern int LerInteiro(char *txt);
//-----------------------------------------

int Menu()
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

    int op;

    printf("\n Selecione sua opcao: ");
    fflush(stdin);
    scanf("%d",&op);

    if(getchar()!='\n' ){
        while ((getchar()) != '\n'); //Limpa o buffer
        return -1;
    };

    return op;
}

int main()
{
    //inicia bliblioteca

    LISTA *ListaPessoa = CriarLista();
    LISTA *ListaDistrito = CriarLista();
    LISTA *ListaConcelho = CriarLista();
    LISTA *ListaFreguesia = CriarLista();

    LISTA *ListaLivro = CriarLista();

    //Exemplo_Hashing();
    BIBLIOTECA *Bib;
    Bib = CriarBiblioteca("Biblioteca-ESTGV", "log.txt");
    int OP, RPessoa;
    do
    {
        setbuf (stdin, 0);
        OP = Menu();

        switch(OP)
        {
            case 1:
                RPessoa=PainelPessoa(ListaPessoa);
                if(RPessoa==9){
                    OP=0;
                };
                break;
            case 2: system("pause"); break;
            case 3: system("pause"); break;
            case 4: LoadFicheiroBiblioteca(Bib); break;
            case 5: ShowBiblioteca(Bib); break;
            case 0: break;
            default:
                if(OP == -1){
                    printf("Tente inserir um numero =P \n");
                }
                else{
                    printf("Opcao %d e invalida\n",OP);
                }
                fflush(stdin);
                system("pause");
                fflush(stdin);

                break;
        }

    }while (OP != 0);

    DestruirLista(ListaPessoa);

    DestruirLista(ListaDistrito);
    DestruirLista(ListaConcelho);
    DestruirLista(ListaFreguesia);

    DestruirLista(ListaLivro);

    DestruirBiblioteca(Bib);

    limparTerminal();
    printf("Obrigado por utilizar o BSoft, volte logo\n");
    return EXIT_SUCCESS; // ou EXIT_FAILURE
}
