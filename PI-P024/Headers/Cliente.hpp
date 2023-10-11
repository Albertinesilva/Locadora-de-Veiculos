#ifndef CLIENTE_HPP
#define CLIENTE_HPP

#include <iostream>

using namespace std;

class Cliente
{
private:
  string nome;
  string cpf;
  string endereco;
  string telefone;

public:
  Cliente(string nome, string cpf, string endereco, string telefone);

  Cliente();

  ~Cliente();

  string getNome();
  void setNome(string nome);

  string getCpf();
  void setCpf(string cpf);

  string getEndereco();
  void setEndereco(string endereco);

  string getTelefone();
  void setTelefone(string telefone);

  void imprimir();
};

#endif