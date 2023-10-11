#ifndef USUARIO_HPP
#define USUARIO_HPP

#include <iostream>

using namespace std;

class Usuario
{
private:
  string nome;
  string email;
  string senha;
  string dataDeNascimento;
  string telefone;
  int numeroDeSeguidores;
  int numeroDeSeguindo;
  int numeroDeTweets;
  int numeroDeLikes;

public:
  Usuario();
  ~Usuario();
};

#endif
