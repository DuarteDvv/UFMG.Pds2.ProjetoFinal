#include "Function.hpp"
#include <iostream>
#include <string>
#include <thread>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

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

bool verifica_categoria(const std::string &cat) {

    for (char a : cat)
    {
        if (!isalpha(a) && !isspace(a))
        {
            std::cout << "ERRO: Apenas letras e espacos" << std::endl;
            return false;
        }
    }

    std::string categoria = cat;
    std::transform(categoria.begin(), categoria.end(), categoria.begin(), ::tolower);

    std::unordered_set<std::string> categoriasValidas = {
        "lancamentos", "lancamento", "lançamento", "lançamentos", "l",
        "estoque", "estoques", "e",
        "promocao", "promocoes", "promoção", "promoções", "promoçao", "promo", "promoçoes", "p", "promocão", "promocões"
    };

    return categoriasValidas.find(categoria) != categoriasValidas.end();
}

std::string retorna_categoria(const std::string &cat) {
    std::unordered_map<std::string, std::string> mapeamentoCategorias = {
        {"lancamentos", "lancamento"},
        {"lancamento", "lancamento"},
        {"lançamento", "lancamento"},
        {"lançamentos", "lancamento"},
        {"l", "lancamento"},
        {"estoque", "estoque"},
        {"estoques", "estoque"},
        {"e", "estoque"},
        {"promocao", "promocao"},
        {"promocoes", "promocao"},
        {"promoção", "promocao"},
        {"promoções", "promocao"},
        {"promoçao", "promocao"},
        {"promo", "promocao"},
        {"promoçoes", "promocao"},
        {"p", "promocao"},
        {"promocão", "promocao"},
        {"promocões", "promocao"}
    };

    std::string categoria = cat;
    std::transform(categoria.begin(), categoria.end(), categoria.begin(), ::tolower);

    auto it = mapeamentoCategorias.find(categoria);
    return (it != mapeamentoCategorias.end()) ? it->second : "";
}


std::string padroniza_entrada(std::string &entrada){
    std::transform(entrada.begin(), entrada.end(), entrada.begin(), ::toupper);
    return entrada;
} 


void mostrarOpcoes() {
    std::cout << "CC - Cadastrar Cliente | RC - Remover Clientes\n"
              << "LC - Listar Clientes | LA - Ler Arquivo\n"
              << "CF - Cadastrar Filme | RF - Remover Filme\n"
              << "LF - Listar Filme | AL - Alugar Filme\n"
              << "DV - Devolucao | FS - Finalizar\n"
              << "OE - Opcoes de Estoque | RA - Registros De Alugueis\n";
}

bool finalizar_prog() {
    bool a = true;

    try {
        std::cout << "Deseja retornar à tela inicial?\n"
                  << "Sim [S]\n"
                  << "Não [N]" << std::endl;

        std::string resposta;
        std::cin >> resposta;
        std::transform(resposta.begin(), resposta.end(), resposta.begin(), ::tolower);

        LimparTela();

        if (resposta == "sim" || resposta == "s") {
            a = false;
        } else if (resposta == "nao" || resposta == "n") {
            std:: cout << "\033[1;32mO Pograma foi fechado corretamente\033[0m\n";

            a = true;
        } else {
            throw std::invalid_argument("Opcao invalida.");
        }
    } catch (const std::exception& e) {
        std::cerr << "Erro: " << e.what() << std::endl;
    }

    return a;
}
