#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "system.hpp"
#include <sstream>

TEST_CASE("Verificação de CPF")
{ 
    /*---------------------------------------------------
        Adendo: a função TratarCPF não foi testada neste
        escopo pois cumpre apenas a função de auxiliar a
        função  VerificaCpf
    ----------------------------------------------------*/
    Sistema sistema;
    SUBCASE("CPF válido")
    {
        std::string cpf= "00100100101";       

        CHECK(sistema.VerificarCpf(cpf)==true);
    }

    SUBCASE("CPF inválido (tem letras)")
    {
        std::string cpf= "a0100100101";
        std::stringstream buffer;
        std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());
        CHECK(sistema.VerificarCpf(cpf)==false);
        std::cout.rdbuf(old);
        std::string saida = buffer.str();
        CHECK(saida=="ERRO: Apenas numeros sao permitidos\n");
    }

    SUBCASE("CPF inválido (tem mais de 11 dígitos)")
    {
        
        std::string cpf= "910100100101";
        std::stringstream buffer;
        std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());
        CHECK(sistema.VerificarCpf(cpf)==false);
        std::cout.rdbuf(old);
        std::string saida = buffer.str();
        CHECK(saida=="ERRO: CPF possui 11 digitos\n");
    }

    SUBCASE("CPF inválido (tem menos de 11 dígitos)")
    {
        
        std::string cpf= "987";
        std::stringstream buffer;
        std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());
        CHECK(sistema.VerificarCpf(cpf)==false);
        std::cout.rdbuf(old);
        std::string saida = buffer.str();
        CHECK(saida=="ERRO: CPF possui 11 digitos\n");
    }

}

TEST_CASE("Verificação de nome")
{
  /*---------------------------------------------------
        Adendo: a função TratarNome não foi testada neste
        escopo pois cumpre apenas a função de auxiliar a
        função  VerificaNome
    ----------------------------------------------------*/
        SUBCASE("Nome inválido")
        {
        Sistema sistema;
        std::string nome= "987"; //números como parâmetro
        std::stringstream buffer;
        std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());
        CHECK(sistema.VerificarNome(nome)==false);
        std::cout.rdbuf(old);
        std::string saida = buffer.str();
        CHECK(saida=="ERRO: Apenas letras e espacos\n");
        }
        
        SUBCASE("Nome inválido")
        {
        Sistema sistema;
        std::string nome= "Ludovicus"; //números como parâmetro
        CHECK(sistema.VerificarNome(nome)==true);
        }
}

