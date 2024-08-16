#ifndef TERMO_H
#define TERMO_H

#include <string>
#include <iostream>

class Termo {
private:
    std::string termo;
    int peso;

public:
    Termo();
    Termo(const std::string& termo, int peso);

    static int compararPeloPeso(const Termo& t1, const Termo& t2);
    static int compararPeloPrefixo(const Termo& t1, const Termo& t2, int r);

    bool operator<(const Termo& t2) const;

    friend std::ostream& operator<<(std::ostream& out, const Termo& t);

    // Métodos de acesso
    const std::string& getTermo() const;
    int getPeso() const;
};

#endif // TERMO_H
