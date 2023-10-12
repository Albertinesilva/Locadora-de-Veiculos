#include "../Headers/Livro.hpp"
#include "../Headers/Usuario.hpp"
#include "../Headers/Biblioteca.hpp"
#include <iostream>

using namespace std;

int main(){

  Biblioteca biblioteca;
  Biblioteca::recuperaLivros(*biblioteca.getLivros());
  Biblioteca::recuperaUsuarios(*biblioteca.getUsuarios());
  Biblioteca::recuperaAlugueis(*biblioteca.getAlugueis(), *biblioteca.getUsuarios(), *biblioteca.getLivros());
  biblioteca.menuPrincipal(*biblioteca.getAlugueis(), *biblioteca.getUsuarios(), *biblioteca.getLivros());

}