#include <stdio.h>
#include <stdlib.h>

#include "Pessoa.h"
#include "Requisicao.h"

/** \brief Permite Alocar e inicializar uma estrutura Pessoa
 *
 * \param _id int
 * \param _nome char*
 * \param _categoria char*
 * \return PESSOA*
 *
 */

int MenuPessoas()
{
    limparTerminal();

    printf("\n #----------------------------------------------------------------#");
    printf("\n |                    Bem Vindo ao BSoft !                        |");
    printf("\n |-------------------  Menu Requisitantes  -----------------------|");
    printf("\n |                                                                |");
    printf("\n | [1] Adicionar Pessoa                                           |");
    printf("\n | [2] Remover Pessoa                                             |");
    printf("\n | [3] Listar Pessoas                                             |");
    printf("\n | [4] Achar Pessoa                                               |");
    printf("\n | [5] Apelido Mais Comum                                         |");
    printf("\n | [6] Menu idade pessoas                                         |");
    printf("\n | [7] Numero de pessoa com apelido em um distrito                |");
    printf("\n |                                                                |");
    printf("\n |----------------------------------------------------------------|");
    printf("\n | [0] Sair                                                       |");
    printf("\n | [9] Fechar Apl                                                 |");
    printf("\n #----------------------------------------------------------------#");

    int OPPessoa;

    printf("\n Selecione sua opcao: ");
    fflush(stdin);
    scanf("%d",&OPPessoa);

    if(getchar()!='\n' ){
        while ((getchar()) != '\n');
        return -1;
    };

    return OPPessoa;
}

