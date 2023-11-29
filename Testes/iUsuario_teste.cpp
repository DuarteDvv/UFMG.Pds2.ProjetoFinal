#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Usuario.hpp"

TEST_CASE("Obter CPF do usuário")
{
        std::string nome = "Ludovicus";
        std::string cpf = "00100100101";
        Usuario* u = new Usuario(nome, cpf); 
        
        CHECK(u->getCPF() == "00100100101");
}

TEST_CASE("Obter Nome do usuário")
{
        std::string nome = "Ludovicus";
        std::string cpf = "00100100101";
        Usuario* u = new Usuario(nome, cpf);

        CHECK(u->getNome()=="Ludovicus");
}

TEST_CASE("Obter número de acessos do usuário")
{
        std::string nome = "Ludovicus";
        std::string cpf = "00100100101";
        Usuario* u = new Usuario(nome, cpf);

        CHECK(u->getAcessos()==1);
        u->AcessAdd(25);
        CHECK(u->getAcessos()==26);
}

