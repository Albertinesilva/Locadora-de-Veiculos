#ifndef USUARIO_H
#define USUARIO_H
#include <iostream>
#include <string>
using namespace std;

#pragma once

class Usuario
{
public:
    string cpf;
    string nome;
    string endereco;
    string telefone;

    Usuario(string cpf, string nome, string endereco, string telefone)
    {
        this->cpf = cpf;
        this->nome = nome;
        this->endereco = endereco;
        this->telefone = telefone;
    }

    Usuario() {}

    ~Usuario() {}

    void setCPF(string cpf)
    {
        this->cpf = cpf;
    }

    string getCPF()
    {
        return this->cpf;
    }

    void setNome(string nome)
    {
        this->nome = nome;
    }

    string getNome()
    {
        return this->nome;
    }

    void setEndereco(string endereco)
    {
        this->endereco = endereco;
    }

    string getEndereco()
    {
        return this->endereco;
    }

    void setTelefone(string telefone)
    {
        this->telefone = telefone;
    }

    string getTelefone()
    {
        return this->telefone;
    }

    void imprime()
    {
        cout << "CPF: " << this->cpf << endl;
        cout << "Nome: " << this->nome << endl;
        cout << "Endereco: " << this->endereco << endl;
        cout << "Telefone: " << this->telefone << endl;
    }

private:
};

#endif