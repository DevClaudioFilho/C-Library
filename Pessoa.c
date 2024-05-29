#include <stdio.h>
#include <stdlib.h>

#include "Lista.h"
#include "Hashing.h"
#include "Biblioteca.h"

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

int verificarID(int ID_Pessoa){
    int ultimoDigito = ID_Pessoa%10;
    int penultimoDigito = (ID_Pessoa / 10) % 10;

    if(ultimoDigito+penultimoDigito==10){
        return 1;
    }
    else{
        return 0;
    };
}

int gerarID(){
    int c,tmpNum;
    char temp_id[8],tmpChar;

    for(c=0; c<=7; c++){
        if(c<6){
            tmpNum = Aleatorio(0,9);
            tmpChar = '0' + tmpNum;
            temp_id[c] = tmpChar;
        }
        if(c==6){
            tmpNum = Aleatorio(1,9);
            tmpChar = '0' + tmpNum;
            temp_id[c] = tmpChar;
        }
        if(c>6){
            int validator= temp_id[c-1] - '0';
            tmpNum = 10-validator;
            tmpChar = '0' + tmpNum;
            temp_id[c] = tmpChar;
        }
    }
    int INT_ID=atoi(temp_id);
    return INT_ID;
}

char PainelPessoa(LISTA *L_PESS){
    int OPPessoa;

     do
    {
        OPPessoa = MenuPessoas();
        switch(OPPessoa)
        {
            case 1:{
                int p_id,p_Id;
                char p_nome[50],p_categoria[50];

                printf("Nome: ");
                scanf("%s",p_nome);
                while ((getchar()) != '\n');

                printf("Categoria: ");
                scanf("%s",p_categoria);
                while ((getchar()) != '\n');

                p_Id = gerarID();

                int valido = verificarID(p_Id);

                if( valido == 1 ){
                    printf("id:%d/n",p_Id);
                    PESSOA *novaPessoa = CriarPessoa(p_Id, p_nome, p_categoria);
                    AddLista(L_PESS, novaPessoa);
                }

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

PESSOA *CriarPessoa(int _id, char *_nome, char *_categoria)
{
    PESSOA *P = (PESSOA *)malloc(sizeof(PESSOA));
    P->NOME = (char *)malloc((strlen(_nome) + 1)*sizeof(char));
    strcpy(P->NOME, _nome);
    P->CATEGORIA = (char *)malloc((strlen(_categoria) + 1)*sizeof(char));
    strcpy(P->CATEGORIA, _categoria);
    P->ID = _id;
    return P;
}

void MostrarPessoa(PESSOA *P)
{
    printf("\tPESSOA: ID: %d [%s] [%s]\n", P->ID, P->NOME, P->CATEGORIA);
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
    free (P->NOME);
    free (P->CATEGORIA);
    free (P);
}

