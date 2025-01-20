#include "Emprestimo.h"

Emprestimo::Emprestimo(int novoId,Leitor* novoLeitor, Livro* novoLivro, tm novaDataEmprestimo) {
    id=novoId;
    leitor=novoLeitor;
    livro=novoLivro;
    dataEmprestimo=novaDataEmprestimo;
    devolvido=false;

    tm novDataDevolucao = dataEmprestimo;
    novDataDevolucao.tm_mday += leitor->getPrazoMaximo();
    mktime(&novDataDevolucao);

    dataDevolucao= novDataDevolucao;
}

void Emprestimo::Show() {
    cout<<"ID= "<<getId()<<endl;
    cout<<"Livro= "<<livro->getId()<<"-"<<livro->getTitulo()<<endl;
    cout<<"Leitor= "<<leitor->getId()<<"-"<<leitor->getNome()<<endl;
    cout << "Data de Emprestimo: " << put_time(&dataEmprestimo, "%d-%m-%Y") << endl;
    cout << "Data de Devolucao: " << put_time(&dataDevolucao, "%d-%m-%Y") << endl;
    cout << "Devolvido: " << devolvido << endl;

    cout<<"\n"<<endl;
};