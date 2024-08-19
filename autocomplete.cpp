#include "autocomplete.h"
#include <iostream>
#include <algorithm>

Autocompletar::Autocompletar(const ListaOrdenada<Termo>& lista, int limite){
    termos = lista;
    k = limite;
}
void Autocompletar::buscarPorPrefixo(const std::string& prefixo, ListaOrdenada<Termo>& resultados) const {
    for (int i = 0; i < termos.size(); ++i) {
        const Termo& termo = termos[i];
        // Obtenha o termo completo
        std::string termoCompleto = termo.getTermo();
        
        // Verifica se o prefixo corresponde ao início do termo
        if (termoCompleto.substr(0, prefixo.length()) == prefixo) {
            resultados.add(termo);
        }
    }
}

void Autocompletar::exibirResultados(const std::string& prefixo) const {
    ListaOrdenada<Termo> resultados;
    buscarPorPrefixo(prefixo, resultados);
    
    resultados.ordenar([](const Termo& t1, const Termo& t2) {
        return t1.getPeso() > t2.getPeso();  // Ordena por peso em ordem decrescente
    });
    
    int limite = std::min(k, resultados.size());
    for (int i = 0; i < limite; ++i) {
        std::cout << resultados[i] << std::endl;
    }
}
