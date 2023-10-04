#ifndef VEICULO_H
#define VEICULO_H
#include <iostream>
#include "Aluguel.h"
#include <string>
using namespace std;

#pragma once

class Veiculo
{
public:
    string identificador;
    string marca;
    string modelo;
    int anoFabricacao;
    float precoPorDia;

    Veiculo(string identificador, string marca, string modelo, int anoFabricacao, float precoPorDia)
    {
        this->identificador = identificador;
        this->marca = marca;
        this->modelo = modelo;
        this->anoFabricacao = anoFabricacao;
        this->precoPorDia = precoPorDia;
    }

    Veiculo() {}

    ~Veiculo() {}

    void setIdentificador(string identificador)
    {
        this->identificador = identificador;
    }

    string getIdentificador()
    {
        return this->identificador;
    }

    void setMarca(string marca)
    {
        this->marca = marca;
    }

    string getMarca()
    {
        return this->marca;
    }

    void setModelo(string modelo)
    {
        this->modelo = modelo;
    }

    string getModelo()
    {
        return this->modelo;
    }

    void setAnoFabricacao(int anoFabricacao)
    {
        this->anoFabricacao = anoFabricacao;
    }

    int getAnoFabricacao()
    {
        return this->anoFabricacao;
    }

    void setPrecoPorDia(float precoPorDia)
    {
        this->precoPorDia = precoPorDia;
    }

    float getPrecoPorDia()
    {
        return this->precoPorDia;
    }

private:
};

#endif