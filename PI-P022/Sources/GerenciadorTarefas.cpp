#include "../Headers/GerenciadorTarefas.hpp"


GerenciadorTarefas::GerenciadorTarefas(int quantidadeMaximaTarefas)
{
  this->quantidadeMaximaTarefas = quantidadeMaximaTarefas;
}

GerenciadorTarefas::~GerenciadorTarefas(){}

GerenciadorTarefas::GerenciadorTarefas(){}

Tarefa *GerenciadorTarefas::getTarefas()
{
  return this->tarefas;
}

void GerenciadorTarefas::setTarefas(Tarefa *tarefas)
{
  this->tarefas = tarefas;
}

int GerenciadorTarefas::getQuantidadeTarefas()
{
  return this->quantidadeTarefas;
}

void GerenciadorTarefas::setQuantidadeTarefas(int quantidadeTarefas)
{
  this->quantidadeTarefas = quantidadeTarefas;
}

int GerenciadorTarefas::getQuantidadeMaximaTarefas()
{
  return this->quantidadeMaximaTarefas;
}

void GerenciadorTarefas::setQuantidadeMaximaTarefas(int quantidadeMaximaTarefas)
{
  this->quantidadeMaximaTarefas = quantidadeMaximaTarefas;
}