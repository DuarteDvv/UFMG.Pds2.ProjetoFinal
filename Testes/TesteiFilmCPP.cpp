#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "iFilm.cpp"

TEST_CASE("Calculo de preço - Operações básicas") 
{
CHECK(CalcularPreco(10) == 100);
CHECK(CalcularPreco(-10) == 0);
CHECK(CalcularPreco(0) == 0);
}
