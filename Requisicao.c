#include "Requisicao.h"
#include "Livro.h"

int MenuRequisicao()
{
    limparTerminal();

    printf("\n #----------------------------------------------------------------#");
    printf("\n |                     Bem Vindo ao BSoft!                        |");
    printf("\n |---------------------  Menu Requisicao  ------------------------|");
    printf("\n |                                                                |");
    printf("\n | [1] Adicionar Requisicao                                       |");
    printf("\n | [2] Remover Requisicao                                         |");
    printf("\n | [3] Listar Requisicao                                          |");
    printf("\n | [4] Achar Requisicao                                           |");
    printf("\n | [5] Livro mais Requisitado                                     |");
    printf("\n | [6] Area mais Requisitada                                      |");
    printf("\n | [7] Filtros Pessoas                                            |");
    printf("\n | [8] Finalizar Requisicao                                       |");
    printf("\n |                                                                |");
    printf("\n |----------------------------------------------------------------|");
    printf("\n | [0] Sair                                                       |");
    printf("\n | [9] Fechar Apl                                                 |");
    printf("\n #----------------------------------------------------------------#");

    int OPRequisicao;

    printf("\n Selecione sua opcao: ");
    scanf("%d",&OPRequisicao);

    if(getchar()!='\n' ){
        while ((getchar()) != '\n');
        return -1;
    };

    return OPRequisicao;
}

char PainelRequisicao(BIBLIOTECA *BRequisicao){
    int OPRequisicao;
    LISTA *L_Requisicao = BRequisicao->LRequisicoes;
    char *file_log= BRequisicao->FICHEIRO_LOGS;
    do
    {
        OPRequisicao = MenuRequisicao();
        switch(OPRequisicao)
        {
            case 1:{
                int l_isbn;

                LIVRO *Livro;
                do{
                    printf("Qual e o isbn do livro: ");
                    scanf("%d",&l_isbn);
                    while (getchar() != '\n');
                    Livro = PesquisarHashing(BRequisicao->HLivros, PesquisarLivro,l_isbn,file_log);
                }
                while(!Livro);

                PESSOA *Pessoa;
                do{
                    printf("Qual e o ID da Pessoa: ");
                    scanf("%d",&l_isbn);
                    while (getchar() != '\n');
                    Pessoa = PesquisarLista(BRequisicao->LPessoas, PesquisarPessoaId,l_isbn,file_log);
                }
                while(!Pessoa);

                REQUISICAO *novaRequisicao = CriarRequisicao(1,Pessoa,Livro,file_log);


                AddLista(L_Requisicao, novaRequisicao,file_log);

                system("pause");
                setbuf (stdin, 0);
                break;
            }

            case 2: {
                int r_id;

                printf("Digite o id que quer remover: ");
                scanf("%d",&r_id);

                REQUISICAO *REQ = PesquisarLista(L_Requisicao, PesquisarRequisicao,r_id,file_log);

                RemoverLista(L_Requisicao,REQ,file_log);
                DestruirPessoa(REQ,file_log);

                system("pause");
                break;
            }

            case 3: {
                ShowLista(L_Requisicao,MostrarRequisicao,file_log);
                system("pause");
                break;
            }

            case 4: {
                int r_id;
                printf("Digite o id que quer pesquisa: ");
                scanf("%d",&r_id);

                REQUISICAO *REQ = PesquisarLista(L_Requisicao,PesquisarRequisicao,r_id,file_log);
                if (REQ)
                    MostrarRequisicao(REQ,file_log);
                else
                    printf("Nao existe essa requicisao\n");
                system("pause");
                break;
            }

            case 5: {
                LIVRO *L = LivroMaisRequisitadoBiblioteca(L_Requisicao,file_log);
                MostrarLivro(L,file_log);
                system("pause");
                break;
            }

            case 6:{
                printf("A area mais requisitada e: %s",AreaMaisComum(L_Requisicao,file_log));
                system("pause");
                break;
            }

            case 7: {
                int PesLP;
                printf("Filtros pessoas: \n ");
                printf("\t [1] Maior idade das pessoas\n");
                printf("\t [2] Media das idades pessoas\n");
                printf("\t [3] Verificar idades maiores que idade\n");
                scanf("%d",&PesLP);

                if(getchar()!='\n' ){
                    while ((getchar()) != '\n');
                    return -1;
                };

                switch(PesLP)
                {
                    case 1:{
                        int T=IdadeMaximaPessoa(BRequisicao->LPessoas,file_log);
                        printf("Maior idade das pessoas: %d\n",T);
                        system("pause");
                        break;
                    }
                    case 2:{
                        int T=IdadeMediaPessoas(BRequisicao->LPessoas,file_log);
                        printf("Media das idades pessoas: %d\n",T);
                        system("pause");
                        break;
                    }
                    case 3:{
                        int idadeCopm;
                        printf("Digite a idade que quer comparar:");
                        scanf("%d",&idadeCopm);
                        int T= NumMaiorIdade(BRequisicao->LPessoas,idadeCopm,file_log);
                        printf("Numeros de idades maior que %d: %d\n",idadeCopm,T);
                        system("pause");
                        break;
                    }

                    default:
                        if(PesLP == -1){
                            printf("Tente inserir um numero =P \n");
                        }
                        else{
                            printf("Opcao %d e invalida\n",PesLP);
                        }
                        fflush(stdin);
                        system("pause");
                        fflush(stdin);

                        break;
                }
            }

            case 8:{
                int r_id;

                printf("Digite o id que quer finalizar: ");
                scanf("%d",&r_id);

                REQUISICAO *REQ = PesquisarLista(L_Requisicao, PesquisarRequisicao,r_id,file_log);

                if(REQ){
                   FinalizarRequisicao(REQ,file_log);
                }

                system("pause");
                break;
            }
            case 0: break;
            case 9: break;

            default:
                if(OPRequisicao == -1){
                    printf("Tente inserir um numero =P \n");
                }
                else{
                    printf("Opcao %d e invalida\n",OPRequisicao);
                }
                system("pause");

                break;
        }
    }while (OPRequisicao != 0 && OPRequisicao != 9);

    return OPRequisicao;
}


