#ifndef ALUGUEL_H
#define ALUGUEL_H
#include <iostream>
#include "Veiculo.h"
#include "Cliente.h"
#include "Funcionario.h"
#include <string>
#include <vector>
using namespace std;

#pragma once

class Aluguel
{
public:

    string identificador;
    Veiculo veiculo;
    Cliente cliente;
    Funcionario funcionario;
    string dataInicio;
    string dataTermino;
    string dataDevolucao;
    float desconto;
    float adicional;
    vector<Aluguel> listAlugueis;

    Aluguel(string identificador, Veiculo veiculo, Cliente cliente, Funcionario funcionario, string dataInicio, string dataTermino, string dataDevolucao, float desconto, float adicional)
    {
        this->identificador = identificador;
        this->veiculo = veiculo;
        this->cliente = cliente;
        this->funcionario = funcionario;
        this->dataInicio = dataInicio;
        this->dataTermino = dataTermino;
        this->dataDevolucao = dataDevolucao;
        this->desconto = desconto;
        this->adicional = adicional;
    }

    Aluguel() {}

    ~Aluguel() {}

    void setIdentificador(string identificador)
    {
        this->identificador = identificador;
    }

    string getIdentificador()
    {
        return this->identificador;
    }

    void setVeiculo(Veiculo veiculo)
    {
        this->veiculo = veiculo;
    }

    Veiculo getVeiculo()
    {
        return this->veiculo;
    }

    void setCliente(Cliente cliente)
    {
        this->cliente = cliente;
    }

    Cliente getCliente()
    {
        return this->cliente;
    }

    void setFuncionario(Funcionario funcionario)
    {
        this->funcionario = funcionario;
    }

    Funcionario getFuncionario()
    {
        return this->funcionario;
    }

    void setDataInicio(string dataInicio)
    {
        this->dataInicio = dataInicio;
    }

    string getDataInicio()
    {
        return this->dataInicio;
    }

    void setDataTermino(string dataTermino)
    {
        this->dataTermino = dataTermino;
    }

    string getDataTermino()
    {
        return this->dataTermino;
    }

    void setDataDevolucao(string dataDevolucao)
    {
        this->dataDevolucao = dataDevolucao;
    }

    string getDataDevolucao()
    {
        return this->dataDevolucao;
    }

    void setDesconto(float desconto)
    {
        this->desconto = desconto;
    }

    float getDesconto()
    {
        return this->desconto;
    }

    void setAdicional(float adicional)
    {
        this->adicional = adicional;
    }

    float getAdicional()
    {
        return this->adicional;
    }

    float calcularValorFinal()
    {
        return 0;
    }

private:
};

#endif