#ifndef FUNCT_
#define FUNCT_

#include "Usuario.hpp"
#include <list>
#include <cctype>
#include <string>
#include <algorithm>
#include "Film.hpp"

// Funçoes que definem o parametro que ordena em ordem crescente caso cpf ou alfabetica caso nome;
bool compN(Usuario *&, Usuario *&);
bool compC(Usuario *&, Usuario *&);

// Comparação para titulo
bool compT(filme *&, filme *&);
// Comparaçã para cod
bool compCf(filme *&, filme *&);

// Função que verifica se o título está escrito com caracteres alfanuméricos, se sim, retorna verdadeiro
bool verifica_titulo(std::string &);

// Função que verifica se o usuário colocou uma categoria que existe (com as exeções)
// OBS: só retorna true ou false
bool verifica_categoria(std::string &);

/*Função que vai retornar estoque, lancamento ou promocao (forma que tá escrita na classe filme)
 mesmo que o usuario escreva errado */
std::string retorna_categoria(std::string &);


#endif
