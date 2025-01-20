#ifndef LEITORSENIOR_H
#define LEITORSENIOR_H

#include "Leitor.h"
#include <string>

using namespace std;

class LeitorSenior:public Leitor {
    public:
        // Construtor
        LeitorSenior(int id, string nome, int idade);

        // Destruidor virtual para suporte a herança
        virtual ~LeitorSenior();

        // Métodos de acesso
        void Show();
        int getIdTipo(){ return idTipo;}
        int getPrazoMaximo(){ return prazoMaximo;}
        double getTaxaMulta() { return taxaMulta; }

        void Edit();

    protected:
        int idTipo = 4;
        int prazoMaximo = 40;
        double taxaMulta = 1.5;
};


#endif //LEITORSENIOR_H
