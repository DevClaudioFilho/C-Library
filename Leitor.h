#ifndef LEITOR_H
#define LEITOR_H

#include <string>
#include <iostream>

using namespace std;

class Leitor {
    public:
        // Construtor
        Leitor(int id, string nome, int idade);

        // Destruidor virtual para suporte a herança
        virtual ~Leitor();

        // Métodos de acesso
        virtual void Show()=0;
        virtual int getPrazoMaximo()=0;
        virtual int getIdTipo() = 0;


        int getId(){ return id;}
        string getNome(){ return nome; }
        int getIdade() { return idade; }

        // Métodos de modificação
        virtual void Edit()=0;
        void setId(int novoID) {
            id = novoID;
        }

        void setNome(string novoNome) {
            nome = novoNome;
        }

        void setIdade(int novaIdade) {
            idade = novaIdade;
        }

    protected:
        int id;
        string nome;
        int idade;
};

#endif //LEITOR_H