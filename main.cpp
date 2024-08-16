#include <iostream>
#include "autocomplete.h"

int main() {
    Autocompletar autocomplete;

    // Adicionando termos
    autocomplete.adicionarTermo(Termo("apple", 10));
    autocomplete.adicionarTermo(Termo("app", 5));
    autocomplete.adicionarTermo(Termo("application", 8));

    // Ordenar por peso
    autocomplete.ordenarPorPeso();
    std::cout << "Termos ordenados por peso:" << std::endl;
    autocomplete.imprimir();

    // Buscar por prefixo
    std::cout << "Termos que começam com 'app':" << std::endl;
    ListaOrdenada<Termo> resultados = autocomplete.buscarPorPrefixo("app");
    resultados.imprimir();

    // Ordenar por prefixo
    autocomplete.ordenarPorPrefixo(3);
    std::cout << "Termos ordenados por prefixo:" << std::endl;
    autocomplete.imprimir();

    std::cout << "Olá";

    return 0;
}