char PainelPessoa(BIBLIOTECA *BPess){
    int OPPessoa;
    LISTA *L_PESS = BPess->LPessoas;
    char *file_log= BPess->FICHEIRO_LOGS;
    system("pause");
     do
    {
        OPPessoa = MenuPessoas();
        switch(OPPessoa)
        {
            case 1:{
                int p_Id,p_idfreguesia,p_dia,p_mes,p_ano;
                char p_nome[50];

                p_Id = gerarID(file_log);
                printf("Id:%d\n",p_Id);

                printf("Nome: ");
                scanf("%99[^\n]", p_nome);
                while (getchar() != '\n');

                printf("Freguesia: ");
                scanf("%d",&p_idfreguesia);
                while (getchar() != '\n');

                printf("Nascimento: \n");
                printf("\tDia: ");
                scanf("%d",&p_dia);

                printf("\tMes: ");
                scanf("%d",&p_mes);

                printf("\tAno: ");
                scanf("%d",&p_ano);

                DATA *D=CriarData(p_dia,p_mes,p_ano);

                PESSOA *novaPessoa = CriarPessoa(p_Id, p_nome,D,p_idfreguesia,file_log);
                if(novaPessoa){
                    AddLista(L_PESS, novaPessoa,file_log);
                }
                else{
                    printf("Ha algo errado no usuario\n");
                };
                system("pause");
                setbuf (stdin, 0);
                break;
            }

            case 2: {
                int p_id;

                printf("Digite o id que quer remover: ");
                scanf("%d",&p_id);

                PESSOA *PES = PesquisarLista(L_PESS, PesquisarPessoaId,p_id,file_log);

                RemoverLista(L_PESS,PES,file_log);
                DestruirPessoa(PES,file_log);

                system("pause");
                break;
            }

            case 3: {
                int OrdLP;
                printf("Como que deseja a lista? \n ");
                printf("[1]  Por nascimento\n ");
                printf("[2]  Ordem alfabetica\n ");
                printf("[3]  Por freguesia\n ");
                printf("[4]  Pessoas sem requisicao\n ");
                printf("[5]  Pessoas com requisicoes\n ");
                scanf("%d",&OrdLP);

                if(OrdLP<4&&OrdLP>0){
                    bubbleSort(L_PESS,OrdenarPessoas,OrdLP,file_log);
                    ShowLista(L_PESS,MostrarPessoa,file_log);
                }
                if(OrdLP==4){
                    printf("Resultados:\n");
                    MostrarPessoaSemReq(L_PESS,BPess->LRequisicoes,file_log);
                }
                if(OrdLP==5){
                    printf("Resultados:\n");
                    MostrarPessoaComReqAtivo(L_PESS,BPess->LRequisicoes,file_log);
                }

                system("pause");
                break;
            }

            case 4: {
                int p_id,PesLP;
                printf("Como que deseja pesquisar? \n ");
                printf("[1]  Por id\n ");
                printf("[2]  Por Nome\n ");
                scanf("%d",&PesLP);

                PESSOA *PES;
                if(PesLP==1){
                    printf("Digite o id que quer pesquisa: ");
                    scanf("%d",&p_id);

                    PES= PesquisarLista(L_PESS, PesquisarPessoaId,p_id,file_log);
                }
                else if(PesLP==2){
                    char pesq_nome[50];

                    while (getchar() != '\n');
                    printf("Digite o nome que quer pesquisa: ");
                    scanf("%99[^\n]", pesq_nome);
                    while (getchar() != '\n');

                    PES= PesquisarLista(L_PESS, PesquisarPessoaNome,pesq_nome,file_log);
                }

                else{
                    printf("opcao invalida, tente novamente/n");
                    system("pause");
                    break;
                }

                if (PES)
                    MostrarPessoa(PES,BPess->FICHEIRO_LOGS);
                else
                    printf("Nao existe essa pessoa\n");
                system("pause");
                break;
            }

            case 5: {
                char *T=ApelidoMaisComum(L_PESS,file_log);
                printf("Apelido mais repetido e: %s\n",T);
                system("pause");
                break;
            }

            case 6: {
                int PesLP;
                printf("Informacoes sobre idades: \n ");
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
                        int T=IdadeMaximaPessoa(L_PESS,file_log);
                        printf("Maior idade das pessoas: %d\n",T);
                        fflush(stdin);
                        system("pause");
                        fflush(stdin);
                        break;
                    }
                    case 2:{
                        int T=IdadeMediaPessoas(L_PESS,file_log);
                        printf("Media das idades pessoas: %d\n",T);
                        fflush(stdin);
                        system("pause");
                        fflush(stdin);
                        break;
                    }
                    case 3:{
                        int idadeCopm;
                        printf("Digite a idade que quer comparar:");
                        scanf("%d",&idadeCopm);
                        int T= NumMaiorIdade(L_PESS,idadeCopm,file_log);
                        printf("Numeros de idades maior que %d: %d\n",idadeCopm,T);
                        fflush(stdin);
                        system("pause");
                        fflush(stdin);
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

                break;
            }

            case 7:{
                int id_dis;
                printf("Digite o numero do distrito:");
                scanf("%d",&id_dis);

                while (getchar() != '\n');
                char p_nome[50];
                printf("Nome: ");
                scanf("%99[^\n]", p_nome);
                while (getchar() != '\n');

                int T= NumPesDisNom(L_PESS,id_dis,p_nome,file_log);

                printf("Numeros de pessoas de %d com o nome/apellido %s: %d\n",id_dis,p_nome,T);
                system("pause");
                break;
            }
            case 0: break;
            case 9: break;

            default:
                if(OPPessoa == -1){
                    printf("Tente inserir um numero =P \n");
                }
                else{
                    printf("Opcao %d e invalida\n",OPPessoa);
                }
                fflush(stdin);
                system("pause");
                fflush(stdin);

                break;
        }
    }while (OPPessoa != 0 && OPPessoa != 9);

    return OPPessoa;
}

int verificarID(int ID_Pessoa,char *log_file){
    FILE *F_Logs = fopen(log_file, "a");
    time_t now = time(NULL) ;
    fprintf(F_Logs, "Entrei em %s na data %s\n", __FUNCTION__, ctime(&now));

    int c,tmpNum,resto;
    char temp_id[8];
    int tmpSum=0;

    sprintf(temp_id, "%d", ID_Pessoa);

    for(c=0; c<=8; c++){
        tmpNum=temp_id[c] - '0';
        tmpSum += tmpNum;
    }
    resto=tmpSum%10;
    if(resto==0){
        fclose(F_Logs);
        return 1;
    }
    else{
        fclose(F_Logs);
        return 0;
    };
}

