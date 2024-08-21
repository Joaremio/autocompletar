#include <iostream>
#include <string>
#include "Termo.h"
#include "lista.h"
#include "autocomplete.h"
#include "read.h"

void processarEntrada(int argc, char* argv[], std::string& arquivoDados, int& k) {
    if (argc < 3) {
        std::cout << "Uso: " << argv[0] << " <arquivo_dados> <k>" << std::endl;
        exit(1);
    }
    arquivoDados = argv[1];
    k = atoi(argv[2]); // Simpler alternative to std::stoi
}

int main(int argc, char* argv[]) {
    std::string arquivoDados;
    int k;

    // Processar argumentos de entrada
    processarEntrada(argc, argv, arquivoDados, k);

    // Carregar os dados do arquivo na lista
    ListaOrdenada<Termo> lista;
    openfile(arquivoDados, lista);

    // Ordenar a lista por termo
    lista.ordenar([](const Termo& t1, const Termo& t2) {
        return t1.getTermo() < t2.getTermo();
    });

    // Criar objeto Autocompletar
    Autocompletar autocomplete(lista, k);

    // Loop de consulta
    std::string consulta;
    while (true) {
        std::cout << "Entre com o termo a ser auto-completado: (digite \"sair\" para encerrar o programa): " << std::endl;
        std::getline(std::cin, consulta);

        if (consulta == "sair") {
            break;
        }

        autocomplete.exibirResultados(consulta);
    }

    return 0;
}
