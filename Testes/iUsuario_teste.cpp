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

