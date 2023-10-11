#include "../Headers/Cliente.hpp"

Cliente::Cliente(string nome, string cpf, string endereco, string telefone) : nome(nome), cpf(cpf), endereco(endereco), telefone(telefone)
{
  this->nome = nome;
  this->cpf = cpf;
  this->endereco = endereco;
  this->telefone = telefone;
}

Cliente::Cliente(){}

Cliente::~Cliente(){}

void Cliente::setNome(string nome)
{
  this->nome = nome;
}

string Cliente::getNome()
{
  return this->nome;
}

void Cliente::setEndereco(string endereco)
{
  this->endereco = endereco;
}

string Cliente::getEndereco()
{
  return this->endereco;
}

void Cliente::setCpf(string cpf)
{
  this->cpf = cpf;
}

string Cliente::getCpf()
{
  return this->cpf;
}

void Cliente::setTelefone(string telefone)
{
  this->telefone = telefone;
}

string Cliente::getTelefone()
{
  return this->telefone;
}

