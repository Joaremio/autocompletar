#include "autocomplete.h"
#include <functional>

Autocompletar::Autocompletar(int cap) : termos(cap) {}

void Autocompletar::adicionarTermo(const Termo& termo) {
    termos.inserir(termo);
}

ListaOrdenada<Termo> Autocompletar::buscarPorPrefixo(const std::string& prefixo) const {
    ListaOrdenada<Termo> resultados;

    for (int i = 0; i < termos.getTamanho(); ++i) {
        const Termo& termo = termos[i];
        if (termo.getTermo().find(prefixo) == 0) {
            resultados.inserir(termo);
        }
    }

    return resultados;
}

void Autocompletar::ordenarPorPeso() {
    termos.ordenar([](const Termo& t1, const Termo& t2) {
        return Termo::compararPeloPeso(t1, t2) < 0;
    });
}

void Autocompletar::ordenarPorPrefixo(int r) {
    termos.ordenar([r](const Termo& t1, const Termo& t2) {
        return Termo::compararPeloPrefixo(t1, t2, r) < 0;
    });
}

void Autocompletar::imprimir() const {
    termos.imprimir();
}
