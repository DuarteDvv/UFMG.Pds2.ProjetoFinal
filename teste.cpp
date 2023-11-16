#include <iostream>
#include <thread>
#include <chrono>

class Sistema {
public:
    void animacaoSalvando() {
        const int duracaoAnimacao = 10;  // número de iterações para a animação
        const int duracaoPonto = 500;    // tempo em milissegundos para cada ponto

        for (int i = 0; i < duracaoAnimacao; ++i) {
            limparTela();
            std::cout << "Salvando";
            for (int j = 0; j < i % 4; ++j) {
                std::cout << ".";
            }
            std::cout.flush();
            std::this_thread::sleep_for(std::chrono::milliseconds(duracaoPonto));
        }

        limparTela();
        std::cout << "Dados salvos com sucesso!";
    }

private:
    void limparTela() {
#ifdef _WIN32
        system("cls");  // Se estiver usando Windows
#else
        system("clear"); // Se estiver usando Unix/Linux
#endif
    }
};

int main() {
    Sistema sistema;
    sistema.animacaoSalvando();

    return 0;
}
