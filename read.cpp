#include "read.h"
#include <fstream>
#include <iostream>
#include <string>
#include "lista.h"

using namespace std;

void openfile(const string& nomeArquivo, ListaOrdenada<Termo>& lista) {
    ifstream arquivo(nomeArquivo); // abertura
    string line;
    if (!arquivo) { // Verifica o arquivo
        cerr << "Erro durante abertura do arquivo." << endl; //imprime na tela caso tenha algum erro
        return; // Sai da função caso haja erro
    }

    
    while (getline(arquivo, line)) { // Lê cada linha do arquivo
        size_t posicao = line.find('\t');
        string termo_;
        string peso_;
        
         // Encontra a posição da tabulação

        if (posicao != string::npos) { // Se encontrou a tabulação
            termo_ = line.substr(posicao + 1);  // Extrai o termo
            peso_ = line.substr(0, posicao); // Extrai o peso como string

            int64_t peso = stoll(peso_); // Converte o peso para número
            Termo termoOb(termo_, peso); // Cria o objeto Termo
            lista.add(termoOb); // Adiciona à lista
        }
    }

    arquivo.close(); // Fecha o arquivo
}
