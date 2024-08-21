#ifndef TERMO_H
#define TERMO_H

#include <string>
#include <iostream>

using namespace std;

class Termo {
private:
    string termo;
    long peso;

public:
    Termo();
    Termo(const string termo_, long peso_);

    static int compararPeloPeso(const Termo& t1, const Termo& t2);
    static int compararPeloPrefixo(const Termo& t1, const Termo& t2, int r);

    bool operator<(const Termo& t2) const;

    friend ostream& operator<<(ostream& out, const Termo& t);

    // Métodos de acesso
    int getPeso() const;
    const string& getTermo() const;
    
};

#endif // TERMO_H