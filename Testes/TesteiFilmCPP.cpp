#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "system.hpp"

TEST_CASE("Cálculo de Preço para diferentes tipos de filme") {

    /* -------------------------------------------------------------------
        Adendo: A hipótese em que a quantidade de dias inserida é negativa
        não foi inserida neste escopo pois essa exceção é tratada ainda
        na função main.    
    ---------------------------------------------------------------------- */

    SUBCASE("Tipo Estoque") 
    {
        Sistema sistema;
        std::string TituloTeste = "Título teste";
        std::string TipoTeste = "estoque";
        filme* d = new dvd(123,TituloTeste,1,TipoTeste); 
        sistema.CadastrarFilme(d);

        CHECK(d->CalcularPreco(5) == doctest::Approx(10.0 * 5));
    }

     SUBCASE("Tipo Promocao") 
    {
        Sistema sistema;
        std::string TituloTeste = "Título teste";
        std::string TipoTeste = "promocao";
        filme* d = new dvd(123,TituloTeste,1,TipoTeste); 
        sistema.CadastrarFilme(d);

        CHECK(d->CalcularPreco(5) == doctest::Approx(10.0));
    }

    SUBCASE("Tipo Lançamento") 
    {
        Sistema sistema;
        std::string TituloTeste = "Título teste";
        std::string TipoTeste = "lancamento";
        filme* d = new dvd(123,TituloTeste,1,TipoTeste); 
        sistema.CadastrarFilme(d);

        CHECK(d->CalcularPreco(5) == doctest::Approx(100.0));
    }


}
