#ifndef AUTOCOMPLETE_H
#define AUTOCOMPLETE_H

#include "Termo.h"
#include "lista.h"
#include <string>

class Autocompletar {
private:
    ListaOrdenada<Termo> termos;
    int k;

public:
    Autocompletar(const ListaOrdenada<Termo>& lista, int limite);

    void exibirResultados(const std::string& prefixo) const;

private:
    void buscarPorPrefixo(const std::string& prefixo, ListaOrdenada<Termo>& resultados) const;
};

#endif // AUTOCOMPLETAR_H
