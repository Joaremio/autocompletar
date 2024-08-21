#ifndef AUTOCOMPLETE_H
#define AUTOCOMPLETE_H

#include "Termo.h"
#include "lista.h"
#include <string>

using namespace std;

class Autocompletar {
private:
    ListaOrdenada<Termo> termos;
    int k;

public:
    Autocompletar(ListaOrdenada<Termo>& lista, int limite);

    void exibirResultados(const string& prefixo) const;

private:
    void buscarPorPrefixo(const string& prefixo, ListaOrdenada<Termo>& resultados) const;
};

#endif // AUTOCOMPLETAR_H
