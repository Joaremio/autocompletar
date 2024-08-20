#ifndef READ_H
#define READ_H

#include <string>
#include "lista.h"
#include "Termo.h"

// Declaração da função carregarDados
void carregarDados(const std::string& nomeArquivo, ListaOrdenada<Termo>& lista);

#endif // READ_H