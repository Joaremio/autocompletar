#include <fstream>
#include <sstream>
#include <stdexcept>
#include "Termo.h"
#include "lista.h"
#include "autocomplete.h"
#include <iostream>
#include <string>
#include "read.h"

int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cerr << "Uso: " << argv[0] << " <arquivo_dados> <k>" << std::endl;
        return 1;
    }

    std::string arquivoDados = argv[1];
    int k = std::stoi(argv[2]);

    ListaOrdenada<Termo> lista;
    carregarDados(arquivoDados, lista);

    lista.ordenar([](const Termo& t1, const Termo& t2) {
        return t1.getTermo() < t2.getTermo();
    });

    Autocompletar autocomplete(lista, k);

    std::string consulta;
    while (true) {
        std::cout << "Entre com o termo a ser auto-completado: (digite \"sair\" para encerrar o programa): " << std::endl;
        std::getline(std::cin, consulta);

        if (consulta == "sair") {
            break;
        }

        autocomplete.exibirResultados(consulta);
    }

    std::cout << "Olwaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaww" ;

    return 0;
}
