#ifndef LIVRO_HPP
#define LIVRO_HPP

#include <iostream>
#include <vector>

using namespace std;

class Livro
{

private:

    static int quantidadeDeIdentificadores;
    int id;
    string titulo;
    string author;
    int numPaginas;
    int numDeCopiasDisponiveis;

public:

    Livro();

    Livro(const string &titulo, const string &author, const int &numPaginas, const int &numDeCopiasDisponiveis);

    static int getQuantidadeDeIdentificadores();
    static void setQuantidadeDeIdentificadores(int quantidadeDeIdentificadores);

    int getId();
    void setId(int id);

    string getTitulo();
    void setTitulo(string titulo);

    string getAuthor();
    void setAuthor(string author);

    int getNumPaginas();
    void setNumPaginas(int numPaginas);

    int getNumDeCopiasDisponiveis();
    void setNumDeCopiasDisponiveis(int numDeCopiasDisponiveis);

    void mostrarLivro();
};

#endif
