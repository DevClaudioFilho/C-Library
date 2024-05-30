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

char PainelPessoa(LISTA *L_PESS){
    int OPPessoa;

     do
    {
        OPPessoa = MenuPessoas();
        switch(OPPessoa)
        {
            case 1:{
                int p_Id,p_idfreguesia,p_dia,p_mes,p_ano;
                char p_nome[50];

                p_Id = gerarID();
                int Id_valido = verificarID(p_Id);
                printf("Id:%d\n",p_Id);

                printf("Nome: ");
                scanf("%s",p_nome);
                while ((getchar()) != '\n');

                printf("Freguesia: ");
                scanf("%d",&p_idfreguesia);


                printf("Nascimento: \n");
                printf("\tDia: ");
                scanf("%d",&p_dia);
                printf("\tMes: ");
                scanf("%d",&p_mes);
                printf("\tAno: ");
                scanf("%d",&p_ano);

                DATA *D=CriarData(p_dia,p_mes,p_ano);
                int D_valida=ValidarData(*D);

                printf("ID VALIDO: %d\n",Id_valido);
                printf("D VALIDO: %d\n",D_valida);
                printf("teste");
                if( Id_valido == 1 && D_valida==1){
                    PESSOA *novaPessoa = CriarPessoa(p_Id, p_nome,D,p_idfreguesia);
                    AddLista(L_PESS, novaPessoa);
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

                PESSOA *PES = PesquisarLista(L_PESS, PesquisarPessoa,SPesoa);

                RemoverLista(L_PESS, PES);
                system("pause");
                break;
            }

            case 3: {
                ShowLista(L_PESS,MostrarPessoa);
                system("pause");
                break;
            }

            case 4: {
                char SPesoa[50];

                printf("Digite o nome que quer pesquisar: ");
                scanf("%s",SPesoa);
                while ((getchar()) != '\n');

                PESSOA *PES = PesquisarLista(L_PESS, PesquisarPessoa,SPesoa);
                if (PES)
                    MostrarPessoa(PES);
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

int verificarID(int ID_Pessoa){
    int c,tmpNum,resto;
    char temp_id[8];
    int tmpSum=0;

    sprintf(temp_id, "%d", ID_Pessoa);

    printf("INT ID_Pessoa: %d , temp_id:%s\n",ID_Pessoa,temp_id);
    for(c=0; c<=8; c++){
        tmpNum=temp_id[c] - '0';
        tmpSum += tmpNum;
        printf("tmpSum: %d , tmpNum:%d\n",tmpSum,tmpNum);
    }
    resto=tmpSum%10;
    if(resto==0){
        return 1;
    }
    else{
        return 0;
    };
}

int gerarID(){
    int c,tmpNum,resto;
    char temp_id[8],tmpChar;

    int tmpSum=0;
    for(c=0; c<=7; c++){
            tmpNum = rand()%10;//Aleatorio(0,9);
            tmpSum += tmpNum;
            tmpChar = '0' + tmpNum;
            temp_id[c] = tmpChar;
    }
    resto=tmpSum%10;
    temp_id[8]='0'+(10-resto);

    int INT_ID=atoi(temp_id);
    return INT_ID;
}

PESSOA *CriarPessoa(int _id, char *_nome, DATA *_nascimento, int _idfreguesia)
{
    PESSOA *P = (PESSOA *)malloc(sizeof(PESSOA));
    P->ID = _id;
    P->NOME = (char *)malloc((strlen(_nome) + 1)*sizeof(char));
    strcpy(P->NOME, _nome);
    P->NASCIMENTO = _nascimento;
    P->ID_FREGUESIA = _idfreguesia;

    return P;
}

void MostrarPessoa(PESSOA *P)
{
    printf("\tPESSOA: [%d] [%s] [%d]", P->ID, P->NOME, P->ID_FREGUESIA);
    MostrarData(P->NASCIMENTO);
}

int PesquisarPessoa(PESSOA *P, char *palavra )
{
    if(stricmp(P->NOME, palavra) == 0)
    {
        return 1;
    }

    else
        return 0;
}

void DestruirPessoa(PESSOA *P)
{
    free (P->ID);
    free (P->NOME);
    DestruirData(P->NASCIMENTO);
    free (P->ID_FREGUESIA);

    free (P);
}