int gerarID(char *log_file){
    FILE *F_Logs = fopen(log_file, "a");
    time_t now = time(NULL) ;
    fprintf(F_Logs, "Entrei em %s na data %s\n", __FUNCTION__, ctime(&now));
    fclose(F_Logs);

    int Id_valido,c,tmpNum,resto,INT_ID,tmpSum;
    char temp_id[8],tmpChar;
    do{
        tmpSum=0;
        for(c=0; c<=7; c++){
                tmpNum = rand()%10;//Aleatorio(0,9);
                tmpSum += tmpNum;
                tmpChar = '0' + tmpNum;
                temp_id[c] = tmpChar;
        }
        resto=tmpSum%10;
        temp_id[8]='0'+(10-resto);

        INT_ID= atoi(temp_id);

        Id_valido = verificarID(INT_ID,log_file);
    }
    while(Id_valido!=1);

    return INT_ID;
}

PESSOA *CriarPessoa(int _id, char *_nome, DATA *_nascimento, int _idfreguesia,char *log_file)
{
    FILE *F_Logs = fopen(log_file, "a");
    time_t now = time(NULL) ;
    fprintf(F_Logs, "Entrei em %s na data %s\n", __FUNCTION__, ctime(&now));
    fclose(F_Logs);
    //Pre validacoes
    int Id_valido = verificarID(_id,log_file);
    if( Id_valido != 1 )fprintf(F_Logs, "\t %s- ID [%d] nao e valido\n", ctime(&now), _id);

    int D_valida=ValidarData(_nascimento->DIA,_nascimento->MES,_nascimento->ANO);
    if( D_valida != 1 )fprintf(F_Logs, "\t %s- Data [%d/%d/%d] nao e valida\n",
                               ctime(&now),
                               _nascimento->DIA,
                               _nascimento->MES,
                               _nascimento->ANO
                               );

    int F_valida=ValidaLocalCodigo(_idfreguesia,3,log_file);
    if( F_valida != 1 )fprintf(F_Logs, "\t %s- Freguesia %d nao e valida\n",ctime(&now),_idfreguesia);
    if( Id_valido!= 1 || D_valida!=1 || F_valida!=1)return NULL;

    PESSOA *P = (PESSOA *)malloc(sizeof(PESSOA));
    P->ID = _id;
    P->NOME = (char *)malloc((strlen(_nome) + 1)*sizeof(char));
    strcpy(P->NOME, _nome);
    P->NASCIMENTO = _nascimento;
    P->ID_FREGUESIA = _idfreguesia;
    return P;
}

void MostrarPessoa(PESSOA *P,char *log_file)
{
    if(!P) return;
    FILE *F_Logs = fopen(log_file, "a");
    time_t now = time(NULL) ;
    fprintf(F_Logs, "Entrei em %s na data %s\n", __FUNCTION__, ctime(&now));
    fclose(F_Logs);

    char *nome=P->NOME;
    converterParaMaiusculas(nome);

    printf("\tPESSOA: [%d] [%s] [%d]", P->ID,nome, P->ID_FREGUESIA);
    MostrarData(P->NASCIMENTO);


}

int PesquisarPessoaId(PESSOA *P, int *_id,char *log_file)
{
    if(!P) return 0;
    FILE *F_Logs = fopen(log_file, "a");
    time_t now = time(NULL) ;
    fprintf(F_Logs, "Entrei em %s na data %s\n", __FUNCTION__, ctime(&now));
    fclose(F_Logs);

    if(P->ID == _id)
    {
        return 1;
    }

    else
        return 0;
}

int PesquisarPessoaNome(PESSOA *P, char *_nome,char *log_file)
{
    if(!P) return 0;
    FILE *F_Logs = fopen(log_file, "a");
    time_t now = time(NULL) ;
    fprintf(F_Logs, "Entrei em %s na data %s\n", __FUNCTION__, ctime(&now));
    fclose(F_Logs);

    if(strcmp(P->NOME,_nome)==0)
    {
        F_Logs = fopen(log_file, "a");
        now = time(NULL) ;
        fprintf(F_Logs, "Terminar em %s na data %s\n", __FUNCTION__, ctime(&now));
        fclose(F_Logs);
        return 1;
    }

    else{
        F_Logs = fopen(log_file, "a");
        now = time(NULL) ;
        fprintf(F_Logs, "Terminar em %s na data %s\n", __FUNCTION__, ctime(&now));
        fclose(F_Logs);
        return 0;
    }
}