REQUISICAO *CriarRequisicao(int _id, PESSOA *P, LIVRO *L,char *log_file)
{
    FILE *F_Logs = fopen(log_file, "a");
    time_t now = time(NULL) ;
    fprintf(F_Logs, "Entrei em %s na data %s\n", __FUNCTION__, ctime(&now));

    REQUISICAO *Req = (REQUISICAO *)malloc(sizeof(REQUISICAO));
    Req->ID = _id;
    Req->Ptr_Req = P;
    Req->Ptr_Livro = L;
    Req->Data_Requisicao= CriarData(10,10,10);

    fclose(F_Logs);
    return Req;
}

void MostrarRequisicao(REQUISICAO *R,char *log_file)
{
    FILE *F_Logs = fopen(log_file, "a");
    time_t now = time(NULL) ;
    fprintf(F_Logs, "Entrei em %s na data %s\n", __FUNCTION__, ctime(&now));

    printf("REQ ID = %d\n", R->ID);
    MostrarPessoa(R->Ptr_Req,log_file);
    MostrarLivro(R->Ptr_Livro,log_file);
    MostrarData(R->Data_Requisicao);
    printf("TESTE");
    if(R->Data_Devolucao!=NULL){
            printf("TESTE2");
            MostrarData(R->Data_Devolucao);
    }
    printf("TESTE3");

    fclose(F_Logs);
}

void DestruirRequisicao(REQUISICAO *R,char *log_file)
{
    //free (R->Ptr_Livro); //OH Pá se tirares o comentario vais ter problemas!!!!
    //free (R->Ptr_Req); //OH Pá se tirares o comentario vais ter problemas!!!!

    free (R);
}

int PesquisarRequisicao(REQUISICAO *L, int _id,char *log_file){
    FILE *F_Logs = fopen(log_file, "a");
    time_t now = time(NULL) ;
    fprintf(F_Logs, "Entrei em %s na data %s\n", __FUNCTION__, ctime(&now));
    fclose(F_Logs);

    if(L->ID == _id)
    {
        return 1;
    }

    else
        return 0;
}

