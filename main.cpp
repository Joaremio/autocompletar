#include <fstream>
#include <sstream>
#include <stdexcept>
#include "Termo.h"
#include "lista.h"
#include "autocomplete.h"
#include <iostream>
#include <string>

// Função para carregar os dados do arquivo e armazená-los na lista
void carregarDados(const std::string& nomeArquivo, ListaOrdenada<Termo>& lista) {
    std::ifstream arquivo(nomeArquivo);
    if (!arquivo.is_open()) {
        throw std::runtime_error("Não foi possível abrir o arquivo: " + nomeArquivo);
    }

    std::string linha;
    while (std::getline(arquivo, linha)) {
        std::istringstream iss(linha);
        std::string pesoStr, termo;
        
        if (!std::getline(iss, pesoStr, '\t') || !std::getline(iss, termo)) {
            throw std::runtime_error("Erro ao ler linha do arquivo: " + linha);
        }

        int64_t peso = std::stoll(pesoStr);
        Termo termoObj(termo, peso);
        lista.inserir(termoObj);
    }

    arquivo.close();
}

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

    std::cout << "Olaw" ;

    return 0;
}
