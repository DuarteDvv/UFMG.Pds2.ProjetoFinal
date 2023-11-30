#ifndef _sys
#define _sys

#include <list>
#include <iostream>
#include "Usuario.hpp"
#include "Film.hpp"
#include "Function.hpp"
#include <fstream>
#include <thread>
#include <chrono>

// Definição da classe Sistema
class Sistema
{
private:
    // Listas para armazenar objetos de usuário e filmes
    std::list<Usuario *> Usuarios;
    std::list<filme *> Catalogo;

public:
    // Destrutor da classe, responsável por liberar a memória alocada para usuários e filmes
    ~Sistema()
    {
        for (auto &usuarioPtr : Usuarios)
        {
            delete usuarioPtr;
        }

        for (auto &filmePtr : Catalogo)
        {
            delete filmePtr;
        }
    }

    // Métodos relacionados aos usuários
    void TratarCPF(std::string &); // Trata o CPF para consistência
    void TratarNome(std::string &); // Trata o nome para consistência
    void TratarExistenciaU(std::string &); // Trata a existência de um usuário
    void TratarListagemU(std::string &); // Trata a listagem de usuários
    bool VerificarCpf(std::string &); // Verifica a validade do CPF
    bool VerificarNome(std::string &); // Verifica a validade do nome
    bool ExisteUsuario(std::string &); // Verifica se um usuário existe
    void CadastrarCliente(Usuario *&); // Cadastra um novo cliente
    void RemoverCliente(std::string &); // Remove um cliente
    void ListarCliente(std::string &); // Lista os clientes

    // Métodos relacionados aos filmes
    void TratarTIPO(std::string &); // Trata o tipo de filme
    void TratarQuantidade(int &); // Trata a quantidade de filmes
    void TratarCod(int &); // Trata o código do filme
    void TratarTitulo(std::string &); // Trata o título do filme
    void CadastrarFilme(filme *&); // Cadastra um novo filme
    bool VerificaTitulo(std::string &); // Verifica a existência de um título
    void TratarCat(std::string &); // Trata a categoria do filme
    void TratarCodN(int &); // Trata o código do filme para listagem
    void TratarListagemF(std::string &); // Trata a listagem de filmes
    void TratarExistenciaF(int &); // Trata a existência de um filme
    bool ExisteFilme(int &); // Verifica se um filme existe
    void ListarFilmes(std::string &); // Lista os filmes
    void RemoverFilme(int &); // Remove um filme
    void AdicionarCarrinho(int &, std::string &); // Adiciona filme ao carrinho
    void ListarCompras(std::string &); // Lista as compras realizadas
    void Recibo(std::string &, int &); // Gera um recibo de compra
    void CadastrarFilmesDoArquivo(std::ifstream &); // Cadastra filmes a partir de um arquivo

    // Métodos adicionais
    void TratarOE(std::string &); // Trata opções de estoque
    void TratarSenha(std::string &); // Trata senha
    void AnimCarregarDados(); // Animação de carregamento de dados
    void animacaoSalvando(); // Animação de salvamento de dados
    void AnimacaoEscolha(); // Animação de escolha
    void LoadData(); // Carrega dados
    void SaveData(); // Salva dados
    void ListarEstoque(); // Lista o estoque
    void RegistroDeAlugays(); // Registra aluguéis
    void incrementarEstoque(int &, int &); // Incrementa o estoque de um filme
    void decrementarEstoque(int &, int &); // Decrementa o estoque de um filme
    void SugerirFilme(); // Sugere um filme
};

#endif
