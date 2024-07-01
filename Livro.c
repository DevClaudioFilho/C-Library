#include "Livro.h"
#include "Requisicao.h"

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
    printf("\n | [6] Area  com mais Livros                                      |");
    printf("\n | [7] Qual e o livro mais  requisitado                           |");
    printf("\n | [8] Remover Livros sem requisicoes                             |");
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

            case 6:{
                printf("A area com mais livros e : %s\n",AreaComMaisLivros(H_LIVRO,file_log));
                system("pause");
                break;
            }

            case 7:{
                printf("O livro mais requisitado e:");
                LIVRO *T=LivroMaisRequisitadoBiblioteca(BLivro->LRequisicoes,file_log);
                MostrarLivro(T,file_log);
                system("pause");
                break;
            }

            case 8:{
                RemoverLivrosSemReq(BLivro,file_log);
                printf("Livros excluidos\n");
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

char *AreaComMaisLivros(HASHING *H,char *file_log){
    if(!H) return NULL;
    if(!H->LChaves)return NULL;
    if(!H->LChaves->Inicio)return NULL;

    NO_CHAVE *chaveAtual=H->LChaves->Inicio;

    char *AreaComum=NULL;
    int count=0;

    while(chaveAtual){
        int elementos=chaveAtual->DADOS->NEL;
        if(elementos>count){
            printf("%d\n",elementos);
            count=elementos;
            printf("%s",chaveAtual->KEY);
            AreaComum=chaveAtual->KEY;
        }

        chaveAtual=chaveAtual->Prox;
    }

    return AreaComum;
}

LIVRO *LivroMaisRequisitadoBiblioteca(LISTA* LReq, char* log_file) {
    if (!LReq->Inicio) return NULL;

    FILE* F_Logs = fopen(log_file, "a");
    time_t now = time(NULL);
    fprintf(F_Logs, "Entrei em %s na data %s\n", __FUNCTION__, ctime(&now));

    int maxReq = 0;

    NO* atual = LReq->Inicio;
    REQUISICAO* MaisRequisitado = atual->Info;
    while (atual) {
        REQUISICAO* atualReq = atual->Info;
        int tempReq = 0;

        NO* prox = atual->Prox;
        while (prox) {
            REQUISICAO* proxReq = prox->Info;
            if (proxReq->Ptr_Livro->ISBN == atualReq->Ptr_Livro->ISBN) {
                tempReq++;
            }
            prox = prox->Prox;
        }

        if (tempReq > maxReq) {
            MaisRequisitado = atualReq;
        }

        atual = atual->Prox;
    }
    if(MaisRequisitado)return MaisRequisitado->Ptr_Livro;
    else return NULL;
}

void RemoverLivrosSemReq(BIBLIOTECA *B, char* log_file) {
    if(!B->HLivros->LChaves->Inicio) return NULL;

    FILE* F_Logs = fopen(log_file, "a");
    time_t now = time(NULL);
    fprintf(F_Logs, "Entrei em %s na data %s\n", __FUNCTION__, ctime(&now));
    fclose(F_Logs);

    NO_CHAVE* atualChave = B->HLivros->LChaves->Inicio;
    while (atualChave) {
        NO *atualNo=atualChave->DADOS->Inicio;
        while(atualNo){
            LIVRO *atualLivro = atualNo->Info;
            if(B->LRequisicoes->Inicio){
                LIVRO *LIV= PesquisarLista(B->LRequisicoes, PesquisarRequisicaoLivro,atualLivro->ISBN,log_file);
                if(!LIV){
                    RemoverLista(atualChave->DADOS,atualLivro,log_file);
                    //Destroy
                };

            }
            else{
                RemoverLista(atualChave->DADOS,atualLivro,log_file);
            }

            atualNo= atualNo->Prox;
        }

        atualChave=atualChave->Prox;
    }
    return NULL;
}
