#include "functions.hpp"
#include <iostream>
#include <string>

bool verifica_nome(std::string &nome)
{
    for (char a : nome)
    {
        if (!isalpha(a) && !isspace(a))
        {
            return false;
        }
    }
    return true;
}

// Função para verificar se um usuário já está registrado na lista de usuários
bool existeUsuario(std::list<Usuario> &Banco_de_usuarios, const std::string &cpf)
{
    for (auto it = Banco_de_usuarios.begin(); it != Banco_de_usuarios.end(); ++it)
    {
        if (it->getCPF() == cpf)
        {
            return true;
        }
    }
    return false;
}

// Função que vai verificar se o cpf é válido
bool verifica_cpf(std::string &cpf)
{
    for (char a : cpf)
    {
        if (!std::isdigit(a))
        {
            return false;
            break;
        }
    }
    if (cpf.length() != 11)
    {
        return false;
    }

    return true;
}

// Função que remove um usuario da lista
void removeUsuario(std::list<Usuario> &Banco_de_usuarios, const std::string &cpf)
{
    for (auto it = Banco_de_usuarios.begin(); it != Banco_de_usuarios.end(); ++it)
    {
        if (it->getCPF() == (cpf))
        {
            it = Banco_de_usuarios.erase(it);
        }
    }
}

// Funçoes que definem o parametro para ordenar em ordem crescente caso cpf ou alfabetica caso nome;
// Poderia ter utilizado funções lambdas -> [](const std::string& a, const std::string& b) {return a < b;}
bool compN(Usuario &a, Usuario &b)
{
    std::string nomeA = a.getNome();
    std::string nomeB = b.getNome();

    // Converte os títulos para minúsculas antes de comparar
    std::transform(nomeA.begin(), nomeA.end(), nomeA.begin(), ::tolower);
    std::transform(nomeB.begin(), nomeB.end(), nomeB.begin(), ::tolower);

    return nomeA < nomeB;
}

bool compC(Usuario &a, Usuario &b)
{
    return std::stoll(a.getCPF()) < std::stoll(b.getCPF());
}

bool ExisteFilme(std::list<filme *> &catalogo, const int &codigo)
{
    for (auto it = catalogo.begin(); it != catalogo.end(); ++it)
    {
        if ((*it)->getCod() == codigo)
        {
            return true;
        }
    }
    return false;
}

// Verifica se existe caracte
bool verificaDadosFilme(std::string &)
{
}

// Função que remove um filme do catálogo
void removeFilme(std::list<filme *> &catalogo, const int &codigo)
{
    for (auto it = catalogo.begin(); it != catalogo.end(); ++it)
    {
        if ((*it)->getCod() == codigo)
        {
            it = catalogo.erase(it);
        }
    }
}

// Define parametro de ordenação por titulo
bool compT(filme *&a, filme *&b)
{
    std::string tituloA = a->getTitulo();
    std::string tituloB = b->getTitulo();

    // Converte os títulos para minúsculas antes de comparar
    std::transform(tituloA.begin(), tituloA.end(), tituloA.begin(), ::tolower);
    std::transform(tituloB.begin(), tituloB.end(), tituloB.begin(), ::tolower);

    return tituloA < tituloB;
}

bool compCf(filme *&(a), filme *&(b))
{
    return (a)->getCod() < (b)->getCod();
}

bool verifica_titulo(std::string &titulo)
{
    bool resultado = true;
    for (char a : titulo)
    {
        if (!isalnum(a) && !isspace(a))
        {
            resultado = false;
            break;
        }
    }
    return resultado;
}

bool verifica_categoria(std::string &cat)
{
    // Passar tudo para o minúsculo antes de começar
    std::transform(cat.begin(), cat.end(), cat.begin(), ::tolower);
    bool resultado = false;
    if (cat == "lancamentos" || cat == "lancamento" || cat == "lançamento" || cat == "lançamentos" || cat == "l")
    {
        resultado = true;
    }
    else if (cat == "estoque" || cat == "estoques" || cat == "e")
    {
        resultado = true;
    } 
    else if(cat =="promocao" || cat=="promocoes" || cat =="promoção" || cat == "promoções" || cat =="promoçao" || cat == "promo" || cat =="promoçoes"|| cat == "p" || cat =="promocão" || cat == "promocões"){
        resultado = true;
    }
    return resultado;
}
