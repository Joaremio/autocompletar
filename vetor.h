#ifndef VETOR_H
#define VETOR_H


#include <iostream>

using namespace std;


template <typename T>
class Vetor{
    private:
        struct no{
            T dado;
            no *seguir;
        };
        no* origem;
        int contador;
    
    public:
        Vetor();
        ~Vetor();
        int size();
        T at(int i);
        void show();
        bool add(T i_);
        bool sort(bool (*func_compara)(const T&, const T&));
        bool remove(int i);

};
#endif



template <typename T>
Vetor<T>::Vetor()
{
    contador = 0;
    origem = nullptr;
    
}

template <typename T>
 Vetor<T>::~Vetor(){
    no *temp = origem;
    while(temp!=nullptr){
        no *seguinte = temp->seguir;
        delete temp;
        temp = seguinte;
    }
}

template <typename T>
int Vetor<T>::size()
{
    return contador;
}

template <typename T> 
T Vetor<T>::at(int i){
   try{ 
    if(i>=contador){
        throw "Posição invalida";
    }
    if(i<0){
        throw "Posição invalida";
    }
    else{
    no *temp = origem;

    for(int j=0; j<i; j++){
        temp = temp->seguir;
    }

    return temp->dado; // retorna o elemento na posição que foi passada apos o laço de repetição
    }
    
   }catch(const char* msg){
        cout << "ERROR: " << msg << endl;
        return T();
   }

}

template <typename T>
bool Vetor<T>::add(T i_)
{
try{
    no *tmp= new no();
    no *iterador = new no();

    if(origem==nullptr){
        tmp->dado = i_;
        tmp->seguir = nullptr;
        origem = tmp; // adiciona na origem caso o vetor ainda nao tenha elementos.
    }else{
        iterador = origem;
        while(iterador->seguir!=nullptr){
            iterador=iterador->seguir;  
        }
        tmp->dado =i_;
        tmp->seguir =nullptr;
        iterador->seguir = tmp; // adiciona no fim do vetor apos realizar o laço de repetição.
    } 
    contador = contador + 1; //incrementa o tammanho do vetor
    return true;
    } catch(...){
        return false;
    }
}

template <typename T>
void Vetor<T>::show(){
    no *tmp = origem;

    while(tmp!=nullptr){
        cout << tmp->dado << endl;
        tmp = tmp->seguir;
    }


}
template <typename T>
bool Vetor<T>::sort(bool(*func_compara)(const T&, const T&)){
    

    if (origem == nullptr) {
        throw "ERRO: VETOR VAZIO";
        return false;
    }

    
    T* array = new T[contador]; // Converte o vetor para um array
    no* temp = origem;

    for (int i = 0; i < contador; ++i) {
        array[i] = temp->dado;  //adicionando os elementos
        temp = temp->seguir;
    }


    for (int i = 0; i < contador - 1; ++i) {
        for (int j = 0; j < contador - i - 1; ++j) {
            if (!func_compara(array[j], array[j + 1])) { // Troca os elementos se estiverem fora de ordem
                T temp_val = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp_val;
            }
        }
    }

    
    temp = origem;
    for (int i = 0; i < contador; ++i) { // Converte o array de volta para o vetor encadeado
        temp->dado = array[i];
        temp = temp->seguir;
    }

    delete[] array; //libero a memoria alocada
    return true;
   
}


template <typename T>
bool Vetor<T>::remove(int i){
    

    no *temp = origem;
    
try{
    if(i<0){
        throw "Posição invalida";
    }
    if(i>=contador){
        throw "Posição invalida";
    }
    if(i==0){
        origem = origem->seguir;
        delete temp;
        contador = contador-1;
        return true;
    }

    no *reserva;

    for(int r=0; r<i; r++){
        reserva = temp;
        temp=temp->seguir; // laço de repetição até a posição do elemento a ser removido.
    }
    reserva->seguir = temp->seguir; // guarda o valor e depois deleta.
    delete temp;
    contador = contador - 1; // diminui o tamanho do vetor.
    return true;
    }
    catch(const char* msg){
        cout << "ERROR: " << msg << endl;
        return false;
   }catch (...){
		return false;
	}
}
    

    



