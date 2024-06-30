#include "Locais.h"

LOCAL *CriarLocal(int _codigo, char *_nome,char *log_file){
    FILE *F_Logs = fopen(log_file, "a");
    time_t now = time(NULL) ;
    fprintf(F_Logs, "Entrei em %s na data %s\n", __FUNCTION__, ctime(&now));
    fclose(F_Logs);

    //Pre validacoes

    //

    LOCAL *L = (LOCAL *)malloc(sizeof(LOCAL));
    L->CODIGO = _codigo;
    L->NOME = (char *)malloc((strlen(_nome) + 1)*sizeof(char));
    strcpy(L->NOME, _nome);

    F_Logs = fopen(log_file, "a");
    now = time(NULL) ;
    fprintf(F_Logs, "Sai em %s na data %s\n", __FUNCTION__, ctime(&now));
    fclose(F_Logs);
    return L;
};

int ValidaLocalCodigo(int _codigo,int _option,char *log_file){
    // OPTION
    // 1-DISTRITO
    // 2-CONCELHO
    // 3-FREGUESIA
    FILE *F_Logs = fopen(log_file, "a");
    time_t now = time(NULL) ;
    fprintf(F_Logs, "Entrei em %s na data %s\n", __FUNCTION__, ctime(&now));
    fclose(F_Logs);

    if(_option==1 && _codigo>=1 && _codigo<=18){
        F_Logs = fopen(log_file, "a");
        now = time(NULL) ;
        fprintf(F_Logs, "Sai em %s na data %s\n", __FUNCTION__, ctime(&now));
        fclose(F_Logs);
        return 1;
    };
    if(_option==2 && _codigo>=0101 && _codigo<=1824) {
        F_Logs = fopen(log_file, "a");
        now = time(NULL) ;
        fprintf(F_Logs, "Sai em %s na data %s\n", __FUNCTION__, ctime(&now));
        fclose(F_Logs);
        return 1;
    }
    if(_option==3 && _codigo>=010103 && _codigo<=182415){
        F_Logs = fopen(log_file, "a");
        now = time(NULL) ;
        fprintf(F_Logs, "Sai em %s na data %s\n", __FUNCTION__, ctime(&now));
        fclose(F_Logs);
        return 1;
    }

    now = time(NULL) ;
    fprintf(F_Logs, "Sai em %s na data %s\n", __FUNCTION__, ctime(&now));
    fclose(F_Logs);
    return 0;

};

void DestruirLocal(LOCAL *P,char *log_file){
    if(!P);
    free(P->CODIGO);
    free(P->NOME);
    free(P);
};

int PesquisarLocalCodigo(LOCAL *P, int _codigo,char *log_file){
    FILE *F_Logs = fopen(log_file, "a");
    time_t now = time(NULL) ;
    fprintf(F_Logs, "Entrei em %s na data %s\n", __FUNCTION__, ctime(&now));
    fclose(F_Logs);

    if(P->CODIGO == _codigo)
    {
        F_Logs = fopen(log_file, "a");
        now = time(NULL) ;
        fprintf(F_Logs, "Terminou em %s na data %s\n", __FUNCTION__, ctime(&now));
        fclose(F_Logs);
        return 1;
    }

    else
        F_Logs = fopen(log_file, "a");
        now = time(NULL) ;
        fprintf(F_Logs, "Terminou em %s na data %s\n", __FUNCTION__, ctime(&now));
        fclose(F_Logs);
        return 0;
};

int PesquisarLocalNome(LOCAL *P, char *_nome,char *log_file){
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
};
