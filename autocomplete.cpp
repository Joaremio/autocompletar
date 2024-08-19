#include "autocomplete.h"
#include <iostream>
#include <algorithm>

Autocompletar::Autocompletar(ListaOrdenada<Termo>& lista_, int maximo) {
    termos = lista_;
    k = maximo;
}

// Função de comparação para buscar por prefixo
bool compararPorPrefixo(const Termo& termo, const std::string& prefixo) {
    return termo.getTermo() < prefixo;
}

template <typename T>
int buscaBinaria(const T* dados, int tamanho, const std::string& valor, bool (*func_compara)(const T&, const std::string&)) {
    int left = 0;
    int right = tamanho - 1;

    while (left <= right) {
        int meio = left + (right - left) / 2;
        if (func_compara(dados[meio], valor)) {
            left = meio + 1;
        } else {
            right = meio - 1;
        }
    }
    return left;
}


void Autocompletar::buscarPorPrefixo(const std::string& prefixo, ListaOrdenada<Termo>& resultados) const {
    std::string prefixoMin = prefixo;
    std::string prefixoMax = prefixo + static_cast<char>(prefixo.back() + 1);

    // Acessa os dados usando o método de acesso
    int start = buscaBinaria(termos.getDados(), termos.size(), prefixoMin, compararPorPrefixo);
    int end = buscaBinaria(termos.getDados(), termos.size(), prefixoMax, compararPorPrefixo);

    for (int i = start; i < end && i < termos.size(); ++i) {
        if (termos[i].getTermo().substr(0, prefixo.size()) == prefixo) {
            resultados.add(termos[i]);
        }
    }
}



void Autocompletar::exibirResultados(const std::string& prefixo) const {
    ListaOrdenada<Termo> resultados;
    buscarPorPrefixo(prefixo, resultados);

    // Ordena os resultados por peso em ordem decrescente
    resultados.ordenar([](const Termo& t1, const Termo& t2) {
        return t1.getPeso() > t2.getPeso();  // Lambda que compara por peso
    });

    int limite = std::min(k, resultados.size());
    for (int i = 0; i < limite; ++i) {
        std::cout << resultados[i] << std::endl;
    }
}
