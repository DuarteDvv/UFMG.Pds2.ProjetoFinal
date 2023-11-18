#ifndef FUNCT_
#define FUNCT_

#include "Usuario.hpp"
#include <list>
#include <cctype>
#include <string>
#include <algorithm>
#include "Film.hpp"
#include "system.hpp"


// Funçoes que definem o parametro que ordena em ordem crescente caso cpf ou alfabetica caso nome;
bool compN(Usuario *&, Usuario *&);
bool compC(Usuario *&, Usuario *&);

// Comparação para titulo
bool compT(filme *&, filme *&);
// Comparaçã para cod
bool compCf(filme *&, filme *&);

// Função que verifica se o usuário colocou uma categoria que existe (com as exeções)
// OBS: só retorna true ou false
bool verifica_categoria(const std::string &);

/*Função que vai retornar estoque, lancamento ou promocao (forma que tá escrita na classe filme)
 mesmo que o usuario escreva errado */
std::string retorna_categoria(const std::string &cat);

//Extra
//Limpa tela do terminal
void LimparTela();
//Desenha as animações de carregar
void Desenha(int progress, int total);
//padroniza as entradas para que CC e cc sejam equivalentes
std::string padroniza_entrada(std::string &);

//função que vai me dizer se o usuário quer encerrar o programa, se verdadeiro, o programa encerra
bool finalizar_prog();

//função que serve para o usuário voltar á tela inicial 
void retorno_menu(); 

//função que mostra as opções ao usuário 
void mostrarOpcoes(); 
#endif
