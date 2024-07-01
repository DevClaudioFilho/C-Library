#include "Pessoa.h"
#include "Data.h"
#include "Locais.h"
#include "Biblioteca.h"
#include "Livro.h"



/** \brief Aloca Memoria para uma Biblioteca
 *
 * \param _nome char* : Nome da Biblioteca
 * \param _logs char* : Ficheiro dos Logs
 * \return BIBLIOTECA* : Retorna o ponteiro para a biblioteca
 * \author Docentes & Alunos
 * \date   11/04/2024
 *
 */
BIBLIOTECA *CriarBiblioteca(char *_nome, char *_logs)
{
    BIBLIOTECA *Bib = (BIBLIOTECA *)malloc(sizeof(BIBLIOTECA));
    Bib->NOME = (char *)malloc((strlen(_nome) + 1) * sizeof(char));
    strcpy(Bib->NOME, _nome);
    strcpy(Bib->FICHEIRO_LOGS, _logs);
    Bib->HLivros = CriarHashing();
    Bib->LPessoas = CriarLista();
    Bib->LRequisicoes = CriarLista();

    Bib->LDistritos = CriarLista();
    Bib->LConcelhos = CriarLista();
    Bib->LFreguesias = CriarLista();

    return Bib;
}

/** \brief Funcao para Mostrar toda a Biblioteca
 *
 * \param B BIBLIOTECA* : Pnteiro para a Biblioteca
 * \return void
 * \author : Docentes e Alunos
 * \date   : 11/04/2024
 */

void ShowBiblioteca(BIBLIOTECA *B)
{
    FILE *F_Logs = fopen(B->FICHEIRO_LOGS, "a");
    time_t now = time(NULL) ;

    fprintf(F_Logs, "Entrei em %s na data %s\n", __FUNCTION__, ctime(&now));
    printf("NOME BIBLIOTECA = [%s]\n", B->NOME);
    printf("Livros: %d",B->HLivros->LChaves->NEL);
    printf("Pessoas: %d",B->LPessoas->NEL);

    fclose(F_Logs);
}

void DestruirBiblioteca(BIBLIOTECA *B)
{
    FILE *F_Logs = fopen(B->FICHEIRO_LOGS, "a");
    time_t now = time(NULL) ;
    fprintf(F_Logs, "Entrei em %s na data %s\n", __FUNCTION__, ctime(&now));

    // Vosso Codigo.....
    free (B->NOME);
    //DestruirLista(B->LPessoas,DestruirPessoa,B->FICHEIRO_LOGS);
    //DestruirHashing(B->HLivros,B->FICHEIRO_LOGS)
    //------
    free(B);

    fclose(F_Logs);
}

void ImportPessoas(BIBLIOTECA *B) {
    FILE *F_Pes = fopen("Requisitantes.txt", "r");
    if (!F_Pes) return;

    char *file_log = B->FICHEIRO_LOGS;
    char contents[2000];
    int ID, ID_FREGUESIA, dia, mes, ano;
    char NOME[200];

    while (fgets(contents, sizeof(contents), F_Pes) != NULL) {
        sscanf(contents, "%d\t%[^\t]\t%d-%d-%d\t%d", &ID, NOME, &dia, &mes, &ano, &ID_FREGUESIA);

        if (ValidarData(dia, mes, ano) && verificarID(ID, file_log)) {
            DATA *Dat = CriarData(dia, mes, ano);
            PESSOA *novaPessoa = CriarPessoa(ID, NOME, Dat, ID_FREGUESIA, file_log);
            if(novaPessoa){
                AddLista(B->LPessoas, novaPessoa, file_log);
            }
        }
    }

    fclose(F_Pes);
}


void ImportRequisicao(BIBLIOTECA *B) {
    FILE *F_Pes = fopen("Requisicao.txt", "r");
    if (!F_Pes) return;

    char *file_log = B->FICHEIRO_LOGS;
    char contents[2000];
    int ID, ID_FREGUESIA, diaE, mesE, anoE, diaR, mesR, anoR;
    char NOME[200];

    while (fgets(contents, sizeof(contents), F_Pes) != NULL) {
        sscanf(contents, "%d\t%[^\t]\t%d-%d-%d\t%d", &ID, NOME, &diaE, &mesE, &anoE,&diaR, &mesR, &anoR);

        if (ValidarData(diaE, mesE, anoE) && ValidarData(diaR, mesR, anoR) ) {
            DATA *DatE = CriarData(diaE, mesE, anoE);
            DATA *DatR = CriarData(diaR, mesR, anoR);
            REQUISICAO *novaPessoa = CriarRequisicaoImport(ID, NOME, Dat, ID_FREGUESIA, file_log);
            if(novaPessoa){
                AddLista(B->LPessoas, novaPessoa, file_log);
            }
        }
    }

    fclose(F_Pes);
}


