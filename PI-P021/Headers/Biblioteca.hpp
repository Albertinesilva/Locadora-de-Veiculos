#ifndef BIBLIOTECA_HPP
#define BIBLIOTECA_HPP
#include "Livro.hpp"
#include "Usuario.hpp"
#include "Aluguel.hpp"
#include <vector>

class Biblioteca
{
private:
    vector<Livro> listaLivros;
    vector<Usuario> listaUsuario;
    vector<Aluguel> listaAlugueis;

public:
    vector<Livro> *getLivros();
    vector<Usuario> *getUsuarios();
    vector<Aluguel> *getAlugueis();

    static void pause();
    static void limpaTela();

    static void menuPrincipal(vector<Aluguel> alugueis, vector<Usuario> usuarios, vector<Livro> livros);
    static void mostraMenuPrincipal();
    static void mostraMenuSecundario();

    static void menuUsuarios(vector<Usuario> &usuarios);
    static void menuLivros(vector<Livro> &livros);
    static void menuAluguel(vector<Aluguel> &alugueis, vector<Usuario> &usuarios, vector<Livro> &livros);
    static void mostraMenuAluguel();

    static void insereUsuario(vector<Usuario> &usuarios);
    static void encontraUsuario(vector<Usuario> &usuarios);
    static void listarUsuarios(vector<Usuario> &usuarios);
    static void excluirUsuario(vector<Usuario> &usuarios);
    static void modificarUsuario(vector<Usuario> &usuarios);
    static void recuperaUsuarios(vector<Usuario> &usuarios);

    static void insereLivros(vector<Livro> &livros);
    static void encontraLivros(vector<Livro> &livros);
    static void listarLivros(vector<Livro> &livros);
    static void excluirLivros(vector<Livro> &livros);
    static void modificarLivros(vector<Livro> &livros);
    static void recuperaLivros(vector<Livro> &livros);

    static void insereAluguel(vector<Usuario> &usuarios, vector<Livro> &livros, vector<Aluguel> &alugueis);
    static void encontrarAluguel(vector<Aluguel> &alugueis);
    static void finalizarAluguel(vector<Aluguel> &alugueis);
    static void listarAlugueisAtivos(vector<Aluguel> &alugueis);
    static void listarAlugueisInativos(vector<Aluguel> &alugueis);
    static void listarAluguelPorCliente(vector<Aluguel> &alugueis);
    static void recuperaAlugueis(vector<Aluguel> &alugueis, vector<Usuario> &usuarios, vector<Livro> &livros);

};

#endif