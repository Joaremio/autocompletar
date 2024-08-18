#ifndef LISTA_H
#define LISTA_H

#include <iostream>
#include <algorithm> // Para std::sort

using namespace std;

template <typename T>
class Lista {
protected:
    T* itens;       // Ponteiro para armazenar os itens da lista
    int capacidade; // Capacidade atual da lista (quantos elementos ela pode armazenar)
    int tamanho;    // Número real de elementos na lista

public:
    Lista();              // Construtor
    ~Lista();             // Destrutor

    void inserir(const T elemento);  // Método para inserir itens na lista
    int getTamanho() const;       // Método para obter o tamanho da lista
    void imprimir() const;        // Método para imprimir a lista na tela
    const T& operator[](int i) const; // Sobrecarga do operador [] const
};

template <typename T>
Lista<T>::Lista(){
    tamanho = 0;
    capacidade = 10;
    itens = new T[capacidade];
}

template <typename T>
Lista<T>::~Lista() {
    delete[] itens;
}

template <typename T>
void Lista<T>::inserir(const T elemento) {
    if (tamanho == capacidade) {
        capacidade *= 2;
        T* vnovo = new T[capacidade];

        for (int i = 0; i < tamanho; i++) {
            vnovo[i] = itens[i];
        }

        delete[] itens;
        itens = vnovo;
    }

    itens[tamanho] = elemento;
    tamanho++;
}

template <typename T>
int Lista<T>::getTamanho() const {
    return tamanho;
}

template <typename T>
void Lista<T>::imprimir() const {
    for (int i = 0; i < tamanho; i++) {
        std::cout << itens[i] << " ";
    }
    cout << endl;
}


template <typename T>
inline const T &Lista<T>::operator[](int i) const
{
    if (i < 0 || i >= tamanho) { //
        throw std::out_of_range("Índice fora do intervalo!"); // vou apagar isso depois 
    }
    return itens[i];
}

template <typename T>
class ListaOrdenada : public Lista<T> {
public:
    ListaOrdenada() : Lista<T>() {}

    void ordenar();
    void ordenar(bool (*func_compara)(const T&, const T&));
};

template <typename T>
void ListaOrdenada<T>::ordenar(bool (*func_compara)(const T&, const T&)) {
    sort(this->itens, this->itens + this->tamanho, func_compara);
}

template <typename T>
void ListaOrdenada<T>::ordenar() {
    sort(this->itens, this->itens + this->tamanho);
}

// Funções de comparação

inline bool compararCrescente(const int& a, const int& b) {
    return a < b;
}

inline bool compararDecrescente(const int& a, const int& b) {
    return a > b;
}


#endif // LISTA_H
