#include <iostream>
#include <string>
#include "Termo.h"
#include "lista.h"
#include "autocomplete.h"
#include "read.h"

using namespace std;



int main(int argc, char* argv[]) {

     if (argc != 3) {
        cerr << "Uso: " << argv[0] << " <caminho_arquivo> <max_resultados>" << endl;
        return 1;
    }
   
    string pesquisa;
    string baseDados = argv[1];
    int k = atoi(argv[2]);

    // Carregar os dados do arquivo na lista
    ListaOrdenada<Termo> lista;
    openfile(baseDados, lista);

    // Ordenar a lista por termo
    lista.ordenar([](const Termo& t1, const Termo& t2) {
        return t1.getTermo() < t2.getTermo();
    });

    Autocompletar autocomplete(lista, k);

    // Para a consulta
    while (true) {
        cout << endl << "Entre com o termo a ser autoo-completado: (digite \"sair\" para encerrar o programa): " << endl;
        cin  >> pesquisa;

        if (pesquisa == "sair") {
            break;
        }

        if (!pesquisa.empty()) { // Verifica se a consulta não está vazia
        autocomplete.exibirResultados(pesquisa);
    }
    }

  
    
    
    return 0;
}
