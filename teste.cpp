#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    string nomedoarquivo;
    cout << "Digite o nome do arquivo: ";
    cin >> nomedoarquivo;

    string tipo, titulo, categoria, tituloComCategoria;
    int quantidade, codigo;

    ifstream file(nomedoarquivo);
    if (!file.is_open()) {
        cerr << "Erro ao abrir o arquivo." << endl;
        return 1;
    }

    while (file >> tipo >> quantidade >> codigo) {
        file.ignore();  

        if (tipo == "D") {
            getline(file,tituloComCategoria);
            int posicao = tituloComCategoria.find_last_of(' ');
            titulo = tituloComCategoria.substr(0,posicao);
            categoria = tituloComCategoria.substr(posicao + 1);
        } else {
            getline(file, titulo);
        }

        cout << "Tipo: " << tipo << ", Quantidade: " << quantidade << ", Código: " << codigo;

        if (tipo == "D") {
            cout << ", Título: " << titulo << ", Categoria: " << categoria;
        } else {
            cout << ", Título: " << titulo;
        }

        cout << endl;
    }

    file.close();

    return 0;
}