#include "../Headers/Livro.hpp"

int Livro::quantidadeDeIdentificadores = 0;

Livro::Livro(){}

Livro::Livro(const string &titulo, const string &author, const int &numPaginas, const int &numDeCopiasDisponiveis) 
: titulo(titulo), author(author), numPaginas(numPaginas), numDeCopiasDisponiveis(numDeCopiasDisponiveis){
    
    Livro::quantidadeDeIdentificadores++;
    setId(Livro::quantidadeDeIdentificadores);
}

int Livro::getQuantidadeDeIdentificadores()
{
    return quantidadeDeIdentificadores;
}

void Livro::setQuantidadeDeIdentificadores(int quantidadeDeIdentificadores)
{
    Livro::quantidadeDeIdentificadores = quantidadeDeIdentificadores;
}

int Livro::getId(){
    return this->id;
}

void Livro::setId(int id){
    this->id = id;
}

string Livro::getAuthor()
{
    return this->author;
}

void Livro::setAuthor(string author)
{
    this->author = author;
}

string Livro::getTitulo()
{
    return this->titulo;
}

void Livro::setTitulo(string titulo)
{
    this->titulo = titulo;
}

int Livro::getNumPaginas()
{
    return this->numPaginas;
}

void Livro::setNumPaginas(int numPaginas)
{
    this->numPaginas = numPaginas;
}

int Livro::getNumDeCopiasDisponiveis()
{
    return this->numDeCopiasDisponiveis;
}

void Livro::setNumDeCopiasDisponiveis(int numDeCopiasDisponiveis)
{
    this->numDeCopiasDisponiveis = numDeCopiasDisponiveis;
}

void Livro::mostrarLivro()
{
    cout << "\n\tID: " << getId();
    cout << "\n\tTitulo: " << getTitulo();
    cout << "\n\tAutor: " << getAuthor();
    cout << "\n\tNúmero de páginas: " << getNumPaginas();
    cout << "\n\tNúmero de cópias disponíveis: " << getNumDeCopiasDisponiveis();
    // cout << "\n\t====================================\n";
}