void ImportLivro(BIBLIOTECA *B) {
    FILE *F_Pes = fopen("Livros.txt", "r");
    if (!F_Pes) return;

    char *file_log = B->FICHEIRO_LOGS;
    char contents[2000];

    int ISBN;
    char TITULO[2000];
    char AUTOR[2000];
    char AREA[200];
    int ANO_PLUBLICACAO;

    while (fgets(contents, sizeof(contents), F_Pes) != NULL) {
        sscanf(contents, "%d\t%[^\t\n]\t%[^\t\n]\t%[^\t\n]\t%d", &ISBN,TITULO,AUTOR,AREA,&ANO_PLUBLICACAO);

        LIVRO *novoLivro = CriarLivro(ISBN,TITULO,AUTOR,AREA,ANO_PLUBLICACAO,file_log);
        if(novoLivro) AddHashing(B->HLivros,novoLivro,novoLivro->AREA,"char",file_log);
    }

    fclose(F_Pes);
}

void ImportFreguesia(BIBLIOTECA *B) {
    FILE *F_Pes = fopen("freguesia.txt", "r");
    if (!F_Pes) return;

    char *file_log = B->FICHEIRO_LOGS;
    char contents[1024];
    int COD;
    char NOME[100];

    while (fgets(contents, sizeof(contents), F_Pes) != NULL) {
        sscanf(contents, "%d\t%[^\n]", &COD, NOME);

        if (ValidaLocalCodigo(COD,3,file_log)==1) {
            LOCAL *novaLocal = CriarLocal(COD,NOME, file_log);
            AddLista(B->LFreguesias, novaLocal, file_log);
        }
    }

    fclose(F_Pes);
}

void ImportConselhos(BIBLIOTECA *B) {
    FILE *F_Pes = fopen("concelhos.txt", "r");
    if (!F_Pes) return;

    char *file_log = B->FICHEIRO_LOGS;
    char contents[1024];
    int COD;
    char NOME[100];

    while (fgets(contents, sizeof(contents), F_Pes) != NULL) {
        sscanf(contents, "%d\t%[^\n]", &COD, NOME);

        if (ValidaLocalCodigo(COD,2,file_log)==1) {
            LOCAL *novaLocal = CriarLocal(COD,NOME, file_log);
            AddLista(B->LConcelhos, novaLocal, file_log);
        }
    }

    fclose(F_Pes);
}

void ImportDistritos(BIBLIOTECA *B) {
    FILE *F_Pes = fopen("distritos.txt", "r");
    if (!F_Pes) return;

    char *file_log = B->FICHEIRO_LOGS;
    char contents[1024];
    int COD;
    char NOME[100];

    while (fgets(contents, sizeof(contents), F_Pes) != NULL) {
        sscanf(contents, "%d\t%[^\n]", &COD, NOME);

        if (ValidaLocalCodigo(COD,1,file_log)==1) {
            LOCAL *novaLocal = CriarLocal(COD,NOME,file_log);
            AddLista(B->LDistritos, novaLocal, file_log);
        }
    }

    fclose(F_Pes);
}

int LoadFicheiroBiblioteca(BIBLIOTECA *B)
{
    FILE *F_Logs = fopen(B->FICHEIRO_LOGS, "a");
    time_t now = time(NULL) ;
    fprintf(F_Logs, "Entrei em %s na data %s\n", __FUNCTION__, ctime(&now));
    fclose(F_Logs);

    ImportPessoas(B);
    ImportConselhos(B);
    ImportDistritos(B);
    ImportFreguesia(B);
    ImportLivro(B);

    return EXIT_SUCCESS;
}

void ExportPessoas(BIBLIOTECA *B) {
    FILE *F_Pes = fopen("Requisitantes.txt", "w+");
    if (!F_Pes) return;

    NO *atual = B->LPessoas->Inicio;
    while (atual) {
        PESSOA *pes = atual->Info;
        DATA *dat = pes->NASCIMENTO;
        fprintf(F_Pes, "%d\t%s\t%d-%d-%d\t%d\n", pes->ID, pes->NOME, dat->DIA, dat->MES, dat->ANO, pes->ID_FREGUESIA);
        atual = atual->Prox;
    }

    fclose(F_Pes);
}


void ExportLivro(BIBLIOTECA *B) {
    FILE *F_Pes = fopen("Livros.txt", "w+");
    if (!F_Pes) return;

    NO_CHAVE *atual = B->HLivros->LChaves->Inicio;

    while (atual) {
        NO *dados = atual->DADOS->Inicio;
        while(dados){
            LIVRO *livro = dados->Info;
            fprintf(F_Pes, "%d\t%s\t%s\t%s\t%d\n", livro->ISBN,livro->TITULO,livro->AUTOR,livro->AREA,livro->ANO_PLUBLICACAO);
            dados=dados->Prox;
        }
        atual=atual->Prox;
    }

    fclose(F_Pes);
}


void InserirLog(char *_file,char *_string){
    FILE *F_Logs = fopen(_file, "a");
    fprintf(F_Logs, _string);
    fclose(F_Logs);

    free(F_Logs);
}
