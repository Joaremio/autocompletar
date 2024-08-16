#ifndef AUTOCOMPLETE_H
#define AUTOCOMPLETE_H

#include "lista.h"
#include "Termo.h"

class Autocompletar {
private:
    ListaOrdenada<Termo> termos; // Lista para armazenar os termos

public:
    Autocompletar(int cap = 10); // Construtor

    void adicionarTermo(const Termo& termo); // Adiciona um termo à lista
    ListaOrdenada<Termo> buscarPorPrefixo(const std::string& prefixo) const; // Busca termos com um prefixo específico
    void ordenarPorPeso(); // Ordena os termos por peso
    void ordenarPorPrefixo(int r); // Ordena os termos por prefixo com base em r

    void imprimir() const; // Imprime todos os termos
};

#endif // AUTOCOMPLETAR_H
