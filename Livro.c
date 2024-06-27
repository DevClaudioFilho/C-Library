#include "Livro.h"
#include "Hashing.h"
#include "Biblioteca.h"

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



                LIVRO *novoLivro = CriarLivro(l_isbn,l_titulo,l_autor,l_area,l_publicacao);
                printf("/n %s /n",l_area);
                printf("/n %s /n",novoLivro->AREA);
                AddHashing(H_LIVRO,novoLivro,novoLivro->AREA,"char",file_log);

                system("pause");
                setbuf (stdin, 0);
                break;
            }

            case 2: {
                int SLivro;

                printf("Digite o ISBN que quer pesquisar: ");
                scanf("%d",&SLivro);

                LIVRO *LIV = PesquisarHashing(H_LIVRO, PesquisarLivro,SLivro);

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

                LIVRO *LIV = PesquisarHashing(H_LIVRO, PesquisarLivro,SLivro);

                if (LIV)
                    MostrarLivro(LIV);
                else
                    printf("Nao existe essa pessoa\n");
                system("pause");
                break;
            }

            case 5: {
                LivroMaisRecente(H_LIVRO);
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

LIVRO *CriarLivro(int _isbn, char *_titulo, char *_autor,char *_area, int _ano_pub )
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

void MostrarLivro(LIVRO *P)
{
    printf("\tLIVRO: %d [%s] [%s] [%s] [%d]\n", P->ISBN, P->TITULO,P->AUTOR,P->AREA ,P->ANO_PLUBLICACAO);
}

void DestruirLivro(LIVRO *P)
{
    free (P->TITULO);
    free (P->AUTOR);
    free (P);
}

int PesquisarLivro(LIVRO *L, int _isbn )
{
    printf("%d/n",L->ISBN);
    printf("%d/n",_isbn);

    if(L->ISBN == _isbn)
    {
        return 1;
    }

    else
        return 0;
}


void LivroMaisRecente(HASHING *H,char *file_log){
    int i;
    LISTA *LivrosMaisRecentes = CriarLista();
    LivrosMaisRecentes->NEL=0;

    NO_CHAVE *noc_atual=H->LChaves->Inicio;

    for(i=0;i<H->LChaves->NEL;i++){
        NO_CHAVE *noc_temp=noc_atual;
        NO_CHAVE *noc_prox=noc_atual->Prox;

        NO *no_atual=noc_atual->DADOS->Inicio;
        for(i=0;i<=noc_atual->DADOS->NEL;i++){
            NO *no_temp=no_atual;

            LIVRO *LIVRO_TEMP=no_atual->Info;
            LIVRO *LIVRO_MAIS_TEMP=LivrosMaisRecentes->Inicio->Info;
            if(LivrosMaisRecentes->NEL==0){
                AddLista(LivrosMaisRecentes,no_atual->Info,file_log);
            }
            else if(LIVRO_TEMP->ANO_PLUBLICACAO == LIVRO_MAIS_TEMP->ANO_PLUBLICACAO){
                AddLista(LivrosMaisRecentes,no_atual->Info,file_log);
            }
            else if(LIVRO_TEMP->ANO_PLUBLICACAO > LIVRO_MAIS_TEMP->ANO_PLUBLICACAO){
                int i;
                LIVRO *LMA=LivrosMaisRecentes->Inicio->Info;
                for(i=0;i<=LivrosMaisRecentes->NEL;i++){
                    RemoverLista(LivrosMaisRecentes, LMA,file_log);
                    LMA=LivrosMaisRecentes->Inicio->Prox;
                }

                AddLista(LivrosMaisRecentes,no_atual->Info,file_log);
            }
        }
    }

    ShowLista(LivrosMaisRecentes,MostrarLivro,file_log);

}
