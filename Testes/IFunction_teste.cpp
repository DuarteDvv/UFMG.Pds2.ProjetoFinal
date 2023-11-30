#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Function.hpp"
#include "Usuario.hpp"
#include "Film.hpp"
#include <sstream>

TEST_CASE("Comparar nomes")
{
    std::string nome = "Ludovicus";
    std::string cpf = "00100100101";

    std::string nome2 = "Artemis";
    std::string cpf2 = "00200200202";

    Usuario* u = new Usuario(nome, cpf);
    Usuario* j = new Usuario(nome2, cpf2);

    CHECK(compN(u,j)==false);        
}

TEST_CASE("Comparar CPFs")
{
    std::string nome = "Ludovicus";
    std::string cpf = "00100100101";

    std::string nome2 = "Artemis";
    std::string cpf2 = "00200200202";

    Usuario* u = new Usuario(nome, cpf);
    Usuario* j = new Usuario(nome2, cpf2);

    CHECK(compC(u,j)==true);
}

TEST_CASE("Comparar títulos")
{
    std::string TituloTeste = "Título teste";
    std::string TipoTeste = "promocao";

    std::string TituloTeste2 = "Alfabeto";
    std::string TipoTeste2 = "promocao";

    filme* d = new dvd(123,TituloTeste,1,TipoTeste);
    filme* e = new dvd(456,TituloTeste2,1,TipoTeste2);

    CHECK(compT(e,d)); 
}

TEST_CASE("Comparar código do filme")
{
    std::string TituloTeste = "Título teste";
    std::string TipoTeste = "promocao";

    std::string TituloTeste2 = "Alfabeto";
    std::string TipoTeste2 = "promocao";

    filme* d = new dvd(123,TituloTeste,1,TipoTeste);
    filme* e = new dvd(456,TituloTeste2,1,TipoTeste2);

    CHECK(compCf(d,e));
}

TEST_CASE("Mostra de opções")
{
    std::stringstream buffer;
    std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());

    mostrarOpcoes();

    std::cout.rdbuf(old);
    std::string saida = buffer.str();

    CHECK(saida=="CC - Cadastrar Cliente | RC - Remover Clientes\nLC - Listar Clientes | LA - Ler Arquivo\nCF - Cadastrar Filme | RF - Remover Filme\nLF - Listar Filme | AL - Alugar Filme\nDV - Devolucao | FS - Finalizar\nOE - Opcoes de Estoque | RA - Registros De Alugueis\n");
}

/*
    Adendo: Os demais métodos desta classe foram suprimidos
    nos testes por cumprirem funções auxiliares ou apenas
    reproduzirem o funcionamento das aqui já testadas. 
*/
