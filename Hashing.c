#include "Hashing.h"

LISTA_CHAVES *CriarListaCHAVES()
{
    LISTA_CHAVES *L = (LISTA_CHAVES *)malloc(sizeof(LISTA_CHAVES));
    L->NEL = 0;
    L->Inicio = NULL;
    return L;
}

NO_CHAVE *AddCHAVE(LISTA_CHAVES *L, void *key, char *type)
{
    if (!L) return NULL;

    NO_CHAVE *aux = (NO_CHAVE *)malloc(sizeof(NO_CHAVE));
    if(stricmp(type, "char") == 0){
        aux->KEY = (char *)malloc((strlen(key) + 1) * sizeof(char));
        strcpy(aux->KEY, key);
    }
    else{
       aux->KEY = key;
    };

    aux->DADOS = CriarLista();
    aux->Prox = L->Inicio;
    L->Inicio = aux;
    L->NEL++;
    return aux;
}

HASHING *CriarHashing()
{
    HASHING *Has = (HASHING *)malloc(sizeof(HASHING));
    Has->LChaves = CriarListaCHAVES();
    return Has;
}

void DestruirHashing(HASHING *H,char *log_file)
{
    if (!H) return;
    NO_CHAVE *Seguinte;
    NO_CHAVE *P = H->LChaves->Inicio;
    while (P)
    {
        Seguinte = P->Prox;
        DestruirLista(P->DADOS,log_file);
        free(P->KEY);
        free(P);
        P = Seguinte;
    }
    free(H);
}

void AddHashing(HASHING *H, void *P,void *NChave, char *type,char *log_file)
{
    FILE *F_Logs = fopen(log_file, "a");
    time_t now = time(NULL) ;
    fprintf(F_Logs, "Entrei em %s na data %s\n", __FUNCTION__, ctime(&now));

    if (!H) return;
    if (!H->LChaves) return;
    NO_CHAVE *Key_colocar = FuncaoHashing(H, P ,NChave,type,log_file);
    if (!Key_colocar)
    {
        Key_colocar = AddCHAVE(H->LChaves, NChave,type);
    }
    AddLista(Key_colocar->DADOS, P,log_file);

    fprintf(F_Logs, "Terminou %s na data %s\n", __FUNCTION__, ctime(&now));
    fclose(F_Logs);
}

NO_CHAVE *FuncaoHashing(HASHING *H, void *X,void *NChave,char *type,char *log_file)
{
    FILE *F_Logs = fopen(log_file, "a");
    time_t now = time(NULL) ;
    fprintf(F_Logs, "Entrei em %s na data %s\n", __FUNCTION__, ctime(&now));

    if (!H) return NULL;
    if (!H->LChaves) return NULL;

    NO_CHAVE *P = H->LChaves->Inicio;
    while (P)
    {
        if(stricmp(type, "char") == 0){
            if (stricmp(P->KEY, NChave) == 0){
                return P;
            }
        }

        else{
            if (P->KEY== NChave){
                return P;
            }
        }
        P = P->Prox;
    }

    fprintf(F_Logs, "Terminou %s na data %s\n", __FUNCTION__, ctime(&now));
    fclose(F_Logs);

    return NULL;
}

void ShowHashing(HASHING *H,void (*f)(void *),char *type,char *log_file)
{
    FILE *F_Logs = fopen(log_file, "a");
    time_t now = time(NULL) ;
    fprintf(F_Logs, "Entrei em %s na data %s\n", __FUNCTION__, ctime(&now));

    if (!H) return;
    if (!H->LChaves) return;

    NO_CHAVE *P = H->LChaves->Inicio;

    while (P)
    {
        if(stricmp(type, "char") == 0){
            printf("CAT --> [%s] [%d]\n", P->KEY,P->DADOS->NEL);
        }
        else{
           printf("CAT --> [%s] [%d]\n", P->KEY,P->DADOS->NEL);
        };

        ShowLista(P->DADOS,f,log_file);
        P = P->Prox;
    }

    fprintf(F_Logs, "Terminou %s na data %s\n", __FUNCTION__, ctime(&now));
    fclose(F_Logs);
}

void *PesquisarHashing(HASHING *H,void (*f)(void *,void *,void *),void *word,char *log_file)
{
    FILE *F_Logs = fopen(log_file, "a");
    time_t now = time(NULL) ;
    fprintf(F_Logs, "Entrei em %s na data %s\n", __FUNCTION__, ctime(&now));

    if (!H) return NULL;
    if (!H->LChaves) return NULL;
    NO_CHAVE *L = H->LChaves->Inicio;

    void *T;
    while (L)
    {
        T=PesquisarLista(L->DADOS,f,word,log_file);
        if(T!=NULL){
            return T;
        }
        L = L->Prox;
    }

    fprintf(F_Logs, "Terminou %s na data %s\n", __FUNCTION__, ctime(&now));
    fclose(F_Logs);
    return NULL;
}

