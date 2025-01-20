#include "Biblioteca.h"
#include "Emprestimo.h"
#include "Uteis.h"

Uteis u;

void Biblioteca::registrarLivro() {
    int tipoLivro;
    string titulo, autor;

    cout << "Digite o titulo: ";
    cin.ignore();
    getline(cin, titulo);

    cout << "Digite o autor: ";
    getline(cin, autor);

    cout << "Selecione o tipo de livro:\n"
         << "1. Ficcao\n"
         << "2. Cientifico\n"
         << "3. Educativo\n"
         << "4. Revista\n"
         << "5. Jornal\n"
         << "0. Exit\n"
         << "Opcao: ";
    cin >> tipoLivro;

    if (tipoLivro < 1 || tipoLivro > 5) {
        if(tipoLivro==0) {
            return;
        }
        cout << "Opção inválida! Tente novamente.\n";
        system("cls");
        exibirLivrosPorCategoria();
    }

    Livro* novoLivro = nullptr;

    switch (tipoLivro) {
        case 1: {
            string genero;
            cout << "Digite o genero: ";
            cin.ignore();
            getline(cin, genero);
            novoLivro = new LivroFiccao(LLivro.size() + 1, titulo, autor, genero);
            break;
        }
        case 2: {
            string area;
            cout << "Digite a area: ";
            cin.ignore();
            getline(cin, area);
            novoLivro = new LivroCientifico(LLivro.size() + 1, titulo, autor, area);
            break;
        }
        case 3: {
            string nivelEnsino;
            cout << "Digite o nivel de ensino: ";
            cin.ignore();
            getline(cin, nivelEnsino);
            novoLivro = new LivroEducativo(LLivro.size() + 1, titulo, autor, nivelEnsino);
            break;
        }
        case 4: {
            int edicao;
            cout << "Digite a edicao: ";
            cin >> edicao;
            novoLivro = new LivroRevista(LLivro.size() + 1, titulo, autor, edicao);
            break;
        }
        case 5: {
            int semana, ano;
            cout << "Digite a semana: ";
            cin >> semana;
            cout << "Digite o ano: ";
            cin >> ano;
            novoLivro = new LivroJornal(LLivro.size() + 1, titulo, autor, ano, semana);
            break;
        }
        default:
            cout << "Opcao invalida. Tente novamente.\n";
            return;
    }

    if (novoLivro) {
        LLivro.push_back(novoLivro);
        cout << "Livro registrado com sucesso!\n";
        novoLivro->Show();
    }
}

void Biblioteca::exibirLivros() {
    system("cls");
    if (LLivro.empty()) {
        cout << "Não há livros cadastrados na biblioteca.\n";
        return;
    }

    int countL=0;

    cout << "Todos os Livros Registrados:\n";
    for (Livro* livro : LLivro) {
        cout << "-------------------------------------------------\n";
        livro->Show(); // Polimorfismo em ação
    }
    cout << "-------------------------------------------------\n";
    cout << "Total de Livros: " << LLivro.size() << "\n";
}

void Biblioteca::exibirLivrosPorCategoria() {
    int tipoLivro;
    cout << "Selecione o tipo de livro que deseja listar:\n";
    cout << "1. Ficcao\n";
    cout << "2. Cientifico\n";
    cout << "3. Educativo\n";
    cout << "4. Revista\n";
    cout << "5. Jornal\n";
    cout << "Opcao: ";
    cin >> tipoLivro;

    // Validação da entrada
    if (tipoLivro < 1 || tipoLivro > 5) {
        cout << "Opcao invalida! Por favor, selecione entre 1 e 5.\n";
        return;
    }

    system("cls");
    cout << "Livros do Tipo " << tipoLivro << ":\n";
    bool encontrou = false;

    int countLivros = 0;
    // Iterar sobre a lista de livros
    for (Livro* livro : LLivro) {
        if (livro->getIdTipo() == tipoLivro) {
            cout << "-------------------------------------------------\n";
            livro->Show();
            encontrou = true;
            ++countLivros;
        }
    }

    if (!encontrou) {
        cout << "Nenhum livro encontrado deste tipo.\n";
    }

    if (countLivros !=0) {
        cout << "\n-------------------------------------------------\n";
        cout << "Total de livros da categoria " << tipoLivro<<": "<< countLivros  << endl;
    }
}

void Biblioteca::editarLivro() {
    int idLivro;
    cout << "Digite o ID do livro que deseja editar: ";
    cin >> idLivro;

    Livro* livroEncontrado;
    for (Livro* livro : LLivro) {
        if (livro->getId() == idLivro) {
            livroEncontrado = livro;
            break;
        }
    }

    if (!livroEncontrado) {
        cout << "Livro nao encontrado!\n";
        return;
    }

    cout << "Editando o seguinte livro:\n";
    livroEncontrado->Show();
    livroEncontrado->Edit(); // Polimorfismo em ação
}


