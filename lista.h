#ifndef LISTA_H
#define LISTA_H

#include <iostream>
#include <algorithm> // Para std::sort

template <typename T>
class Lista {
protected:
    T* itens;       // Ponteiro para armazenar os itens da lista
    int capacidade; // Capacidade atual da lista (quantos elementos ela pode armazenar)
    int tamanho;    // Número real de elementos na lista

public:
    Lista();              // Construtor
    ~Lista();             // Destrutor

    void inserir(const T& item);  // Método para inserir itens na lista
    int getTamanho() const;       // Método para obter o tamanho da lista
    void imprimir() const;        // Método para imprimir a lista na tela
    T& operator[](int index);     // Sobrecarga do operador []
    const T& operator[](int index) const; // Sobrecarga do operador [] const
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
void Lista<T>::inserir(const T& item) {
    if (tamanho == capacidade) {
        capacidade *= 2;
        T* novosItens = new T[capacidade];

        for (int i = 0; i < tamanho; ++i) {
            novosItens[i] = itens[i];
        }

        delete[] itens;
        itens = novosItens;
    }

    itens[tamanho] = item;
    tamanho++;
}

template <typename T>
int Lista<T>::getTamanho() const {
    return tamanho;
}

template <typename T>
void Lista<T>::imprimir() const {
    for (int i = 0; i < tamanho; ++i) {
        std::cout << itens[i] << " ";
    }
    std::cout << std::endl;
}

template <typename T>
T& Lista<T>::operator[](int index) {
    if (index < 0 || index >= tamanho) {
        throw std::out_of_range("Índice fora do intervalo!");
    }
    return itens[index];
}

template <typename T>
inline const T &Lista<T>::operator[](int index) const
{
    if (index < 0 || index >= tamanho) {
        throw std::out_of_range("Índice fora do intervalo!");
    }
    return itens[index];
}

#include <functional>

template <typename T>
class ListaOrdenada : public Lista<T> {
public:
    ListaOrdenada(int cap = 10) : Lista<T>(cap) {}

    void ordenar();  // Ordena usando a STL (std::sort)
    void ordenar(std::function<bool(const T&, const T&)> comp);  // Ordena usando uma função de comparação
};

template <typename T>
void ListaOrdenada<T>::ordenar(std::function<bool(const T&, const T&)> comp) {
    std::sort(this->itens, this->itens + this->tamanho, comp);
}
template <typename T>
void ListaOrdenada<T>::ordenar() {
    std::sort(this->itens, this->itens + this->tamanho);
}



#endif // LISTA_H
