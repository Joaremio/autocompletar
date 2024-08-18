#ifndef LISTA_H
#define LISTA_H

#include <iostream>
#include <algorithm> // Para std::sort

using namespace std;

template <typename T>
class Lista {
protected:
    T* dados;       // Ponteiro para armazenar os itens da lista
    int contador;    // Número real de elementos na lista
    int tamanho; // Capacidade atual da lista (quantos elementos ela pode armazenar)
public:
    Lista();              // Construtor
    ~Lista();             // Destrutor
    int size() const;           // Método para obter o tamanho da lista //era tamanho
    void add(const T elemento);  // Método para inserir itens na lista // inserir
    void show();       // Método para imprimir a lista na tela //imprimir
    const T& operator[](int i) const; // Sobrecarga do operador [] const
};

template <typename T>
Lista<T>::Lista(){
    contador = 0;
    tamanho = 10;
    dados = new T[tamanho];
}

template <typename T>
Lista<T>::~Lista() {
    delete[] dados;
}

template <typename T>
void Lista<T>::add(const T elemento) {
    if (contador == tamanho) {
        tamanho = tamanho*2;
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
int Lista<T>::size()const{
    return contador;
}

template <typename T>
void Lista<T>::show() {
    for (int i = 0; i < contador; i++) {
        std::cout << dados[i] << " ";
    }
    cout << endl;
}


template <typename T>
inline const T &Lista<T>::operator[](int i) const
{
    if (i < 0 || i >= contador) { //
        throw std::out_of_range("Índice fora do intervalo!"); // vou apagar isso depois 
    }
    return dados[i];
}

template <typename T>
class ListaOrdenada : public Lista<T> {
public:
    ListaOrdenada() : Lista<T>() {}

    void ordenar();
    void ordenar(bool (*func_compara)(const T&, const T&));
};

template <typename T>
void ListaOrdenada<T>::ordenar() {
    sort(this->dados, this->dados + this->contador);
}

template <typename T>
void ListaOrdenada<T>::ordenar(bool (*func_compara)(const T&, const T&)) {
    sort(this->dados, this->dados + this->contador, func_compara);
}

// Funções de comparação

inline bool compararCrescente(const int& a, const int& b) {
    return a < b;
}

inline bool compararDecrescente(const int& a, const int& b) {
    return a > b;
}


#endif // LISTA_H