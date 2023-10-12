#ifndef ALUGUEL_HPP
#define ALUGUEL_HPP
#include "Usuario.hpp"
#include "Livro.hpp"

#include <iostream>
#include <ctime>

using namespace std;

typedef struct tm Data;

class Aluguel
{
  private:

    static int contadorDeAlugueis;
    int id;
    bool ativo;
    Usuario* usuario;
    Livro* livro;
    Data dataDeAluguel;

  public:

    Aluguel();

    ~Aluguel();

    Aluguel(const bool ativo, Usuario* usuario, Livro* livro, const Data dataDeAluguel);

    static int getContadorDeAlugueis();
    static void setContadorDeAlugueis(int contadorDeAlugueis);

    int getId();
    void setId(int id);

    bool getAtivo();
    void setAtivo(bool ativo);

    Usuario* getUsuario();
    void setUsuario(Usuario* usuario);

    Livro* getLivro();
    void setLivro(Livro* livro);

    Data getDataDeAluguel();
    void setDataDeAluguel(Data dataDeAluguel);

    void mostrarAluguel();

};

#endif