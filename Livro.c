#include "Livro.h"

int MenuLivro()
{
    limparTerminal();

    printf("\n #----------------------------------------------------------------#");
    printf("\n |                     Bem Vindo ao BSoft!                        |");
    printf("\n |-----------------------  Menu Livros  --------------------------|");
    printf("\n |                                                                |");
    printf("\n | [1] Adicionar Livro                                            |");
    printf("\n | [2] Remover Livro                                              |");
    printf("\n | [3] Listar Livros                                              |");
    printf("\n | [4] Achar Livro                                                |");
    printf("\n | [5] Livro mais recente                                         |");
    printf("\n |                                                                |");
    printf("\n |----------------------------------------------------------------|");
    printf("\n | [0] Sair                                                       |");
    printf("\n | [9] Fechar Apl                                                 |");
    printf("\n #----------------------------------------------------------------#");

    int OPLivro;

    printf("\n Selecione sua opcao: ");
    scanf("%d",&OPLivro);

    if(getchar()!='\n' ){
        while ((getchar()) != '\n');
        return -1;
    };

    return OPLivro;
}

char PainelLivro(BIBLIOTECA *BLivro){
    int OPLivro;
    HASHING *H_LIVRO = BLivro->HLivros;
    char *file_log= BLivro->FICHEIRO_LOGS;
    do
    {
        OPLivro = MenuLivro();
        switch(OPLivro)
        {
            case 1:{
                int l_isbn,l_publicacao;
                char l_titulo[50],l_autor[50],l_area[100];

                printf("ISBN: ");
                scanf("%d",&l_isbn);
                while (getchar() != '\n');

                printf("Titulo: ");
                scanf("%99[^\n]", l_titulo);
                while (getchar() != '\n');

                printf("Autor: ");
                scanf("%99[^\n]", l_autor);
                while (getchar() != '\n');

                printf("Area: ");
                scanf("%99[^\n]", l_area);
                while (getchar() != '\n');

                printf("Ano publicacao: ");
                scanf("%d",&l_publicacao);


                LIVRO *novoLivro = CriarLivro(l_isbn,l_titulo,l_autor,l_area,l_publicacao,file_log);
                if(novoLivro) AddHashing(H_LIVRO,novoLivro,novoLivro->AREA,"char",file_log);

                system("pause");
                setbuf (stdin, 0);
                break;
            }

            case 2: {
                int SLivro;

                printf("Digite o ISBN que quer pesquisar: ");
                scanf("%d",&SLivro);

                LIVRO *LIV = PesquisarHashing(H_LIVRO, PesquisarLivro,SLivro,file_log);

                RemoverLista(H_LIVRO->LChaves->Inicio->DADOS,LIV,file_log);
                system("pause");
                break;
            }

            case 3: {
                ShowHashing(H_LIVRO,MostrarLivro,"char",file_log);
                system("pause");
                break;
            }

            case 4: {
                int SLivro;

                printf("Digite o ISBN que quer pesquisar: ");
                scanf("%d",&SLivro);

                LIVRO *LIV = PesquisarHashing(H_LIVRO, PesquisarLivro,SLivro,file_log);

                if (LIV)
                    MostrarLivro(LIV,file_log);
                else
                    printf("Nao existe essa pessoa\n");
                system("pause");
                break;
            }

            case 5: {
                LivroMaisRecente(H_LIVRO,file_log);
                system("pause");
                break;
            }

            case 0: break;
            case 9: break;

            default:
                if(OPLivro == -1){
                    printf("Tente inserir um numero =P \n");
                }
                else{
                    printf("Opcao %d e invalida\n",OPLivro);
                }
                system("pause");

                break;
        }
    }while (OPLivro != 0 && OPLivro != 9);

    return OPLivro;
}

LIVRO *CriarLivro(int _isbn, char *_titulo, char *_autor,char *_area, int _ano_pub,char *log_file )
{
    LIVRO *P = (LIVRO *)malloc(sizeof(LIVRO));
    P->ISBN = _isbn;
    P->TITULO = (char *)malloc((strlen(_titulo) + 1)*sizeof(char));
    strcpy(P->TITULO, _titulo);
    P->AUTOR = (char *)malloc((strlen(_autor) + 1)*sizeof(char));
    strcpy(P->AUTOR, _autor);
    P->AREA = (char *)malloc((strlen(_area) + 1)*sizeof(char));
    strcpy(P->AREA, _area);
    P->ANO_PLUBLICACAO = _ano_pub;

    return P;
}

void MostrarLivro(LIVRO *P,char *log_file)
{
    printf("\tLIVRO: %d [%s] [%s] [%s] [%d]\n", P->ISBN, P->TITULO,P->AUTOR,P->AREA ,P->ANO_PLUBLICACAO);
}

void DestruirLivro(LIVRO *P,char *log_file)
{
    free (P->TITULO);
    free (P->AUTOR);
    free (P);
}

int PesquisarLivro(LIVRO *L, int _isbn,char *log_file )
{
    if(L->ISBN == _isbn)
    {
        return 1;
    }

    else
        return 0;
}

void LivroMaisRecente(HASHING *H,char *file_log){
    if(!H) return;
    if(!H->LChaves)return;
    if(!H->LChaves->Inicio)return;

    NO_CHAVE *chave=H->LChaves->Inicio;

    LIVRO *LivroMaisRecentes;
    int ano_livro_recente;

    while(chave){
        NO *no_livro= chave->DADOS->Inicio;

        while(no_livro){
            LIVRO *livro= no_livro->Info;

            if(ano_livro_recente){
                ano_livro_recente=livro->ANO_PLUBLICACAO;
                break;
            }
            else{
                if(ano_livro_recente<livro->ANO_PLUBLICACAO){
                    ano_livro_recente=livro->ANO_PLUBLICACAO;
                    LivroMaisRecentes=livro;
                }
            }

            no_livro=no_livro->Prox;
        }

        chave=chave->Prox;
    }

    MostrarLivro(LivroMaisRecentes,file_log);
}
