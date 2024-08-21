#include "read.h"
#include <fstream>
#include <iostream>
#include <string>
#include "Termo.h"
#include "lista.h"

using namespace std;

void openfile(const string& arquive, ListaOrdenada<Termo>& lista_) {
    ifstream arquivo(arquive); // abertura do arquivo
    string line;
    if (!arquivo) { // Verifica se o arquivo foi aberto com sucesso
        cerr << "Erro durante abertura do arquivo." << endl;
        return;
    }

    // Ler cada linha do arquivo
    while (getline(arquivo, line)) { 
        size_t posicao = line.find('\t');
        string termo_;
        string peso_;
        
        if (posicao != string::npos) { // Se encontrou o separador
            termo_ = line.substr(posicao + 1);  // Extrai o termo
            peso_ = line.substr(0, posicao); // Extrai o peso como string

            // Converte o peso para long
            long peso = stol(peso_); 
            Termo termoOb(termo_, peso); // Cria o objeto Termo
            lista_.add(termoOb); // Adiciona à lista
        }
    }

    arquivo.close(); // Fecha o arquivo
}
