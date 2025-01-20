#include "LivroJornal.h"

// Construtor
LivroJornal::LivroJornal(int novoID,string novoTitulo, string novoAutor, int novoAno, int novaSemana)
: Livro(novoID,novoTitulo,novoAutor), ano(novoAno),semana(novaSemana){
    titulo = novoTitulo;
    autor = novoAutor;
    ano= novoAno;
    semana= novaSemana;
    idTipo=5;
};

void LivroJornal::Show() {
    cout<<"ID="<<getId()<<endl;
    cout<<"Titulo="<<getTitulo()<<endl;
    cout<<"Autor="<<getAutor()<<endl;
    cout<<"Data="<<getSemana()<<"/"<<getAno()<<endl;
    cout<<"Tipo= Jornal-"<<getIdTipo()<<endl;
    cout<<"\n"<<endl;
};

void LivroJornal::Edit() {
    string novoTitulo,novoAutor;
    int novaSemana,novoAno;

    cout << "Digite um novo titulo: ";
    cin >> novoTitulo;
    setTitulo(novoTitulo);

    cout << "Digite um novo nome do autor: ";
    cin >> novoAutor;
    setAutor(novoAutor);

    cout << "Digite uma nova semana: ";
    cin >> novaSemana;
    setSemana(novaSemana);

    cout << "Digite uma novo ano: ";
    cin >> novoAno;
    setSemana(novoAno);

    cout<<"\n"<<endl;
};

LivroJornal::~LivroJornal() {}