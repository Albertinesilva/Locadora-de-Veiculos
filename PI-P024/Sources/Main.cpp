#include "../Headers/BancoDeDados.hpp"
#include "../Headers/Dependente.hpp"
#include "../Headers/Deslocamento.hpp"
#include "../Headers/Evento.hpp"
#include <iostream>

using namespace std;

int main()
{
    BancoDeDados* banco = new BancoDeDados();
    Dependente* dependente = new Dependente();
    Deslocamento* deslocamento = new Deslocamento();
    Evento* evento = new Evento();
    cout << "Hello World!" << endl;
    return 0;
}