#ifndef GERENCIADORTAREFAS_HPP
#define GERENCIADORTAREFAS_HPP
#include "Tarefa.hpp"

#include <iostream>

using namespace std;

class GerenciadorTarefas
{
private:
  Tarefa *tarefas;
  int quantidadeTarefas;
  int quantidadeMaximaTarefas;

public:
  GerenciadorTarefas(int quantidadeMaximaTarefas);

  GerenciadorTarefas();

  ~GerenciadorTarefas();

  Tarefa *getTarefas();
  void setTarefas(Tarefa *tarefas);

  int getQuantidadeTarefas();
  void setQuantidadeTarefas(int quantidadeTarefas);

  int getQuantidadeMaximaTarefas();
  void setQuantidadeMaximaTarefas(int quantidadeMaximaTarefas);

  void adicionarTarefa(Tarefa tarefa);

  void removerTarefa(int id);

  void listarTarefas();

  void listarTarefasPorPrioridade();

  void listarTarefasPorStatus();

  void listarTarefasPorResponsavel();

  void listarTarefasPorData();

  void listarTarefasPorPrazo();

  void listarTarefasPorTitulo();

  void listarTarefasPorDescricao();

  void listarTarefasPorId();

  void listarTarefasPorId(int id);
};

#endif