int PesquisarRequisicaoPessoa(REQUISICAO *L, int _id,char *log_file ){
    FILE *F_Logs = fopen(log_file, "a");
    time_t now = time(NULL) ;
    fprintf(F_Logs, "Entrei em %s na data %s\n", __FUNCTION__, ctime(&now));
    if(L->Ptr_Req->ID == _id) {
        FILE *F_Logs = fopen(log_file, "a");
        time_t now = time(NULL) ;
        fprintf(F_Logs, "Entrei em %s na data %s\n", __FUNCTION__, ctime(&now));
        return 1;
    }
    else{
        FILE *F_Logs = fopen(log_file, "a");
        time_t now = time(NULL) ;
        fprintf(F_Logs, "Entrei em %s na data %s\n", __FUNCTION__, ctime(&now));
        return 0;
    }
}

int PesquisarRequisicaoAtiva(REQUISICAO *L, int _id ){
    if(!L->Data_Devolucao) return 1;
    else return 0;
}

int PesquisarRequisicaoFechada(REQUISICAO *L, int _id ){
    if(L->Data_Devolucao) return 1;
    else return 0;
}

LIVRO *LivroMaisRequisitadoBiblioteca(LISTA* LReq, char* log_file) {
    if (!LReq->Inicio) return NULL;

    FILE* F_Logs = fopen(log_file, "a");
    time_t now = time(NULL);
    fprintf(F_Logs, "Entrei em %s na data %s\n", __FUNCTION__, ctime(&now));

    int maxReq = 0;
    REQUISICAO* MaisRequisitado = NULL;

    NO* atual = LReq->Inicio;
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

    fclose(F_Logs);
    if(MaisRequisitado)return MaisRequisitado->Ptr_Livro;
    else return NULL;
}

LIVRO* AreaMaisRequisitadoBiblioteca(LISTA* LReq, char* log_file) {
    if (!LReq->Inicio) return NULL;

    FILE* F_Logs = fopen(log_file, "a");
    time_t now = time(NULL);
    fprintf(F_Logs, "Entrei em %s na data %s\n", __FUNCTION__, ctime(&now));

    int maxReq = 0;
    REQUISICAO* MaisRequisitado = NULL;

    NO* atual = LReq->Inicio;
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

    fclose(F_Logs);
    if(MaisRequisitado)return MaisRequisitado->Ptr_Livro;
    else return NULL;
}

char *AreaMaisComum(LISTA* LReq, char* log_file) {
    if (!LReq->Inicio) return NULL;

    FILE* F_Logs = fopen(log_file, "a");
    time_t now = time(NULL);
    fprintf(F_Logs, "Entrei em %s na data %s\n", __FUNCTION__, ctime(&now));

    int maxReq = 0;
    char *areaMaisRequisitado = NULL;

    NO* atual = LReq->Inicio;
    REQUISICAO* atualReq;

    if (!atual->Prox){
        atualReq = atual->Info;
        return atualReq->Ptr_Livro->AREA;
    }

    while (atual) {
        atualReq = atual->Info;
        int tempReq = 0;

        NO* prox = atual->Prox;
        while (prox) {
            REQUISICAO* proxReq = prox->Info;
            if (strcmp(proxReq->Ptr_Livro->AREA ,atualReq->Ptr_Livro->AREA)==0) {
                tempReq++;
            }
            prox = prox->Prox;
        }

        if (tempReq > maxReq) {
            areaMaisRequisitado = atualReq->Ptr_Livro->AREA;
        }

        atual = atual->Prox;
    }


    fclose(F_Logs);
    if(areaMaisRequisitado)return areaMaisRequisitado;
    else return NULL;
}

void FinalizarRequisicao(REQUISICAO *R,char* log_file){
    time_t mytime = time(NULL);
    struct tm *timeinfo = localtime(&mytime);

    int Adia= timeinfo->tm_mday;
    int Ames= timeinfo->tm_mon + 1;
    int Aano= timeinfo->tm_year + 1900;

    if(ValidarData(Adia,Ames,Aano)!=1){
        InserirLog(log_file,"Ocorreu um erro ao finalizar Requisicao");
        printf("Ocorreu um erro ao finalizar Requisicao");
    }

    R->Data_Requisicao=CriarData(Adia,Ames,Aano);
}

