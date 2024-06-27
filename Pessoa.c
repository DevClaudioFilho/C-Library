#include <stdio.h>
#include <stdlib.h>

#include "Lista.h"
#include "Hashing.h"
#include "Biblioteca.h"
#include "Data.h"

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

    printf("%s",&file_log);
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
                int D_valida=ValidarData(*D);

                if( D_valida==1){
                    PESSOA *novaPessoa = CriarPessoa(p_Id, p_nome,D,p_idfreguesia,file_log);
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
                char SPesoa[50];

                printf("Digite o nome que quer remover: ");
                scanf("%s",SPesoa);
                while ((getchar()) != '\n');

                PESSOA *PES = PesquisarLista(L_PESS, PesquisarPessoa,SPesoa,file_log);

                RemoverLista(L_PESS,PES,file_log);
                DestruirPessoa(PES,file_log);

                system("pause");
                break;
            }

            case 3: {
                int OrdLP;
                printf("Como que deseja ordenar? \n ");
                printf("[1]  Por nascimento\n ");
                printf("[2]  Ordem alfabetica\n ");
                printf("[3]  Por freguesia\n ");
                scanf("%d",&OrdLP);

                bubbleSort(L_PESS,OrdenarPessoas);
                ShowLista(L_PESS,MostrarPessoa,file_log);
                system("pause");
                break;
            }

            case 4: {
                char SPesoa[50];

                printf("Digite o nome que quer pesquisar: ");
                scanf("%s",SPesoa);
                while ((getchar()) != '\n');

                PESSOA *PES = PesquisarLista(L_PESS, PesquisarPessoa,SPesoa,file_log);
                if (PES)
                    MostrarPessoa(PES,BPess->FICHEIRO_LOGS);
                else
                    printf("Nao existe essa pessoa\n");
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

    //Pre validacoes
    int Id_valido = verificarID(_id,log_file);
    if( Id_valido != 1 )fprintf(F_Logs, "\t %s- ID [%d] nao e valido\n", ctime(&now), _id);

    int D_valida=ValidarData(_nascimento);
    if( D_valida != 1 )fprintf(F_Logs, "\t %s- Data [%d/%d/%d] nao e valida\n",
                               ctime(&now),
                               _nascimento->DIA,
                               _nascimento->MES,
                               _nascimento->ANO
                               );

    //int Validar_freguesia
    //if( D_valida != 1 )fprintf(F_Logs, "\t %s- Data [%d/%d/%d] nao e valida\n",ctime(&now),D->DIA, D->MES, D->ANO);

    if( Id_valido!= 1 || D_valida!=1 )return;
    //

    PESSOA *P = (PESSOA *)malloc(sizeof(PESSOA));
    P->ID = _id;
    P->NOME = (char *)malloc((strlen(_nome) + 1)*sizeof(char));
    strcpy(P->NOME, _nome);
    P->NASCIMENTO = _nascimento;
    P->ID_FREGUESIA = _idfreguesia;

    fclose(F_Logs);
    return P;
}

void MostrarPessoa(PESSOA *P,char *log_file)
{
    FILE *F_Logs = fopen(log_file, "a");
    time_t now = time(NULL) ;
    fprintf(F_Logs, "Entrei em %s na data %s\n", __FUNCTION__, ctime(&now));

    printf("\tPESSOA: [%d] [%s] [%d]", P->ID, P->NOME, P->ID_FREGUESIA);
    MostrarData(P->NASCIMENTO);
        fclose(F_Logs);
}

int PesquisarPessoa(PESSOA *P, char *palavra,char *log_file)
{
    FILE *F_Logs = fopen(log_file, "a");
    time_t now = time(NULL) ;
    fprintf(F_Logs, "Entrei em %s na data %s\n", __FUNCTION__, ctime(&now));
    fclose(F_Logs);

    if(strstr(P->NOME, palavra))
    {
        return 1;
    }

    else
        return 0;
}

void DestruirPessoa(PESSOA *P,char *log_file)
{
    FILE *F_Logs = fopen(log_file, "a");
    time_t now = time(NULL) ;
    fprintf(F_Logs, "Entrei em %s na data %s\n", __FUNCTION__, ctime(&now));
    fclose(F_Logs);

    free(P->NOME);
    DestruirData(P->NASCIMENTO);
    free(P);
}

int OrdenarPessoas(PESSOA *a, PESSOA *b,int sw)//1 = TROCA COM A PROXIMA
{
    //Por data de nascimento mais velho para o mais novo
    if(sw == 1){

        if(a->NASCIMENTO->ANO > b->NASCIMENTO->ANO){
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

}
