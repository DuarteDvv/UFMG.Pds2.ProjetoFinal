#include "functions.hpp"
#include <iostream>
#include <string>
#include <thread>
#include <algorithm>

// Funçoes que definem o parametro para ordenar em ordem crescente caso cpf ou alfabetica caso nome;
// Poderia ter utilizado funções lambdas -> [](const std::string& a, const std::string& b) {return a < b;}
bool compN(Usuario *&a, Usuario *&b)
{
    std::string nomeA = a->getNome();
    std::string nomeB = b->getNome();

    // Converte os nomes para minúsculas antes de comparar
    std::transform(nomeA.begin(), nomeA.end(), nomeA.begin(), ::tolower);
    std::transform(nomeB.begin(), nomeB.end(), nomeB.begin(), ::tolower);

    return nomeA < nomeB;
}

bool compC(Usuario *&a, Usuario *&b)
{
    return std::stoll(a->getCPF()) < std::stoll(b->getCPF());
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

// Limpa a tela do terminal
void LimparTela() {
    #ifdef _WIN32
            system("cls");  // Se estiver usando Windows
    #else
            system("clear"); // Se estiver usando Unix/Linux
    #endif
}

void Desenha(int progress, int total) {

    int larguraBarra = 40;
    int larguraBarraProgresso = (progress * larguraBarra) / total;

    std::cout << "[";

    for (int i = 0; i < larguraBarraProgresso; ++i) {
        std::cout << "=";
    }

    for (int i = larguraBarraProgresso; i < larguraBarra; ++i) {
        std::cout << " ";
    }

    std::cout << "] " << (progress * 100) / total << "%\r";
    std::cout.flush();
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
    else if (cat == "promocao" || cat == "promocoes" || cat == "promoção" || cat == "promoções" || cat == "promoçao" || cat == "promo" || cat == "promoçoes" || cat == "p" || cat == "promocão" || cat == "promocões")
    {
        resultado = true;
    }
    return resultado;
}

std::string retorna_categoria(std::string &cat)
{
    std::string resultado;

    /*mesmo processo do veririca_categoria
    passa para o minúsculo, vê qual categoria que se aplica e retorna uma string com essa categoria
    na formatação certa para o programa conseguir atribuir a categoria na classe DVD
    */

    std::transform(cat.begin(), cat.end(), cat.begin(), ::tolower);
    if (cat == "lancamentos" || cat == "lancamento" || cat == "lançamento" || cat == "lançamentos" || cat == "l")
    {
        resultado = "lancamento";
    }
    else if (cat == "estoque" || cat == "estoques" || cat == "e")
    {
        resultado = "estoque";
    }
    else if (cat == "promocao" || cat == "promocoes" || cat == "promoção" || cat == "promoções" || cat == "promoçao" || cat == "promo" || cat == "promoçoes" || cat == "p" || cat == "promocão" || cat == "promocões")
    {
        resultado = "promocao";
    }
    return resultado;
}


std::string padroniza_entrada(std::string &entrada){
    std::transform(entrada.begin(), entrada.end(), entrada.begin(), ::tolower);
    return entrada;
}
