#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H
#include <iostream>
#include "Usuario.h"
#include "Aluguel.h"
#include "Cliente.h"
#include "Veiculo.h"
#include <vector>
#include <string>
using namespace std;

#pragma once

class Funcionario : public Usuario
{
public:

    // vector<Aluguel> listHistoricoAlugueis;

    // Funcionario(string cpf, string nome, string endereco, string telefone, vector<Aluguel> listHistoricoAlugueis) : Usuario(cpf, nome, endereco, telefone) {
    //     this->cpf = cpf;
    //     this->nome = nome;
    //     this->endereco = endereco;
    //     this->telefone = telefone;
    //     this->listHistoricoAlugueis = listHistoricoAlugueis;
    // }

    // Funcionario(){}

    // ~Funcionario(){}

    // void setAluguel(Aluguel aluguel)
    // {
    //     this->listHistoricoAlugueis.push_back(aluguel);
    // }

    // vector<Aluguel> getAluguel()
    // {
    //     return this->listHistoricoAlugueis;
    // }

    // Aluguel alugarVeiculo(Cliente cliente, Veiculo veiculo, string dataInicio, string dataTermino){}

    // void finalizarAluguel(Aluguel dataDevolucao){}

private:

};

#endif