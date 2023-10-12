#include "../Headers/Aluguel.hpp"

int Aluguel::contadorDeAlugueis = 0;

Aluguel::Aluguel() {}

Aluguel::~Aluguel() {}

Aluguel::Aluguel(bool ativo, Usuario *usuario, Livro *livro, Data dataDeAluguel)
{
  Aluguel::contadorDeAlugueis++;
  setId(Aluguel::getContadorDeAlugueis());
  setAtivo(ativo);
  setUsuario(usuario);
  setLivro(livro);
  setDataDeAluguel(dataDeAluguel);
}

int Aluguel::getContadorDeAlugueis()
{
  return contadorDeAlugueis;
}

void Aluguel::setContadorDeAlugueis(int contadorDeAlugueis)
{
  Aluguel::contadorDeAlugueis = contadorDeAlugueis;
}

int Aluguel::getId()
{
  return this->id;
}

void Aluguel::setId(int id)
{
  this->id = id;
}

bool Aluguel::getAtivo()
{
  return this->ativo;
}

void Aluguel::setAtivo(bool ativo)
{
  this->ativo = ativo;
}

Usuario *Aluguel::getUsuario()
{
  return this->usuario;
}

void Aluguel::setUsuario(Usuario *usuario)
{
  this->usuario = usuario;
}

Livro *Aluguel::getLivro()
{
  return this->livro;
}

void Aluguel::setLivro(Livro *livro)
{
  this->livro = livro;
}

Data Aluguel::getDataDeAluguel()
{
  return this->dataDeAluguel;
}

void Aluguel::setDataDeAluguel(Data dataDeAluguel)
{
  this->dataDeAluguel = dataDeAluguel;
}

void Aluguel::mostrarAluguel()
{
  cout << "\n\t========ALUGUEL========\n";

  cout << "\n\t=====cliente=====\n";
  cout << "ID: " << getId() << endl;
  getUsuario()->mostrarUsuario();

  cout << "\n\t=====livro=====\n";
  getLivro()->mostrarLivro();

  cout << "\n\t=====data de aluguel=====\n";
  cout << "Data de aluguel: " 
  << getDataDeAluguel().tm_mday << "/"  
  << getDataDeAluguel().tm_mon << "/" 
  << getDataDeAluguel().tm_year << endl;
}