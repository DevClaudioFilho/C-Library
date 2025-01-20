#ifndef EMPRESTIMO_H
#define EMPRESTIMO_H

#include "Livro.h"
#include "Leitor.h"

#include <ctime>
#include <iomanip> // Para manipulação de data/horas
#include <string>

using namespace std;


class Emprestimo {
public:
    Emprestimo(int id,Leitor* leitor, Livro* livro, tm dataEmprestimo);

    void setDevolvido(bool statusDevolucao) { devolvido=statusDevolucao; }
    void setDataDevolucao(tm data){ dataDevolucao=data; }
    void setDataLimite(tm data){ dataLimite=data; }
    void setMulta(double valor){ multa=valor; }
    void Show();


    int getId()  { return id; }
    Leitor* getLeitor()  { return leitor; }
    Livro* getLivro()  { return livro; }
    tm getDataEmprestimo() { return dataEmprestimo; }
    tm getDataLimite() { return dataLimite; }
    tm getDataDevolucao() { return dataEmprestimo; }
    bool getDevolvido() { return devolvido; }

private:
    int id;
    Leitor* leitor;
    Livro* livro;
    tm dataEmprestimo;
    tm dataLimite;
    tm dataDevolucao;
    bool devolvido=false;
    double multa=0;
};

#endif // EMPRESTIMO_H


