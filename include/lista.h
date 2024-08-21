#ifndef LISTA_H
#define LISTA_H

#include <iostream>
#include <algorithm> 

using namespace std;

template <typename T>
class Lista {
protected:
    T* dados;       // Ponteiro para os itens da lista
    int contador;    // Número de elementos na lista
    int tamanho; // Capacidade atual da lista

public:
    Lista();              
    ~Lista();             
    int size() const;           // obter o tamanho da lista
    void add(const T& elemento);  // inserir itens na lista
    void show() const;       // imprimir a lista na tela
    const T& operator[](int i) const; // Sobrecarga do operador [] 

    // Método para acessar os dados
    T* getDados() { return dados; }
    const T* getDados() const { return dados; }
};

template <typename T>
Lista<T>::Lista() : contador(0), tamanho(10) {
    dados = new T[tamanho];
}

template <typename T>
Lista<T>::~Lista() {
    
}

template <typename T>
void Lista<T>::add(const T& elemento) {
    if (contador == tamanho) {
        tamanho *= 2;
        T* vnovo = new T[tamanho];

        for (int i = 0; i < contador; i++) {
            vnovo[i] = dados[i];
        }

        delete[] dados;
        dados = vnovo;
    }

    dados[contador] = elemento;
    contador++;
}

template <typename T>
int Lista<T>::size() const {
    return contador;
}

template <typename T>
void Lista<T>::show() const {
    for (int i = 0; i < contador; i++) {
        std::cout << dados[i] << " ";
    }
    cout << endl;
}

template <typename T>
inline const T& Lista<T>::operator[](int i) const {
    if (i < 0 || i >= contador) {
        throw std::out_of_range("Índice fora do intervalo!");
    }
    return dados[i];
}

template <typename T>
class ListaOrdenada : public Lista<T> {
public:
    ListaOrdenada() : Lista<T>() {}

    void ordenar();
    void ordenar(bool (*func_compara)(const T&, const T&));

    // Use os métodos da classe base para acessar os dados
    using Lista<T>::getDados;
};

template <typename T>
void ListaOrdenada<T>::ordenar() {
    std::sort(this->getDados(), this->getDados() + this->size());
}

template <typename T>
void ListaOrdenada<T>::ordenar(bool(*func_compara)(const T&, const T&)) {
    std::sort(this->getDados(), this->getDados() + this->size(), func_compara);
}


#endif // LISTA_H

