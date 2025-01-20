#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include <list>
#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

#include "Livro.h"
#include "Leitor.h"
#include "LivroFiccao.h"
// #include "Emprestimo.h"


#include "Emprestimo.h"
#include "Uteis.h"
#include "LeitorComum.h"
#include "LeitorEstudante.h"
#include "LeitorProfessor.h"
#include "LeitorSenior.h"
#include "LivroJornal.h"

#include "LivroFiccao.h"
#include "LivroCientifico.h"
#include "LivroEducativo.h"
#include "LivroRevista.h"


using namespace std;

class Biblioteca {
public:
    Biblioteca() = default;
    ~Biblioteca();

    void registrarLivro();
    void exibirLivros();
    void exibirLivrosPorCategoria();
    void editarLivro();

    void registrarLeitor();
    void exibirLeitor();
    void exibirLeitorPorTipo();
    void editarLeitor();

    void registrarEmprestimo();
    void exibirEmprestimo();
    void exibirEmprestimoPorStatus();
    void devolucao();
    void relatorioEmprestimo();
    void prorrogarEmprestimo();


    void registrarLeitor(Leitor* leitor);

    void realizarEmprestimo(Leitor* leitor, Livro* livro);
    // void devolverLivro(Emprestimo& emprestimo);
    // void prorrogarEmprestimo(Emprestimo& emprestimo, int diasExtras);

    void reservarLivro(const string& tituloLivro, const string& nomeLeitor);
    void cancelarReserva(const string& tituloLivro);
    void exibirReservas() const;

    void gerarRelatorioEmprestimosPorTipo() const;
    void gerarRelatorioMultasPendentes() const;
    void exibirHistoricoLeitor(const string& nomeLeitor) const;

    void editarInformacoesLivro(const string& tituloLivro);
    void editarInformacoesLeitor(const string& nomeLeitor);

    void carregarDados();
    void salvarDados();

    Livro* buscarLivro(const string& titulo);
    Leitor* buscarLeitor(const string& nome);


    void exibirLeitores();


    // Emprestimo* buscarEmprestimo(const string& tituloLivro);
    void forcarMulta(const string& tituloLivro, const string& dataDevolucao);



private:
    list<Livro*> LLivro;
    list<Leitor*> LLeitor;
    list<Emprestimo*> LEmprestimo;
};

#endif