void DestruirPessoa(PESSOA *P,char *log_file)
{
    FILE *F_Logs = fopen(log_file, "a");
    time_t now = time(NULL) ;
    fprintf(F_Logs, "Entrei em %s na data %s\n", __FUNCTION__, ctime(&now));
    fclose(F_Logs);

    if(!P)return NULL;

    free(P->NOME);
    DestruirData(P->NASCIMENTO);
    free(P);
}

int OrdenarPessoas(PESSOA *a, PESSOA *b,int sw)//1 = TROCA COM A PROXIMA
{
    //Por data de nascimento mais velho para o mais novo
    if(sw == 1){
        if(a->NASCIMENTO->ANO < b->NASCIMENTO->ANO){
            return 1;
        }
        else if(a->NASCIMENTO->ANO == b->NASCIMENTO->ANO){
            if(a->NASCIMENTO->MES > b->NASCIMENTO->MES){
                return 1;
            }
            else if(a->NASCIMENTO->MES == b->NASCIMENTO->MES){
                if(a->NASCIMENTO->DIA < b->NASCIMENTO->DIA){
                    return 1;
                }
                else{
                    return 0;
                }
            }
            else{
                return 0;
            }
        }
        else{
            return 0;
        }
    }

    //Por ordem alfabetica
    else if(sw == 2){
        if( strcmp(a->NOME,b->NOME)< 0){
            return 1;
        }
        return 0;
    }

    //Por freguesia
    if(sw == 3){
        if(a->ID_FREGUESIA > b->ID_FREGUESIA){
            return 1;
        }
        return 0;
    }

    return 0;
}

void MostrarPessoaSemReq(LISTA *P,LISTA *R,char *log_file){
    if (!P) return;

    FILE *F_Logs = fopen(log_file, "a");
    time_t now = time(NULL);
    fprintf(F_Logs, "Entrei em %s na data %s\n", __FUNCTION__, ctime(&now));
    fclose(F_Logs);

    NO *atual = P->Inicio;

    while (atual) {
        PESSOA *Pes = atual->Info;

        REQUISICAO *REQ = PesquisarLista(R,PesquisarRequisicaoPessoa,Pes->ID,log_file);
        if (!REQ)
            MostrarPessoa(Pes,log_file);

        atual = atual->Prox;
    }
    return;
}

void MostrarPessoaComReqAtivo(LISTA *P,LISTA *R,char *log_file){
    if (!P) return NULL;

    FILE *F_Logs = fopen(log_file, "a");
    time_t now = time(NULL);
    fprintf(F_Logs, "Entrei em %s na data %s\n", __FUNCTION__, ctime(&now));
    fclose(F_Logs);

    NO *atual = P->Inicio;

    while (atual) {
        PESSOA *Pes = atual->Info;

        REQUISICAO *REQ = PesquisarLista(R,PesquisarRequisicaoPessoa,Pes->ID,log_file);
        if (REQ)
            MostrarPessoa(Pes,log_file);

        atual = atual->Prox;
    }


    return;
}

char *ApelidoMaisComum(LISTA *P, char *log_file) {
    if (!P) return NULL;

    FILE *F_Logs = fopen(log_file, "a");
    time_t now = time(NULL);
    fprintf(F_Logs, "Entrei em %s na data %s\n", __FUNCTION__, ctime(&now));

    NO *atual = P->Inicio;

    char *maisRepetido = NULL;
    int maxRep = 0;

    while (atual) {
        PESSOA *Pes = atual->Info;
        char *str=Pes->NOME;
        char *apelido = strtok(str, " ");
        apelido = strtok(NULL, " ");

        if(!maisRepetido){
            maisRepetido=apelido;
        }

        while (apelido != NULL) {
            int tempRep = 0;
            NO *inicio = P->Inicio;

            while (inicio) {
                PESSOA *Ptemp = inicio->Info;
                char *ret = strstr(Ptemp->NOME, apelido);
                if (ret) {
                    tempRep++;
                }
                inicio = inicio->Prox;
            }

            if (tempRep > maxRep) {
                maxRep = tempRep;
                maisRepetido = apelido;
            }
            apelido = strtok(NULL, " ");
        }

        atual = atual->Prox;
    }

    fclose(F_Logs);
    return maisRepetido;
}

