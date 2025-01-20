
#ifndef UTEIS_H
#define UTEIS_H

#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <chrono>
#include <ctime>

using namespace std;

class Uteis
{
public:
    static void limparTela();

    static bool ImparOuPar(int x);
    static int AleatorioEntre(int a, int b);
    static vector <int> AleatorioDiferentes(int a);
    static bool chance50Porcento();
    static int Eixoy(int q){
        return q/4;
    }
    static int Eixox(int q){
        return q%4;
    }
    //static bool Verificar(int a, int b);
    static int MaiorElementoVector(vector<int>& VectorAAnalisar);
    tm criarData(int dia, int mes, int ano);
    static tm obterDataAtual();
};

#endif //UTEIS_H
