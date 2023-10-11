#include "../Headers/Tarefa.hpp"

int Tarefa::quantidadeDeIdentificadores = 0;

Tarefa::Tarefa(){}

Tarefa::~Tarefa(){}

Tarefa::Tarefa(const string &titulo, const string &descricao, const string &dataDeCriacao, const string &dataDeConclusao, const bool &concluida)
{
  this->id = 0;
  this->titulo = titulo;
  this->descricao = descricao;
  this->dataDeCriacao = dataDeCriacao;
  this->dataDeConclusao = dataDeConclusao;
  this->concluida = concluida;
}

int Tarefa::getId()
{
  return this->id;
}

void Tarefa::setId(int id)
{
  this->id = id;
}

string Tarefa::getTitulo()
{
  return this->titulo;
}

void Tarefa::setTitulo(string titulo)
{
  this->titulo = titulo;
}

string Tarefa::getDescricao()
{
  return this->descricao;
}

void Tarefa::setDescricao(string descricao)
{
  this->descricao = descricao;
}

string Tarefa::getDataDeCriacao()
{
  return this->dataDeCriacao;
}

void Tarefa::setDataDeCriacao(string dataDeCriacao)
{
  this->dataDeCriacao = dataDeCriacao;
}

string Tarefa::getDataDeConclusao()
{
  return this->dataDeConclusao;
}

void Tarefa::setDataDeConclusao(string dataDeConclusao)
{
  this->dataDeConclusao = dataDeConclusao;
}

bool Tarefa::getConcluida()
{
  return this->concluida;
}

void Tarefa::setConcluida(bool concluida)
{
  this->concluida = concluida;
}
