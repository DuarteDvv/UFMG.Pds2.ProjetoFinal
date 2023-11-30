#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "system.hpp"
#include "Usuario.hpp"
#include "Film.hpp"
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

TEST_CASE("Cadastrar cliente e verificar existência de Usuário")
{
    /*---------------------------------------------------
        Adendo: a função TratarExistenciaU não foi testada 
        neste escopo pois cumpre apenas a função de 
        auxiliar a função ExisteUsuario
    ----------------------------------------------------*/

    SUBCASE("O usuário existe")
    {
        Sistema sistema;

        //Criando usuário
        std::string nome = "Ludovicus";
        std::string cpf = "00100100101";
        Usuario* u = new Usuario(nome, cpf); 

        sistema.CadastrarCliente(u);
        CHECK(sistema.ExisteUsuario(cpf)==true);
    }

    SUBCASE("O usuário não existe")
    {
        Sistema sistema;
        std::string cpf = "00100100101";
        CHECK(sistema.ExisteUsuario(cpf)==false);
    }

}

TEST_CASE("Remover Cliente")
{
   Sistema sistema;

        //Criando usuário
        std::string nome = "Ludovicus";
        std::string cpf = "00100100101";
        Usuario* u = new Usuario(nome, cpf); 

        sistema.CadastrarCliente(u);
        sistema.RemoverCliente(cpf);
        CHECK(sistema.ExisteUsuario(cpf)==false); 
}

TEST_CASE("Listar clientes")
{
    Sistema sistema;
    std::string nome = "Ludovicus";
    std::string cpf = "00100100101";
    Usuario* u = new Usuario(nome, cpf);
    std::string cat ="N"; 
    std::stringstream buffer;
    std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());

    sistema.CadastrarCliente(u);
    sistema.ListarCliente(cat);
    std::cout.rdbuf(old);
    std::string saida = buffer.str();

    CHECK(saida=="|| 00100100101 || >> Ludovicus\n");

}

TEST_CASE("Verificar título")
{
    SUBCASE("Título válido")
    {
    Sistema sistema;
    std::string tit = "Titulo de Teste";
    CHECK(sistema.VerificaTitulo(tit)==true);
    }

    SUBCASE("Título inválido")
    {
    Sistema sistema;
    std::string tit = "Teste/////";
    CHECK(sistema.VerificaTitulo(tit)==false);
    }
}

TEST_CASE("Cadastrar filme e Existe filme")
{
    Sistema sistema;
    int cod=456;
    filme* e = new dvd(cod,"Título teste II",1,"promocao");
    sistema.CadastrarFilme(e);
    CHECK(sistema.ExisteFilme(cod)==true);
    
}

TEST_CASE("Listar filmes")
{
    Sistema sistema;
    int cod=456;
    std::string cmd = "T";
    std::stringstream buffer;
    std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());
    filme* e = new dvd(cod,"Título teste II",1,"promocao");
    sistema.CadastrarFilme(e);
    sistema.ListarFilmes(cmd);
    std::cout.rdbuf(old);
    std::string saida = buffer.str();

    CHECK(saida=="||456|| >> Título teste II\n");
}

TEST_CASE("Remoção de filme")
{
     Sistema sistema;
    int cod=456;
    filme* e = new dvd(cod,"Título teste II",1,"promocao");
    sistema.CadastrarFilme(e);
    sistema.RemoverFilme(cod);
    
    CHECK(sistema.ExisteFilme(cod)==false);
}

/*
    Adendo: Os demais métodos desta classe foram suprimidos
    nos testes por cumprirem funções auxiliares ou apenas
    reproduzirem o funcionamento das aqui já testadas. 
*/
