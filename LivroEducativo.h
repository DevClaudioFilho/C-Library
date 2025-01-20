#ifndef LIVROEDUCATIVO_H
#define LIVROEDUCATIVO_H

#include "Livro.h"

#include <string>
#include <iostream>

class LivroEducativo:public Livro {
    public:
        // Construtor
        LivroEducativo(int id,string titulo, string autor, string nivelEnsino);

        // Destruidor virtual para suporte a herança
        virtual ~LivroEducativo();

        // Métodos de acesso
        void Show();
        string getNivelEnsino() { return nivelEnsino; }
        int getIdTipo() { return idTipo; }

        // Métodos de modificação
        void Edit();
        void setNivelEnsino(string novoNivelEnsino) {
            nivelEnsino = novoNivelEnsino;
        }

    protected:
        int idTipo = 3;
        string nivelEnsino;
};



#endif //LIVROEDUCATIVO_H
