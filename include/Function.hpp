#ifndef FUNCT_
#define FUNCT_

#include "Usuario.hpp"
#include <list>
#include <cctype>
#include <string>
#include <algorithm>
#include "Film.hpp"
#include "system.hpp"

// Funções de comparação para ordenação de usuários por nome (alfabética) ou CPF (crescente)
bool compN(Usuario *&, Usuario *&);
bool compC(Usuario *&, Usuario *&);

// Funções de comparação para ordenação de filmes por título ou código
bool compT(filme *&, filme *&);
bool compCf(filme *&, filme *&);

/* Verifica se a categoria fornecida pelo usuário é válida,
 retorna true se for válida, false caso contrário*/
bool verifica_categoria(const std::string &);

// Retorna uma categoria padronizada, mesmo se o usuário fornecer uma entrada alternativa
std::string retorna_categoria(const std::string &cat);

// Função para limpar a tela do terminal
void LimparTela();

// Desenha uma barra de progresso para indicar o andamento de uma operação
void Desenha(int progress, int total);

// Padroniza a entrada para garantir consistência (por exemplo, CC e cc são equivalentes)
std::string padroniza_entrada(std::string &);

// Verifica se o usuário deseja encerrar o programa. Retorna true se sim, false caso contrário
bool finalizar_prog();

// Mostra as opções disponíveis para o usuário
void mostrarOpcoes();

#endif
