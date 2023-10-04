#ifndef CLIENTE_H
#define CLIENTE_H
#include <iostream>
#include "Veiculo.h"
#include "Usuario.h"
#include "Aluguel.h"
#include <string>
#include <vector>
using namespace std;

#pragma once

class Cliente : public Usuario
{
public:

    // Aluguel aluguel;
    string habilitacao;
    vector<Cliente> listHistoricoAlugueis;

    Cliente(string cpf, string nome, string endereco, string telefone, string habilitacao, vector<Cliente> listHistoricoAlugueis) : Usuario(cpf, nome, endereco, telefone) {
        this->cpf = cpf;
        this->nome = nome;
        this->endereco = endereco;
        this->telefone = telefone;
        this->habilitacao = habilitacao;
        this->listHistoricoAlugueis = listHistoricoAlugueis;
    }

    Cliente(){}

    ~Cliente(){}

    void setHabilitacao(string habilitacao)
    {
        this->habilitacao = habilitacao;
    }

    string getHabilitacao()
    {
        return this->habilitacao;
    }

    // void setAluguel(Aluguel aluguel)
    // {
    //     this->listHistoricoAlugueis.push_back(aluguel);
    // }

    // vector<Aluguel> getAluguel()
    // {
    //     return this->listHistoricoAlugueis;
    // }

    float cotarAluguel(Veiculo veiculo, string dataInicio, string dataTermino);

    // Aluguel alugarVeiculo(Veiculo veiculo, string dataInicio, string dataTermino);

    // void devolverVeiculo(Aluguel aluguel, string dataDevolucao){}



private:

};

#endif