int calcularIdade(int dia, int mes, int ano){
    if(!dia&&!mes&&!ano) return 0;
    int idade=0;

    time_t mytime = time(NULL);
    struct tm *timeinfo = localtime(&mytime);

    int Adia= timeinfo->tm_mday;
    int Ames= timeinfo->tm_mon + 1;
    int Aano= timeinfo->tm_year + 1900;

    if(ano<Aano){
        idade= Aano-ano-1;
        if(mes<Ames){
            idade++;
        }
        else if(mes==Ames && dia<Adia){
            idade++;
        }
    }

    if(idade==-1)return 0;
    return idade;
}

int IdadeMaximaPessoa(LISTA *P,char *log_file){
    FILE *F_Logs = fopen(log_file, "a");
    time_t now = time(NULL) ;
    fprintf(F_Logs, "Entrei em %s na data %s\n", __FUNCTION__, ctime(&now));
    fclose(F_Logs);
    if(!P) return 0;
    if(!P->Inicio) return 0;

    int idadeMax=0;


    NO *atual=P->Inicio;
    int tmpIdade;
    while(atual){
        PESSOA *Pes=atual->Info;
        DATA *Nas=Pes->NASCIMENTO;
        tmpIdade=calcularIdade(Nas->DIA,Nas->MES,Nas->ANO);
        if(tmpIdade>=idadeMax){
            idadeMax=tmpIdade;
        }

        atual=atual->Prox;
    }

    return idadeMax;
}

int IdadeMediaPessoas(LISTA *P,char *log_file){
    FILE *F_Logs = fopen(log_file, "a");
    time_t now = time(NULL) ;
    fprintf(F_Logs, "Entrei em %s na data %s\n", __FUNCTION__, ctime(&now));
    fclose(F_Logs);
    if(!P) return 0;
    if(!P->Inicio) return 0;

    int idadeSum=0;


    NO *atual=P->Inicio;
    int tmpIdade;
    while(atual){
        PESSOA *Pes=atual->Info;
        DATA *Nas=Pes->NASCIMENTO;
        tmpIdade=calcularIdade(Nas->DIA,Nas->MES,Nas->ANO);
        idadeSum=idadeSum+tmpIdade;
        atual=atual->Prox;
    }

    return idadeSum/P->NEL;
}

int NumMaiorIdade(LISTA *P,int _idadeCopm,char *log_file){
    FILE *F_Logs = fopen(log_file, "a");
    time_t now = time(NULL) ;
    fprintf(F_Logs, "Entrei em %s na data %s\n", __FUNCTION__, ctime(&now));
    fclose(F_Logs);
    if(!P) return 0;
    if(!P->Inicio) return 0;

    int countMaior=0;

    NO *atual=P->Inicio;
    int tmpIdade;
    while(atual){
        PESSOA *Pes=atual->Info;
        DATA *Nas=Pes->NASCIMENTO;
        tmpIdade=calcularIdade(Nas->DIA,Nas->MES,Nas->ANO);
        if(tmpIdade>_idadeCopm){
            countMaior++;
        }
        atual=atual->Prox;
    }

    return countMaior;
}

int NumPesDisNom(LISTA *P,int _idDis,char *_nome,char *log_file){
    FILE *F_Logs = fopen(log_file, "a");
    time_t now = time(NULL) ;
    fprintf(F_Logs, "Entrei em %s na data %s\n", __FUNCTION__, ctime(&now));
    fclose(F_Logs);
    if(!P) return 0;
    if(!P->Inicio) return 0;

    int countPes=0;

    NO *atual=P->Inicio;
    while(atual){
        PESSOA *Pes=atual->Info;

        if(Pes->ID_FREGUESIA==_idDis && strstr(Pes->NOME,_nome)){
            countPes++;
        }
        atual=atual->Prox;
    }

    F_Logs = fopen(log_file, "a");
    now = time(NULL) ;
    fprintf(F_Logs, "Sai em %s na data %s\n", __FUNCTION__, ctime(&now));
    fclose(F_Logs);

    return countPes;
}
