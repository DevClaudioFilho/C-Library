#include "Uteis.h"

int Uteis::AleatorioEntre(int a, int b) {
    if(a>b) return 0;
    return a + (rand() % (b - a + 1));
}

bool Uteis::ImparOuPar(int x) {        //utilizando bool pois é mais facil interpretar valores binarios
    return x % 2 == 0;                //true se for par | false se for impar
}

bool Uteis::chance50Porcento() {
    //srand(static_cast<unsigned int>(std::time(nullptr)));
    int randNum = rand();
    return randNum <= RAND_MAX / 2;
}

int Uteis::MaiorElementoVector(vector<int>& VectorAAnalisar) {
    if (VectorAAnalisar.empty()) {
        cout << "Erro: vetor vazio\n"; //por enquanto este output esta ativo durante a fase de teste
        return -1;
    }
    int maior = VectorAAnalisar[0];

    for (int i = 1; i < VectorAAnalisar.size(); ++i) {
        if (VectorAAnalisar[i] > maior) {
            maior = VectorAAnalisar[i];
        }
    }
    return maior;
}

void Uteis::limparTela() {
    cout << "\033[2J\033[1;1H";
}

tm Uteis::criarData(int dia, int mes, int ano) {
    tm data = {};
    data.tm_mday = dia;
    data.tm_mon = mes - 1; // Meses em `tm` vão de 0 a 11
    data.tm_year = ano - 1900; // Anos em `tm` são contados a partir de 1900

    // Normaliza a data
    mktime(&data);

    return data;
}

tm Uteis::obterDataAtual() {
    time_t agora = time(0); // Obtém o tempo atual em segundos desde 1 de janeiro de 1970
    tm* dataAtual = localtime(&agora); // Converte para a estrutura tm no horário local
    return *dataAtual;
}