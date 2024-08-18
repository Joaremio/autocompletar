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

#include <functional>

template <typename T>
class ListaOrdenada : public Lista<T> {
public:
    ListaOrdenada() : Lista<T>() {}

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