void Biblioteca::registrarLeitor() {
    int tipoLeitor;
    string nome;
    int idade;

    cout << "Digite o nome do leitor: ";
    cin.ignore();
    getline(cin, nome);

    cout << "Digite a idade do leitor: ";
    cin >> idade;

    cout << "Selecione o tipo de leitor:\n"
         << "1. Comum\n"
         << "2. Estudante\n"
         << "3. Professor\n"
         << "4. Senior\n"
         << "Opcao: ";
    cin >> tipoLeitor;

    Leitor* novoLeitor;

    switch (tipoLeitor) {
        case 1:
            novoLeitor = new LeitorComum(LLeitor.size() + 1, nome, idade);
        break;
        case 2:
            novoLeitor = new LeitorEstudante(LLeitor.size() + 1, nome, idade);
        break;
        case 3:
            novoLeitor = new LeitorProfessor(LLeitor.size() + 1, nome, idade);
        break;
        case 4:
            novoLeitor = new LeitorSenior(LLeitor.size() + 1, nome, idade);
        break;
        default:
            cout << "Opção invalida! Tente novamente.\n";
        return;
    }

    if (novoLeitor) {
        LLeitor.push_back(novoLeitor);
        cout << "Leitor registrado com sucesso!\n";
        novoLeitor->Show(); // Polimorfismo em ação
    }
}

void Biblioteca::exibirLeitor() {
    if (LLeitor.empty()) {
        cout << "Nao ha leitores cadastrados.\n";
        return;
    }

    cout << "Todos os Leitores:\n";
    for (Leitor* leitor : LLeitor) {
        cout << "-------------------------------------------------\n";
        leitor->Show();
    }
    cout << "-------------------------------------------------\n";
    cout << "Total de Leitores: " << LLeitor.size() << "\n";
}



void Biblioteca::exibirLeitorPorTipo() {
    int tipoLeitor;
    cout << "Selecione o tipo de leitor que deseja listar:\n";
    cout << "1. Comum\n";
    cout << "2. Estudante\n";
    cout << "3. Professor\n";
    cout << "4. Senior\n";
    cout << "Opcao: ";
    cin >> tipoLeitor;

    if (tipoLeitor < 1 || tipoLeitor > 4) {
        cout << "Opção invalida! Tente novamente.\n";
        return;
    }

    system("cls");
    cout << "Leitores do Tipo " << tipoLeitor << ":\n";
    bool encontrou = false;
    int countLeitores = 0;

    for (Leitor* leitor : LLeitor) {
        if (leitor->getIdTipo() == tipoLeitor) {
            cout << "-------------------------------------------------\n";
            leitor->Show();
            encontrou = true;
            ++countLeitores;
        }
    }

    if (!encontrou) {
        cout << "Nenhum leitor encontrado deste tipo.\n";
    }

    if (countLeitores !=0) {
        cout << "\n-------------------------------------------------\n";
        cout << "Total de leitor encontrado do tipo " << tipoLeitor <<": "<< countLeitores  << endl;
    }
}


void Biblioteca::editarLeitor() {
    int idLeitor;
    cout << "Digite o id do livro que quer editar: ";
    cin >> idLeitor;

    Leitor* leitorEncontrado;

    for(list<Leitor*>::iterator it = LLeitor.begin(); it!=LLeitor.end(); ++it) {
        if((*it)->getId()==idLeitor) {
            leitorEncontrado=(*it);
            break;
        }
    }

    if(!leitorEncontrado){cout << "Digite um id valido, pode listar os livros e depois pegar seu id. ";}
    else {
        system("cls");
        cout << "Livro Selecionado:"<<endl;
        leitorEncontrado->Show();
        cout << "_____________________________________________________________"<<endl;
        leitorEncontrado->Edit();
    }
}

void Biblioteca::registrarEmprestimo() {
    int idLivro, idLeitor;
    cout << "Digite o ID do livro a ser emprestado: ";
    cin >> idLivro;
    cout << "Digite o ID do leitor: ";
    cin >> idLeitor;

    Livro* livroSelecionado;
    Leitor* leitorSelecionado;

    for (Livro* livro : LLivro) {
        if (livro->getId() == idLivro) {
            livroSelecionado = livro;
            break;
        }
    }

    for (Leitor* leitor : LLeitor) {
        if (leitor->getId() == idLeitor) {
            leitorSelecionado = leitor;
            break;
        }
    }

    if (!livroSelecionado || !leitorSelecionado) {
        cout << "Livro ou leitor nao encontrado.\n";
        return;
    }

    for (Emprestimo* emprestimo : LEmprestimo) {
        if (emprestimo->getLivro() == livroSelecionado && !emprestimo->getDevolvido()==1) {
            cout << "Este livro ja esta emprestado.\n";
            return;
        }
    }

    tm dataEmprestimo = Uteis::obterDataAtual();
    tm dataDevolucao = dataEmprestimo;
    dataDevolucao.tm_mday += leitorSelecionado->getPrazoMaximo(); // Prazo com base no tipo de leitor
    mktime(&dataDevolucao);

    Emprestimo* novoEmprestimo = new Emprestimo(LEmprestimo.size() + 1,leitorSelecionado,livroSelecionado, dataEmprestimo);
    LEmprestimo.push_back(novoEmprestimo);

    cout << "Emprestimo registrado com sucesso!\n";
}

