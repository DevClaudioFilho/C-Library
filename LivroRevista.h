#ifndef LIVROREVISTA_H
#define LIVROREVISTA_H

#include "Livro.h"

#include <string>
#include <iostream>

class LivroRevista:public Livro {
    public:
        // Construtor
        LivroRevista(int id,string titulo, string autor, int edicao);

        // Destruidor virtual para suporte a herança
        virtual ~LivroRevista();

        // Métodos de acesso
        void Show();
        int getEdicao() { return edicao; }
        int getIdTipo() { return idTipo; }


        // Métodos de modificação
        void Edit();
        void setEdicao(int novaEdicao) {
            edicao = novaEdicao;
        }

    protected:
        int idTipo = 4;
        int edicao;
};



#endif //LIVROREVISTA_H
