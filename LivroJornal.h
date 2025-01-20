#ifndef LIVROJORNAL_H
#define LIVROJORNAL_H

#include "Livro.h"

#include <string>
#include <iostream>

class LivroJornal:public Livro {
    public:
        // Construtor
        LivroJornal(int id,string titulo, string autor, int semana, int ano);

        // Destruidor virtual para suporte a herança
        virtual ~LivroJornal();

        // Métodos de acesso
        void Show();
        int getSemana() { return semana; }
        int getAno() { return ano; }
        int getIdTipo() { return idTipo; }


        // Métodos de modificação
        void Edit();
        void setSemana(int novaSemana) {
            semana = novaSemana;
        }
        void setAno(int novaAno) {
            ano = novaAno;
        }

    protected:
        int idTipo = 5;
        int semana;
        int ano;
};



#endif //LIVROJORNAL_H