void Biblioteca::exibirEmprestimo() {
    system("cls");
    int countL=0;

    cout << "Todos Emprestimos da biblioteca:\n";
    for(list<Emprestimo*>::iterator it = LEmprestimo.begin(); it!=LEmprestimo.end(); ++it) {
        cout << "____________________________________________________________:\n";
        (*it)->Show();
        countL++;
    }
    cout << "Total de Emprestimos [ "<< countL  << " ]\n";
}

void Biblioteca::exibirEmprestimoPorStatus() {
    int countL=0,statusOP;
    bool statusToCheck;

    system("cls");
    cout << "Selecione o status do Emprestimo\n";
    cout << "1.Ativos"<<endl;
    cout << "2.Encerrados"<<endl;

    cout << "Opcao: ";
    cin >> statusOP;

    cout << "Todos Emprestimos da biblioteca com status( "<< statusOP <<" ):"<<endl;

    if(statusOP==1 || statusOP==2) {
        statusToCheck= statusOP==1?false:true;
        for(list<Emprestimo*>::iterator it = LEmprestimo.begin(); it!=LEmprestimo.end(); ++it) {
            if((*it)->getDevolvido() == statusToCheck) {
                cout << "____________________________________________________________:"<<endl;;
                (*it)->Show();
                countL++;
            }
        }
    }
    else {
        cout << "Digitou um status nao existente"<<endl;;
    }

    cout << "Total de Livros [ "<< countL  << " ]\n";
}

void Biblioteca::relatorioEmprestimo() {
    list<int> LTiposLivros = {1, 2, 3, 4, 5};
    list<int> LTiposLeitores = {1, 2, 3, 4};

    map<int, int> contagemEmprestimosTLivro;
    map<int, map<int, int>> contagemEmprestimosTLivroLeitor;


    for (list<Emprestimo*>::iterator it = LEmprestimo.begin(); it != LEmprestimo.end(); ++it) {
        Livro *L = (*it)->getLivro();
        Leitor *LE = (*it)->getLeitor();
        int idLivroTipo = L->getIdTipo();
        int idLeitorTipo = LE->getIdTipo();

        cout << "Debug: Livro Tipo=" << idLivroTipo << ", Leitor Tipo=" << idLeitorTipo << endl;

        contagemEmprestimosTLivro[idLivroTipo]++;
        contagemEmprestimosTLivroLeitor[idLivroTipo][idLeitorTipo]++;
    }

    cout << "Relatorio de Emprestimos por Tipo de Livro:" << endl;
    for (auto& livroEntry : contagemEmprestimosTLivro) {
        int tipoLivro = livroEntry.first;
        int totalEmprestimos = livroEntry.second;

        cout << "Tipo de Livro " << tipoLivro << ": " << totalEmprestimos << " emprestimos" << endl;

        int maxRequisicoes = 0;
        int tipoLeitorMaisRequisitou = -1;

        for (auto& leitorEntry : contagemEmprestimosTLivroLeitor[tipoLivro]) {
            int tipoLeitor = leitorEntry.first;
            int qtdEmprestimos = leitorEntry.second;

            if (qtdEmprestimos > maxRequisicoes) {
                maxRequisicoes = qtdEmprestimos;
                tipoLeitorMaisRequisitou = tipoLeitor;
            }
        }

        if (tipoLeitorMaisRequisitou != -1) {
            cout << "   Tipo de Leitor que mais requisitou: " << tipoLeitorMaisRequisitou
                 << " (" << maxRequisicoes << " emprestimos)" << endl;
        } else {
            cout << "   Nenhum leitor requisitou este tipo de livro." << endl;
        }
    }
}

void Biblioteca::devolucao() {
    int idLivro;
    cout << "Digite o ID do livro que deseja devolver: ";
    cin >> idLivro;

    Emprestimo* emprestimoEncontrado;

    for (Emprestimo* emprestimo : LEmprestimo) {
        if (emprestimo->getLivro()->getId() == idLivro && !emprestimo->isDevolvido()) {
            emprestimoEncontrado = emprestimo;
            break;
        }
    }

    if (!emprestimoEncontrado) {
        cout << "Nenhum empréstimo ativo encontrado para este livro.\n";
        return;
    }

    // Marcar como devolvido
    emprestimoEncontrado->setDevolvido(true);
    cout << "Devolução registrada com sucesso!\n";

    // Calcular multa (se aplicável)
    tm dataAtual = Uteis::obterDataAtual();
    if (difftime(mktime(&dataAtual), mktime(&emprestimoEncontrado->getDataDevolucao())) > 0) {
        Leitor* leitor = emprestimoEncontrado->getLeitor();
        double multa = leitor->calcularMulta(difftime(mktime(&dataAtual), mktime(&emprestimoEncontrado->getDataDevolucao())));
        cout << "Multa aplicada: " << multa << " euros.\n";
    } else {
        cout << "Nenhuma multa aplicada.\n";
    }
}


Biblioteca::~Biblioteca() {
    for (Livro* livro : LLivro) delete livro;
    for (Leitor* leitor : LLeitor) delete leitor;
    for (Emprestimo* emprestimo : LEmprestimo) delete emprestimo;
}
