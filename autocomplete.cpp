#include "autocomplete.h"
#include <iostream>

using namespace std;


Autocompletar::Autocompletar(ListaOrdenada<Termo>& lista_, int maximo) {
    termos = lista_;
    k = maximo;
}

// Função de comparação para buscar por prefixo
bool compararPorPrefixo(const Termo& termo, const string& prefixo) {
    return termo.getTermo() < prefixo;
}

template <typename T>
int buscabinaria(const T* item, int tamanho, const string& valor, bool (*func_compara)(const T&, const string&)) {
    int inicio = 0;
    int fim = tamanho - 1;

    while (inicio <= fim) {
        int meio = inicio + (fim - inicio) / 2;
        if (func_compara(item[meio], valor)) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    return inicio;
}


void Autocompletar::buscarPorPrefixo(const string& prefixo, ListaOrdenada<Termo>& resultados) const {
    string pref1 = prefixo;
    string pref2 = prefixo + static_cast<char>(prefixo.back() + 1);

    // Acessa os dados usando o método de acesso
    int inicio = buscabinaria(termos.getDados(), termos.size(), pref1, compararPorPrefixo);
    int  fim = buscabinaria(termos.getDados(), termos.size(), pref2, compararPorPrefixo);

    for (int i = inicio; i < fim && i < termos.size(); ++i) {
        if (termos[i].getTermo().substr(0, prefixo.size()) == prefixo) {
            resultados.add(termos[i]);
        }
    }
}

void Autocompletar::exibirResultados(const string& prefixo) const {
    ListaOrdenada<Termo> resultados;
    buscarPorPrefixo(prefixo, resultados);

    // Ordena os resultados por peso em ordem decrescente usando o método de comparação da classe Termo
    resultados.ordenar([](const Termo& t1, const Termo& t2) {
        return Termo::compararPeloPeso(t1, t2) > 0;  // Utiliza o método compararPeloPeso para ordenar
    });

    int maximo;

    if(resultados.size()<k){
        maximo = resultados.size();
    }else{
        maximo = k;
    }
    for (int i = 0; i < maximo; ++i) {
        cout << resultados[i] << endl;
    }
}